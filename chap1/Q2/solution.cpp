// Write code to reverse a C-style string.
// (C-string means that "abcd" is represented as five characters,
// including the null character

#include <iostream>

using namespace std;

class Solution
{
	public:
		void reverse(char *s)
		{
			int l = 0;
			char *p = s;
			for (; *p != '\0'; l++, p++);

			int i = 0;
			int j = l-1;
			while (i < j)
			{
				char tmp = *(s+i);
				*(s+i) = *(s+j);
				*(s+j) = tmp;
				i++;
				j--;
			}
		}
};

int main()
{
	char s1[] = "";
	char s2[] = "a";
	char s3[] = "abcdefg";

	Solution solu;

	cout << s1 << " ";
	solu.reverse(s1);
	cout << s1 << endl;
	cout << s2 << " ";
	solu.reverse(s2);
	cout << s2 << endl;
	cout << s3 << " ";
	solu.reverse(s3);
	cout << s3 << endl;

	return 0;
}
