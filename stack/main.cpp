#include <iostream>
#include <string>
#include <map>
using namespace std;

//структура для элемента стека
typedef struct node{
    int data;   //значение
    node* next; //следующий элемент
}node;

class stack
{
    node* head; //указатель на вершину стека

public:

    stack(int a)
    {
        head = new node;
        head->data = a;
        head->next = NULL;  //это единственный элемент
    }

    //поместить в стек
    void push(int a)
    {
        node* temp = new node;
        temp->data = a;
        temp->next = head;  //следующим элементом будет ранее заполненный элемент, который был вершиной стека
        head = temp;        //вершина стека теперь указывает на новый элемент
    }

    //извлечь из стека
    int pop()
    {
        node* temp = head;      //получим вершину стека
        if(temp->next == NULL)  //это единственный элемент
        {
            int a = temp->data;
            delete temp;
            return a;
        }
        head = temp->next;  //вершина стека теперь указывает на предыдущий элемент
        int a = temp->data;
        delete temp;
        return a;
    }

    ~stack()
    {
        //удалим все элементы
        while(head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
	map <string, int> commands;		//список команд
	commands["stack"]=1;
	commands["end"]=2;
	commands["push"]=3;
	commands["pop"]=4;

	string s;
	stack A(0);				//создадим пустой стек. Ноль удалится при выполнении команды "stack" (A.pop)

	do{						//цикл обработки команд
		cin>>s;

        int temp;

		switch ( commands[s] ){
            case 1:				//"stack" - создание первого элемента
                cin>>temp;
                A.pop();        //Удалим ноль, который появился при создании стека
                A.push(temp);	//сохраним введенное
                break;

            case 2: 			//"end" - выход
                break;

            case 3:        		//"push" - поместим в конец
                cin>>temp;
                A.push(temp);
                break;

            case 4:   		    //"pop" - заберем с конца
                cout<<A.pop()<<endl;
                break;
            }
  	}
	while (s!="end");

	return 0;
}
