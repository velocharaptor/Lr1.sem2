#ifndef LR2_PRESENTER_H
#define LR2_PRESENTER_H

#include "vector"

#include "ArraySequence.h"
#include "ListSequence.h"
#include "ISort.h"

#define arrType ArraySequence<int>

class Presenter {
private:
    arrType* arr;
    int size;
public:
    void createArr(int size);
    string sortArr(string s);
    string getArr();
    string tests();
    vector<double> getPointForGraph(string s);
};

#endif //LR2_PRESENTER_H
