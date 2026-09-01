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

    virtual void accept(){
        cout<<"Enter Employee Id : "<<endl;
        cin>>id;
        cout<<"Enter Employee Salary : "<<endl;
        cin>>salary;
    }

   virtual void display(){
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
        acceptManager();
    }

    void display(){
        Employee::display();
        displayManager();
    }

    protected:
    void acceptManager(){
        Employee::accept();
        cout<<"Enter Bonus : "<<endl;
        cin>>bonus;
    }

    void displayManager(){
        
        cout<<"Bonus : "<<bonus<<endl;
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

    virtual void accept(){
        Employee::accept();
        acceptSalesman();
    }

    virtual void display(){
        Employee::display();
        displaySalesman();
    }

    protected:
    void acceptSalesman(){
        cout<<"Enter the commission : "<<endl;
        cin>>commission;
    }

    void displaySalesman(){
        cout<<"Commission : "<<commission<<endl;
    }
};

class SalesManager : public Manager, public Salesman{
    public:
    SalesManager()
    {   }
    SalesManager(int id, double salary, double bonus ,double commission):Manager(id,salary, bonus),Salesman(id, salary, commission)
    {   }

    void accept(){
        //Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display(){
        //Employee::accept();
        Manager::display();
        Salesman::display();
    }
};

int menuList(){
    int choice;
    cout<<"1. Add Manager "<<endl;
    cout<<"2. Add Salesman "<<endl;
    cout<<"3. Add Salesmanager "<<endl;
    cout<<"4. Display the count of all employees with respect to designation"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman"<<endl;
    cout<<"7. Display All SalesManagers"<<endl;
}

int main(){

}