#include <cstddef>
#include <print>
#include <stdexcept>
#include <cstring>

#include "array_list.hpp"
#include "linked_list.hpp"

int main(int argc, char** argv) {
	// auto a = ArrayList<int>();
	// a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);
	// a.push_front(4);
	// a.pop_front();
	// a.pop_back();

	auto l = LinkedList<int>();
	l.push_back(1);
	l.push_back(2);
	l.push_front(0);
	l.push_back(3);
	l.insert(2, 5);

	// try {
	// 	// for (size_t i = 0; i < a.length(); i++) {
	// 	// 	std::println("{}", a.get(i));
	// 	// }
	// 	// a.get(17);
	// } catch (const std::out_of_range& e) {
	// 	std::println("hendle exception {}", e.what());
	// }

	std::println("Lenght: {}", l.length());
	std::println("First: {}", l.get_first());
	std::println("Last: {}", l.get_last());
	std::println("Get: {}", l.get(2));

	std::println("arg count: {}", argc);
	for (size_t i = 0; i < static_cast<size_t>(argc); i++) {
		std::println("args: {}", argv[i]);
	}

	return 0;
}
