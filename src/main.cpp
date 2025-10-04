#include <stdio.h>

int main(int argc, char **argv) {
	for (size_t i = 0; i < argc; i++) {
		printf("args: %s\n", argv[i]);
}
	return 0;
}
