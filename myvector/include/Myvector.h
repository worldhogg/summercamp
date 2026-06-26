#include <iostream>
#pragma once
template <class T>
class Myvector{
private:
    T*data;
    int size;
    int capacity;
public:
    Myvector(){
        capacity = 5;
        size = 0;
        data = new T[capacity];
    }
    ~Myvector(){
        delete[]data;
        data = nullptr;
    }
    int getsize()const{
        return this->size;
    }
    int getcapacity()const{
        return this->capacity;
    }

};
    // void push_back(T value){
    //     if (this->size <= this->capacity)
    //     data[size + 1] = value;
    //     size++;
    // }
    //     else{
    //         capacity *= 2;
    //         newdata = new T(capacity);
    //         for (int i = 0; i < size;i++){
    //             newdata[i] = data[i];
    //         }
    //         newdata[size + 1] = value;
    //         delete[]data;
    //         newdata = data;
    //         size++;
    //     }
