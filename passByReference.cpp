#include <iostream>
#include <string>

using namespace std;


string name = "5";

string& get_name() {
    return name;
}

int main() {
    cout << "Hello" << endl;
    cout << get_name() << endl;
    get_name() = "Allen";
    cout << get_name() << endl;
} 
