#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;


int main()
{
    ifstream input("02input.txt");

    if (input.bad())
    {
        cout << "Error opening file";
        return 1;
    }

    int total = 0;
    int currentGameNumber = 0;
    bool currentlyValid = true;
    while (input)
    {
        string token;
        input >> token;

        //will update turn counter and move token to be first number
        if(token == "Game")
        {
            if (currentlyValid)
                total += currentGameNumber;
            input >> currentGameNumber >> token >> token;
            currentlyValid = true;
        }

        if (currentlyValid)
        {
            if (token[0] >= '0' && token[0] <= '9')
            {
                int numDice = stoi(token); 

                //token now color of dice
                input >> token;

                if (token.find("red") != string::npos)
                    currentlyValid = (numDice <= MAX_RED);
                else if (token.find("green") != string::npos)
                    currentlyValid = (numDice <= MAX_GREEN);
                else if (token.find("blue") != string::npos)
                    currentlyValid = (numDice <= MAX_BLUE);   
             
            }
        }            
    }

    if (currentlyValid)
        total += currentGameNumber;

    cout << "total: " << total << endl;
    return 0;
}