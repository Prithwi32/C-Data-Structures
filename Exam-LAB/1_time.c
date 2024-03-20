// 1. a) Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and average_ marks.
// Develop a menu driven program to perform the following by writing separate function for each operation: a) read 
// information of N students b) display student’s information c) to calculate the average of best two test marks of each 
// student.
// Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure.

// b) Define a structure called Time containing 3 integer members (Hour, Minute, Second).Develop a menu driven 
// program to perform the following by writing separate function for each operation.
// a) Read (T) :To read time b) Display (T):To display time c) update(T):To Update time d) Add(T1, T2) : Add two 
// time variables.
// Update function increments the time by one second and returns the new time (if the increment results in 60
// seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60
// minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour
// becomes 24, Time should be reset to zero. While reading two time variables, normalize the resultant time value as in 
// the case of update function. Note: Illustrate the use of pointer to pass time variable to different functions.
// a
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
    ptr->avg = 0.0;
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

// b
#include <stdio.h>
#include <stdlib.h>
struct time
{
    int hour;
    int min;
    int sec;
};
void read(struct time *p)
{
    printf("Enter time in hour:min:sec\n");
    scanf("%d%d%d", &p->hour, &p->min, &p->sec);
};
void display(struct time *p)
{
    printf("time is:\n");
    printf("%d:%d:%d\n", p->hour, p->min, p->sec);
}
void update(struct time *p)
{
    p->sec += 1;
    if (p->sec > 59)
    {
        p->sec = 0;
        p->min += 1;
        if (p->min > 59)
        {
            p->min = 0;
            p->hour += 1;
            if (p->hour == 24)
            {
                p->hour = 0;
            }
        }
    }
    display(p);
}
void Add(struct time *t1, struct time *t2)
{
    struct time res;
    res.hour = t1->hour + t2->hour;
    res.min = t1->min + t2->min;
    res.sec = t1->sec + t2->sec;
    if (res.sec > 59)
    {
        res.sec = res.sec - 60;
        res.min += 1;
    }
    if (res.min > 59)
    {
        res.min = res.min - 60;
        res.hour += 1;
    }
    if (res.hour > 23)
    {
        res.hour = res.hour - 24;
    }
    display(&res);
}

int main()
{
    struct time *ptr, *t1, *t2;
    ptr = (struct time *)malloc(sizeof(struct time));
    t1 = (struct time *)malloc(sizeof(struct time));
    t2 = (struct time *)malloc(sizeof(struct time));
    int i;
    while (1)
    {
        printf("enter\n 1.read\n 2.display\n 3.update\n 4.add two time values\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            read(ptr);
            break;
        case 2:
            display(ptr);
            break;
        case 3:
            update(ptr);
            break;
        case 4:
            read(t1);
            read(t2);
            Add(t1, t2);
            break;
        default:
            free(ptr);
            return 0;
        }
    }
}