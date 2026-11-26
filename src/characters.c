// What each key types, for each combination of modifiers.

#include "characters.h"

#include "dead_keys.h"
#include "kbd.h"
#include "vk.h"

// Caps Lock acts as Shift, with and without AltGr.
#define CAPS (CAPLOK | CAPLOKALTGR)

// The character keys of the French (US) layout.
//
// Columns: none, Shift, Ctrl, Shift+Ctrl, AltGr, Shift+AltGr
// (see `CHAR_MODIFIERS` in `kbdfrus.c`).
// A key with a dead key (`WCH_DEAD`) is followed by a `VK__NONE_` row giving
// its accent. Ctrl columns hold ASCII control characters: `u'Q' & 0x1F` is
// `^Q`.
struct vk_to_wchars6 CHARACTERS[] = {
    {VK_OEM_3, 0, {u'`', u'~', WCH_NONE, WCH_NONE, WCH_DEAD, WCH_NONE}},
    {VK__NONE_, 0, {WCH_NONE, WCH_NONE, WCH_NONE, WCH_NONE, GRAVE, WCH_NONE}},
    {'1', 0, {u'1', u'!', WCH_NONE, WCH_NONE, u'1', u'!'}},
    {'2', 0, {u'2', u'@', WCH_NONE, u'@' & 0x1F, u'2', u'@'}},
    {'3', 0, {u'3', u'#', WCH_NONE, WCH_NONE, u'3', u'#'}},
    {'4', 0, {u'4', u'$', WCH_NONE, WCH_NONE, u'€', u'¤'}},
    {'5', 0, {u'5', u'%', WCH_NONE, WCH_NONE, u'€', WCH_NONE}},
    {'6', 0, {u'6', u'^', WCH_NONE, u'^' & 0x1F, WCH_DEAD, WCH_NONE}},
    {VK__NONE_, 0, {WCH_NONE, WCH_NONE, WCH_NONE, WCH_NONE, CIRCUMFLEX, WCH_NONE}},
    {'7', 0, {u'7', u'&', WCH_NONE, WCH_NONE, u'7', u'&'}},
    {'8', 0, {u'8', u'*', WCH_NONE, WCH_NONE, u'8', u'*'}},
    {'9', 0, {u'9', u'(', WCH_NONE, WCH_NONE, u'9', u'('}},
    {'0', 0, {u'0', u')', WCH_NONE, WCH_NONE, u'0', u')'}},
    {VK_OEM_MINUS, 0, {u'-', u'_', WCH_NONE, u'_' & 0x1F, u'-', u'_'}},
    {VK_OEM_PLUS, 0, {u'=', u'+', WCH_NONE, WCH_NONE, u'=', u'+'}},

    {'Q', CAPS, {u'q', u'Q', u'Q' & 0x1F, u'Q' & 0x1F, u'q', u'Q'}},
    {'W', CAPS, {u'w', u'W', u'W' & 0x1F, u'W' & 0x1F, u'w', u'W'}},
    {'E', CAPS, {u'e', u'E', u'E' & 0x1F, u'E' & 0x1F, u'é', u'É'}},
    {'R', CAPS, {u'r', u'R', u'R' & 0x1F, u'R' & 0x1F, u'è', u'È'}},
    {'T', CAPS, {u't', u'T', u'T' & 0x1F, u'T' & 0x1F, u't', u'T'}},
    {'Y', CAPS, {u'y', u'Y', u'Y' & 0x1F, u'Y' & 0x1F, u'ÿ', u'Ÿ'}},
    {'U', CAPS, {u'u', u'U', u'U' & 0x1F, u'U' & 0x1F, u'ù', u'Ù'}},
    {'I', CAPS, {u'i', u'I', u'I' & 0x1F, u'I' & 0x1F, u'ï', u'Ï'}},
    {'O', CAPS, {u'o', u'O', u'O' & 0x1F, u'O' & 0x1F, u'ô', u'Ô'}},
    {'P', CAPS, {u'p', u'P', u'P' & 0x1F, u'P' & 0x1F, u'œ', u'Œ'}},
    {VK_OEM_4, 0, {u'[', u'{', u'[' & 0x1F, WCH_NONE, u'«', u'“'}},
    {VK_OEM_6, 0, {u']', u'}', u']' & 0x1F, WCH_NONE, u'»', u'”'}},
    {VK_OEM_5, 0, {u'\\', u'|', u'\\' & 0x1F, WCH_NONE, u'\\', u'|'}},

