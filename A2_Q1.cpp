#include <iostream>
using namespace std;

class VolumeOfBox{

    private:
    double length;
    double breadth;
    double height;

    public:
    VolumeOfBox( void ){
        this->length = 10.0;
        this->breadth= 5.0;
        this->height = 4.0;
        //double vol = length*breadth*height;
        //cout<<"Volume of Box = "<<vol<<endl;
    }

    VolumeOfBox( double sameValue ){
        this->length = sameValue;
        this->breadth = sameValue;
        this->height = sameValue;
    }

    VolumeOfBox( double length , double breadth, double height ){
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    void volume(){ // double length , double breadth, double height
        double vol = length*breadth*height;
        cout<<"Volume of Box = "<<vol<<endl;
    }

};

int main(){

    double sameValue;
    double length;
    double breadth;
    double height;
    int choice;

    cout<<"Enter choice"<<endl;
    cout<<"Volume by default values"<<endl;
    cout<<"Volume with same value"<<endl;
    cout<<"Volume with different values"<<endl;
    cin>>choice;

        switch (choice)
        {
        case 1:
        {
            VolumeOfBox();
            VolumeOfBox vd;
            vd.volume();
            break;
        }
        case 2:
        {
            cout<<"Enter the same value"<<endl;
            cin>>sameValue;
            VolumeOfBox(sameValue);
            VolumeOfBox vs;
            vs.volume();
            break;
        }
        case 3:
        {
            cout<<"Enter the value of length , breadth and height"<<endl;
            cin>>length;
            cin>>breadth;
            cin>>height;
            VolumeOfBox(length,breadth,height);
            VolumeOfBox v3;
            v3.volume();
            break;
        }
        default:
        {
            cout<<"Invalid choice";
        }
        }

    return 0;
}
