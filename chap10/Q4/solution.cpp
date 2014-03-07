// Write a method to implement *, -, / operations.
// You should use only the + operator.

#include <iostream>

using namespace std;

// ignore over and underflow
class Operations
{
    public:
        int multiply(int a, int b)
        {
            if (a == 0 || b == 0)
            {
                return 0;
            }

            bool sign = ((a > 0 && b > 0) || (a < 0 && b < 0));
            a = (a < 0 ? negate(a) : a);
            b = (b < 0 ? negate(b) : b);

            int result = 0;
            for (int i = 0; i < b; i++)
            {
                result += a;
            }
            return (!sign ? negate(result) : result);
        }

        int subtract(int a, int b)
        {
            return a + negate(b);
        }

        int divide(int a, int b)
        {
            if (b == 0)
            {
                cerr << "divided by 0!" << endl;
                return 0;
            }
            if (a == 0)
            {
                return 0;
            }

            bool sign = ((a > 0 && b > 0) || (a < 0 && b < 0));
            a = (a < 0 ? negate(a) : a);
            b = (b < 0 ? negate(b) : b);

            int result = 0;
            int sum = b;
            while (sum <= a)
            {
                result++;
                sum += b;
            }
            return (!sign ? negate(result) : result);
        }

        int negate(int x)
        {
            x = ~x;
            x++;
            return x;
        }
};

int main()
{
    Operations op;

    cout << "-0 = " << op.negate(0) << endl;
    cout << "-1 = " << op.negate(1) << endl;
    cout << "-(-1) = " << op.negate(-1) << endl;

    int a = 0;
    int b = 0;
    cout << a << " - " << b << " = " << op.subtract(a,b) << endl;
    a = 0;
    b = -3;
    cout << a << " - " << b << " = " << op.subtract(a,b) << endl;
    a = 0;
    b = 3;
    cout << a << " - " << b << " = " << op.subtract(a,b) << endl;
    a = 4;
    b = 4;
    cout << a << " - " << b << " = " << op.subtract(a,b) << endl;
    a = 4;
    b = 2;
    cout << a << " - " << b << " = " << op.subtract(a,b) << endl;
    a = 4;
    b = 6;
    cout << a << " - " << b << " = " << op.subtract(a,b) << endl;

    a = 0;
    b = 0;
    cout << a << " * " << b << " = " << op.multiply(a,b) << endl;
    a = -2;
    b = 0;
    cout << a << " * " << b << " = " << op.multiply(a,b) << endl;
    a = -2;
    b = 4;
    cout << a << " * " << b << " = " << op.multiply(a,b) << endl;
    a = -2;
    b = -4;
    cout << a << " * " << b << " = " << op.multiply(a,b) << endl;
    a = 2;
    b = -3;
    cout << a << " * " << b << " = " << op.multiply(a,b) << endl;
    a = 2;
    b = 3;
    cout << a << " * " << b << " = " << op.multiply(a,b) << endl;

    a = 0;
    b = 0;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;
    a = -2;
    b = 0;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;
    a = -19;
    b = 4;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;
    a = -19;
    b = -4;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;
    a = 19;
    b = -5;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;
    a = 3;
    b = 5;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;
    a = 13;
    b = 5;
    cout << a << " / " << b << " = " << op.divide(a,b) << endl;


    return 0;
}
