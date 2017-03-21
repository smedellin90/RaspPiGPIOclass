#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>//instead of unix based windows for clocks. Change back when running code on Raspberry Pi

using namespace std;

class GPIOClass{
public:
    GPIOClass(string x); // creates a GPIO object that controls GPIOx, where x is passed to this constructor.. Also default constructor (pin 4)
	~GPIOClass();//Destructor that unexports the selected pins by default
    void export_gpio(); // exports GPIO
    void unexport_gpio(); // unexport GPIO
    void setdir_gpio(string dir); // Set GPIO Direction
    void setval_gpio(string val); // Set GPIO Value (Output pins)
    void getval_gpio(string &val); // Get GPIO Value (input/ output pins)
    string get_gpionum(); // return the GPIO number associated with the instance of an object
private:
    string gpionum; // GPIO number associated with the instance of an object
};

#endif
