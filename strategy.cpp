#include <iostream>

class ReplaceAlgorithm{
public:
    virtual void Replace() = 0;
};

class LRU_ReplaceAlgorithm : public ReplaceAlgorithm{
public:
    void Replace() {
        std::cout<<"Least Recently Used replace algorithm"<<std::endl;
    }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm{
public:
    void Replace() {
        std::cout<<"First in First out replace algorithm"<<std::endl;
    }
};

class Random_ReplaceAlgorithm : public ReplaceAlgorithm{
public:
    void Replace() {
        std::cout<<"Random replace algorithm"<<std::endl;
    }
};

class Cache {
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(ReplaceAlgorithm *ra) {m_ra = ra;}
    ~Cache() {delete m_ra;}
    void Replace() {m_ra->Replace();}
};