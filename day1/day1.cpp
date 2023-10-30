//
// Created by Gard Cappelen on 29/08/2023.
//

#include "day1.h"

#include <vector>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

typedef int calories;

struct Elf {
    std::vector<calories> meals;
    [[nodiscard]] inline int total_cals() const { return std::reduce(meals.begin(), meals.end()); };
};

std::vector<Elf> parse_elves() {
    std::ifstream file("cals.txt");

    if (!file.is_open()) {
        throw std::runtime_error("File cannot be opened.");
    }

    std::string currentLine;
    std::vector<std::string> lines;
    while (std::getline(file, currentLine)) {
        lines.push_back(currentLine);
    }

    std::vector<Elf> elves;
    std::vector<calories> currentElfCalories;

    // Declare lambda function to handle the common code
    auto addElfFromBuffer = [&]() {
        if (!currentElfCalories.empty()) {
            Elf e;
            e.meals = currentElfCalories;
            elves.push_back(e);
            currentElfCalories.clear();
        }
    };

    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].empty()) {
            // Line break, the currently parsed elf is done, add it to the vector.
            addElfFromBuffer();
        } else {
            // Add the current line (meal) to the currently parsed elf's calories.
            currentElfCalories.push_back(std::stoi(lines[i]));
            // if last line, add the elf to the vector
            if (i == lines.size() - 1) {
                addElfFromBuffer();
            }
        }
    }

    return elves;
}

void do_day1() {
    auto elves = parse_elves();
    // iterate over the elves, print all meals for an elf along with the elf index number, and the total calories for the elf.
    for (size_t i = 0; i < elves.size(); ++i) {
        std::cout << "Elf " << i + 1 << " has: ";
        for (auto &meal: elves[i].meals) {
            std::cout << meal << " ";
        }
        std::cout << " calories for a total of " << elves[i].total_cals() << " calories." << std::endl;
    }

    // find the elf with the most calories and its index, and print it.
    auto elf = std::max_element(elves.begin(), elves.end(), [](Elf &a, Elf &b) {
        return a.total_cals() < b.total_cals();
    });
    std::cout << "Elf with most cals: " << elf->total_cals() << " is at index " << elf - elves.begin() << std::endl;

    // PART II
    std::cout << "PART II" << "\n\n";

    // Sort in descending order based on total_cals
    std::sort(elves.begin(), elves.end(), [](const Elf &a, const Elf &b) {
        return a.total_cals() > b.total_cals();
    });

    int combinedTotal = std::accumulate(elves.begin(), elves.begin() + std::min(3, static_cast<int>(elves.size())), 0,
                                        [](int sum, const Elf& e) { return sum + e.total_cals(); });

    std::cout << "Combined total calories of top 3 elves: " << combinedTotal << std::endl;
}
