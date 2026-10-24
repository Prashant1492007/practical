#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

class stack
{
private:
    int arr[100];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int val)
    {
        top++;
        arr[top] = val;
    }

    int pop()
    {
        int p = arr[top];
        top--;
        return(p);
    }
};

int evaluate(char x, int op1, int op2)
{
    if (x == '+')
        return(op1 + op2);

    if (x == '-')
        return(op1 - op2);

    if (x == '*')
        return(op1 * op2);

    if (x == '/')
        return(op1 / op2);

    if (x == '%')
        return(op1 % op2);

    if (x == '$')
        return(pow(op1, op2));

    return 0;
}

int main(void)
{
    stack s;
    char x;
    int op1, op2, val;

    cout << "\nEnter postfix expression: ";

    while ((x = getchar()) != '\n')
    {
        if (isdigit(x))
        {
            s.push(x - 48);
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();

            val = evaluate(x, op1, op2);

            s.push(val);
        }
    }

    val = s.pop();

    cout << "\nAnswer = " << val;

    return 0;
}
//output
//PS C:\Users\poona\OneDrive\Desktop\pt123> g++ postfixusingstack.cpp -o postfixusingstack
//PS C:\Users\poona\OneDrive\Desktop\pt123> ./postfixusingstack

//Enter postfix expression: 623+-564/+*3$9+

//Answer = 225