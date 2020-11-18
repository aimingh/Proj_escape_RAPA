#include<iostream>
using namespace std;

int main(){
    int var = 20;                     // 변수 값 지정
    int * ptr_first;                  // 변수 ptr_first 포인터 데이터 타입으로 선언, 주소를 연결 
    ptr_first = &var;                 // 변수 ptr_first에 var의 주소참조가 지정됨 
    cout << "var variable: " << var << ", address: " << &var << endl; 
    // var : 20 (변수 값 출력), &var : 0x7fffffffdb9c (var의 주소)

    cout << "ptr_first variable: "<< ptr_first << ", address: "<< &ptr_first << endl;
    // ptr_first : 0x7fffffffdb9c > &var 출력 (var의 주소), &ptr_first : 0x7fffffffdba0 (변수 ptr_first 의 주소)

    cout << "Value of *ptr_first variable: " << *ptr_first << ", address " << &(*ptr_first);
    // *ptr_first: 20 (변수 ptr_first의 값 > &var의 주소에 저장된 값 > var의 값) , 
    // &(*ptr_first): 0x7fffffffdb9c (*ptr_first의 값의 주소를 출력 >> var의 주소 출력 )
    return 0;
}