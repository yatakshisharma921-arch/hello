#include <iostream>
#include <string>
using namespace std;

int minAddToMakeValid(string s)
{
    int open = 0, add = 0;

    for (char c : s)
    {
        if (c == '(')
            open++;
        else if (open > 0)
            open--;
        else
            add++;
    }

    return add + open;
}

int main()
{
    string s = "())";

    cout << "Minimum additions: " << minAddToMakeValid(s);

    return 0;
}
