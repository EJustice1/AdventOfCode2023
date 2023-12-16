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

    while (input >> line)
    {
       
    }

    return 0;
}