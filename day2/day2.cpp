#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "day2.h"
#include "rock-paper-scissor.h"

int main() {
	return do_day2();
}

int do_day2()
{
	// define hands
	std::vector<char> enemy_hands, my_hands;
	// parse the input file
	std::string current_line_buffer;
	auto file = std::ifstream("input.txt");
	if (file.is_open()) {
		while (std::getline(file, current_line_buffer)) {
			enemy_hands.push_back(current_line_buffer.at(0));
			my_hands.push_back(current_line_buffer.at(2));
		}
	}
	else {
		std::cout << "something went wrong";
		return EXIT_FAILURE;
	};

	int total_score = 0;

	// iterate all hands
	for (int i = 0; i < enemy_hands.size(); i++)
	{
		GameHand enemy_hand = ParseGameHand(enemy_hands.at(i));
		GameHand my_hand = ParseGameHand(my_hands.at(i));
		auto result = GetResultForRound(my_hand, enemy_hand);
		auto score = GetScoreForRound(my_hand, result);
		total_score += score;

		std::cout << i + 1 << " | " << enemy_hands.at(i) << " - " << my_hands.at(i) << " : " << score << std::endl;
	}

	std::cout << "PART I : total score: " << total_score << std::endl;
	
	// Part 2
	std::cout << std::endl << "PART II" << std::endl << std::endl;
	total_score = 0;
	// iterate all hands
	for (int i = 0; i < enemy_hands.size(); i++)
	{
		GameHand enemy_hand = ParseGameHand(enemy_hands.at(i));
		GameResult wanted_result = ParseWantedGameResult(my_hands.at(i));
		auto my_hand = WhatShouldIPlay(enemy_hand, wanted_result);
		auto score = GetScoreForRound(my_hand, wanted_result);
		total_score += score;

		std::cout << i + 1 << " | " << enemy_hands.at(i) << " - " << my_hands.at(i) << " : " << score << std::endl;
	}
	std::cout << "PART II : total score: " << total_score << std::endl;
	
	return EXIT_SUCCESS;
}