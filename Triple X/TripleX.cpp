#include <iostream> // Includes IOstream header
#include <ctime>


void PrintIntroduction(int Difficulty){
    std::cout << "\nYou are a budding lockpicker...\n"; // Print greeting to terminal
    std::cout << "You a picking a level " << Difficulty << " lock.\n";
    std::cout << "Enter the correct code to crack each lock.\n\n";
}

bool PlayGame(int Diff){
    
    PrintIntroduction(Diff);

    int CodeA = rand() % Diff + Diff;
    int CodeB = rand() % Diff + Diff;
    int CodeC = rand() % Diff + Diff;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProd = CodeA * CodeB * CodeC;

    std::cout << std::endl << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The sum of the codes is: " << CodeSum << std::endl;
    std::cout << "+ The product of the code is: " << CodeProd << "\n\n";

    //* Store Players Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProd == CodeProd){
        std::cout << "\n" << "*** Congrats! You have managed to pick the lock and are moving on to the next level. ***\n";
        return true;
    }
    else{
        std::cout << "\n" << "Unfortunately, you were wrong and have been denied access. Try Again!\n";
        return false;
    }
}

int main(){
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //* Clears input stream of errors.
        std::cin.ignore(); //* Discards the buffer.

        if (bLevelComplete){
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n*** Congratulations, you have become a master lockpicker. ***\n";

    return 0;
}