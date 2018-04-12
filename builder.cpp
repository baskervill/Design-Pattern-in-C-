#include <iostream>
using namespace std;
class Builder{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildLeftArm() = 0;
    virtual void BuildRightArm() = 0;
    virtual void BuildLeftLeg() = 0;
    virtual void BuildRightLeg() = 0;
};

class FatBuilder : public Builder{
    void BuildHead(){
        
    }
    void BuildBody(){

    }
    void BuildLeftArm(){

    }
    void BuildRightArm(){

    }
    void BuildLeftLeg(){

    }
    void BuildRightLeg(){

    }
};

class ThinBuilder : public Builder{
    void BuildHead(){
        
    }
    void BuildBody(){

    }
    void BuildLeftArm(){

    }
    void BuildRightArm(){

    }
    void BuildLeftLeg(){
        
    }
    void BuildRightLeg(){

    }
};

class Director{
public:
    Builder* m_bd;
    Director(Builder* bd){
        this->m_bd = bd;
    }

    void create(){
        m_bd->BuildBody();
        m_bd->BuildHead();
        m_bd->BuildLeftArm();
        m_bd->BuildLeftLeg();
        m_bd->BuildRightArm();
        m_bd->BuildRightLeg();
    }
};

int main(){
    ThinBuilder* tbd = new ThinBuilder();
    FatBuilder* fbd = new FatBuilder();
    Director* director1 = new Director(tbd);;
    director1->create();
    Director* director2 = new Director(fbd);
    director2->create();
    return 0;

}
