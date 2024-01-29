#include <iostream>
#include <cstring>

using namespace std;

struct Element
{
    char data;
    Element* Next;
};

class List
{
    Element* Head;
    Element* Tail;
    int Count;

public:
    List();
    ~List();
    void Add(char data);
    void Del();
    void DelAll();
    void Print();
    void Print(int pos);
    int GetCount();
};

List::List()
{
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    DelAll();
}

int List::GetCount()
{
    return Count;
}

void List::Add(char data)
{
    Element* temp = new Element;
    temp->data = data;
    temp->Next = NULL;

    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    else {
        Head = Tail = temp;
    }

    Count++;
}

void List::Del()
{
    Element* temp = Head;
    Head = Head->Next;
    delete temp;
    Count--;
}

void List::DelAll()
{
    while (Head != NULL)
        Del();
}

void List::Print(int pos)
{
    if (pos < 0 || pos >= Count)
    {
        cout << "Позиция корректна\n";
        return;
    }
    Element* temp = Head;
    for (int i = 0; i < pos; i++)
    {
        temp = temp->Next;
    }
    cout << "Элемент на позиции " << pos << ": " << temp->data << "\n";
}
void List::Print()
{
    Element* temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << "\n\n";
}

int main()
{
    List lst;
    char s[] = "Hello, World !!!";
    cout << s << "\n\n";
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);
    lst.Print(5);

    return 0;
}
