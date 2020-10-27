// C++ Program to Implement Z-Algorithm
// It is linear time pattern searching algorithm

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool zAlgorithm(string pattern, string target)
{
    string s = pattern + '$' + target;
    int n = s.length();
    vector<int> z(n, 0);
    int goal = pattern.length();
    int r = 0, l = 0, i;
    for (int k = 1;  k < n; k++)
    {
        if (k > r)
        {
            for (i = k; i < n && s[i] == s[i - k]; i++);
            if (i > k)
            {
                z[k] = i - k;
                l = k;
                r = i - 1;
            }
        }
        else
        {
            int kt = k - l, b = r - k + 1;
            if (z[kt] > b)
            {
                for (i = r + 1; i < n && s[i] == s[i - k]; i++);
                z[k] = i - k;
                l = k;
                r = i - 1;
            }
        }
        if (z[k] == goal)
            return true;
    }
    
    return false;
}

int main()
{
    string line , target ;
    
    cout << "write the string :" << endl;
    cin >> line;
    
    cout << "write the part of string that you want to find :" << endl ;
    cin >> target ;
   
    if ( zAlgorithm ( target , line ) )
        cout << "'" << target << "' found in string '" << line << "'" << endl ;

    else
        cout << "'" << target << "' not found in string '" << line << "'" << endl;
}

// contributed by : user-akj
