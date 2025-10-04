#include <cstdio>
#include <stdio.h>
#include <print>

int main(int argc, char **argv) {
	std::println ("arg count: {}", argc);
	for (size_t i = 0; i < static_cast<size_t>(argc); i++) {
		std::println("args: {}", argv[i]); 
	}
	return 0;
}
