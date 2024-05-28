#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand((unsigned int)time(NULL)); // Seed the random number generator with the current time

    int number = (rand() % 100) + 1; // Generate a random number between 1 and 100

    int guess = 0;

    do
    {
        cout << "Guess a Number (1-100) = ";
        cin >> guess;
        if (guess > number)
        {
            cout << "Too high! Try again: " << endl;
        }
        else if (guess < number)
        {
            cout << "Too low! Try again: " << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number.\n";
        }
    } while (guess != number);
}