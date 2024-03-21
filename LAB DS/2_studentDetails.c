#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    int reg_no;
    int m1, m2, m3;
    float avg;
} *ptr;
typedef struct student stud;

void read(stud *ptr, int n);
void display(stud *ptr, int n);
void calculateAvg(stud *ptr, int n);

int main()
{
    int n, i;
    printf("Enter Number of Students: ");
    scanf("%d", &n);
    ptr = (stud *)malloc(n*sizeof(stud));
    if(ptr == NULL){
        printf("Dynamic memory Allocation is not possible");
        return 0;
    }
    while (1)
    {
        printf("Enter\n1 to read\n2 to display\n3 to calculate Average of best 2 marks:\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            read(ptr, n);
            break;
        case 2:
            display(ptr, n);
            break;
        case 3:
            calculateAvg(ptr, n);
            break;
        default:
            free(ptr);
            return 0;
        }
    }
    return 0;
}

void read(stud *ptr, int n)
{   int i;
    for(i=0; i<n; i++){
    printf("Enter student%d Name, RegisterNumber, marks of 3 test out of 30: \n", i+1);
    scanf("%s%d%d%d%d", ptr->name, &ptr->reg_no, &ptr->m1, &ptr->m2, &ptr->m3);
    ptr++;
    }
}

void display(stud *ptr, int n)
{
    int i;
    printf("Name\tReg_No\tM1\tM2\tM3\tAverage\n");
    for(i=0; i<n; i++){
        printf("%s\t%d\t%d\t%d\t%d\t%f\n", ptr->name, ptr->reg_no, ptr->m1, ptr->m2, ptr->m3, ptr->avg);
        ptr++;
    }
}

void calculateAvg(stud *ptr, int n)
{
    int min, i;
    for (i = 0; i < n; i++)
    {
        min = ptr->m1 < ptr->m2 ? ptr->m1 : ptr->m2;
        min = min < ptr->m3 ? min : ptr->m3;
    ptr->avg = (ptr->m1 + ptr->m2 + ptr-> m3 - min) / 2.0;
    ptr++;
    }
}