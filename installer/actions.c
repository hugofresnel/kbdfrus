// Installer custom actions: add or remove the layout for the installing user.
#include <windows.h>
#include <msiquery.h>

#define ILOT_UNINSTALL 0x00000001

typedef BOOL(WINAPI *InstallLayoutOrTipFn)(LPCWSTR layout, DWORD flags);

static UINT install_layout(MSIHANDLE install, DWORD flags)
{
    WCHAR layout[32];
    DWORD size = ARRAYSIZE(layout);
    if (MsiGetPropertyW(install, L"CustomActionData", layout, &size) != ERROR_SUCCESS) {
        return ERROR_INSTALL_FAILURE;
    }

    HMODULE input = LoadLibraryExW(L"input.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!input) {
        return ERROR_INSTALL_FAILURE;
    }

    auto install_layout_or_tip =
        (InstallLayoutOrTipFn)(void *)GetProcAddress(input, "InstallLayoutOrTip");
    BOOL ok = install_layout_or_tip && install_layout_or_tip(layout, flags);
    FreeLibrary(input);
    return ok ? ERROR_SUCCESS : ERROR_INSTALL_FAILURE;
}

__declspec(dllexport) UINT WINAPI AddLayout(MSIHANDLE install)
{
    return install_layout(install, 0);
}

__declspec(dllexport) UINT WINAPI RemoveLayout(MSIHANDLE install)
{
    return install_layout(install, ILOT_UNINSTALL);
}
