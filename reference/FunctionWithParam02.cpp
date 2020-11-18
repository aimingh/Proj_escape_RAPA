#include"under/FunctionOther02.cpp"
extern int max();

int max(int, int);

int main(){
    int first, second, result;

    cout <<"input first: ";
    cin >> first;

    cout <<"input second: ";
    cin >> second;

    result = max(first, second);
    cout << "Max value is: " << result << endl;
    cout << "Max value is: " << max(second, first) << endl;
    return 0;
}