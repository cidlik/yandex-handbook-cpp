MAKEFLAGS += --always-make
OPTIMIZATION ?= -O0

%.cpp:
	clang++ --std=c++20 $(OPTIMIZATION) -fsanitize=address,undefined -Wall -Wextra -Werror $@ -o $(subst .cpp,,$@)
