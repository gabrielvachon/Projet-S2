#ifndef P12_CONTROLLER
#define P12_CONTROLLER

#include "json.hpp"
#include "serial\SerialPort.hpp"
using namespace std;
using json = nlohmann::json;

#define BAUD 9600
#define MSG_MAX_SIZE 1024

class p12_controller
{
private:
    SerialPort * arduino;
    uint8_t com;

public:
    p12_controller();
    ~p12_controller();
    uint8_t init();
    bool send();
    bool receive(SerialPort * arduino, string &msg);
    //SerialPort * arduino;
};

#endif