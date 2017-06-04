#include <iostream>

using namespace std;

//структура для элемента
typedef struct node{
    int data;
    node* next;
}node;

//список
class list{
    node* head;

public:
    //создадим список с одним элементом
    list(int val){
        head = new node;
        head->data = val;
        head->next = NULL;
    }

    ~list(){
        while(head!=NULL){
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //добавить в начало списка
    void push_head(int val){
        node* temp = new node;
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    //поместить в конец списка
    void push_back(int val){
        node* temp = new node;
        node* t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = temp;
        temp->data = val;
        temp->next = NULL;
    }

    //извлечь из начала с удалением
    int pop(){
        node* temp = head;
        if(temp->next == NULL){
            int val = temp->data;
            delete temp;
            return val;
        }
        head = temp->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    //вставка элемента val после элемента data
    bool push_data(int val, int data){
        node* t = head;
        while(t->next != NULL) {
            if(t->data == data){
                node* temp = new node;
                temp->data = val;
                temp->next = t->next;
                t->next = temp;
                return true;
            }
            t = t->next;
        }

        if(t->data == data){
            node* temp = new node;
            temp->data = val;
            temp->next = t->next;
            t->next = temp;
            return true;
        }
        return false;
    }

    //получить значение по номеру
    int get(int i){
        if(i < 1) return 0;
        node* temp = head;
        for(int s = 1; s<i; s++){
            if(temp->next == NULL){
                if((s+1) == i)
                    return temp->data;
                return 0;
            }
            temp = temp->next;
        }
        return temp->data;
    }

    //установить значение по номеру
    void set(int i, int val){
        if(i < 1) return;
        node* temp = head;
        for(int s = 1; s<i; s++){
            if(temp->next == NULL) return;
            temp = temp->next;
        }
        temp->data = val;
    }

    //печать списка
    void print() {
        if(head == NULL)
            return;
        for(node* temp = head; temp != 0; temp = temp->next)
            cout << temp->data <<' ';
        cout<<endl;
    }

    //поиск по значению
    int find(int val){
        node* temp = head;
        int i = 1;
        while (temp != NULL){
            if(val == temp->data)
                return i;
            temp = temp->next;
            i++;
        } ;
        return -1;
    }

    //удаление по номеру
    void del_num(int i){
        node* temp = head;
        if(i == 1){
            head = head->next;
            delete temp;
            return;
        }
        for(int l = 1; l < i-1; l++){
            temp = temp->next;
            if (temp == NULL){
                return;
            }
        }
        node* temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
    }

    //удаление по значению
    void del_val(int val) {
        int i = find(val);
        if (i > 0) del_num(i);
    }

    //удаление всего списка
    void del() {
        while(head != NULL)
            del_num(1);
    }

};

int main()
{
    list v(11);     //создадим, с одним элементом 11
    v.push_back(22);
    v.push_back(33);
    v.push_back(44);
    v.push_head(10);
    v.push_data(34, 33);
    v.print();
    cout << v.get(3) << endl;
    cout << v.get(6) << endl;
    cout << v.find(33) << endl;

    v.pop();
    v.set(2, 2);
    v.print();

    v.del_num(3);
    v.print();

    v.del_val(2);
    v.print();

    v.del();
    v.print();

    return 0;
}
