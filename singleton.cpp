class Singleton{
public:
    static Singleton* GetInstance();
private:
    Singleton() {}
    static Singleton *singleton;
};

Singleton* Singleton::singleton = NULL;
Singleton* Singleton::GetInstance(){
    if(singleton == NULL)
        singleton = new Singleton();
    return singleton;
}
