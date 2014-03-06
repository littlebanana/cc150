// You are given two 32-bit numbers, N and M, and two bit positions, i and j.
// Write a method to set all bits between i and j in N equal to M
// (e.g., M becomes a substring of N located at i and starting at j)
// EXAMPLE:
// Input: N = 10,000,000,000, M = 10101, i = 2, j = 6
// Output: N = 10001010100

#include <iostream>

using namespace std;

void printBytes(unsigned int bytes)
{
    int n = 8*sizeof(unsigned int);

    int mask = 0x80000000;

    for (int i = 0; i < n; i++)
    {
        cout << ((bytes & mask) == mask ? '1' : '0');
        if (i < n-1 && i % 4 == 3)
        {
            cout << ',';
        }
        bytes <<= 1;
    }
    cout << endl;
}

class Solution
{
    public:
        unsigned int setMiddleBits(unsigned int M, unsigned int N, int i, int j)
        {
            int l = 8*sizeof(unsigned int);

            unsigned int mask = 0xFFFFFFFF;
            mask <<= i;
            mask &= (0xFFFFFFFF >> (l-1-j));

            return ((M & (~mask)) | (N & mask));
        }
};

int main()
{
    unsigned int bytes1 = 0xF0F09ABC;
    printBytes(bytes1);
    unsigned int bytes2 = 0xABCDEF12;
    printBytes(bytes2);

    Solution solu;
    unsigned int modified = solu.setMiddleBits(bytes1, bytes2, 4, 11);
    printBytes(modified);

    return 0;
}
