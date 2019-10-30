

#ifndef ROWARAY_H
#define	ROWARAY_H
#include <cstdlib>
#include <iostream>
using namespace std;
template<class T>
class RowAray{

protected:
    int size;
    T *rowData;

public:
    RowAray(int);
    virtual ~RowAray();
    int getSize()const{return size;}
    T getData(int i)const{
        if(i>=0&&i<size)return rowData[i];
        else return 0;
    }
    void setData(int,T);
};


template<class T>
RowAray<T>::~RowAray(){};

template<class T>
RowAray<T>::RowAray(int size){
    this->size=size;
    rowData=new T[size];
    for(int i=0;i<size;i++){
        rowData[i]=rand()%100+1;
    }
}
template<class T>
void RowAray<T>::setData(int i,T t){
    rowData[i]=t;
};

#endif