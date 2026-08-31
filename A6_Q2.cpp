#include<iostream>
using namespace std;

class Employee{
    private:
    int id;
    double salary;

    public:
    Employee(void): id(0), salary(0.0)
    {   }

    Employee(int id , double salary): id(id), salary(salary)
    {   }

    void setId(int id){
        this->id = id;
    }

    int getId(){
        return this->id;
    }

    void setSalary(double salary){
        this->salary= salary;
    }

    double getSalary(){
        return this->salary;
    }

    void accept(){
        cout<<"Enter Employee Id : "<<endl;
        cin>>id;
        cout<<"Enter Employee Salary : "<<endl;
        cin>>salary;
    }

    void display(){
        cout<<"Employee Id : "<<id<<endl;
        cout<<"Employee Salary : "<<salary<<endl;
    }
};

class Manager : virtual public Employee{
    private:
    double bonus;

    public:
    Manager(): bonus(0)
    {    }

    Manager(int id , double salary, double bonus): Employee(id,salary){
        this->bonus= bonus;
    }

    void setBonus(double bonus){
        this->bonus = bonus;
    }

    double getBonus(){
        return this->bonus;
    }

    void accept(){
        Employee::accept();
        cout<<"Enter Bonus : "<<endl;
        cin>>bonus;
    }

    void display(){
        Employee::display();
        cout<<"Bonus : "<<bonus<<endl;
    }

    protected:
    void acceptManager(){
        accept();
    }

    void displayManager(){
        display();
    }
};

class Salesman : virtual public Employee{
    private:
    double commission;

    public:
    Salesman(): commission(0)
    {    }

    Salesman(int id , double salary, double commission): Employee(id,salary){
        this->commission= commission;
    }

    void setCommission(double commission){
        this->commission = commission;
    }

    double getCommission(){
        return this-> commission;
    }

    void accept(){
        Employee::accept();
        cout<<"Enter the commission : "<<endl;
        cin>>commission;
    }

    void display(){
        Employee::display();
        cout<<"Commission : "<<commission<<endl;
    }

    protected:
    void acceptSalesman(){
        accept();
    }

    void displaySalesman(){
        display();
    }
};

class SalesManager : public Manager, public Salesman{
    public:
    SalesManager()
    {   }
    SalesManager(int id, double salary, double bonus ,double commission):Manager(id,salary, bonus),Salesman(id, salary, commission)
    {   }

    void accept(){
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display(){
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int main(){
    SalesManager sm;
    sm.Manager::accept();
    sm.Manager::display();
    sm.Salesman::accept();
    sm.Salesman::display();
}