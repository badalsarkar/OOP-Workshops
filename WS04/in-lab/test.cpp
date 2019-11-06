#include <iostream>
using namespace std;

int main(){
    char* name;
    cout<<sizeof(name)<<endl;
    name=new char[10];
    cout<<sizeof(name)<<endl;
    return 0;
} 
