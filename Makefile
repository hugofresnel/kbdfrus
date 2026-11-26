VERSION ?= 0.0.0

CC := x86_64-w64-mingw32-gcc
CFLAGS := -std=c23 -O2 -Wall -Wextra -Iinclude -fno-zero-initialized-in-bss
LDFLAGS := -shared -nostdlib -Wl,--entry=0,--subsystem=native
ACTIONS_CFLAGS := -std=c23 -O2 -Wall -Wextra
ACTIONS_LDFLAGS := -shared -nostdlib -Wl,--entry=0
TEST_CFLAGS := -std=c23 -Wall -Wextra -Iinclude

SRCS := $(shell find src -name '*.c')
HEADERS := $(shell find include -name '*.h')
TEST_SRCS := $(shell find tests -name '*.c')
TABLES := $(filter-out src/kbdfrus.c,$(SRCS))
TESTS := $(patsubst %.c,build/%,$(TEST_SRCS))

PHONY += build
build: msi

PHONY += dll
dll: build/kbdfrus.dll

PHONY += msi
msi: build/kbdfrus.dll build/actions.dll
	wixl --arch x64 \
		-D Version=$(VERSION) \
		-D Dll=build/kbdfrus.dll \
		-D Actions=build/actions.dll \
		-o build/kbdfrus-$(VERSION).msi \
		installer/kbdfrus.wxs

build/kbdfrus.dll: $(SRCS) $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SRCS)

build/actions.dll: installer/actions.c
	@mkdir -p $(@D)
	$(CC) $(ACTIONS_CFLAGS) $(ACTIONS_LDFLAGS) -o $@ $< -lkernel32 -lmsi

PHONY += test
test: $(TESTS)
	for test in $^; do $$test || exit 1; done

build/tests/%: tests/%.c $(HEADERS) $(TABLES)
	@mkdir -p $(@D)
	gcc $(TEST_CFLAGS) -o $@ $< $(TABLES)

PHONY += clean
clean:
	rm -rf build

.PHONY: $(PHONY)
