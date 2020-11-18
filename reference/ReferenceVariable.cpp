#include<iostream>
using namespace std;

int main(){
    int first = 5;
    int& ref_first = first; // & >> type 을 주소의 성격으로 바꾼다고 생각하자! 
    cout << "Value of first: " << first << ", address: " << &first << endl; // 5, address: 0x7fffffffdb7c

    cout << "Value of first reference: " << ref_first << ", address: " << &ref_first << endl;  // 5, address: 0x7fffffffdb7c

    ref_first = 6;
    cout << "Value of first: " << first << ", address: " << &first << endl; // 6, address: 0x7fffffffdb7c

    double second = 11.7;
    double& ref_second = second;  
 
    cout << "Value of second: " << second << endl; // 11.7

    cout << "Value of second reference: " << ref_second << endl; //11.7
    cout << "Value of second reference: " << &ref_second << endl;  //0x7fffffffdb7c
    
    cout << "size of first " << sizeof(&ref_first) <<endl;  // size of first : 4 , size of first address : 8
    cout << "size of second " << sizeof(&ref_second) << endl; // size of second : 8 , size of second address : 8  
    return 0;
}

//sizeof >> 크기 , size() >> string length