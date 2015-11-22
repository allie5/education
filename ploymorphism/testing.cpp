#include <iostream>
#include "testing.h"

using namespace std;

static void mess();

class Email : public Message {
    string message;
    string sender;
    public:

    Email(string sender_in) {
        sender = sender_in;
    }

    virtual void set_string(string message_in) {
        message = message_in;
    }

    virtual string get_string();
    virtual ~Email() {}

};

string Email::get_string() {
        mess();
        cout << "Sent by " << sender << endl;
        return message;
    }

static void mess() {

    cout << "Message Sent" << endl;
}

Message* Player_factory(string sender) {

    cout << "Message Created: " << endl;
    return new Email(sender);
}
