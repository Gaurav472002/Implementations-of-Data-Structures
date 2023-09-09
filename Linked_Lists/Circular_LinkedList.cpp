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
        this->next = this;
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
            head->next=head;
        }
        else
        {
            
            // head = n;
            Node * temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=n;
            n->next = head;
            head=n;
            
        }
    }

    void insertAtLast(int data)
    {

        Node *n = new Node(data);

        if (!head)
        {
            head = n;
            head->next=head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->next=head;
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
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout << endl;
    }

    void deleteFirst()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        if(head==temp){
            delete head;
            head=nullptr;
        }
        temp->next=head->next;
        delete head;
        head=temp->next;
    }

    void deletelast()
    {
        if (!head)
        {
            return;
        }

        Node *temp = head;
        Node *prevtemp = nullptr;
        while (temp->next != head)
        {
            prevtemp = temp;
            temp = temp->next;
        }
        prevtemp->next = head;
        temp->next=nullptr;
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
    L1.insertAtFirst(100);
    L1.insertAtLast(200);
    L1.insertAtLast(300);
    L1.insertAtLast(400);
    L1.print();
    // L1.deletelast();
    L1.deleteFirst();
    
    
    L1.print();
}