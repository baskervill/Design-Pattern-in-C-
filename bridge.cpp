#include <iostream>
using namespace std;
class OS{
public:
    virtual void InstallOS_Imp(){
    }
};

class WindowsOS : public OS{
public:
    void InstallOS_Imp(){
        cout<<"Install Windows Operating System"<<endl;
    }
};

class MacOS : public OS{
public:
    void InstallOS_Imp(){
        cout<<"Install Mac Operating System"<<endl;
    }
};

class LinuxOS : public OS{
public:
    void InstallOS_Imp(){
        cout<<"Install Linux Operating System"<<endl;
    }
};

class Computer{
public:
    virtual void InstallOS(OS *os){
    }
};

class DellComputer : public Computer{
public:
    void InstallOS(OS *os){
        os->InstallOS_Imp();
    }
};

class AppleComputer : public Computer{
public:
    void InstallOS(OS *os){
        os->InstallOS_Imp();
    }
};

class HPComputer : public Computer{
public:
    void InstallOS(OS *os){
        os->InstallOS_Imp();
    }
};

//client 

int main(){
    OS* windows = new WindowsOS();
    Computer* apple = new AppleComputer();
    apple->InstallOS(windows);
    return 0;
}