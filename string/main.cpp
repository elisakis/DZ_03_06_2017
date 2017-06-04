#include <iostream>
#include <windows.h>    //для русского языка ввода
using namespace std;

//Работа со строками
class str{
    int n;          //длина строки
    char* Array;    //строка
public:
    //конструктор, сразу запомним вводимую строку нужной длины
    str(int x){
        n = x;
        Array = new char[n];
        cout << "Введите строку длиной " << n << " символов" << endl;
        for(int c = 0; c < n; c++)
            cin >> Array[c];
    }

    //объединение со строкой S (дописывается в конце текущей)
    void concat(str S){
        for(int c = n; c < n+S.size(); c++)
            Array[c] = S.get(c-n);
        n += S.size();  //запомним новую длину строки
    }

    //Поиск вхождения S в текущую строку
    bool find(str S){
        if(n >= S.size()){
            for(int c = 0; c < n+1-S.size(); c++){
                 if(Array[c] == S.get(0)){
                    for(int q=1; q<S.size(); q++){
                        if(Array[c+q] != S.get(q)) break;
                        if((q+1) == S.size()) return true;
                    }
                }
           }
        }
        return false;
    }

    //печать строки
    void print(){
        for(int c=0; c<n; c++)
            cout << Array[c];
        cout << endl;
    }

    //вставка символа в любое место
    void set(int i){
        cout << "Введите символ номер " << i << endl;
        cin >> Array[i];
    }

    //получение символа
    char get(int i){
        return Array[i];
    }

    //длина строки
    int size(){
        return n;
    }

    ~str(){
        delete [] Array;
    }
};

int main(){
    //русский язык на ввод и вывод
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Пример - три строки
    str A(5);
    str B(4);
    str C(3);

    A.print();
    B.print();
    C.print();

    if (A.find(C))
        cout << "С входит в A" << endl;
    else
        cout << "С не входит в A" << endl;

    A.concat(B);
    cout << "результат соединения А и В:" << endl;
    A.print();

    B.set(3);
    B.print();

    cout << A.get(1) << endl;

    return 0;
}
