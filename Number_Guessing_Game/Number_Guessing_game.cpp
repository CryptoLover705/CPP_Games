#include <iostream>
#include<stdio.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    srand(time(0));
    int number = rand() % 10;
    int nguess = 3, guess = 0, x = 0;

    int guessedNums[3] = {};

    cout << "I have a number from 1 to 10." << endl;
    //sleep(1);
    cout << "You have 3 tries to guess it." << endl;
    //sleep(1);
    while (nguess != 0 && guess != number)
    {
        cout << "Guess a number: " << endl;
        cin >> guess;

        nguess--;
        guessedNums[x] = guess;
        x++;

        if (guess > number)
        {
            cout << "My number is lower." << endl;
            //sleep(1);
        }
        else if (guess < number)
        {
            cout << "My number is higher." << endl;
            //sleep(1);
        }
    }



    if (nguess == 0 && guess != number)
    {
        cout << "My number was " << number << endl;
        cout << "You lost." << endl;
    }
    else if (guess == number)
    {
        cout << "You won!";
    }
    else
        cout << "You somehow have broke the programm.";
}