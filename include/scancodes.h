// Scancode to virtual key tables of a PC keyboard (type 4: 101/102 keys),
// the same as the US layout.

#ifndef SCANCODES_H
#define SCANCODES_H

#include <stdint.h>

#include "kbd.h"

// Virtual keys of the scancodes without prefix, indexed by scancode.
extern uint16_t VSC_TO_VK[0x80];
// Virtual keys of the scancodes prefixed with `E0`.
extern struct vsc_vk VSC_TO_VK_E0[];
// Virtual keys of the scancodes prefixed with `E1`.
extern struct vsc_vk VSC_TO_VK_E1[];

#endif
