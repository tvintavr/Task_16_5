#include <iostream>
#include <climits>
#include <iomanip>
#include <vector>
#include <limits>


int main() {

char del;
int hour;
int minute;
int intemp;
int outtemp;
int movement;
int innerLight;
while (true) {
    do {
        std::string buffer;
        std::cout<<"Input correct time (HH:MM): ";
        std::cin>>buffer;
        std::stringstream buffer_stream(buffer);
        buffer_stream>>hour>>del>>minute;
    } while (!(hour>=0 && hour<=23 && minute >=0 && minute <=59 && del==':'));
    do {
        std::cout<<"Input correct inner temperature (C): ";
        std::cin>>intemp;
        if (std::cin.fail()) {
            intemp=-100;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!(intemp>-50 && intemp<50));
    do {
        std::cout<<"Input correct outer temperature (C): ";
        std::cin>>outtemp;
        if (std::cin.fail()) {
            outtemp=-100;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!(outtemp>-50 && outtemp<50));
    do {
        std::cout<<"Input movement (1 or 0): ";
        std::cin>>movement;
        if (std::cin.fail()) {
            movement=-1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!(movement==1 || movement==0));
    do {
        std::cout<<"Input inner light (1 or 0): ";
        std::cin>>innerLight;
        if (std::cin.fail()) {
            innerLight=-1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!(innerLight==1 || innerLight==0));

    if (outtemp<0) {
        std::cout<<"Water heating system is on"<<"\n";
    } else if (outtemp>5) {
        std::cout<<"Water heating system is off"<<"\n";
    } else {
        std::cout<<"Water heating system is not regulated"<<"\n";
    }

    if ((hour>=16 && hour<=23 || hour>=0 && hour <5) && movement==1) {
        std::cout<<"Outdoor lighting is on"<<"\n";
    } else {
        std::cout<<"Outdoor lighting is off"<<"\n";
    }

    if (intemp<22) {
        std::cout<<"Heating system is on"<<"\n";
    } else if (intemp>=25) {
        std::cout<<"Heating system is off"<<"\n";
    } else {
        std::cout<<"Heating system is not regulated"<<"\n";
    }

    if (intemp>=30) {
        std::cout<<"Cooling system is on"<<"\n";
    } else if (intemp<=25) {
        std::cout<<"Cooling system is off"<<"\n";
    } else {
        std::cout<<"Cooling system is not regulated"<<"\n";
    }

    if ((hour>=16 && hour<20) && innerLight==1) {
        std::cout<<"Interior lighting is on"<<"\n";
        float lightTemp=5000-(hour-16)*575-minute*9.683333;
        std::cout<<"Light temperature is: "<<lightTemp<<"\n";
    } else {
        std::cout<<"Interior lighting is off"<<"\n";
    }











}




  
  
  

  
}