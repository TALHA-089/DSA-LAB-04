#pragma Once
#include <iostream>
#include <sstream>

using namespace std;

template<class Type>
class Queue{
    
    private:
    int front;
    int rear;
    int maxSize;
    Type *queue;
    
    public:

    Queue(int maxSize);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void Insert(Type item);
    void Remove(Type &item);

};