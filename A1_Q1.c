#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;

};

void initDate(struct Date* ptrDate){
   ptrDate->day=1;
   ptrDate->month=1;  
   ptrDate->year=2000;
   printf(" Initialized Date: %d/%d/%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}

void printDate(struct Date*ptrDate){
   printf(" Initialized Date: %d/%d/%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}

void acceptDate(struct Date*ptrDate){
    printf("Enter the day: ");
    scanf("%d",&ptrDate->day);
    printf("Enter the month: ");
    scanf("%d",&ptrDate->month);
    printf("Enter the year: ");
    scanf("%d", &ptrDate->year);
}

void menu() {
    printf("1. Initialize Date\n");
    printf("2. Print Date\n");
    printf("3. Accept Date\n");
    printf("4. Exit\n");
}



int main() {
    struct Date dt;
    int n;
    while( n != 4) {
        menu();
        scanf("%d", &n);
        switch(n) {
            case 1:
                printf("Initialized Date\n");
                initDate(&dt);
                break;
            case 2:
                printf("PrintDate selected\n");
                printDate(&dt);
                break;
            case 3:
                printf("AcceptDate selected\n");
                acceptDate(&dt);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}