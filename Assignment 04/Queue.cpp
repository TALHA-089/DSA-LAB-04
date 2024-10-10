#pragma Once
#include "Queue.h"

template<class Type>
Queue<Type>::Queue(int maxSize){
    front = -1;
    rear = -1;
    this->maxSize = maxSize;
    queue = new Type[maxSize];
}

template<class Type>
Queue<Type>::~Queue(){
    delete [] queue;
}


template<class Type>
bool Queue<Type>::isEmpty(){
    return (front == -1 && rear == -1);
}

template<class Type>
bool Queue<Type>::isFull(){
    return (front == (rear + 1) % maxSize);
}

template<class Type>
void Queue<Type>::Insert(Type item){
    if(isFull()){
        cout << "\nQueue Overflow!\n";
        return;
    }else{
        if(front == -1 && rear == -1){
            front++;
            rear++;
            queue[rear] = item;
        }else{
            rear = (rear + 1) % maxSize;
            queue[rear] = item;
        }
    }
}

template<class Type>
void Queue<Type>::Remove(Type &item){
    if(isEmpty()){
        cout << "\nQueue Underflow!\n";
        return;
    }else{
        if(front == rear){
            item = queue[front];
            front = -1;
            rear = -1;
        }else{
            item = queue[front];
            front = (front + 1) % maxSize;
        }
    }
}
