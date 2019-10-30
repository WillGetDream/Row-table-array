#ifndef TABLE_H
#define	TABLE_H
#include "RowAray.h"

template<class T>
class Table{

protected:
    int szRow;
    int szCol;
    RowAray<T> **columns;

public:
    Table(unsigned int,unsigned int);
    Table(const Table<T> &);
    virtual ~Table();
    int getSzRow()const {return szRow;}
    int getSzCol()const {return szCol;}
    T getData(int,int)const;
    void setData(int,int,T);
    Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::~Table(){};

template<class T>
Table<T>::Table(unsigned int r,unsigned int c){
    this->szCol=c;
    this->szRow=r;
    columns=new RowAray<T>*[r];
    for(int i=0;i<r;i++){
        columns[i]=new RowAray<T>(c);
    }
};

template<class T>
Table<T>::Table(const Table<T> &t){
    this->szRow=t.szRow;
    this->szCol=t.szCol;
    this->columns=new RowAray<T>*[this->szRow];

    for(int r=0;r<t.szRow;r++){
        columns[r]=new RowAray<T>(this->szCol);
        for(int c=0;c<t.szCol;c++){
            columns[r]->setData(c,t.getData(r,c));
        }
    }

};

template<class T>
T Table<T>::getData(int r,int c)const{
    return columns[r]->getData(c);
};

template<class T>
void Table<T>::setData(int r,int c,T t){
    columns[r]->setData(c,t);
};

template<class T>
Table<T> Table<T>::operator+(const Table<T> &t2){
    Table<T>* t3=new Table<T>(this->szRow,this->szCol);
    for(int r=0;r<this->szRow;r++){
        for(int c=0;c<this->szCol;c++){
            t3->setData(r,c,(this->getData(r,c)+t2.getData(r,c)));
        }
    }
    return  *t3;
};



#endif	/* RowAray */