#include "p12_controller.h"

#define BAUD 9600
#define MAX_LENGHT 1024

std::string received_msg;
json r_msg, s_msg;

p12_controller::p12_controller()
{
    std::string input;
    std::cout << "COM port : ";
    std::cin >> input;
    arduino = new SerialPort(input.c_str(), BAUD);

    if(!arduino->isConnected())
    {
        std::cerr << "Unable to connect" << std::endl;
        exit(1);
    }
}

p12_controller::~p12_controller()
{}

bool p12_controller::send()
{
    json payload;
}

bool p12_controller::receive(SerialPort * arduino, std::string &msg)
{
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear();
    while(msg.back()!='\n') {
        if(msg.size()>MSG_MAX_SIZE) {
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }

    msg.pop_back();
    return true;
}