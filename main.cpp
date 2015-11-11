#include "testing.h"
#include <iostream>

using namespace std;


int main() {
    
    string x = "Bob";
    Message* m = Player_factory(x);
    string message_in = "Hello World"; 
    m->set_string(message_in);

    cout << m->get_string() << endl;

}
