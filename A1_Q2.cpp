#include<iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    void initDate(){
        day= 11;
        month= 10;
        year= 2003;
    }

    void printDateOnConsole(){
        cout<<"Day = "<<day<<endl;
        cout<<"Month = "<<month<<endl;
        cout<<"Year = "<<year<<endl;
    }

    void acceptDateFromConsole(){
        cout<<"Enter Date"<<endl;
        cin>>day;
        cout<<"Enter Month"<<endl;
        cin>>month;
        cout<<"Enter Year"<<endl;
        cin>>year;
    }

    bool isLeapYear(){
        if((year%4==0 && year%100!=0) || year%400==0){
            return 1;
        }
        else{
            return 2;
        }
    }
};

int main(){
    int choice = 0;
    Date d;
    d.initDate();

    do{
    //Creating menu
    cout<<"1. For Printing Date on Console";
    cout<<"2. For Accepting Date on Console";
    cout<<"3. For Checking Leap Year Date";
    cin>>choice;
    
    switch (choice)
    {
        case 1:
        d.printDateOnConsole();
        break;
        case 2:
        d.acceptDateFromConsole();
        break;
        case 3:
        if(d.isLeapYear()==1){
            cout<<"It is a leap year";
        }
        else{
            cout<<"Not a leap year";
        }
        break;
        default:
        break;
    }
}while (choice!=4);
return 0;

}