#ifndef LR2_ARRAYSEQUENCE_H
#define LR2_ARRAYSEQUENCE_H

#include <cstring>
#include <iostream>
#include "DynamicArray.h"
#include "Sequence.h"

using namespace std;


template<class A> class ArraySequence: public Sequence<A>{
private:
    DynamicArray<A>* array;
public:
    ArraySequence(A* input_arr, size_t count){
        array = new DynamicArray<A>(input_arr, count);
    }

    explicit ArraySequence(size_t count){
        array = new DynamicArray<A>(count);
    }

    ArraySequence(ArraySequence<A> &input_arr){
        array = new DynamicArray<A>(input_arr.GetLength());
        for(int i = 0; i < input_arr.GetLength(); i++){
            array->Set(i, input_arr.Get(i));
        }
    }

    ~ArraySequence(){
        //array->~DynamicArray();
        delete array;
    }

    A Get(size_t index) const override{
        return array->Get(index);
    }

    size_t GetLength() const override{
        return array->GetLength();
    }

    A GetFirst() const override{
        return array->Get(0);
    }

    A GetLast() const override{
        return array->Get(array->GetLength() - 1);
    }

    /*void Set(A value, size_t index) override{
        array->set(index, value);
    }*/

    void Resize(size_t new_size){
        array->Resize(new_size);
    }

    void Append(A item) override{
        array->Resize(array->GetLength() + 1);
        array->set(item, array->GetLength() - 1);
    }

    void PopBack() override{
        array->PopBack();
    }

    void Prepend(A item) override{
        array->Resize(array->GetLength() + 1);
        for(int i = array->GetLength() - 1; i > 0; i--){
            A temp = array->Get(i);
            array->set(array->Get(i-1), i);
            array->set(temp, i - 1);
        }
        array->set(item, 0);
    }

    ArraySequence<A> GetSubListSequence(size_t start_index, size_t last_index) {
        ArraySequence<A> sub_arr(0);
        for(int i = start_index; i < last_index+1; i++){
            sub_arr.Append(array->Get(i));
        }
        return sub_arr;
    }

    void InsertAt(A item, size_t index) override{
        array->set(item, index);
    }

    void swap(int a, int b) override {
        int a_it = a, b_it = b;
        A a_val = Get(a_it);
        A b_val = Get(b_it);
        InsertAt(a_val, b_it);
        InsertAt(b_val, a_it);
    }

    void Print() override{
        array->OutputArray();
    }
};

#endif //LR2_ARRAYSEQUENCE_H
