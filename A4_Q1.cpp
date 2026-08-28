#include<iostream>
using namespace std;

class Time 
{
    private:
    int h;
    int m;
    int s;

    public:
    Time():h(0), m(0), s(0)
    {   }

    Time(int h, int m, int s):h(h), m(m), s(s)
    {    }

    int getHour(){
        return this->h;
    }

    int getMinute(){
        return this->m;
    }

    int getSeconds(){
        return this->s;
    }

    void setHour(int h){
        this->h = h;
    }

    void setMinute(int m){
        this->m = m;
    }

    void setSeconds(int s){
        this->s = s;
    }

    void acceptTime(){
        cout<<"Enter time Hour : minutes : seconds"<<endl;
        cin>>h>>m>>s;
    }

    void printTime(){
        cout<<"Time : "<<h<<" : "<<m<<" : "<<s<<endl;
    }
};

int menu(){
    int choice;
    cout<<"Enter the choice"<<endl;
    cout<<"1. Add Time"<<endl;
    cout<<"2. Display all time"<<endl;
    cout<<"3. Display only hours of all time objects"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int n;
    cout<<"Enter the no. of objects"<<endl;
    cin>>n;
    int choice;
    Time *arr = new Time[n];

    while ((choice=menu())!=0)   
    {
        switch (choice)
        {
        case 1:
        for (int index = 0; index <n; index++){
            arr[index].acceptTime();
        }
        break;

        case 2:
        for (int index = 0; index <n; index++){
            arr[index].printTime();
        }
        break;
        
        case 3:
        for (int index = 0; index <n; index++){
            arr[index].getHour();
        }
        default:
            break;
        }
    }
    delete[]arr;
    arr= NULL;
}


