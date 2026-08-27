#include<iostream>
using namespace std;

class Cylinder
{
    private:
    static double PI;
    double height;
    double radius;

    public:
    Cylinder():radius(0) , height(0){}

    Cylinder(double radius, double height): radius(radius), height(height){}

    double getRadius(){
        return this->radius;
    }
    void setRadius(double radius){
        this->radius=radius;
    }
    double getHeight(){
        return this->height;
    }
    void setHeight(double height){
        this->height=height;
    }
    void calculateVolume(){
        cout<<"Volume = "<<PI*radius*radius*height<<endl;
    }
};

double Cylinder :: PI = 3.14;

int main(){

    Cylinder c1;
    c1.calculateVolume();
    Cylinder c2(2.0,3.0);
    c2.calculateVolume();
    c1.setRadius(4.0);
    c1.setHeight(3.0);
    c1.calculateVolume();
}
