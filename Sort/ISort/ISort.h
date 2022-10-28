#ifndef LR2_ISORT_H
#define LR2_ISORT_H

#include <iostream>
#include <cstring>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"

using namespace std;

template<class R, class T> class ISort{
private:
    static void bQuickSort(T* data, int low, int high){
        int i = low;
        int j = high;
        R pivot = (data->Get(i) + data->Get(j))/2;
        while (i <= j){
            while (pivot > data->Get(i))
                i++;
            while (data->Get(j) > pivot)
                j--;
            if (i <= j){
                data->swap(i, j);
                i++;
                j--;
            }
        }
        if (j > low)
            bQuickSort(data, low, j);
        if (i < high)
            bQuickSort(data, i, high);
    }
public:
  /* bool cmp(int& x1, int& x2){
        return x1 > x2;
    }*/

    static void QuickSort(T* data){
        bQuickSort(data, 0, data->GetLength()-1);
    }

    static void ShellSort(T *data) {
        int n = data->GetLength();
        int d = n;
        d = d/2;
        while (d > 0) {
            for (int i = 0; i < n-d; i++) {
                int j = i;
                while (j >= 0 && data->Get(j) > data->Get(j+d)){
                    data->swap(j, j+d);
                    j--;
                }
            }
            d=d/2;
        }
    }

    static void InsertionSort(T* data){
        for(int i = 1; i < data->GetLength(); i++){
            for(int j = i; j > 0 && data->Get(j-1) > data->Get(j); j--){
                data->swap(j-1, j);
            }
        }
    }

};



#endif //LR2_ISORT_H
