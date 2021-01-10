// Program 5
// A short program demonstrating operator overloading, header files,
// and how they are used.
// CS320
// November 25, 2020
// @author Aiden Perez cssc****


#include <stdlib.h>
#include <iostream>
#include "intArray.h"

using namespace std;

IntArray::IntArray() {
    size = 10;
    pA = new int[size];
    lo = 0;
    hi = 9;
}

IntArray::IntArray(int x) {
    size = x;
    pA = new int[size];
    lo = 0;
    hi = size-1;
}

IntArray::IntArray(int x, int y){
    if (x > y) {
        cout << "Error: Impossible indices" << endl;
        lo = x;
        hi = y;
        size = (y-x)+1;
        pA = NULL;
    } else {
        size = (y-x) + 1;
        pA = new int[size];
        lo = x;
        hi = y;
    }
}

IntArray::IntArray(const IntArray& a){
    size = a.size;
    pA = new int[size];
    lo = a.lo;
    hi = a.hi;
    for(int i = 0; i <= size; i++){
        pA[i] = a.pA[i];
    }
}

IntArray::~IntArray(){
    if (pA != NULL) delete [] pA;
}

void IntArray::setName(char *name2){
    name = name2;
}

void IntArray::getName(){
    cout << name << endl;
}

int IntArray::high(){
    return hi;
}

int IntArray::low(){
    return lo;
}

int IntArray::operator==(const IntArray& a){
    if(size != a.size){
        return 0;
    } else {
        for (int i = 0; i <= size; i++){
            if (pA[i] != a.pA[i]) {
                return 0;
            }
        }
    }
    return 1;
}

int IntArray::operator!=(const IntArray& a){
    if (size != a.size){
        return 1;
    } else {
        for (int i = 0; i <= size; i++){
            if (pA[i] != a.pA[i]) {
                return 1;
            } 
        }
    }
    return 0;
}

int& IntArray::operator[](int index){
    int realIndex = index-lo;
    if(realIndex < 0 || realIndex >= size) {
        cout << "Error: Out of Bounds" << endl;
        return pA[0];
    } else {
        return pA[realIndex];
    }
}

IntArray& IntArray::operator=(const IntArray& a){
    if(size != a.size){
        cout << "Error: sizes are not equal" << endl;
        //exit(1);
        return *this;
    } else {
        delete [] pA;
        pA = new int[size];
        for(int i = 0; i <= size; i++){
           pA[i] = a.pA[i];
        }
    }
    return *this;
}

IntArray IntArray::operator+(const IntArray& a){
    if(size != a.size){
        cout << "Error: sizes are not equal" << endl;
        return 0;
    } else {
        IntArray brand_new(size);
        for (int i = 0; i <= size; i++){
        brand_new[i] = pA[i] + a.pA[i];
        }
        return brand_new;
    }
}

IntArray& IntArray::operator+=(const IntArray& a){
    if(size != a.size){
        cout << "Error: sizes are not equal" << endl;
        return *this;
    } else {
        for (int i = 0; i <= size; i++){
            pA[i] += a.pA[i];
        }
        return *this;
    }
}

ostream& operator<<(ostream& os, const IntArray& a){
    int count = 0;
    for (int i = a.lo; i <= a.hi; i++ ){
        os << a.name << "[" << i << "] = " << a.pA[count] << endl;
        count++;
    }
    return os;
}
