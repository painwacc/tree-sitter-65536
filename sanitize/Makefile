# https://github.com/tlaplus-community/tree-sitter-tlaplus/blob/7ba226cf85280c7917d082940022006e6a3b7b6f/test/sanitize/build-sanitized.sh

CFLAGS ?= -fsanitize=address,undefined -fno-omit-frame-pointer -g
CC=clang
CXX=clang++

all: runner

tree-sitter/libtree-sitter.a:
	make -C tree-sitter CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" libtree-sitter.a

parser.o: ../src/parser.c
	$(CC) $(CFLAGS) $< -o $@ -c -I tree-sitter/lib/include/

runner: runner.cc parser.o tree-sitter/libtree-sitter.a
	$(CXX) $(CFLAGS) $^ -o $@ -I tree-sitter/lib/include/

.PHONY: clean
clean:
	make -C tree-sitter clean
	rm -rf parser.o runner

