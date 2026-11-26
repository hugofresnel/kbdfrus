// Scancode to virtual key tables of a PC keyboard (type 4: 101/102 keys),
// the same as the US layout.

#include "scancodes.h"

#include <stdint.h>

#include "kbd.h"
#include "vk.h"

// Virtual keys of the scancodes without prefix, indexed by scancode.
// `KBDNUMPAD | KBDSPECIAL`: numeric keypad keys that type digits with Num Lock
// and move without it.
uint16_t VSC_TO_VK[] = {
    VK__NONE_,                          // 0x00
    VK_ESCAPE,                          // 0x01
    '1',                                // 0x02
    '2',                                // 0x03
    '3',                                // 0x04
    '4',                                // 0x05
    '5',                                // 0x06
    '6',                                // 0x07
    '7',                                // 0x08
    '8',                                // 0x09
    '9',                                // 0x0A
    '0',                                // 0x0B
    VK_OEM_MINUS,                       // 0x0C
    VK_OEM_PLUS,                        // 0x0D
    VK_BACK,                            // 0x0E
    VK_TAB,                             // 0x0F
    'Q',                                // 0x10
    'W',                                // 0x11
    'E',                                // 0x12
    'R',                                // 0x13
    'T',                                // 0x14
    'Y',                                // 0x15
    'U',                                // 0x16
    'I',                                // 0x17
    'O',                                // 0x18
    'P',                                // 0x19
    VK_OEM_4,                           // 0x1A
    VK_OEM_6,                           // 0x1B
    VK_RETURN,                          // 0x1C
    VK_LCONTROL,                        // 0x1D
    'A',                                // 0x1E
    'S',                                // 0x1F
    'D',                                // 0x20
    'F',                                // 0x21
    'G',                                // 0x22
    'H',                                // 0x23
    'J',                                // 0x24
    'K',                                // 0x25
    'L',                                // 0x26
    VK_OEM_1,                           // 0x27
    VK_OEM_7,                           // 0x28
    VK_OEM_3,                           // 0x29
    VK_LSHIFT,                          // 0x2A
    VK_OEM_5,                           // 0x2B
    'Z',                                // 0x2C
    'X',                                // 0x2D
    'C',                                // 0x2E
    'V',                                // 0x2F
    'B',                                // 0x30
    'N',                                // 0x31
    'M',                                // 0x32
    VK_OEM_COMMA,                       // 0x33
    VK_OEM_PERIOD,                      // 0x34
    VK_OEM_2,                           // 0x35
    VK_RSHIFT | KBDEXT,                 // 0x36
    VK_MULTIPLY | KBDMULTIVK,           // 0x37
    VK_LMENU,                           // 0x38
    VK_SPACE,                           // 0x39
    VK_CAPITAL,                         // 0x3A
    VK_F1,                              // 0x3B
    VK_F2,                              // 0x3C
    VK_F3,                              // 0x3D
    VK_F4,                              // 0x3E
    VK_F5,                              // 0x3F
    VK_F6,                              // 0x40
    VK_F7,                              // 0x41
    VK_F8,                              // 0x42
    VK_F9,                              // 0x43
    VK_F10,                             // 0x44
    VK_NUMLOCK | KBDEXT | KBDMULTIVK,   // 0x45
    VK_SCROLL | KBDMULTIVK,             // 0x46
    VK_HOME | KBDNUMPAD | KBDSPECIAL,   // 0x47
    VK_UP | KBDNUMPAD | KBDSPECIAL,     // 0x48
    VK_PRIOR | KBDNUMPAD | KBDSPECIAL,  // 0x49
    VK_SUBTRACT,                        // 0x4A
    VK_LEFT | KBDNUMPAD | KBDSPECIAL,   // 0x4B
    VK_CLEAR | KBDNUMPAD | KBDSPECIAL,  // 0x4C
    VK_RIGHT | KBDNUMPAD | KBDSPECIAL,  // 0x4D
    VK_ADD,                             // 0x4E
    VK_END | KBDNUMPAD | KBDSPECIAL,    // 0x4F
    VK_DOWN | KBDNUMPAD | KBDSPECIAL,   // 0x50
    VK_NEXT | KBDNUMPAD | KBDSPECIAL,   // 0x51
    VK_INSERT | KBDNUMPAD | KBDSPECIAL, // 0x52
    VK_DELETE | KBDNUMPAD | KBDSPECIAL, // 0x53
    VK_SNAPSHOT,                        // 0x54
    VK__NONE_,                          // 0x55
    VK_OEM_102,                         // 0x56
    VK_F11,                             // 0x57
    VK_F12,                             // 0x58
    VK_CLEAR,                           // 0x59
    VK_OEM_WSCTRL,                      // 0x5A
    VK_OEM_FINISH,                      // 0x5B
    VK_OEM_JUMP,                        // 0x5C
    VK_EREOF,                           // 0x5D
    VK_OEM_BACKTAB,                     // 0x5E
    VK_OEM_AUTO,                        // 0x5F
    VK__NONE_,                          // 0x60
    VK__NONE_,                          // 0x61
    VK_ZOOM,                            // 0x62
    VK_HELP,                            // 0x63
    VK_F13,                             // 0x64
    VK_F14,                             // 0x65
    VK_F15,                             // 0x66
    VK_F16,                             // 0x67
    VK_F17,                             // 0x68
    VK_F18,                             // 0x69
    VK_F19,                             // 0x6A
    VK_F20,                             // 0x6B
    VK_F21,                             // 0x6C
    VK_F22,                             // 0x6D
    VK_F23,                             // 0x6E
    VK_OEM_PA3,                         // 0x6F
    VK__NONE_,                          // 0x70
    VK_OEM_RESET,                       // 0x71
    VK__NONE_,                          // 0x72
    VK_ABNT_C1,                         // 0x73
    VK__NONE_,                          // 0x74
    VK__NONE_,                          // 0x75
    VK_F24,                             // 0x76
    VK__NONE_,                          // 0x77
    VK__NONE_,                          // 0x78
    VK__NONE_,                          // 0x79
    VK__NONE_,                          // 0x7A
    VK_OEM_PA1,                         // 0x7B
    VK_TAB,                             // 0x7C
    VK__NONE_,                          // 0x7D
    VK_ABNT_C2,                         // 0x7E
    VK_OEM_PA2,                         // 0x7F
};

