#include<iostream>
#include<typeinfo>
using namespace std;
class employee{
      private:
      int id;
      double salary;

      public:
      employee(){

      }
      employee(int id,double salary):id(id),salary(salary){

      }
      void setId(int Id){
           this->id=Id;
      }
      int getId(){
            return this->id;
      }
      void setSalary(double salary){
            this->salary=salary;
      }
      double getSalary(){
            return this->salary;
      }
      virtual void accept(){
            cout<<"enter id : ";
            cin>>this->id;
            cout<<"enter salary : ";
            cin>>this->salary;
      }
      virtual void display(){
            cout<<"ID : "<<this->id<<" Salary : "<<this->salary<<" ";
      }
};
class manager:virtual public employee{
    protected:
    double bonus;

    public:
    manager(){

    }
    manager(int id ,double salary, double bonus):employee(id,salary),bonus(bonus){
        
    }
    void setBonus(double bonus){
         this->bonus=bonus;
    }
    double getBonus(){
      return this->bonus;
    }
    void accept(){
      employee::accept();
      acceptManager();
    }
    void display(){
      employee::display();
      displayManager();
    }

    protected:
    void acceptManager(){
      cout<<"enter bonus : ";
      cin>>this->bonus;
      //cout<<endl;
    }
    void displayManager(){
      cout<<"Bonus : "<<this->bonus<<endl;
    }
};
class salesman:virtual public employee{
    protected:
    double commision;

    public:
    salesman(){

    }
    salesman(int id ,double salary, double commision):employee(id,salary),commision(commision){
        
    }
    void setcommision(double commision){
         this->commision=commision;
    }
    double getcommision(){
      return this->commision;
    }
    void accept(){
      employee::accept();
      acceptSalesman();
    }
    void display(){
      employee::display();
      displaySalesman();
    }
    
    protected:
    void acceptSalesman(){
      cout<<"enter commision : ";
      cin>>this->commision;
      //cout<<endl;
    }
    void displaySalesman(){
      cout<<" Commision : "<<this->commision<<endl;
    }
};
class salesManager:public manager,public salesman{
    public:
    salesManager(){

    }
    salesManager(int id,double salary,double bonus,double commision):manager(id,salary,bonus),salesman(id,salary,commision){

    }
    void accept(){
      //employee::accept(); this is amguity. solved using virtual
      employee::accept();
      manager::acceptManager();
      salesman::acceptSalesman();
    }
    void display(){
      employee::display();
      manager::displayManager();
      salesman::displaySalesman();
    }
};

int menu(){
    cout<<"0. Exit"<<endl;
    cout<<"1. Add Manager"<<endl;
    cout<<"2. Add Salesman"<<endl;
    cout<<"3. Add Salesmanager"<<endl;
    cout<<"4. Display the count of all employees with respect to designation"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman"<<endl;
    cout<<"7. Display All SalesManagers"<<endl;
    int x;
    cin>>x;
    return x;
}
int main(){
    employee* ptr[5];
    int choice;
    int i=0;
    while((choice=menu())!=0){
        switch(choice){
            case 1:
              if(i<5){
                ptr[i]=new manager;
                ptr[i]->accept();
                i++;
              }
              else{
                cout<<"limit exceeds ";
              }
              break;

            case 2:
              if(i<5){
              ptr[i]=new salesman;
              ptr[i]->accept();
              i++;
              }
              else{
                cout<<"limit exceeds ";
              }
              break;

            case 3:
              if(i<5){
              ptr[i]=new salesManager;
              ptr[i]->accept();
              i++;
              }
              else{
              cout<<"limit exceeds ";
              }
              break;

            case 4:{
              int m=0;
              int s=0;
              int sm=0;
              for(int j=0;j<i;j++){
                  if(typeid(*ptr[j])==typeid(manager)){
                    m++;
                  }
                  else if(typeid(*ptr[j])==typeid(salesman)){
                    s++;
                  }
                  else if(typeid(*ptr[j])==typeid(salesManager)){
                    sm++;
                  }
              }
              cout<<m<<" managers"<<endl;
              cout<<s<<" salesman"<<endl;
              cout<<sm<<" salesmanager"<<endl;
              break;
            }
              
            case 5:
              for(int j=0;j<i;j++){
                if(ptr[j]!=nullptr && typeid(*ptr[j])==typeid(manager)){
                  ptr[j]->display();
                }
              }
              break;

            case 6:
              for(int j=0;j<i;j++){
                if(ptr[j]!=nullptr && typeid(*ptr[j])==typeid(salesman)){
                  ptr[j]->display();
                }
              }
              break;

            case 7:
              for(int j=0;j<i;j++){
                if(ptr[j]!=nullptr && typeid(*ptr[j])==typeid(salesManager)){
                  ptr[j]->display();
                }
              }
              break;
        }
    }
}