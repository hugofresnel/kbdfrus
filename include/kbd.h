// The keyboard layout tables read by Windows, as declared in `kbd.h` of the
// Windows Driver Kit.

#ifndef KBD_H
#define KBD_H

#include <stdint.h>

// Modifier bits.
#define KBDSHIFT 0x01
#define KBDCTRL 0x02
#define KBDALT 0x04
// Modifier combination that types nothing.
#define SHFT_INVALID 0x0F

// Character key attributes.
#define CAPLOK 0x01
#define CAPLOKALTGR 0x04

// Special characters of the character tables.
#define WCH_NONE 0xF000
#define WCH_DEAD 0xF001

// The result of a dead key transition is itself a dead key.
#define DKF_DEAD 0x0001

// Scancode flags.
#define KBDEXT 0x0100
#define KBDMULTIVK 0x0200
#define KBDSPECIAL 0x0400
#define KBDNUMPAD 0x0800

// Layout flags and keyboard type.
#define KLLF_ALTGR 0x0001
#define KBD_VERSION 1
#define KEYBOARD_TYPE_GENERIC_101 4

// `VK_TO_BIT`: the modifier bit of a modifier key.
struct vk_to_bit {
    uint8_t vk;
    uint8_t mod_bits;
};

// `MODIFIERS`: the character table column of each modifier combination.
struct modifiers {
    const struct vk_to_bit *vk_to_bit;
    uint16_t max_mod_bits;
    uint8_t mod_number[8];
};

// `VK_TO_WCHARS<N>`: what a virtual key types in each of the `N` columns.
// Characters are Windows characters (`WCHAR`), such as `u'é'`.
struct vk_to_wchars1 {
    uint8_t vk;
    uint8_t attributes;
    uint16_t wch[1];
};

struct vk_to_wchars3 {
    uint8_t vk;
    uint8_t attributes;
    uint16_t wch[3];
};

struct vk_to_wchars6 {
    uint8_t vk;
    uint8_t attributes;
    uint16_t wch[6];
};

// `VK_TO_WCHAR_TABLE`: a character table, its number of columns and the size
// of its rows.
struct vk_to_wchar_table {
    const void *vk_to_wchars;
    uint8_t modifications;
    uint8_t size;
};

// `DEADKEY`: typing `base` after the dead key `accent` types `composed`.
// `base` and `accent` are the two halves of `dwBoth`, x86-64 being
// little-endian.
struct dead_key {
    uint16_t base;
    uint16_t accent;
    uint16_t composed;
    uint16_t flags;
};

// `VSC_LPWSTR`: the name of the key with a scancode, a NUL-terminated wide
// string.
struct vsc_lpwstr {
    uint8_t vsc;
    const uint16_t *name;
};

// `VSC_VK`: the virtual key of a prefixed scancode.
struct vsc_vk {
    uint8_t vsc;
    uint16_t vk;
};

// `KBDTABLES`: the layout, as returned by `KbdLayerDescriptor`.
struct kbd_tables {
    const struct modifiers *char_modifiers;
    const struct vk_to_wchar_table *vk_to_wchar_table;
    const struct dead_key *dead_keys;
    const struct vsc_lpwstr *key_names;
    const struct vsc_lpwstr *key_names_ext;
    const uint16_t *const *key_names_dead;
    const uint16_t *vsc_to_vk;
    uint8_t max_vsc_to_vk;
    const struct vsc_vk *vsc_to_vk_e0;
    const struct vsc_vk *vsc_to_vk_e1;
    uint32_t locale_flags;
    uint8_t lg_max;
    uint8_t cb_lg_entry;
    const void *ligatures;
    uint32_t kbd_type;
    uint32_t kbd_sub_type;
};

#endif
