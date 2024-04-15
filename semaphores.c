#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int mutex=1,empty=3,full=0;

int wait(int s)
   {
    s--;
    return s;
   }
   
int signal(int s)
   {
    s++;
    return s;
   }

void producer()
   {
    printf("Producer is called\n");
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    mutex=signal(mutex);
   }

void consumer()
   {
    printf("Consumer is called\n");
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    mutex=signal(mutex);
   }
   
void main()
   {
    int choice;
    while(true)
       {
        printf("-------------------------------------\n");
        printf("Enter choice :  [ 1.Producer  2.Consumer  3.Exit ]\n");
        scanf("%d",&choice);

        switch(choice)
           {
            case 1:
               if (mutex==1 && empty!=0)
                  producer();
               else
                  printf("Buffer Full\n");
               break;
            case 2:
               if (mutex==1 && full!=0)
                  consumer();
               else
                  printf("Buffer Empty\n");
               break;
            case 3:
               exit(0);
           }
       }
   }











