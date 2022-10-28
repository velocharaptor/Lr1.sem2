#include "Presenter.h"
#include <random>
#include <string>
#include <time.h>
#include "ISort.h"
#include "tests.h"

void Presenter::createArr(int size) {
    this->size = size;
    int* tmp_arr = new int[size];
    for (int i = 0; i < size; i++)
        tmp_arr[i] = rand() % 100 + 1;

    arr = new arrType(tmp_arr, size);
}

string Presenter::sortArr(string s) {
    clock_t start = clock();

    if (s == "Insertion")
        ISort<int, arrType>::InsertionSort(arr);
    else if(s == "Quick")
        ISort<int, arrType>::QuickSort(arr);
    else if(s == "Shell")
        ISort<int, arrType>::ShellSort(arr);

    clock_t end = clock();
    return to_string((int)(end - start) / (CLOCKS_PER_SEC / 1000));
}

string Presenter::getArr() {
    string res = "";
    for (int i = 0; i < this->size; i++)
        res += to_string(arr->Get(i)) + " ";
    return res;
}

string Presenter::tests(){
    return SortTests();
}

vector<double> Presenter::getPointForGraph(string s) {
    vector<double> resVec;
    resVec.push_back(0);
    for (int i = 1; i <= 10000; i*=10) {
        int tmp_size = i;
        int* tmp_arr = new int[tmp_size];
        for (int j = 0; j < tmp_size; j++)
            tmp_arr[j] = rand() % 10 + 1;
        arrType tmp_arrSeq(tmp_arr, tmp_size);
        clock_t start = clock();
        if (s == "Insertion")
            ISort<int, arrType>::InsertionSort(&tmp_arrSeq);
        else if (s == "Quick")
            ISort<int, arrType>::QuickSort(&tmp_arrSeq);
        else if (s == "Shell")
            ISort<int, arrType>::ShellSort(&tmp_arrSeq);
        clock_t end = clock();
        for(int j = 0; j < i; j++)
            resVec.push_back((int)(end - start) / (CLOCKS_PER_SEC / 1000));
    }

    return resVec;
}