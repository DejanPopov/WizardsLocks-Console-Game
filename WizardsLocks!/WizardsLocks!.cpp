#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
	//Print welcome messages
	std::cout << "\n\nYou are a rouge who escaped prison cell from Amber castle while trying to steal treasure.\n";
	std::cout << "The prison has magically locked doors created by wizard.\n";
	std::cout << "You have no choice,pick locks are not good here...\n";
	std::cout << "\n\nYou are trying to unlock magic door level " << Difficulty ;
}
bool PlayGame(int Diffuculty) 
{
	PrintIntroduction(Diffuculty);

	//Declare 3 number code
	const int CodeA = rand() % Diffuculty + Diffuculty;
	const int CodeB = rand() % Diffuculty + Diffuculty;
	const int CodeC = rand() % Diffuculty + Diffuculty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	//Print sum and multiple to terminal
	std::cout << std::endl;
	std::cout << "There are 3 numbers in the magic lock\n";
	std::cout << "The numbers add up to: " << CodeSum << std::endl;
	std::cout << "The numbers when mutiplayed give: " << CodeProduct << std::endl;

	//Player guesses
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\nYou managed to escape";
	}
	else
	{
		std::cout << "\nYou have enter wrong numbers!Let's try this again...";
		return false;
	}
}


int main()
{
	srand(time(NULL)); //Create new random sequance based on time in the day

	int LevelDifficulty = 1;
	int const MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) // Loop game until it is completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors from input
		std::cin.ignore(); // Discards the buffer

		if  (bLevelComplete)
		{
			++LevelDifficulty; //Increase level difficulty
		}
	}
	
	std::cout << "You managed to escape Amber castle with nothing but your life...damned be the treasure!\n";
	return 0;
} 