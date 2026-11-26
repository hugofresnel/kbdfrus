// Dead keys: the sequences of the X11 Compose table that start with the dead
// keys of the layout.
//
// Windows identifies a dead key by a character, its accent, which it types
// when the following key does not combine with it. A dead key followed by
// another dead key leads to a chained state, identified by a character of
// the Private Use Area.

#ifndef DEAD_KEYS_H
#define DEAD_KEYS_H

#include "kbd.h"

#define GRAVE u'`'
#define CIRCUMFLEX u'^'
#define DIAERESIS u'¨'

extern struct dead_key DEAD_KEYS[];

#endif
