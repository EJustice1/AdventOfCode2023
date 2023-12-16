#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("01input.txt");

    if (input.bad())
    {
        cout << "Error opening file";
        return 1;
    }

    string line;
    int total = 0;

    while (input >> line)
    {
        int firstDigit= -1;
        int lastDigit = -1;
    
        for (char c : line)
        {
            if (c >= '0' && c <= '9')
            {
                if (firstDigit == -1)
                    firstDigit = c - '0';

                lastDigit = c - '0';
            }
        }

        total += firstDigit * 10 + lastDigit;
        cout <<firstDigit << lastDigit << endl;
    }

    cout << "total: " << total << endl;

    return 0;
}