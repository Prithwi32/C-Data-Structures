#include <stdio.h>
#include <stdlib.h>
int n = 0;
struct student
{
    char name[100];
    int reg_no;
    int m1, m2, m3;
    int avg;
};

void read(struct student *str)
{
    printf("Enter Student Name: ");
    scanf("%s", (char *)&str[n].name);
    printf("Enter Register Number: ");
    scanf("%d", &str[n].reg_no);
    printf("Enter the marks obtained in three subjects: ");
    scanf("%d %d %d", &str[n].m1, &str[n].m2, &str[n].m3);
    str[n].avg;
    n++;
}
struct student calcAvg(struct student *str){
    int min;
    for(int i=0; i<n; i++){
        if(str[i].m1 < str[i].m2){
            if(str[i].m1 < str[i].m3){
                min = str[i].m1;
            }else{
                min = str[i].m3;
            }
        }else if(str[i].m2 < str[i].m1){
            if(str[i].m2 < str[i].m3){
                min = str[i].m2;
            }else{
                min = str[i].m3;
            }
        }else{
            if(str[i].m3 < str[i].m1){
                min = str[i].m3;
            }else{
                min = str[i].m1;
            }
        }
        int total = str[i].m1 + str[i].m2 + str[i].m3;
        // str[i].avg = (total-min) / 2.0;
        str[i].avg = total/3;
     }  
  }


void display(struct student *str)
{
    printf("Name\tRegisterNumber \tM1\tM2\tM3\tAverage\n");
    for(int i=0; i<n; i++){
        printf("%s\t\t%d\t%d\t%d\t%d\t%d\n",str->name,str->reg_no,str->m1,str->m2,str->m3,str->avg);
    }
}


int main()
{
    struct student *str = NULL;
    str = (struct student *)realloc(str, (n + 1) * sizeof(struct student));
    read(str);
    calcAvg(str);
    display(str);
    return 0;
}