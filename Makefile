# =============================================================
#  iImaginate build
#
#  make            -> debug build  (warnings + AddressSanitizer)
#  make run        -> debug build, then launch it in debug mode
#  make release    -> optimized build, no sanitizers
#  make clean      -> delete all build output
#
#  Output binary:  bin/iImaginate
#  Object files:   build/**  (mirrors the src/ tree, git-ignored)
# =============================================================

# ---- Tools & flags ------------------------------------------

CC      := gcc

# Flags used when COMPILING each .c file into a .o
#   -std=c11          use the C11 language standard
#   -Wall -Wextra     turn on the useful warning sets
#   -Wshadow          warn when a local variable hides another
#   -g                embed debug info (for gdb / sanitizers)
#   -Og               optimize but keep debugging sane
#   -MMD -MP          emit .d files so header edits trigger rebuilds
CFLAGS  := -std=c11 -Wall -Wextra -Wshadow -g -Og -MMD -MP

# Flags used only for the LINK step
LDFLAGS :=

# Libraries to link against (X11)
LDLIBS  := -lX11

# AddressSanitizer + UndefinedBehaviorSanitizer: catches buffer
# overruns, use-after-free, bad shifts, etc. at runtime. Applied
# to both compile and link for the default (debug) build.
SAN     := -fsanitize=address,undefined

# ---- Files ------------------------------------------------

SRC := $(shell find src -name '*.c')       # every source file
OBJ := $(SRC:src/%.c=build/%.o)            # src/a/b.c -> build/a/b.o
DEP := $(OBJ:.o=.d)                         # the generated .d files
BIN := bin/iImaginate

# ---- Default target: debug build --------------------------

.PHONY: all
all: CFLAGS  += $(SAN)
all: LDFLAGS += $(SAN)
all: $(BIN)

# ---- Release target: optimized, no sanitizers ------------

.PHONY: release
release: CFLAGS := -std=c11 -Wall -Wextra -Wshadow -O2 -DNDEBUG
release: clean $(BIN)

# ---- Link step: combine all .o into the binary -----------
#   $@  = the target        (bin/iImaginate)
#   $^  = all prerequisites  (every .o file)

$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# ---- Compile step: one rule for every .c -> .o -----------
#   $<  = the first prerequisite  (the .c file)
#   $@  = the target              (the .o file)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ---- Convenience: build then run ------------------------

.PHONY: run
run: all
	./$(BIN) debug

# ---- Housekeeping --------------------------------------

.PHONY: clean
clean:
	rm -rf build $(BIN)

# Pull in the auto-generated header dependencies (if present).
# The leading '-' means "don't error if the files don't exist yet".
-include $(DEP)
