#include <iostream>

using namespace std;

//Вектор
typedef class Vector{
    int* Array;
    int Size;
    int cap;

public:
    Vector(int new_size){
        Size=new_size;
        cap=0;
        Array=new int [Size];
    }

    ~Vector(){
        delete [] Array;
    }

    //размер вектора
    int get_size(){
        return Size;
    }

    //количество заполненных
    int get_cap(){
        return cap;
    }

    //заберем из начала
    int pop_head(){
        int k=Array[0];
        int* t=new int[Size-1];
        for(int i=1; i<Size; i++) t[i-1]=Array[i];
        cap--;
        Size--;
        delete [] Array;
        Array=t;

        return k;
    };

    //зададим новый размер вектора
    void append(int new_size){
        int* t=new int[new_size];
        for(int i=0; i<cap; i++) t[i]=Array[i];
        Size=new_size;
        delete [] Array;
        Array=t;
    }

    //увеличим вектор в два раза
    void append(){
        int* t=new int[2*Size];
        for(int i=0; i<cap; i++) t[i]=Array[i];
        Size*=2;
        delete [] Array;
        Array=t;
    }

    //перегрузка оператора [] для доступа к элементам вектора
    const int& operator [] (int i) const{
        return Array[i];
    }

    //добавим в конец
    void Push_back(int a){
        if (cap==Size) append();
        Array[cap]=a;
        cap++;
    }
}Vector;

int main()
{
    Vector Q(9);
    cout << Q.get_size() << Q.get_cap() << endl;
    for(int i=0; i<Q.get_size();i++){
        int a;
        cin >> a;
        Q.Push_back(a);
    }
    Q.Push_back(3);
    cout << Q[1] << "   .   " << Q.get_size() << "   .   " << Q.get_cap() << endl;

    cout << Q.pop_head() << endl;

    cout << "Vector:" << endl;
    for(int i=0; i<Q.get_cap();i++){
        cout << Q[i] << endl;
    }

    return 0;
}
