#include <iostream>
using namespace std;

class TollBooth{

    private:
    unsigned int payCar;
    unsigned int notPayCar;
    double amount;

    public:

    TollBooth(){
        this->payCar = 0;
        this->notPayCar = 0;
        this->amount = 0;
    }

    void payingCar(){
        payCar++;
        amount = amount + 0.50;
    }

    void nopayCar(){
        notPayCar = notPayCar++;
        //amount = amount + 0.0;
    }

    void printOnConsole(){
        unsigned int totalCar = payCar + notPayCar;

        cout<<"Total Cars passed = "<<totalCar<<endl;
        cout<<"Cars that paid toll = "<<payCar<<endl;
        cout<<"Cars that not paid toll  = "<<notPayCar<<endl;
        cout<<"Total amount collected = "<<amount<<endl;
    }

};

int menu()
{
     int choice;
    cout<<"Enter the detail of the car passed"<<endl;
    cout<<"1. for car that paid toll"<<endl;
    cout<<"2. for car that not paid toll"<<endl;
    cout<<"3. for printing full details of all the cars "<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main(){

    TollBooth tb;

    int choice;

    while ((choice=menu())!=0)
    {
        switch (choice)
        {
      case 1:
            tb.payingCar();
            break;
        
        case 2:
            tb.nopayCar();
            break;

        case 3:
            tb.printOnConsole();
            break;
        
        
        default:
            break;
        }
    }
    return 0;
    
}    
   

    // do
    
    
    // {
    //     switch (choice)
    //     {
    //     case 1:
    //         tb.payingCar();
    //         break;
        
    //     case 2:
    //         tb.nopayCar();
    //         break;

    //     case 3:
    //         tb.printOnConsole();
    //         break;
        
    //     default:
    //         cout<<"Invalid choice";
    //         break;
    //     }
        
    // } while (choice!=0);
    
