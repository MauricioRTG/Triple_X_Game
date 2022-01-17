#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	//Print welcome messages to the terminal
	std::cout << "\n\nYou are an astronaut breaking into an level " << Difficulty << " abandon space station door";
	std::cout << "\nYou need to enter the correct code to enter...\n\n";
	std::cout << "     _..._     \n";
	std::cout << "   .'     '.      _ \n";
	std::cout << "   /    .-""-\\   _/ \\ \n";
	std::cout << ".-|   /:.   |  |   |\n";
	std::cout << "|  \\  |:.   /.-'-./\n";
	std::cout << "| .-'-;:__.'    =/\n";
   
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	//Declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	//Print sum and product to the terminal
	std::cout << " + There are 3 numbers in the code\n";
	std::cout << " + The codes add-up to: " << CodeSum << "\n";
	std::cout << " + The codes multiply to give: " << CodeProduct << "\n";

	//Store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;


	std::cout << "You entered: " << GuessA << GuessB << GuessC << "\n";

	int GuessProduct = GuessA * GuessB * GuessC;
	int GuessSum = GuessA + GuessB + GuessC;

	//Check if the player's guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "Correct code! You have entered the abandon space station. Keep going!!" << "\n";
		return true;
	}
	else
	{
		std::cout << "Incorrect code! The alarms sound and the aliens are going after you!! Try Again!" << "\n";
		return false;
	}
}

int main()
{
	srand(time(NULL)); //Creates a new random sequence based on the time of the day

	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;
	while (LevelDifficulty <= MaxDifficulty) //Loop game until all levels are completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();  // Clears any errors
		std::cin.ignore(); // Discard the buffers

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << "\n\n****Great Work astronout You have successfully enter the abandon space station without dying****\n";
	
	return 0;
}