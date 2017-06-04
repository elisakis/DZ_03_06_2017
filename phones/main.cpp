#include <iostream>
#include <string>
#include <map>
#include <windows.h>    //для русского языка ввода

using namespace std;

//Телефонный справочник, до 5 телефонов на одну фамилию
class phones
{
    multimap <string, string> ph;
    multimap <string, string>::iterator item;

public:
    //добавление связки Фамилия + Номер телефона
    void add(string fio, string num)
    {
        if (fio.length() == 0 or num.length() == 0)
        {
            cout << "Фамилия и номер телефона должны быть заполнены" << endl;
            return;
        }
        switch (ph.count(fio))  //количество телефонов по Фамилии
        {
            case 0:
                break;
            case 1:
                item = ph.find(fio);
                if (item->second == num)
                {
                    cout << "Номер телефона " << num << " уже есть для: " << fio << endl;
                    return;
                }
                break;
            case 5:
                cout << "Уже есть 5 номеров для: " << fio << endl;
                return;
            default:
                //ищем по диапазону телефонов, чтобы не было повтора
                typedef multimap<string,string>::iterator iterator;
                pair<iterator, iterator> pos;
	            // pos.first - адрес 1-го найденного
	            // pos.second - адрес 1-го отличного от найденного
	            pos = ph.equal_range(fio);
	            for (item = pos.first; item != pos.second; item++ )
	            {
                    if (item->second == num)
                    {
                        cout << "Номер телефона " << num << " уже есть для: " << fio << endl;
                        return;
                    }
	            }
        }
        ph.insert(pair<string, string>(fio, num));
    }

    //удаление всех телефонов по Фамилии
    void del(string fio)
    {
        ph.erase(fio);
    }

    //Вывод всего справочника на экран
    void print()
    {
        cout << "Справочник телефонов содержит:" << endl;
        for (item = ph.begin(); item != ph.end(); ++item)
        {
            cout << item->first << " : "<< item->second << endl;
        }
    }
};


int main()
{
    //русский язык на ввод и вывод
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    phones ps;

    /*
    cout << "------- Начало теста -------" << endl;
    ps.add("Иванов", "+7(812)555-66-77");
    ps.add("Иванов", "+7(812)555-66-77");
    ps.add("Иванов", "+7(812)555-666-77");
    ps.add("Иванов", "+7(812)555-686-77");
    ps.add("Иванов", "+7(812)555-686-77");
    ps.add("Иванов", "555-696-77");
    ps.add("Иванов", "+7(812)555-676-77");
    ps.add("Иванов", "+7(812)555-636-77");
    ps.add("Сидоров", "55543677");
    ps.add("Сидоров", "+7(812)355-436-77");
    ps.add("Сидоров", "+7(812)155-436-77");
    ps.add("Петров", "+7(812)155-436-77");
    ps.print();
    ps.del("Петров");
    ps.print();
    ps.del("Иванов");
    ps.del("Сидоров");
    cout << "------- Конец теста --------" << endl << endl;
    */

	map <string, int> commands;		//список команд
	commands["add"]=1;      //добавление связки Фамилия + Номер телефона
	commands["del"]=2;      //удаление всех телефонов по Фамилии
	commands["prn"]=3;      //Вывод всего справочника на экран
	commands["end"]=4;      //Выход

	string s, fio, num;

    cout << "Вводите команду add, del, prn или end." << endl;
    cout << "Для команды add затем вводите фамилию и номер телефона, для del вводите фамилию." << endl;
    do
    {
        cin>>s;  //читаем команду

        switch (commands[s])
        {
            case 1:			//add
                cin>>fio;   //читаем фамилию
                cin>>num;   //читаем номер телефона
                ps.add(fio, num);
                break;

            case 2:        	//del
                cin>>fio;   //читаем фамилию
                ps.del(fio);
                break;

            case 3:   		//prn
                ps.print();
                break;
        }
    }
    while (s!="end");

    return 0;
}
