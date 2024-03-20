// 10. Develop a menu driven program to convert infix expression to postfix expression using stack and evaluate
// the postfix expression. (Test for nested parenthesized expressions) Note: Define Stack structure and
// implement the operations. Use different stacks for conversion and evaluation

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
    if ((symbol == '^') || (symbol == '$'))
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

void infixToPostfix(char infix[], char postfix[])
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
            while (S.top >= 0 && (precedence(infix[i]) < precedence(S.stack[S.top]) || (precedence(infix[i]) == precedence(S.stack[S.top]) && associativity(infix[i] == 'L'))))
                postfix[index++] = S.stack[(S.top)--];
            S.stack[++(S.top)] = infix[i];
        }
    }
    while (S.top >= 0)
        postfix[index++] = S.stack[(S.top)--];
    postfix[index] = '\0';
    // printf("The postfix expression is: %s",postfix);
}

void evalPostfix(char postfix[])
{
    float r, op1, op2;
    char symbol;
    int i, top = -1;
    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9')
            S.stackE[++(S.top)] = symbol - '0';
        else
        {
            op2 = S.stackE[(S.top)--];
            op1 = S.stackE[(S.top)--];
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
                if(op2 != 0){
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
    printf("The result is %f", S.stackE[(S.top)--]);
}

void main()
{
    char infix[MAX];   // Array to store Infix Expression
    char postfix[MAX]; // Array to store Prefix Expression
    S.top = -1;
    int choice;
    printf("Menu\n1.Enter Infix Expression\n2.Convert to Postfix\n3.Evaluate postfix\n4.Exit\n");
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
            infixToPostfix(infix, postfix);
            printf("The Postfix Expression is : ");
            printf("%s\n", postfix);
            break;
        case 3:
            printf("Enter the Postfix Expression : ");
            scanf("%s", postfix);
            evalPostfix(postfix);
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
}
