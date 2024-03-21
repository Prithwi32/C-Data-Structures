// Infix to postfix conversion and evaluation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack1{
    char arr[100];
    int top;
}*s1;
struct stack2
{
    float arr[100];
    int top;
}*s2;

int prec(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

char associ(char c) {
    if (c == '^')
        return 'R';
    return 'L';
}

void InfixToPostfix(char infix[], char postfix[]) {
    char c;//stack[100], c;
    int index = 0,l = strlen(infix), i;
    
    for (i = 0; i < l; i++) {
        c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[index++] = c;
        } else if (c == '(') {
             s1->arr[++(s1->top)]= c;
        } else if (c == ')') {
            while (s1->top >= 0 && s1->arr[s1->top] != '(') {
                postfix[index++] = s1->arr[(s1->top)--];
            }
            (s1->top)--;
        } else {
            while (s1->top >= 0 && ((prec(c) < prec(s1->arr[s1->top])) || (prec(c) == prec(s1->arr[s1->top]) && associ(c) == 'L'))) {
                postfix[index++] = s1->arr[(s1->top)--];
            }
            s1->arr[++(s1->top)]= c;
        }
    }
    while (s1->top >= 0) {
        postfix[index++] = s1->arr[(s1->top)--];
    }
    postfix[index] = '\0';
    printf("%s\n", postfix);
}

void EvalPostfix(char postfix[]) {
    float  r, op1, op2;
    char c;
    int  i, l = strlen(postfix);
    for (i = 0; i < l; i++) {
        c = postfix[i];
        if (c >= '0' && c <= '9') {
            s2->arr[++(s2->top)] = c - '0';
        } else {
            op2 = s2->arr[(s2->top)--];
            op1 = s2->arr[(s2->top)--];
            switch (c) {
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
                        r = op1 / op2;
                    break;
                /* case '^':
                    r = pow(op1, op2);
                    break; */
            }
           s2->arr[++(s2->top)] = r;
        }
    }
    printf("The result is %f\n", s2->arr[s2->top--]);
}

int main() {
    int choice;
    char infix[100], postfix[100];
    s1=(struct stack1*)malloc(sizeof(struct stack1));
    s1->top=-1;
    
    s2=(struct stack2*)malloc(sizeof(struct stack2));
    s2->top=-1;
    while(1){
        printf("Enter \n1 to convert infix to postfix\n2 for evaluate expression\n0 for exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:printf("Enter the expression\n");
            scanf("%s",infix);
            InfixToPostfix(infix, postfix);
            break;
            case 2:printf("Enter the expression\n");
            scanf("%s",infix);
            InfixToPostfix(infix, postfix);
            EvalPostfix(postfix);
            break;
            case 0:printf("Thank you\n");
            return 0;
            default:printf("Invalid choice\n\tTry again......\n");
        }
    }
    return 0;
}






//Infix to prefix conversion and evaluation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
struct stack1{
    char arr[100];
    int top;
}*s1;
struct stack2
{
    float arr[100];
    int top;
}*s2;
void reverse(char expre[]);
int prec(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

char associ(char c) {
    if (c == '^')
        return 'R';
    return 'L';
}

void InfixToPrefix(char infix[], char prefix[]) {
    char c;//stack[100], c;
    int index = 0,l = strlen(infix), i;
    reverse(infix);
    for(i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    for (i = 0; i < l; i++) {
        c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            prefix[index++] = c;
        } else if (c == '(') {
             s1->arr[++(s1->top)]= c;
        } else if (c == ')') {
            while (s1->top >= 0 && s1->arr[s1->top] != '(') {
                prefix[index++] = s1->arr[(s1->top)--];
            }
            (s1->top)--;
        } else {
            while (s1->top >= 0 && ((prec(c) < prec(s1->arr[s1->top])) || (prec(c) == prec(s1->arr[s1->top]) && associ(c) == 'R'))) {
                prefix[index++] = s1->arr[(s1->top)--];
            }
            s1->arr[++(s1->top)]= c;
        }
    }
    while (s1->top >= 0) {
        prefix[index++] = s1->arr[(s1->top)--];
    }
    prefix[index] = '\0';
    reverse(prefix);
    printf("The prefix expression is %s\n",prefix);
}

void EvalPrefix(char prefix[]) {
    float  r, op1, op2;
    char c;
    int  i, l = strlen(prefix);
    for (i = l-1; i>=0; i--) {
        c = prefix[i];
        if (c >= '0' && c <= '9') {
            s2->arr[++(s2->top)] = c - '0';
        } else {
            op1 = s2->arr[(s2->top)--];
            op2 = s2->arr[(s2->top)--];
            switch (c) {
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
                        r = op1 / op2;
                    break;
                case '^':
                    r = pow(op1, op2);
                    break;
            }
           s2->arr[++(s2->top)] = r;
        }
    }
    printf("The result is %f\n", s2->arr[s2->top--]);
}
void reverse(char expre[])
{
  char temp;
  int l=strlen(expre),i=0,j=l-1;
  while(i<j)
  {
      temp=expre[i];
      expre[i]=expre[j];
      expre[j]=temp;
      i++;
      j--;
  }
}

int main() {
    int i,choice;
    char infix[100], prefix[100];
    s1=(struct stack1*)malloc(sizeof(struct stack1));
    s1->top=-1;
    
    s2=(struct stack2*)malloc(sizeof(struct stack2));
    s2->top=-1;
    while(1){
        printf("Enter \n1 to convert infix to prefix\n2 for evaluate expression\n0 for exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the expression: ");
            scanf("%s", infix);
            InfixToPrefix(infix, prefix);
            break;
            case 2:printf("Enter the expression: ");
            scanf("%s", infix);
            InfixToPrefix(infix, prefix);
            EvalPrefix(prefix);
            break;
            case 0:printf("Thank you\n");
            return 0;
            default:printf("Invalid choice\n\tTry again..........\n");
        }  
    }
    return 0;
}