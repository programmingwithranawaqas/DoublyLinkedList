// Author : Programming with Rana Waqas
// Youtube Channel Name : Programming with Rana Waqas
// Subscribe and like if you are enjoying the videos

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data =data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
    Node* head;
    Node* tail;
public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtStart(int data)
    {
        Node *N = new Node(data);
        if(head==NULL)
        {
            head = N;
            tail = N;
        }
        else
        {
            N->next = head;
            head->prev = N;
            head = N;
        }

    }
    void displayIterative()
    {
        if(head==NULL)
        {
            cerr<<"List is Empty."<<endl;
        }
        else
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ==> ";
                temp = temp->next;
            }
        }
    }
    Node* getHead()
    {
        return head;
    }

    void displayRecursively(Node* temp)
    {
        if(temp==NULL)
            return;
        cout<<temp->data<<" ==> ";
        displayRecursively(temp->next);
    }

    void displayListReverseOrder(Node* temp)
    {
        if(temp==NULL)
            return;
        displayListReverseOrder(temp->next);
        cout<<temp->data<<" ==> ";
    }

    void insertAtEnd(int data)
    {
        Node* N = new Node(data);

        if(head==NULL)
        {
            head = N;
        }
        else
        {
            /*Node* temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }

            N->prev = temp;
            temp->next = N;*/
            tail->next = N;
            N->prev = tail;
            tail = N;

        }
    }

    void displayReverseUsingItratively()
    {
        if(head==NULL)
            cerr<<"List if Empty"<<endl;
        else
        {
            Node* temp = tail;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ==> ";
                temp = temp->prev;
            }
        }
    }

    Node* search(int data)
    {
        if(head==NULL)
            return head;
        else
        {
            Node* temp = head;
            while(temp!=NULL)
            {
                if(temp->data == data)
                {
                    return temp;
                }
                temp = temp->next;
            }
        }
        return NULL;
    }

    void insertAfter(int key, int data)
    {
        Node* found = search(key);
        if(found==NULL)
        {
            cout<<key<<" Not found, sorry we cannot add "<<data<<endl;
        }
        else
        {
            Node* N = new Node(data);
            if(found==head)
            {
                head->next->prev = N;
                N->next = head->next;
                N->prev = head;
                head->next = N;
                return;
            }
            else if(found == tail)
            {
                insertAtEnd(data);
                delete N;
                return;
            }
            else
            {
                Node* temp = head->next;
                while(temp!=tail)
                {
                    if(temp->data == key)
                    {
                        temp->next->prev = N;
                        N->next = temp->next;
                        N->prev = temp;
                        temp->next = N;
                        return;
                    }

                    temp = temp->next;
                }
            }
            cout<<key<<" Not found, sorry we cannot add "<<data<<endl;
        }
    }
    void deleteFromStart()
    {
        if(head==NULL)
        {
            cerr<<"List is empty"<<endl;
        }
        else if(head->next==NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }
    void deleteFromEnd()
    {
        if(tail==NULL)
        {
            cerr<<"List is empty"<<endl;
        }
        else if(head->next==NULL)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Node* temp = tail;
            tail = tail->prev;
            delete temp;
            tail->next = NULL;
        }
    }
    void deleteData(int key)
    {
        if(head==tail)
        {
            if(head==NULL)
            {
                cerr<<key<<" not found in the list"<<endl;
            }
            else if(head->data==key)
            {
                delete head;
                head=tail=NULL;
                cout<<key<<" has been deleted successfully."<<endl;
            }
        }
        else
        {
            Node* temp = head;
            while(temp!=NULL)
            {
                if(temp->data==key)
                {
                    if(temp==head)
                    {
                        deleteFromStart();
                        break;
                    }
                    else if(temp==tail)
                    {
                        deleteFromEnd();
                        break;
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                        break;
                    }
                }
                temp=temp->next;
            }
        }
    }
};
int main()
{
    DoublyLinkedList dll;
    dll.insertAtStart(15);
    dll.insertAtStart(20);
    dll.insertAtStart(30);
    dll.insertAtEnd(50);
    dll.insertAtStart(45);
    dll.insertAtEnd(60);
    dll.insertAfter(50, 70);
    dll.insertAfter(45, 100);
    dll.insertAfter(1000, 15);
    cout<<endl;
    dll.displayIterative();
    dll.deleteData(60);
    cout<<endl;
    dll.displayIterative();
    //dll.displayIterative();
    //cout<<"DLL traversing recusively in reverse order : ";
    //dll.displayListReverseOrder(dll.getHead());
    return 0;
}
