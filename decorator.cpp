#include <iostream>
#include <string>
using namespace std;
class Phone{
public:
    Phone(){}
    virtual ~Phone() {}
    virtual void ShowDecorate() {}
};

class iPhone : public Phone{
private:
    string m_name;
public:
    iPhone(string name): m_name(name) {}
    ~iPhone() {}
    void ShowDecorate() {
        cout<<m_name<<"Decorate"<<endl;
    }
};

class NokiaPhone : public Phone{
private:
    string m_name;
public:
    NokiaPhone(string name): m_name(name) {}
    ~NokiaPhone(){}
    void ShowDecorate() {
        cout<<m_name<<" Decorate"<<endl;
    }
};

class DecoratorPhone : public Phone {
private:
    Phone *m_phone;
public:
    DecoratorPhone(Phone* phone):m_phone(phone) {}
    virtual void ShowDecorate() {m_phone->ShowDecorate();}
};

class DecoratorPhoneA : public DecoratorPhone{
public:
    DecoratorPhoneA(Phone* phone) : DecoratorPhone(phone) {}
    void ShowDecorate() {
        DecoratorPhone::ShowDecorate();
        AddDecorate();
    }
private:
    void AddDecorate(){
        cout<<"add decorator"<<endl;
    }
};

class DecoratorPhoneB : public DecoratorPhone{
public:
    DecoratorPhoneB(Phone* phone) : DecoratorPhone(phone) {}
    void ShowDecorate() {
        DecoratorPhone::ShowDecorate();
        AddDecorate();
    }
private:
    void AddDecorate(){
        cout<<"add some kind of things"<<endl;
    }
};

int main(){
    Phone* iphone = new NokiaPhone("6300");
    Phone* dpa = new DecoratorPhoneA(iphone);
    Phone* dpb = new DecoratorPhoneB(dpa);
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete iphone;
    return 0;
}