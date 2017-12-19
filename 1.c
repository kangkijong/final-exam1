#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char number[30];
    char name[30];
    int korean;
    int math;
    int english;
}Student;

Student arr[100];
int snum = 0;

void Input(Student * arr, int *snum);
void Output(Student * arr, int snum);
void Save(Student * arr, int snum);
void Load(Student * arr, int *snum);

void main(void)
{
    system("clear");

    int m;
    
    printf("\n student's grade management program\n\n");

    while(1)
    {
        printf("menu\n");
        printf("1. Input\n");
        printf("2. Output\n");
        printf("3. Save\n");
        printf("4. Load\n");
        printf("5. Exit\n");
        printf(">> Select : ");
        scanf("%d", &m);
        fflush(stdin);
        switch(m)
        {
            case 1:
                Input(arr, &snum);
                break;
            case 2:
                Output(arr, snum);
                break;
            case 3:
                Save(arr, snum);
                break;
            case 4:
                Load(arr, &snum);
                break;
            case 5:
                printf("program exit!\n");
                return;
                break;
            default:
                printf("please enter the correct menu!\n");
                break;
        }
    }
}

void Input(Student * arr, int *snum)
{
    system("clear");
    
    char number[30];
    char name[30];
    int korean;
    int math;
    int english;
      
    printf("number : ");
    scanf("%s", number);
    printf("name : ");
    scanf("%s", name);
    printf("korean : ");
    scanf("%d", &korean);
    printf("math : ");
    scanf("%d", &math);
    printf("english : ");
    scanf("%d", &english);
    
    strcpy(arr[*snum].number, number);
    strcpy(arr[*snum].name, name);
    arr[*snum].korean = korean;
    arr[*snum].math = math;
    arr[*snum].english = english;
    (*snum)++;
}

void Output(Student * arr, int snum)
{
    system("clear");

    int i;

    for(i=0 ; i<snum ; i++)
    {
        printf("student %d\n", i+1);
        printf("number : %s\n", arr[i].number);
        printf("name : %s\n", arr[i].name);
        printf("korean : %d\n", arr[i].korean);
        printf("math : %d\n", arr[i].math);
        printf("english : %d\n\n", arr[i].english);
    }
}

void Save(Student * arr, int snum)
{
    int i;
    FILE *fp = fopen("student.txt", "wt");
    if(fp == NULL)
    {
        return;
    }

    for(i=0 ; i<snum ; i++)
    {
        fprintf(fp, "%s %s %d %d %d\n", arr[i].number, arr[i].name, 
                                        arr[i].korean, arr[i].math, arr[i].english);
    }
}

void Load(Student * arr, int *snum)
{
    FILE *fp = fopen("student.txt", "rt");
    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        fscanf(fp, "%s %s %d %d %d", arr[*snum].number, arr[*snum].name, 
                                     &arr[*snum].korean, &arr[*snum].math, &arr[*snum].english);
        
        if(feof != 0)
            break;
        (*snum)++;
    }
}
