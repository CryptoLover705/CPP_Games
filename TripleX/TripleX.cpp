#include <iostream>
#include <ctime>

void WelcomeMsg()
{
    std::cout << " Welcome to TripleX\n ";
    std::cout << " Version *1.0.1* \n\n";
}

void PrintIntroduction(int Difficulty)
{
    // Prints welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room... \nEnter the correct code to continue! \n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Random code possibility depending on the level difficulty
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+ HINTS\n";
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "+ The code must be imputed like 0 0 0 (Please note the spaces) ";
    std::cout << "\n+ The codes will equal to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store Player's guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    // This line is optional >> It just tells the user what numbers they have entered 
    // std::cout << "You have entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check's if the players guess is correct 
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going!! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** Great work agent! You found all the files! Now get out of there! ***";
        return false;
    }
}

int main()
{
    WelcomeMsg();
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;

    while(LevelDifficulty <= MaxDifficulty) // Loop the game until all the levels are complete
    {
    bool bLevelComplete = PlayGame(LevelDifficulty);    
    std::cin.clear(); // Clears any errors
    std::cin.ignore(); // Discards the buffer 

    if (bLevelComplete)
    {
        // Increase the level difficulty
        ++LevelDifficulty;
    }
    
    }
    std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
    return 0;
}
