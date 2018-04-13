#include <string>
#include <iostream>
using namespace std;
class Image{
protected:
    string m_imageName;
public:
    Image(string name):m_imageName(name){
    }
    virtual ~Image(){}

    virtual void Show(){
        
    }

};

class BigImage : public Image{
public:
    BigImage(string name):Image(name){}
    ~BigImage(){}
    void Show(){
        cout<<"big image"<<endl;
    }
};

class BigImageProxy : public Image{
private:
    BigImage* m_bigImage;
public:
    BigImageProxy(string name):Image(name){}
    ~BigImageProxy(){delete m_bigImage;}
    void Show(){
        if(m_bigImage == NULL){
            m_bigImage = new BigImage(m_imageName);
        }
        m_bigImage->Show();
    }
};
//client
int main(){
   Image* image = new BigImage("proxy");
   image->Show();
   delete image;
   return 0;
}