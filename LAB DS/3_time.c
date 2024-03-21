#include <stdio.h>
#include <stdlib.h>
struct Time
{
    int hour;
    int min;
    int sec;
};
struct Time read(struct Time *p);
void display(struct Time *p);
void update(struct Time *p);
void Add(struct Time t1, struct Time t2);

int main()
{
    struct Time *ptr, t1, t2;
    ptr = (struct Time *)malloc(sizeof(struct Time));

    int i;
    while (1)
    {
        printf("Enter\n1 to read\n2 to display\n3 for updating time\n4 for adding 2 time:\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            *ptr = read(ptr);
            break;
        case 2:
            display(ptr);
            break;
        case 3:
            update(ptr);
            break;
        case 4:
            t1 = read(ptr);
            t2 = read(ptr);
            Add(t1, t2);
            break;
        default:
            free(ptr);
            return 0;
        }
    }
    return 0;
}

struct Time read(struct Time *p)
{
    printf("Enter Time in the form of hour, minute, second: ");
    scanf("%d%d%d", &p->hour, &p->min, &p->sec);
    return (*p);
}

void display(struct Time *p)
{
    printf("The Time is:\n");
    printf("%dhours %dminutes %dseconds\n", p->hour, p->min, p->sec);
}

void update(struct Time *p)
{
    p->sec += 1;
    if(p->sec > 59){
        p->sec = 0;
        p->min += 1;
        if(p->min > 59){
            p->min = 0;
            p->hour += 1;
            if(p->hour == 24){
                p->hour = 0;
                display(p);
            }
        }
    }
}

void Add(struct Time t1, struct Time t2)
{
    struct Time res;
    res.sec = t1.sec + t2.sec;
    res.min = t1.min + t2.min;
    res.hour = t1.hour + t2.hour;
    if(res.sec > 59){
        res.sec -= 60;
        res.min += 1;
    }
    if(res.min > 59){
        res.min -= 60;
        res.hour += 1;
    }
    if(res.hour > 23){
        res.hour -= 24;
    }
    display(&res);
}