#include "GPIOClass.h"


using namespace std;

GPIOClass::GPIOClass(string gnum = "4")
{
    this->gpionum = gnum;  //Instatiate GPIOClass object for GPIO pin number "gnum".
							//Default pin 4
}

void GPIOClass::export_gpio()
{
    string export_str = "/sys/class/gpio/export";//Sysfs for GPIO location
    ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    if (exportgpio.fail()){
        cerr << " OPERATION FAILED: Unable to export GPIO"<< this->gpionum <<" ."<< endl; //Changed 'cout' to 'cerr'
        exit(1);
    }

    exportgpio << this->gpionum ; //write GPIO number to export
    exportgpio.close(); //close export file
}

void GPIOClass::unexport_gpio()
{
    string unexport_str = "/sys/class/gpio/unexport";
    ofstream unexportgpio(unexport_str.c_str()); //Open unexport file
    if (unexportgpio.fail()){
        cerr << " OPERATION FAILED: Unable to unexport GPIO"<< this->gpionum <<" ."<< endl;
        exit(1);
    }

    unexportgpio << this->gpionum ; //write GPIO number to unexport
    unexportgpio.close(); //close unexport file
}

void GPIOClass::setdir_gpio(string dir)
{

    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio.fail()){
            cerr << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            exit(1);
        }

        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
		cout << "Direction for GPIO" << this->gpionum << " is:" << dir << endl;

}

void GPIOClass::setval_gpio(string val)
{
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio.fail()){
            cerr << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            exit(1);
        }

        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file
}

void GPIOClass::getval_gpio(string &val){

    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio.fail()){
        cerr << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        exit(1);
            }

    getvalgpio >> val ;  //read gpio value

    if(val != "0")
        val = "1";
    else
        val = "0";


    getvalgpio.close(); //close the value file

	//expand method to output value as an integer (string to int conversion.. Consider sstream)
}

string GPIOClass::get_gpionum(){

return this->gpionum;

}

GPIOClass::~GPIOClass(){
	this->unexport_gpio();
}
