#include <iostream>
#include <string>
#include <map>
using namespace std;

//структура для элемента очереди
typedef struct node{
    int data;
    node* next;
}node;

class queue{
    node* head;     //указатель на конец очереди

public:

    queue(int a){
        head = new node;
        head->data = a;
        head->next = NULL;  //это единственный элемент
    }

    //поместить в очередь
    void push(int a){
        node* temp = new node;
        temp->data = a;
        temp->next = head;  //следующим элементом будет ранее заполненный элемент, который был концом очереди
        head = temp;        //конец очереди теперь указывает на новый элемент
    }

    //извлечь из очереди
    int pop(){
        node* temp = head;              //получим конец очереди
        if (temp->next == NULL){        //это единственный элемент
            int a = temp->data;
            delete temp;
            return a;
        }
        while(temp->next->next!=NULL)
            temp = temp->next;          //ищем второй элемент очереди с начала

        int a = temp->next->data;       //значение первого элемента
        delete temp->next;              //удалим первый элемент очереди
        temp->next = NULL;              //теперь второй элемент стал первым
        return a;
    }

    ~queue(){
        //удалим все элементы
        while(head != NULL){
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
	map <string, int> commands;		//список команд
	commands["queue"]=1;
	commands["end"]=2;
	commands["push"]=3;
	commands["pop"]=4;

	string s;
	queue A(0);				//создадим пустую очередь. Ноль удалится при выполнении команды "queue" (A.pop)

	do{						//цикл обработки команд

		cin>>s;

        int temp;

		switch ( commands[s] ){
            case 1:				//"queue" - создание первого элемента очереди
                cin>>temp;
                A.pop();        //Удалим ноль, который появился при создании очереди
                A.push(temp);   //сохраним введенное в первый элемент очереди
                break;

            case 2: 			//"end" - выход
                break;

            case 3:        		//"push" - поместим в конец
                cin>>temp;
                A.push(temp);
                break;

            case 4:   		    //"pop" - заберем с начала
                cout<<A.pop()<<endl;
                break;
        }
  	}
	while (s!="end");

	return 0;
}