    {'A', CAPS, {u'a', u'A', u'A' & 0x1F, u'A' & 0x1F, u'à', u'À'}},
    {'S', CAPS, {u's', u'S', u'S' & 0x1F, u'S' & 0x1F, u'æ', u'Æ'}},
    {'D', CAPS, {u'd', u'D', u'D' & 0x1F, u'D' & 0x1F, u'ê', u'Ê'}},
    {'F', CAPS, {u'f', u'F', u'F' & 0x1F, u'F' & 0x1F, u'ë', u'Ë'}},
    {'G', CAPS, {u'g', u'G', u'G' & 0x1F, u'G' & 0x1F, u'g', u'G'}},
    {'H', CAPS, {u'h', u'H', u'H' & 0x1F, u'H' & 0x1F, u'ü', u'Ü'}},
    {'J', CAPS, {u'j', u'J', u'J' & 0x1F, u'J' & 0x1F, u'û', u'Û'}},
    {'K', CAPS, {u'k', u'K', u'K' & 0x1F, u'K' & 0x1F, u'î', u'Î'}},
    {'L', CAPS, {u'l', u'L', u'L' & 0x1F, u'L' & 0x1F, u'l', u'L'}},
    {VK_OEM_1, 0, {u';', u':', WCH_NONE, WCH_NONE, u';', u':'}},
    {VK_OEM_7, 0, {u'\'', u'"', WCH_NONE, WCH_NONE, WCH_DEAD, u'°'}},
    {VK__NONE_, 0, {WCH_NONE, WCH_NONE, WCH_NONE, WCH_NONE, DIAERESIS, WCH_NONE}},

    {'Z', CAPS, {u'z', u'Z', u'Z' & 0x1F, u'Z' & 0x1F, u'â', u'Â'}},
    {'X', CAPS, {u'x', u'X', u'X' & 0x1F, u'X' & 0x1F, u'x', u'X'}},
    {'C', CAPS, {u'c', u'C', u'C' & 0x1F, u'C' & 0x1F, u'ç', u'Ç'}},
    {'V', CAPS, {u'v', u'V', u'V' & 0x1F, u'V' & 0x1F, u'v', u'V'}},
    {'B', CAPS, {u'b', u'B', u'B' & 0x1F, u'B' & 0x1F, u'b', u'B'}},
    {'N', CAPS, {u'n', u'N', u'N' & 0x1F, u'N' & 0x1F, u'n', u'N'}},
    {'M', CAPS, {u'm', u'M', u'M' & 0x1F, u'M' & 0x1F, u'm', u'M'}},
    {VK_OEM_COMMA, 0, {u',', u'<', WCH_NONE, WCH_NONE, u',', u'<'}},
    {VK_OEM_PERIOD, 0, {u'.', u'>', WCH_NONE, WCH_NONE, u'.', u'>'}},
    {VK_OEM_2, 0, {u'/', u'?', WCH_NONE, WCH_NONE, u'/', u'?'}},
    {VK_OEM_102, 0, {u'<', u'>', WCH_NONE, WCH_NONE, u'|', u'¦'}},

    {VK_SPACE, 0, {u' ', u' ', WCH_NONE, WCH_NONE, u' ', u' '}},
    {},
};

// Keys that type control characters, as on every Windows layout.
// Columns: none, Shift, Ctrl.
struct vk_to_wchars3 CONTROL_KEYS[] = {
    {VK_BACK, 0, {u'H' & 0x1F, u'H' & 0x1F, u'\x7F'}},
    {VK_ESCAPE, 0, {u'[' & 0x1F, u'[' & 0x1F, u'[' & 0x1F}},
    {VK_RETURN, 0, {u'M' & 0x1F, u'M' & 0x1F, u'J' & 0x1F}},
    {VK_CANCEL, 0, {u'C' & 0x1F, u'C' & 0x1F, u'C' & 0x1F}},
    {VK_TAB, 0, {u'I' & 0x1F, u'I' & 0x1F, WCH_NONE}},
    {VK_ADD, 0, {u'+', u'+', WCH_NONE}},
    {VK_SUBTRACT, 0, {u'-', u'-', WCH_NONE}},
    {VK_MULTIPLY, 0, {u'*', u'*', WCH_NONE}},
    {VK_DIVIDE, 0, {u'/', u'/', WCH_NONE}},
    {VK_DECIMAL, 0, {u'.', u'.', WCH_NONE}},
    {},
};

// Numeric keypad digits. They come last so that digits are looked up on the
// main keys first.
struct vk_to_wchars1 NUMPAD_KEYS[] = {
    {VK_NUMPAD0, 0, {u'0'}},
    {VK_NUMPAD1, 0, {u'1'}},
    {VK_NUMPAD2, 0, {u'2'}},
    {VK_NUMPAD3, 0, {u'3'}},
    {VK_NUMPAD4, 0, {u'4'}},
    {VK_NUMPAD5, 0, {u'5'}},
    {VK_NUMPAD6, 0, {u'6'}},
    {VK_NUMPAD7, 0, {u'7'}},
    {VK_NUMPAD8, 0, {u'8'}},
    {VK_NUMPAD9, 0, {u'9'}},
    {},
};
