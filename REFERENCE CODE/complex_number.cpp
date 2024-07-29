#include <iostream>
#include <cmath>
using namespace std;

struct Complex{
    double a,b;
    Complex (){a=0;b=0;}
    Complex (double x){a=x;b=0;}
    Complex (double x, double y){a=x;b=y;}
    Complex operator+ (Complex num2){
        return Complex(this->a+num2.a,this->b+num2.b);
    }
    Complex operator- (Complex num2){
        return Complex(this->a-num2.a,this->b-num2.b);
    }
    Complex operator* (Complex num2){
        return Complex(this->a*num2.a-this->b*num2.b,this->b*num2.a+this->a*num2.b);
    }
    Complex operator/ (Complex num2){
        double mod = num2.a*num2.a+num2.b*num2.b;
        return Complex((this->a*num2.a-this->b*num2.b)/mod,(this->b*num2.a+this->a*num2.b)/mod);
    }

};

int main(){
    Complex num1={1,2};
    Complex num2={1,4};
    cout<<(num1+num2).a<<endl;
    cout<<(num1-num2).a<<endl;
    cout<<(num1*num2).a<<endl;
    cout<<(num1/num2).a<<endl;
}