

#include <iostream>

#include "../h/list.h"

using namespace std;

List::List() : head(nullptr), tail(nullptr) {}

List::List(const List &l)
{

    Node *n = l.head;
    Node *tek = nullptr;
    while (n)
    {

        if (this->head == nullptr)
        {
            this->head = new Node(n->v);
            tek = this->head;
        }
        else
        {

            tek->next = new Node(n->v);

            tek = tek->next;
        }

        if (n->next == nullptr)
            this->tail = tek;

        n = n->next;
    }
}

List::List(List &&l)
{

    this->head = l.head;
    this->tail = l.tail;
    l.head = nullptr;
    l.tail = nullptr;
}

List::Iterator::Iterator(const List::Iterator &it)
{

    this->current = new Node(it.current->v);
}

List::Iterator::Iterator(Iterator &&it)
{

    this->current = it.current;
    it.current = nullptr;
    cout << "Dule car" << endl;
}

List::~List()
{

    while (head)
    {

        Node *temp = head;
        head = head->next;

        delete temp;
    }
}

List &List::push_back(const int &v)
{

    if (this->head == nullptr)
    {

        head = new Node(v);
        tail = head;
    }
    else
    {

        tail->next = new Node(v);
        tail = tail->next;
    }
    return *this;
}

List::Iterator List::begin()
{

    return List::Iterator(this->head);
}

List::Iterator List::end()
{
    /*
    if (this->tail != nullptr)
        return List::Iterator(this->tail->next);
    else
    */
    return List::Iterator(nullptr);
}

bool List::Iterator::operator!=(const List::Iterator &it)
{

    return this->current != it.current;
}

int &List::Iterator::operator*()
{
    return this->current->v;
}

List::Iterator &List::Iterator::operator++()
{

    this->current = this->current->next;

    return *this;
};

List::Iterator::~Iterator()
{

    delete this->current;
}