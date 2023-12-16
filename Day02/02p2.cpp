#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

    int maxRed = 0, maxBlue = 0, maxGreen = 0;
    while (input)
    {
        string token;
        input >> token;

        //will update turn counter and move token to be first number
        if(token == "Game")
        {
            total += maxRed * maxGreen * maxBlue;
            cout <<  maxRed * maxGreen * maxBlue << endl;
            maxRed = maxGreen = maxBlue = 0;
            input >> currentGameNumber >> token >> token;
        }

        if (token[0] >= '0' && token[0] <= '9')
        {
            int numDice = stoi(token); 

            //token now color of dice
            input >> token;

            if (token.find("red") != string::npos)
                maxRed = max(maxRed, numDice);
            else if (token.find("green") != string::npos)
                maxGreen = max(maxGreen, numDice);
            else if (token.find("blue") != string::npos)
                maxBlue = max(maxBlue, numDice);  
            
        }     
             
    }

    total += maxRed * maxGreen * maxBlue;

    cout << "total: " << total << endl;
    return 0;
}