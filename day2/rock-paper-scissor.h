//
// Created by dev on 10/24/2023.
//

#ifndef AOC_CPP_ROCK_PAPER_SCISSOR_H
#define AOC_CPP_ROCK_PAPER_SCISSOR_H

enum GameHand {
	Rock = 1,
	Paper = 2,
	Scissors = 3,
	None = 0,
};
GameHand ParseGameHand(char x);

enum GameResult {
	Win = 6,
	Draw = 3,
	Loss = 0,
};

GameResult GetResultForRound(GameHand my_hand, GameHand enemy_hand);
int GetScoreForRound(GameHand my_hand, GameResult round_result);

// part 2
GameHand WhatShouldIPlay(GameHand enemy_hand, GameResult round_result);
GameResult ParseWantedGameResult(char result);

#endif //AOC_CPP_ROCK_PAPER_SCISSOR_H
