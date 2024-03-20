// 11. Develop a menu driven program to convert infix expression to prefix expression using stack and evaluate
// the prefix expression (Test for nested parenthesized expressions)
// Note: Define Stack structure and implement the operations. Use different stacks for conversion and
// evaluation.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

struct Stack
{
    int top;
    float stackE[MAX];
    char stack[MAX];
} S;

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if ((symbol == '*') || (symbol == '/') || (symbol == '%'))
        return 2;
    else if ((symbol == '+') || (symbol == '-'))
        return 1;
    else
        return 0;
}

char associativity(char symbol)
{
    if (symbol == '^')
        return 'R';
    return 'L';
}

void nearlyInfixToPostfix(char infix[], char postfix[])
{
    int i, len = strlen(infix), index = 0;
    for (i = 0; i < len; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
            postfix[index++] = infix[i];

        else if (infix[i] == '(')
            S.stack[++(S.top)] = infix[i];

        else if (infix[i] == ')')
        {
            while (S.stack[S.top] != '(' && S.top >= 0)
                postfix[index++] = S.stack[(S.top)--];
            S.top--;
        }

        else
        {
            while (S.top >= 0 && (precedence(infix[i]) < precedence(S.stack[S.top])))
                postfix[index++] = S.stack[(S.top)--];
            S.stack[++(S.top)] = infix[i];
        }
    }
    while (S.top >= 0)
        postfix[index++] = S.stack[(S.top)--];
    postfix[index] = '\0';
}

void reverseString(char str[])
{
    int len = strlen(str) - 1, i = 0;
    char temp;
    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
}

void infixToPrefix(char infix[], char npostfix[])
{
    int i;
    reverseString(infix);
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == ')')
            infix[i] = '(';
        else if (infix[i] == '(')
            infix[i] = ')';
    }
    nearlyInfixToPostfix(infix, npostfix);
    reverseString(npostfix);
}

void evalPrefix(char prefix[])
{
    float r, op1, op2;
    char symbol;
    int i;
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        symbol = prefix[i];
        if (symbol >= '0' && symbol <= '9')
            S.stackE[++(S.top)] = symbol - '0';
        else
        {
            op1 = S.stackE[(S.top)--];
            op2 = S.stackE[(S.top)--];
            switch (symbol)
            {
            case '+':
                r = op1 + op2;
                break;
            case '-':
                r = op1 - op2;
                break;
            case '*':
                r = op1 * op2;
                break;
            case '/':
                if (op2 != 0)
                {
                    r = op1 / op2;
                }
                break;
            case '%':
                r = (int)op1 % (int)op2;
                break;
            case '^':
                r = pow(op1, op2);
                break;
            }
            S.stackE[++(S.top)] = r;
        }
    }
    printf("The result is %f\n", S.stackE[(S.top)--]);
}

int main()
{
    char infix[MAX];  // Array to store Infix Expression
    char prefix[MAX]; // Array to store Prefix Expression
    S.top = -1;
    int choice;
    printf("Menu\n1.Enter Infix Expression\n2.Convert to Prefix\n3.Evaluate prefix\n4.Exit\n");
    for (;;)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Infix Expression : ");
            scanf("%s", infix);
            break;
        case 2:
            infixToPrefix(infix, prefix);
            printf("The Prefix Expression is : ");
            printf("%s\n", prefix);
            break;
        case 3:
            printf("Enter the Prefix Expression : ");
            scanf("%s", prefix);
            evalPrefix(prefix);
            break;
        case 4:
            printf("!! THANK YOU !!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
