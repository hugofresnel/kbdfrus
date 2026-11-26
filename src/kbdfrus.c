// The French (US) keyboard layout as a Windows keyboard layout DLL.
//
// Windows loads the DLL and calls `KbdLayerDescriptor` to get the layout
// tables. The DLL has no other code, and no dependency: not even the C runtime.
//
// The kernel reads the tables straight from the file, in the `.data` section
// only: the tables are not `const`, and the `Makefile` links the DLL like the
// layouts of Windows.

#include "characters.h"
#include "dead_keys.h"
#include "kbd.h"
#include "scancodes.h"
#include "vk.h"

// No key names: Windows reads this table without checking for null.
static struct vsc_lpwstr NO_KEY_NAMES[] = {{}};

static struct vk_to_bit VK_TO_BITS[] = {
    {VK_SHIFT, KBDSHIFT},
    {VK_CONTROL, KBDCTRL},
    {VK_MENU, KBDALT},
    {},
};

// The column of the character tables for each modifier combination.
static struct modifiers CHAR_MODIFIERS = {
    .vk_to_bit = VK_TO_BITS,
    .max_mod_bits = 7,
    .mod_number =
        {
            0,            // None
            1,            // Shift
            2,            // Ctrl
            3,            // Shift + Ctrl
            SHFT_INVALID, // Alt
            SHFT_INVALID, // Shift + Alt
            4,            // Ctrl + Alt (AltGr)
            5,            // Shift + Ctrl + Alt (Shift + AltGr)
        },
};

static struct vk_to_wchar_table VK_TO_WCHAR_TABLES[] = {
    {CHARACTERS, 6, sizeof(CHARACTERS[0])},
    {CONTROL_KEYS, 3, sizeof(CONTROL_KEYS[0])},
    {NUMPAD_KEYS, 1, sizeof(NUMPAD_KEYS[0])},
    {},
};

static struct kbd_tables TABLES = {
    .char_modifiers = &CHAR_MODIFIERS,
    .vk_to_wchar_table = VK_TO_WCHAR_TABLES,
    .dead_keys = DEAD_KEYS,
    .key_names = NO_KEY_NAMES,
    .key_names_ext = NO_KEY_NAMES,
    .key_names_dead = nullptr,
    .vsc_to_vk = VSC_TO_VK,
    .max_vsc_to_vk = sizeof(VSC_TO_VK) / sizeof(VSC_TO_VK[0]),
    .vsc_to_vk_e0 = VSC_TO_VK_E0,
    .vsc_to_vk_e1 = VSC_TO_VK_E1,
    .locale_flags = KBD_VERSION << 16 | KLLF_ALTGR,
    .kbd_type = KEYBOARD_TYPE_GENERIC_101,
};

__declspec(dllexport) const struct kbd_tables *KbdLayerDescriptor(void) {
    return &TABLES;
}
