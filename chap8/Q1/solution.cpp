// Write a method to generate the n-th Fibonacci number.

#include <iostream>

using namespace std;

class Solution
{
	public:
		int Fibonacci(int n)
		{
			if (n == 1 || n == 2)
			{
				return 1;
			}

			return Fibonacci(n-1) + Fibonacci(n-2);
		}

		int Fibonacci2(int n)
		{
			if (n == 1 || n == 2)
			{
				return 1;
			}

			int pprev = 1;
			int prev = 1;
			int fab = 1;
			for (int i = 3; i <= n; i++)
			{
				fab = pprev + prev;
				pprev = prev;
				prev = fab;
			}
			return fab;
		}
};

int main()
{
	Solution solu;
	int n = 1;
	cout << n << "-th Fabonacci = " << solu.Fibonacci2(n) << endl;
	n = 2;
	cout << n << "-th Fabonacci = " << solu.Fibonacci2(n) << endl;
	n = 6;
	cout << n << "-th Fabonacci = " << solu.Fibonacci2(n) << endl;

	return 0;
}
