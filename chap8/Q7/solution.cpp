// Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent),
// write code to calculate the number of ways of representing n cents.

#include <iostream>

using namespace std;

class Solution
{
    public:
        int numWaysDP(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            int num[n];     // num[i] = # of ways to represent i+1
            for (int i = 0; i < n; i++)
            {
                num[i] = 0;
                if ((i+1) - 1 >= 0)
                {
                    num[i] += ((i+1)-1 == 0 ? 1 : num[i-1]);
                }
                if ((i+1) - 5 >= 0)
                {
                    num[i] += ((i+1)-5 == 0 ? 1 : num[i-5]);
                }
                if ((i+1) - 10 >= 0)
                {
                    num[i] += ((i+1)-10 == 0 ? 1 : num[i-10]);
                }
                if ((i+1) - 25 >= 0)
                {
                    num[i] += ((i+1)-25 == 0 ? 1 : num[i-25]);
                }
            }
            return num[n-1];
        }

        int numWaysRecursive(int n)
        {
            if (n < 0)
            {
                return 0;
            }
            if (n == 0)
            {
                return 1;
            }

            int num = 0;
            num += numWaysRecursive(n-1);
            num += numWaysRecursive(n-5);
            num += numWaysRecursive(n-10);
            num += numWaysRecursive(n-25);
            return num;
        }
};

int main()
{
    Solution solu;

    int n = 1;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;
    n = 2;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;
    n = 4;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;
    n = 5;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;
    n = 8;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;
    n = 18;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;
    n = 35;
    cout << "n = " << n << ", # of ways = " << solu.numWaysDP(n) << endl;
    cout << "n = " << n << ", # of ways = " << solu.numWaysRecursive(n) << endl;

    return 0;
}
