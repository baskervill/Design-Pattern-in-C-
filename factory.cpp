#include <iostream>
//easy factory

enum CTYPE {COREA, COREB};
class SingleCore{
public:
    virtual void Show() = 0;
};

class SingleCoreA : public SingleCore{
public:
    void Show(){
        std::cout<<"SingleCore A"<<std::endl;
    }
};

class SingleCoreB : public SingleCore{
public:
    void Show(){
        std::cout<<"SingleCore B"<<std::endl;
    }
};

class Factory{
public:
    SingleCore* CreateSingleCore(enum CTYPE ctype){
        if(ctype == COREA){
            return new SingleCoreA();
        }
        else if(ctype == COREB){
            return new SingleCoreB();
        }
        else return NULL;
    }
};