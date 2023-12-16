#include <iostream>
#include <fstream>

using namespace std;

void processString(string &str)
{
    string digitWords[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < 9; i++) 
    {
        string numstr = to_string(i+1);

        int position = str.find(digitWords[i]);
        while(position != string::npos)
        {
            str.replace(position + 1, 1, numstr);
            position = str.find(digitWords[i]);
        }
    }
}

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
        processString(line);
        cout << line << ": ";

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