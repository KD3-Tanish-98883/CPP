#include<iostream>
using namespace std;

class Product{
    protected:
    int id;
    string title;
    double price;

    public:
    Product(): id(0), title(""), price(0.0)
    {   }

    Product(int id, string title, double price): id(id), title(title), price(price)
    {   }

    virtual void acceptRecord(){
        cout<<"Id : "<<endl;
        cin>>id;
        cout<<"Name : "<<endl;
        cin>>title;
        cout<<"price"<<endl;
        cin>>price;
    }

    virtual void displayRecord(){
        cout<<"Id : "<<id<<endl;
        cout<<"Name : "<<title<<endl;
        cout<<"Price : "<<price<<endl; 
    }

    virtual double calculateBill() = 0;
};

class Book : public Product{
    private:
    string author;

    public:
    void acceptRecord(){
        Product::acceptRecord();
        cout<<"Author : "<<endl;
        cin>>author;
    }

    void displayRecord(){
        Product::displayRecord();
        cout<<"Author : "<<author<<endl;
    }

    double calculateBill(){
        return price-(price*0.1); 
    }

};

class Tape :  public Product{
    private:
    string artist;

    public:
    void acceptRecord(){
        Product::acceptRecord();
        cout<<"Artist : "<<endl;
        cin>>artist;
    }

    void displayRecord(){
        Product::displayRecord();
        cout<<"Artist : "<<artist<<endl;
    }

    double calculateBill(){
        return price -(price*0.05); 
    }
};



int menu(){
    int choice;
    cout<<"Enter 3 products"<<endl;
    cout<<"1. Book"<<endl;
    cout<<"2. Tape"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    Product *product[3];
    int i = 0;
    double total= 0;

    //while((choice=::menu())!=0)
    for(int i=0; i<3; i++)
    {
    switch (::menu())
    {
        case 1:{
            product[i]= new Book();
            product[i]->acceptRecord();
            //product[i]->displayRecord();
            total += product[i]->calculateBill();
        }
        break;
    
        case 2:{
            product[i]= new Tape();
            product[i]->acceptRecord();
            //product[i]->displayRecord();
            total += product[i]->calculateBill();
        }
        break;
        default:
        cout<<"Invalid Choice"<<endl;
    }

    cout<<"Total bill : "<<total<<endl;
    }
    for(i=0;i<3;i++){
        delete[] product[i];
        product[i] = NULL;
    }
    return 0;
}
