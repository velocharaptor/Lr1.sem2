#ifndef LR2_DYNAMICARRAY_H
#define LR2_DYNAMICARRAY_H

#include <cstring>
#include <iostream>

using namespace std;

template<class T> class DynamicArray{
private:
    T* arr = nullptr;
    size_t size = 0;
public:
    DynamicArray(T* input_arr, size_t count):DynamicArray(count){
        //size = count;
        //arr = new T[size];
        for (int i = 0; i < count/*size*/; i++) {
            arr[i] = input_arr[i];
        }
    }

    explicit DynamicArray(size_t count){
        size = count;
        arr = new T[size];
    }

    DynamicArray(DynamicArray<T> const &input_arr){
        size = input_arr.size;
        arr = new T[size];
        for(int i = 0; i < size; i++){
            arr[i] = input_arr.arr[i];
        }
    }

    ~DynamicArray(){
        delete[] arr;
    }

    T Get(size_t index){
        return arr[index];
    }

    T GetLength(){
        return size;
    }

    void PopBack(){
        size--;
    }
    //фикс зис
    void set(T value, size_t index){
            arr[index] = value;
    }

    void Resize(size_t newSize){
        T* new_arr = new T[size];
        for(int i = 0; i < size; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new T[newSize];
        T k = 0;
        if(newSize > size) {
            for (int i = 0; i < size; i++) {
                arr[i] = new_arr[i];
            }
            for (int i = size; i < newSize; i++) {
                arr[i] = k;
            }
        }
        else{
            for (int i = 0; i < newSize; i++) {
                arr[i] = new_arr[i];
            }
        }
        size = newSize;
        delete[] new_arr;
    }

    void OutputArray(){
        //cout << "Output array:\n";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

#endif
