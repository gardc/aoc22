#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

struct State {
	int sum_of_priorities = 0;
};

int char_to_priority(char ch) {
	if ('a' <= ch && ch <= 'z') {
		return ch - 'a' + 1;
	}
	else if ('A' <= ch && ch <= 'Z') {
		return ch - 'A' + 27;
	}
	else {
		// out of range
		std::cout << "character " << ch << " was out of range" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void handle_line_read(State &s, const std::string &rucksack_line) {
	const int len = rucksack_line.length();
	if (len % 2 != 0) {
		std::cout << "^^^ line length is not even! that's not supposed to happen" << std::endl;
		exit(EXIT_FAILURE);
	}
	const int half = len / 2;
	const auto first_half = rucksack_line.substr(0, half);
	const auto second_half = rucksack_line.substr(half, half);
	std::cout << "first half: " << first_half << " | second half: " << second_half << std::endl;

	// count chars
	std::map<char, int> first_half_chars;
	std::map<char, int> second_half_chars;
	for (const auto& c : first_half) {
		first_half_chars[c]++;
	}
	for (const auto& c : second_half) {
		second_half_chars[c]++;
	}

	// compare
	std::set<char> intersecting_chars;
	for (const auto& pair : first_half_chars) {
		char key = pair.first;
		if (second_half_chars.find(key) != second_half_chars.end()) {
			intersecting_chars.insert(key);
		}
	}

	// add to the state sum
	for (const auto& ch : intersecting_chars) {
		s.sum_of_priorities += char_to_priority(ch);
	}
}

// Currently it iterates every line synchronously. It could be made asynchronous using a M:N thread pool for peak performance.
// Obviously it's not necessary for this problem, but it would be the solution for making this optimal.
// 
// Looks like ctpl::ThreadPool is a good library for this, but also potentially just using Boost.Asio would 
// work just fine and avoid depending on some random lib.
int main() {
	auto state = State();

	// read file
	std::string line;
#ifdef _DEBUG
	auto file = std::ifstream("test-input.txt");
#else
	auto file = std::ifstream("input.txt");
#endif
	if (file.is_open()) {
		while (std::getline(file, line)) {
			handle_line_read(state, line);
		}
	}
	else {
		std::cout << "could not open file for reading";
		return EXIT_FAILURE;
	}

	std::cout << "sum of priorities: " << state.sum_of_priorities << std::endl;

	return EXIT_SUCCESS;
}
