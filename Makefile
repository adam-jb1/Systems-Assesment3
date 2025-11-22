TEST_FILES = $(wildcard tests/*.c)
TEST_DEPS  = $(patsubst %.c,%.d,$(TEST_FILES))
TEST_BIN   = $(sort $(patsubst %.c,%.bin,$(TEST_FILES)))
TEST_OBJS  = $(sort $(patsubst %.c,%.o,$(TEST_FILES)))

# Implementation sources (exclude alist.c, since we only use prebuilt alist.o)
IMPL_C   = ipc.c
IMPL_OBJ = $(patsubst %.c,%.o,$(IMPL_C))
IMPL_DEP = $(patsubst %.c,%.d,$(IMPL_C))

CC       = gcc
CFLAGS   = -MP -MD -g -I.
LD       = gcc
LDFLAGS  = -L. -Wl,-z,lazy -no-pie

all: $(TEST_BIN)

%.bin: %.o $(IMPL_OBJ) 
	$(LD) $(LDFLAGS) $(IMPL_OBJ) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(TEST_OBJS) $(TEST_BIN) $(IMPL_OBJ) \
	       $(TEST_DEPS) $(IMPL_DEP)


test: $(TEST_BIN)
	@echo "Running tests..." && \
	echo && \
	$(foreach T, $(TEST_BIN), ./$(T);)

.PHONY: all clean test

# include the dependencies
-include $(TEST_DEP) $(IMPL_DEP)