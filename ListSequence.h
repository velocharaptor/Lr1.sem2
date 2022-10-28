#ifndef LR2_LISTSEQUENCE_H
#define LR2_LISTSEQUENCE_H

#include <cstring>
#include <iostream>
#include "LinkedList.h"
#include "Sequence.h"

using namespace std;

template<class L> class ListSequence: public Sequence<L>{
private:
    LinkedList<L>* list;
public:
    ListSequence(L* items, size_t count){
        list = new LinkedList<L>(items, count);
    }

    ListSequence(){
        list = new LinkedList<L>();
    }

    ListSequence(const ListSequence<L> &input_list){
        list = new LinkedList<L>();
        for(int i = 0; i < input_list.GetLength(); i++){
            list->Append(input_list.Get(i));
        }
    }

    ~ListSequence(){
        //list->~LinkedList();
        delete list;
    }

    L GetFirst() const override{
        return list->GetFirst();
    }

    L GetLast() const override{
        return list->GetLast();
    }

    L Get(size_t index) const override{
        return list->Get(index);
    }

    void Append(L item) override{
        list->Append(item);
    }

    void PopBack() override{
        list->PopBack();
    }

    void Prepend(L item) override{
        list->Prepend(item);
    }

    void PopFront() {
        list->PopFront();
    }

    size_t GetLength() const override{
        return list->GetLength();
    }

    ListSequence<L> GetSubListSequence(size_t start_index, size_t last_index) {
        ListSequence<L> new_list;
        LinkedList<L>  buff = list->GetSubList(start_index, last_index);
        for(int i = 0; i < buff.GetLength(); i++){
            new_list.Append(buff.Get(i));
        }
        return new_list;
    }

   /* void Set(L item, size_t index) override{
        list->Set(item, index);
    }*/

    void InsertAt(L item, size_t index) override{
        list->InsertAt(item, index);
    }

    ListSequence<L> Concat(ListSequence<L>* list2){
        LinkedList<L>* temp_list;
        for(int i = 0; i < list2->GetLength(); i++){
            temp_list->Append(list2->Get(i));
        }
        return list->Concat(temp_list);
    }

    void swap(int a, int b) override {
        list->swap(a, b);
    }

    void Print() override{
        list->OutputList();
    }
};

#endif //LR2_LISTSEQUENCE_H
