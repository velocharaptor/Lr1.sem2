#ifndef LR2_LINKEDLIST_H
#define LR2_LINKEDLIST_H

#include <cstring>
#include <iostream>

using namespace std;

template<class L> class LinkedList{
private:
    typedef struct List{
      L item;
      List* next = nullptr;
      List* pred = nullptr;
    }List;
    List* list_head = nullptr;
    List* list_tail = nullptr;
    size_t size = 0;
public:
    LinkedList(L* items, size_t count): LinkedList(){
        list_head = new List;
        list_tail = new List;
        size = count;
        List* temp;
        List* new_head = list_head;
        for(int i = 0; i < size; i++){
            temp = list_head;
            list_head->item = items[i];
            if(i < size - 1) {
                list_head->next = new List;
                list_head = list_head->next;
                list_head->pred = temp;
            }
        }
        list_tail = list_head;
        list_head = new_head;
    }

    LinkedList(){
      list_head = nullptr;
      size = 0;
    }

    LinkedList(LinkedList<L> const &list){
        list_head = new List;
        list_tail = new List;
        size = list.size;
        List* new_head = list_head;
        List* temp_list = list.list_head;
        List* temp;
        for(int i = 0; i < size; i++){
            temp = list_head;
            list_head->item = temp_list->item;
            if(i < size - 1){
                list_head->next = new List;
                list_head = list_head->next;
                list_head->pred = temp;
                temp_list = temp_list->next;
            }
        }
        list_tail = list_head;
        list_head = new_head;
    }

    ~LinkedList(){
        while(list_head){
            list_tail = list_head->next;
            delete list_head;
            list_head = list_tail;
        }
        //cout << "LinkedList destroy.\n";
    }

    L GetFirst(){
        if(size == 0){
            throw "IndexOutOfRange";
        }
        //cout << "first elem:" << list_head->item << "\n";
        return list_head->item;
    }

    L GetLast(){
        if(size == 0){
            throw "IndexOutOfRange";
        }
        //cout << "last elem:" << list_tail->item << "\n";
        return list_tail->item;
    }

    L Get(size_t index){
        if(size == 0){
            throw "IndexOutOfRange";
        }
        L result;
        if(index == size){
            result = list_tail->item;
        }
        else {
            List *temp = list_head;
            for (int i = 0; i < index; i++) {
                list_head = list_head->next;
            }
            result = list_head->item;
            list_head = temp;
        }
            //cout << "elem[" << index << "]:" << result << "\n";
            return result;
    }

    LinkedList<L> GetSubList(size_t start_index, size_t last_index){
        LinkedList<L> list;
        List* temp = list_head;
        for(size_t i = 0; i < start_index; i++){
            list_head = list_head->next;
        }
        List* temp_list = list.list_head;
       /*for(size_t i = start_index; i < last_index + 1; i++){
            list.list_head->item = list_head->item;
            if(i < last_index) {
                list_head = list_head->next;
                list.list_head->next = new List;
                list.list_head = list.list_head->next;
            }
        }
*/      for(size_t i = start_index; i < last_index + 1; i++){
            list.Append(list_head->item);
            if(i < last_index)
                list_head = list_head->next;

        }
        //list.list_tail = list.list_head;
        //list.list_head = temp_list;
        list_head = temp;
        temp = list.list_head;
        list.size = 0;
        while(list.list_head != nullptr){
            list.list_head = list.list_head->next;
            list.size++;
        }
        list.list_head = temp;
        //cout <<  "Sub list:\n";
        //list.OutputList();
        return list;
    }

    size_t GetLength(){
        return size;
    }

    void Append(L item){
        List* temp = new List;
        temp->pred = list_tail;
        temp->item = item;
        temp->next = nullptr;
        if(list_tail != nullptr){
            list_tail->next = temp;
        }
        if(size == 0)
            list_head = list_tail = temp;
        else
            list_tail = temp;
        size++;
    }

    void PopBack(){
        List* temp = list_tail;
        list_tail = list_tail->pred;
        if(list_tail){
            list_tail->next = nullptr;
        }
        if(temp == list_tail){
            list_tail = nullptr;
        }
        delete temp;
        size--;
    }

    void Set(L item, int index){
        List* temp = list_head;
        for(int i = 0; i < index; i++){
            list_head = list_head->next;
        }
        list_head->item = item;
        list_head = temp;
    }

    void Prepend(L item){
        List* temp = new List;
        temp->next = list_head;
        temp->item = item;
        temp->pred = nullptr;
        if(list_tail == nullptr){
            list_tail = temp;
        }
        if(size == 0)
            list_head = list_tail = temp;
        else
            list_head = temp;
        size++;
    }

    void PopFront(){
        List* temp = list_head;
        list_head = list_head->next;
        if(list_head){
            list_head->pred = nullptr;
        }
        if(temp == list_head){
            list_head = nullptr;
        }
        delete temp;
        size --;
    }

    void InsertAt(L item, size_t index){
        if(index == 0)
            this->Append(item);
        if(index == size)
            this->Prepend(item);
        else {
            List* elem = new List;
            elem->item = item;

            List* temp1 = list_head;
            for (int i = 0; i < index - 1; i++) {
                list_head = list_head->next;
            }
            List* pred_elem = list_head;
            list_head = temp1;

            for (int i = 0; i < index; i++) {
                list_head = list_head->next;
            }
            List* next_elem = list_head;
            list_head = temp1;

            elem->next = next_elem;
            elem->pred = pred_elem;
            pred_elem->next = elem;
            next_elem->pred = elem;
            size++;
        }
    }

    LinkedList<L> Concat(LinkedList<L>* list){
        List* temp = list->list_head;
        while(temp != nullptr){
            Append(temp->item);
            temp = temp->next;
        }

        return *this;
    }

    void swap(int index1, int index2){
        List* tmp = list_head;
        int count=0;
        int min, max;
        if(index1<index2){
            min = index1;
            max = index2;
        }
        else{
            min = index2;
            max = index1;
        }
        int diff = max - min;
        while(min!=count){
            tmp=  tmp->next;
            count++;
        }
        int minValue = tmp->item;
        while(max!=count){
            tmp=  tmp->next;
            count++;
        }
        int maxValue = tmp->item;
        tmp->item = minValue;
        tmp = list_head;
        count =0;
        while(min!=count){
            tmp=  tmp->next;
            count++;
        }
        tmp->item = maxValue;
    }

    void OutputList(){
        List* temp = list_head;
        while(temp){
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

};

#endif
