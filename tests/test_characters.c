#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "characters.h"
#include "dead_keys.h"
#include "kbd.h"
#include "vk.h"

#define ALT_GR 4
#define SHIFT_ALT_GR 5

static size_t row(uint8_t vk) {
    size_t i = 0;
    while (CHARACTERS[i].vk != vk) {
        assert(CHARACTERS[i].vk);
        i++;
    }
    return i;
}

// The character typed, `WCH_NONE` if none.
static uint16_t typed(uint8_t vk, size_t column) {
    uint16_t wch = CHARACTERS[row(vk)].wch[column];
    return wch == WCH_DEAD ? WCH_NONE : wch;
}

// The accent of the dead key typed with AltGr, given by the row that follows.
static uint16_t dead_key(uint8_t vk) {
    size_t i = row(vk);
    assert(CHARACTERS[i].wch[ALT_GR] == WCH_DEAD);
    assert(CHARACTERS[i + 1].vk == VK__NONE_);
    return CHARACTERS[i + 1].wch[ALT_GR];
}

static void alt_gr_keys(void) {
    static const struct {
        uint8_t vk;
        uint16_t alt_gr;
        uint16_t shift_alt_gr;
    } expected[] = {
            {'4', u'€', u'¤'},
            {'5', u'€', WCH_NONE},
            {'E', u'é', u'É'},
            {'R', u'è', u'È'},
            {'Y', u'ÿ', u'Ÿ'},
            {'U', u'ù', u'Ù'},
            {'I', u'ï', u'Ï'},
            {'O', u'ô', u'Ô'},
            {'P', u'œ', u'Œ'},
            {VK_OEM_4, u'«', u'“'},
            {VK_OEM_6, u'»', u'”'},
            {'A', u'à', u'À'},
            {'S', u'æ', u'Æ'},
            {'D', u'ê', u'Ê'},
            {'F', u'ë', u'Ë'},
            {'H', u'ü', u'Ü'},
            {'J', u'û', u'Û'},
            {'K', u'î', u'Î'},
            {VK_OEM_7, WCH_NONE, u'°'},
            {'Z', u'â', u'Â'},
            {'C', u'ç', u'Ç'},
            {VK_OEM_102, u'|', u'¦'},
    };
    for (size_t i = 0; i < sizeof expected / sizeof expected[0]; i++) {
        assert(typed(expected[i].vk, ALT_GR) == expected[i].alt_gr);
        assert(typed(expected[i].vk, SHIFT_ALT_GR) == expected[i].shift_alt_gr);
    }
}

static void alt_gr_dead_keys(void) {
    assert(dead_key(VK_OEM_3) == GRAVE);
    assert(dead_key('6') == CIRCUMFLEX);
    assert(dead_key(VK_OEM_7) == DIAERESIS);
}

static void other_keys_ignore_alt_gr(void) {
    static const uint8_t vks[] = {'1', 'Q', 'G', 'X', VK_OEM_2, VK_OEM_5};
    for (size_t i = 0; i < sizeof vks / sizeof vks[0]; i++) {
        assert(typed(vks[i], ALT_GR) == typed(vks[i], 0));
        assert(typed(vks[i], SHIFT_ALT_GR) == typed(vks[i], 1));
    }
}

static void caps_lock_also_applies_with_alt_gr(void) {
    for (size_t i = 0; CHARACTERS[i].vk; i++) {
        uint8_t vk = CHARACTERS[i].vk;
        bool letter = vk >= 'A' && vk <= 'Z';
        assert((CHARACTERS[i].attributes == (CAPLOK | CAPLOKALTGR)) == letter);
    }
}

int main(void) {
    alt_gr_keys();
    alt_gr_dead_keys();
    other_keys_ignore_alt_gr();
    caps_lock_also_applies_with_alt_gr();
}
