#include<iostream>
using namespace std;

int max(int, int); 
int main(){
    int first = 100, second = 200, result;
    result = max(first, second);
    cout << "Max value is: " << result << endl;
    cout << "Max value is: " << max(second, first) << endl;
    return 0;
}

int max(int num_first, int num_second){
    int result;
    if (num_first > num_second) result = num_first;
    else result = num_second;
    return result;
}