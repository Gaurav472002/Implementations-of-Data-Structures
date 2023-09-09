#include <iostream>
using namespace std;

// create the node for the linked list

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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
            temp->next = n;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
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
        Node *prevtemp = nullptr;
        while (temp->next != nullptr)
        {
            prevtemp = temp;
            temp = temp->next;
        }
        prevtemp->next = nullptr;
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
            Node *fast = head, *slow = head, *prevslow = nullptr;
            while (fast->next && fast->next->next)
            {
                prevslow = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prevslow->next = slow->next;
            slow->next = nullptr;
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
            Node *prevtemp = nullptr;
            while (temp && temp->data != x)
            {
                prevtemp = temp;
                temp = temp->next;
            }
            if (!temp)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                prevtemp->next = temp->next;
                temp->next=nullptr;
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
            Node *prevtemp = nullptr;
            int count = 1;
            while (count != pos)
            {
                prevtemp = temp;
                temp = temp->next;
                count++;
            }
            prevtemp->next = temp->next;
            temp->next=nullptr;
            delete temp;
        }
    }
};

int main()
{

    Linked_List L1;
    L1.insertAtFirst(10);
    L1.insertAtLast(20);
    L1.insertAtLast(30);
    L1.insertAtLast(40);
    L1.insertAtLast(50);
    L1.insertAtMiddle(35);
    L1.print();
    // L1.insertAtpos(44,3);
    // L1.deleteFirst();
    // L1.deletelast();
    L1.deleteMiddle();
    // L1.deleteElement(410);
    // L1.deleteElementatPosition(3);
    
    L1.print();
}