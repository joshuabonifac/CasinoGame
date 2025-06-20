// CasinoGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate a simple casino game

void drawLine(int n, char symbol);
void rules();

int main()
{
    string playerName;
    int amount;
    int bet;
    int guess;
    int dice;
    char choice;

    srand(time(0)); // Seeds the random number generator
    drawLine(60, '_');
    std::cout << "Welcome to the Casino Game!" << endl;
    drawLine(60, '_');
    std::cout << "Enter your name: ";
    getline(cin, playerName);
    std::cout << "Enter your starting amount: $";
    cin >> amount;
    
    do
    {
        system("cls"); // Clears the console screen
        rules();
        std::cout << "Hello, " << playerName << " Your current balance is $" << amount << endl;

        do
        {
            std::cout << playerName << ", enter your money to bet: $";
            cin >> bet;
            if (bet > amount)
                std::cout << "Your betting amount is more than your current balance\n" << "Re-enter Data\n";
        } while (bet > amount);

        do
        {
            std::cout << "Guess your number to be between 1 and 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                std::cout << "Please check the number you entered!! it needs to be between 1 and 10\n" << "Re-enter data\n";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // Holds the randomly generated number between 1 and 10
        if (dice == guess)
        {
            std::cout << "\n\nCongrulations!! You won $." << bet * 10;
            amount = amount + (bet * 10);
        }
        else
        {
            std::cout << "\n\nSorry, you lost $" << bet << "\n";
            amount = amount - bet;
        }
        std::cout << "\nThe winning number was: " << dice << "\n";
        std::cout << "\n" << playerName << ", You have $" << amount << "\n";

        if (amount == 0)
        {
            std::cout << "You have no money to play";
            break;
        }
        std::cout << "\n\n-->Do you want to play again (y/n)?";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
      std::cout << "\n\n\n";
      drawLine(70, '=');
      std::cout << "\n\nThanks for playing. Your current balance is $ " << amount << "\n\n";
      drawLine(70, '=');
      return 0;
 }
 void drawLine(int n, char symbol)
 {
    for (int i = 0; i < n; i++)
        std::cout << symbol;
    std::cout << "\n";
 }
 void rules()
 {
     system("cls");
     std::cout << "\n\n";
     drawLine(80, '-');
     std::cout << "\t\tRules of the Casino Game\n";
     drawLine(80, '-');
     std::cout << "\t1. Choose a number between 1 and 10\n";
     std::cout << "\t2. If you win you will get 10 times of money you bet\n";
     std::cout << "\t3. If you bet on the wrong number, you will lose your betting amount\n\n";
     drawLine(80, '-');
}