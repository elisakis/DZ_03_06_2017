#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <algorithm>    //для find
#include <windows.h>    //для русского языка ввода

using namespace std;

//Электронная очередь.
//В очередь можно вставать (т.е. добавить в конец).
//Из очереди можно позвать (т.е. найти первый элемент и потом удалить его).
//Из очереди можно выйти (поиск по фамилии с удалением элемента).
//Т.к. чем позже пришел, тем позже попал в очередь, то сортировка всей очереди будет по времени прихода, но само время хранить не надо.
//
//Сделано через deque, т.к. там есть удаление элемента, в очередь сохраняются фамилии.

class el_que
{
    deque <string> que;
    deque <string>::iterator item;

public:
    //"Встать в очередь" (добавление в конец)
    void add(string fio)
    {
        que.push_back(fio);
    }

    //"выйти из очереди" (удаление по Фамилии)
    void del(string fio)
    {
        item = find(que.begin(), que.end(), fio);
        if (item != que.end())
            que.erase(item);
    }

    //"Позвать следующего" (из начала очереди)
    void next()
    {
        cout << "Вызван:" << que.front() << endl;
        que.pop_front();
    }

    //Вывод всего справочника на экран
    void print()
    {
        cout << "Очередь содержит:" << endl;
        for (item = que.begin(); item != que.end(); ++item)
        {
            cout << *item << endl;
        }
    }
};

//электронная очередь с возможность произвольного удаления
int main()
{
    //русский язык на ввод и вывод
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    el_que qu;

    /*
    cout << "------- Начало теста -------" << endl;
    qu.add("Иванов");
    qu.add("Сидоров");
    qu.add("Петров");
    qu.print();
    qu.del("Петров");
    qu.print();
    qu.del("Иванов");
    qu.del("Сидоров");
    cout << "------- Конец теста --------" << endl << endl;
    */

	map <string, int> commands;			//список команд
	commands["add"]=1;      //"Встать в очередь" (добавление в конец)
	commands["del"]=2;      //"выйти из очереди" (удаление по Фамилии)
	commands["next"]=3;     //"Позвать следующего" (из начала очереди)
	commands["prn"]=4;      //Вывод всего справочника на экран
	commands["end"]=5;      //Выход

	string s, fio, num;

    cout << "Вводите команду add, del, next, prn или end." << endl;
    cout << "Для команд add и del затем вводите фамилию." << endl;
    do
    {
        cin>>s;  //читаем команду

        switch (commands[s])
        {
            case 1:			//add
                cin>>fio;   //читаем фамилию
                qu.add(fio);
                break;

            case 2:        	//del
                cin>>fio;   //читаем фамилию
                qu.del(fio);
                break;

            case 3:        	//next
                qu.next();
                break;

            case 4:   		//prn
                qu.print();
                break;
        }
    }
    while (s!="end");

    return 0;
}
