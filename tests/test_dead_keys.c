#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "dead_keys.h"
#include "kbd.h"

static const struct dead_key *transition(uint16_t accent, uint16_t base) {
    for (size_t i = 0; DEAD_KEYS[i].accent; i++) {
        if (DEAD_KEYS[i].accent == accent && DEAD_KEYS[i].base == base) {
            return &DEAD_KEYS[i];
        }
    }
    return nullptr;
}

// What Windows types for a sequence of dead keys, ended by 0, followed by a
// character; `WCH_NONE` if nothing.
static uint16_t typed_after(const uint16_t *dead_keys, uint16_t base) {
    uint16_t state = dead_keys[0];
    for (const uint16_t *dead_key = &dead_keys[1]; *dead_key; dead_key++) {
        const struct dead_key *chained = transition(state, *dead_key);
        if (!chained) {
            return WCH_NONE;
        }
        assert(chained->flags == DKF_DEAD);
        state = chained->composed;
    }
    const struct dead_key *result = transition(state, base);
    return result ? result->composed : WCH_NONE;
}

static void dead_keys(void) {
    static const struct {
        uint16_t dead_keys[3];
        uint16_t base;
        uint16_t result;
    } expected[] = {
            {{GRAVE}, u'a', u'à'},
            {{GRAVE}, u'e', u'è'},
            {{GRAVE}, u'u', u'ù'},
            {{GRAVE}, u' ', u'`'},
            {{CIRCUMFLEX}, u'a', u'â'},
            {{CIRCUMFLEX}, u'e', u'ê'},
            {{CIRCUMFLEX}, u'c', u'ĉ'},
            {{CIRCUMFLEX}, u'2', u'²'},
            {{CIRCUMFLEX}, u' ', u'^'},
            {{DIAERESIS}, u'e', u'ë'},
            {{DIAERESIS}, u'i', u'ï'},
            {{DIAERESIS}, u'y', u'ÿ'},
            {{DIAERESIS}, u' ', u'"'},
            {{GRAVE, CIRCUMFLEX}, u'a', u'ầ'},
            {{GRAVE, CIRCUMFLEX}, u'e', u'ề'},
            {{GRAVE, CIRCUMFLEX}, u'o', u'ồ'},
    };
    for (size_t i = 0; i < sizeof expected / sizeof expected[0]; i++) {
        assert(typed_after(expected[i].dead_keys, expected[i].base) ==
               expected[i].result);
    }
}

int main(void) {
    dead_keys();
}
