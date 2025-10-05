#include <cstdio>
#include <stdio.h>
#include <print>

class A {
public:
	int x;
};

class B : public A {
public:
	float y;
};

int main(int argc, char **argv) {
	B b;
	b.y = 17.;
	b.x = 3;
	std::println("B fields: {}, {}", b.y, b.x);
	std::println("arg count: {}", argc);
	for (size_t i = 0; i < static_cast<size_t>(argc); i++) {
		std::println("args: {}", argv[i]);
	}
	return 0;
}
