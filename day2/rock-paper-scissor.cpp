#include "rock-paper-scissor.h"

GameHand ParseGameHand(char hand)
{
	if (hand == 'X' || hand == 'A') {
		return GameHand::Rock;
	}
	else if (hand == 'Y' || hand == 'B') {
		return GameHand::Paper;
	}
	else if (hand == 'Z' || hand == 'C') {
		return GameHand::Scissors;
	}
	else return GameHand::None;
}

// part 2
GameResult ParseWantedGameResult(char result)
{
	if (result == 'X') {
		return GameResult::Loss;
	}
	else if (result == 'Y') {
		return GameResult::Draw;
	}
	else if (result == 'Z') {
		return GameResult::Win;
	}
	else return GameResult::Draw;
}

GameResult GetResultForRound(GameHand my_hand, GameHand enemy_hand) {
	if (my_hand == enemy_hand) {
		return GameResult::Draw;
	}

	int result = (my_hand - enemy_hand + 3) % 3;
	if (result == 1) {
		return GameResult::Win;
	}
	else {
		return GameResult::Loss;
	}
}

int GetScoreForRound(GameHand my_hand, GameResult round_result)
{
	switch (round_result) {
	case Win:
		return int(my_hand) + int(Win);
	case Loss:
		return int(my_hand) + int(Loss);
	case Draw:
		return int(my_hand) + int(Draw);
	default:
		return 0;
	}
}

GameHand WhatShouldIPlay(GameHand enemy_hand, GameResult round_result)
{
	// Based on the wanted round result, we can determine what hand to play against the enemy hand.
	if (round_result == GameResult::Win) {
		if (enemy_hand == GameHand::Rock) {
			return GameHand::Paper;
		}
		else if (enemy_hand == GameHand::Paper) {
			return GameHand::Scissors;
		}
		else if (enemy_hand == GameHand::Scissors) {
			return GameHand::Rock;
		}
	}
	else if (round_result == GameResult::Loss) {
		if (enemy_hand == GameHand::Rock) {
			return GameHand::Scissors;
		}
		else if (enemy_hand == GameHand::Paper) {
			return GameHand::Rock;
		}
		else if (enemy_hand == GameHand::Scissors) {
			return GameHand::Paper;
		}
	}
	else if (round_result == GameResult::Draw) {
		return enemy_hand;
	}
	return GameHand::None;
}
