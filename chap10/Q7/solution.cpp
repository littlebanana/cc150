// Design an algorithm to find the k-th number such that the only prime factors are 3, 5 and 7.

#include <iostream>
#include <stdexcept>
#include <climits>

using namespace std;

class Solution
{
    public:
        unsigned long long generateKth(int k)
        {
            if (k <= 0)
            {
                return 0;
            }

            unsigned long long pow = 1;
            unsigned long long pow3 = 3;
            unsigned long long pow5 = 5;
            unsigned long long pow7 = 7;
            for (int i = 2; i <= k; i++)
            {
                if (pow3 < pow5 && pow3 <pow7)
                {
                    pow = pow3;
                    pow3 *= 3;
                    /*if (pow3 > (double)UINT_MAX/3.0)
                      {
                      cerr << "overflow" << endl;
                      return 0;
                      }*/
                }
                else if (pow5 < pow3 && pow5 < pow7)
                {
                    pow = pow5;
                    pow5 *= 5;
                    /*if (pow5 > (double)UINT_MAX/5.0)
                      {
                      cerr << "overflow" << endl;
                      return 0;
                      }*/
                }
                else
                {
                    pow = pow7;
                    pow7 *= 7;
                    /*if (pow7 > (double)UINT_MAX/7.0)
                      {
                      cerr << "overflow" << endl;
                      return 0;
                      }*/
                }
            }
            /*if (pow > (double)UINT_MAX/(3*5*7.0))
              {
              cerr << "overflow" << endl;
              return 0;
              }*/
            return 3*5*7*pow;
        }
};

int main()
{
    Solution solu;

    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;

    cout << solu.generateKth(0) << endl;
    cout << solu.generateKth(-1) << endl;
    for (int i = 1; i <= 20; i++)
    {
        cout << solu.generateKth(i) << endl;
    }

    return 0;
}