struct vsc_vk VSC_TO_VK_E0[] = {
    {0x10, VK_MEDIA_PREV_TRACK | KBDEXT},
    {0x19, VK_MEDIA_NEXT_TRACK | KBDEXT},
    {0x1D, VK_RCONTROL | KBDEXT},
    {0x20, VK_VOLUME_MUTE | KBDEXT},
    {0x21, VK_LAUNCH_APP2 | KBDEXT},
    {0x22, VK_MEDIA_PLAY_PAUSE | KBDEXT},
    {0x24, VK_MEDIA_STOP | KBDEXT},
    {0x2E, VK_VOLUME_DOWN | KBDEXT},
    {0x30, VK_VOLUME_UP | KBDEXT},
    {0x32, VK_BROWSER_HOME | KBDEXT},
    {0x35, VK_DIVIDE | KBDEXT},
    {0x37, VK_SNAPSHOT | KBDEXT},
    {0x38, VK_RMENU | KBDEXT},
    {0x47, VK_HOME | KBDEXT},
    {0x48, VK_UP | KBDEXT},
    {0x49, VK_PRIOR | KBDEXT},
    {0x4B, VK_LEFT | KBDEXT},
    {0x4D, VK_RIGHT | KBDEXT},
    {0x4F, VK_END | KBDEXT},
    {0x50, VK_DOWN | KBDEXT},
    {0x51, VK_NEXT | KBDEXT},
    {0x52, VK_INSERT | KBDEXT},
    {0x53, VK_DELETE | KBDEXT},
    {0x5B, VK_LWIN | KBDEXT},
    {0x5C, VK_RWIN | KBDEXT},
    {0x5D, VK_APPS | KBDEXT},
    {0x5F, VK_SLEEP | KBDEXT},
    {0x65, VK_BROWSER_SEARCH | KBDEXT},
    {0x66, VK_BROWSER_FAVORITES | KBDEXT},
    {0x67, VK_BROWSER_REFRESH | KBDEXT},
    {0x68, VK_BROWSER_STOP | KBDEXT},
    {0x69, VK_BROWSER_FORWARD | KBDEXT},
    {0x6A, VK_BROWSER_BACK | KBDEXT},
    {0x6B, VK_LAUNCH_APP1 | KBDEXT},
    {0x6C, VK_LAUNCH_MAIL | KBDEXT},
    {0x6D, VK_LAUNCH_MEDIA_SELECT | KBDEXT},
    {0x1C, VK_RETURN | KBDEXT},
    {0x46, VK_CANCEL | KBDEXT},
    {},
};

struct vsc_vk VSC_TO_VK_E1[] = {
    {0x1D, VK_PAUSE},
    {},
};
