#include <string>

class Message {

std::string message;

public:
    virtual std::string get_string() = 0;
    virtual void set_string(std::string x) = 0;
    virtual ~Message() {}

};

Message* Player_factory(std::string x);


