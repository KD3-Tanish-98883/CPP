#include<iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    Date( void ) : day(0), month(0), year(0)
    {   }

    Date(int day, int month, int year):day(day),month(month),year(year)
    {   }
    
    void accept(){
        cout<<"Enter date in day/month/year"<<endl;
        cin>>day>>month>>year;
    }

    void display(){
        cout<<day<<" / "<<month<<" / "<<year<<" / " <<endl;
    }
};

class Person{
    private:
    string name;
    string address;
    Date birthdate;
    
    public:
    Person( void ): name(""), address("")
    {   }

    Person(string name, string address, Date birthdate): name(name), address(address), birthdate(birthdate)
    {    }

    void accept(){
        cout<<"Enter the name"<<endl;
        cin>>name;
        cout<<"Enter address"<<endl;
        cin>>address;
        cout<<"Enter birthdate"<<endl;
        this->birthdate.accept();
    }

    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl;
        cout<<"Birth date : ";
        this->birthdate.display();
    }
};

class Student{
    int id;
    int marks;
    string course;
    Date joiningDate;
    Date endDate;

    public:
    Student( void ): id(0), marks(0), course("")
    {   }

    Student(int id, int marks, string course, int day, int month, int year, int day1, int month1, int year1):id(id), marks(marks), course(course), joiningDate(day,month,year), endDate(day1,month1,year1)
    {   }

    void accept(){
        cout<<"Enter Student id"<<endl;
        cin>>id;
        cout<<"Enter Student marks"<<endl;
        cin>>marks;
        cout<<"Enter Student course"<<endl;
        cin>>course;
        cout<<"Enter joining date"<<endl;
        this->joiningDate.accept();
        cout<<"Enter end date"<<endl;
        this->endDate.accept();
    }

    void display(){
        cout<<"Student Id: "<<id<<endl;
        cout<<"Student Marks: "<<marks<<endl;
        cout<<"Student Course: "<<course<<endl;
        cout<<"Joining Date: ";
        this->joiningDate.display();
        cout<<"Ending Date: ";
        this->endDate.display();
    }
};

int main(){
    // Person p;
    // p.accept();
    // p.display();
    Student stu(23, 543, "Cdac", 23,64,65 , 76,43,54 );
    // stu.accept();
    stu.display();
}