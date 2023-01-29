#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long long Factorial(long long n)
{
    if (n <= 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n)
{
    std::deque<int> dq;
    dq.push_front(1);
    
    for (int i = 2; i <= n; ++i)
    {
        for (auto &a : dq) a *= i;
        
        int carry = 0;
        int temp = 0;
        
        for (auto it = dq.rbegin(); it != dq.rend(); ++it)
        {
            temp = (*it + carry) % 10;
            carry = (*it + carry) / 10;
            *it = temp;
        }
        
        while (carry)
        {
            dq.push_front(carry % 10);
            carry /= 10;
        }
    }
        
    for (auto &a : dq) cout << a;
}

void extraLongFactorials2(int n)
{
    vector<int> d;
    d.push_back(1);
    
    for (int i = 2; i <= n; ++i)
     {
        for (auto it = d.begin(); it != d.end(); ++it)
            *it *= i;
        
        for (size_t j = 0; j < d.size(); ++j)
        {
            if (d[j] < 10)
                continue;

            if (j == d.size()-1)
            {
                d.push_back(0);
            }
            
            d[j+1] += d[j] / 10;
            d[j] %= 10;
        }
    }

    for (auto it = d.rbegin(); it != d.rend(); ++it)
        cout << *it;    
}
