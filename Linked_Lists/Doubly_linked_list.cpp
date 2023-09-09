#include <iostream>
using namespace std;

// create the node for the linked list

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Linked_List
{
public:
    Node *head = nullptr;

    void insertAtFirst(int data)
    {

        Node *n = new Node(data);
        if (!head)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertAtLast(int data)
    {

        Node *n = new Node(data);

        if (!head)
        {
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }

    void insertAtMiddle(int data)
    {
        Node *fast = head;
        Node *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *n = new Node(data);
        n->next = slow->next;
        slow->next->prev = n;
        n->prev = slow;
        slow->next = n;
    }

    void insertAtpos(int data, int pos)
    {
        if (pos == 0)
        {
            insertAtFirst(data);
        }
        else
        {
            int count = 1;
            Node *temp = head;
            while (count != pos)
            {
                temp = temp->next;
                count++;
            }
            Node *n = new Node(data);
            n->next = temp->next;
            temp->next->prev = n;
            n->prev = temp;
            temp->next = n;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << "<-";
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteFirst()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        temp->next->prev = nullptr;
        head = head->next;
        delete temp;
    }

    void deletelast()
    {
        if (!head)
        {
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {

            temp = temp->next;
        }
        temp->prev->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    void deleteMiddle()
    {
        if (!head)
        {
            return;
        }
        else
        {
            Node *fast = head, *slow = head;
            while (fast->next && fast->next->next)
            {

                slow = slow->next;
                fast = fast->next->next;
            }
            slow->next->prev = slow->prev;
            slow->prev->next = slow->next;
            slow->next = nullptr;
            slow->prev = nullptr;
            delete slow;
        }
    }

    void deleteElement(int x)
    {
        if (head->data == x)
        {
            deleteFirst();
        }
        else
        {
            Node *temp = head;

            while (temp && temp->data != x)
            {

                temp = temp->next;
            }
            if (!temp)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
            }
        }
    }

    void deleteElementatPosition(int pos)
    {
        if (pos == 1)
        {
            deleteFirst();
        }
        else
        {
            Node *temp = head;

            int count = 1;
            while (count != pos)
            {

                temp = temp->next;
                count++;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }
    }
};

int main()
{

    Linked_List L1;
    L1.insertAtFirst(100);
    L1.insertAtLast(200);
    L1.insertAtLast(300);
    L1.insertAtLast(400);
    L1.insertAtMiddle(600);
    L1.insertAtpos(3001, 3);
    L1.print();
    // L1.deleteElement(3001);
    // L1.deleteFirst();
    // L1.deletelast();
    // L1.deleteMiddle();
    L1.deleteElementatPosition(4);
    L1.print();
}