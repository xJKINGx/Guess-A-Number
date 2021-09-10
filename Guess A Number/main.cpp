#include <iostream>
#include <string>

int getRdmNumber(std::string difficulty);
int gameFunc(std::string difficultySeperator);
std::string difficultySelection{};
int highScore = 0;

int main() {
	std::srand(time(0));
	bool game_loop = true;
	while (game_loop) {
		std::cout << "-----GUESS A NUMBER-----" << std::endl;
		std::cout << "Choose a difficulty: \n1. Easy (1-5)\n2. Medium (1-10)\n3. Hard (1-30)" << std::endl;
		std::cout << "Select between 1 and 3: ";
		
		getline(std::cin, difficultySelection);

		
		int guessCount = gameFunc(difficultySelection);
		if (highScore == 0) {
			highScore = guessCount;
		}
		else if (highScore > guessCount) {
			highScore = guessCount;
		}
		
		std::cout << "Highscore: " << highScore << " guesses." << std::endl;
		std::cout << "The game is over, would you like to play again? (Yes/No): ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string exitQuestion{};
		getline(std::cin, exitQuestion);
		if (exitQuestion == "Yes") {
			continue;
		}
		else if (exitQuestion == "No") {
			exit(0);
		}
	}
}

int getRdmNumber(std::string difficulty) {
	int value{};
	if (difficulty == "1") {
		value = std::rand() % 5 + 1;
	}
	else if (difficulty == "2") {
		value = std::rand() % 10 + 1;
	}
	else if (difficulty == "3") {
		value = std::rand() % 30 + 1;
	}
	
	return value;
}

int gameFunc(std::string difficultySeperator) {
	int currentRdmNumber = getRdmNumber(difficultySelection);
	int guessNumber{};
	bool mechanics_loop = true;
	while (mechanics_loop) {
		std::cout << "Guess a number between 1 and ";
		if (difficultySeperator == "1") {
			std::cout << "5: " << std::endl;
		}
		else if (difficultySeperator == "2") {
			std::cout << "10: " << std::endl;
		}
		else if (difficultySeperator == "3") {
			std::cout << "30: " << std::endl;
		}

		int selectedValue{};
		std::cin >> selectedValue;
		if (selectedValue == currentRdmNumber) {
			std::cout << "YOU WON THE GAME!" << std::endl;
			mechanics_loop = false;
		}
		else if (selectedValue < currentRdmNumber) {
			std::cout << "Your guess was lower than the value" << std::endl;
			guessNumber++;
		}
		else if (selectedValue > currentRdmNumber) {
			std::cout << "Your guess was higher than the value" << std::endl;
			guessNumber++;
		}
		std::cout << "Guesses: " << guessNumber << std::endl;
	}

	return guessNumber;
}