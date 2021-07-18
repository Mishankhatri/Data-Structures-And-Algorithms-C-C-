//write a program to implement to basic implementations on Linked List(insert-All senarios,display,delete-All senarios)

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    };
};

class linkedlist
{
private:
    Node *head;
    int count = -1;

public:
    linkedlist()
    {
        head = NULL;
    };

    void insert(int d) //d stands for  user-input data in list.
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    };

    void insert_before(int d, int m) //m stands for data already present in list.
    {
        Node *newNode = new Node(d);
        Node *temp = head;
        if (temp->data == m)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *tempprev;
            do
            {
                tempprev = temp;
                temp = temp->next;
                if (temp->data == m)
                {
                    break;
                }
            } while (temp->next != NULL);
            tempprev->next = newNode;
            newNode->next = temp;
        }
        count++;
    }

    void insert_after(int d, int m)
    {
        Node *newNode = new Node(d);
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == m)
            {
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    };

    void insert_pos(int d, int pos)
    {
        Node *newNode = new Node(d);
        Node *temp = head;
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            };
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
    };

    void replace(int m, int d) 
    {
        Node *temp = head;
        do{
            temp = temp->next;
        }while(temp->data != m);
        temp->data = d;
    };

    void delete_first()
    {
        // head=head->next;  //this is not preferred as there is still previous node in heap.
        Node *temp = head;
        head = temp->next;
        delete temp;
        count--;
    };

    void delete_pos(int pos)
    {
        Node *temp = head;
        if (pos == 0)
        {
            head = temp->next;
            delete temp;
        }
        else
        {
            if (pos < count)
            {
                for (int i = 1; i < pos; i++)
                {
                    temp = temp->next;
                }
                Node *p;
                p = temp->next;
                temp->next = temp->next->next;
                temp = p;
                delete temp;
            }
            else if (pos >= count)
            {
                for (int i = 1; i < count; i++)
                {
                    temp = temp->next;
                };
                Node *p;
                p = temp->next;
                temp->next = NULL;
                temp = p;
                delete temp;
            }
        }
        count--;
    };

    void delete_node(int m)
    {
        Node *temp = head;
        if (temp->data == m)
        {
            head = temp->next;
            delete temp;
            count--;
        }
        else
        {
            bool found = false;
            for (int i = 1; i < count; i++)
            {
                temp = temp->next;
                if (temp->next->data == m)
                {
                    found = true;
                    break;
                };
            };

            if (temp->next->next != NULL && found == true)
            {
                Node *p = temp->next;
                temp->next = temp->next->next;
                delete p;
                count--;
            }

            else if (temp->next->next == NULL && found == true)
            {
                Node *p = temp->next;
                temp->next = NULL;
                delete p;
                count--;
            }

            else
            {
                cout << m << " doesnot exists" << endl;
            };
        };
    };

    void delete_node_before(int m)
    {
        Node *temp = head;
        if (temp->data == m)
        {
            cout << m << " "
                 << "is head node" << endl;
        }
        else
        {
            Node *temp_prev;
            do
            {
                temp_prev = temp;
                temp = temp->next;
            } while (temp->next->data != m);
            Node *p = temp;
            temp_prev->next = temp->next;
            delete p;
            count--;
        }
    };

    void delete_node_after(int m)
    {
        Node *temp = head;
        Node *temp_prev;
        bool found = false;
        do
        {
            temp_prev = temp;
            temp = temp->next;
        } while (temp_prev->data != m && temp->next != NULL);

        if (temp_prev->data == m)
        {
            found = true;
        }

        if (temp->next != NULL && found == true) //node other than second last and last node
        {
            Node *p = temp;
            temp_prev->next = temp->next;
            delete p;
            count--;
        }

        else if (temp->next == NULL && found == true) //for the second last node
        {
            Node *p = temp;
            temp_prev->next = NULL;
            delete p;
            count--;
        }

        if (temp->next == NULL && found == false) //for the last node or not present in the node
        {
            cout << "Oops! Either it's the last node or not present in the list." << endl;
        }
    };

    void deleteAll()
    {
        Node *temp = head;
        Node *deleteptr;
        do
        {
            deleteptr = temp;
            temp = temp->next;
            delete deleteptr;
            count--;
        } while (temp->next != NULL);
        delete temp;
        cout << "All nodes deleted." << endl;
    };

    void printlist()
    {
        if (count != 0)
        {
            Node *temp = head;
            cout << "Head-->";
            while (temp != NULL)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
        else
        {
            cout << "Empty list." << endl;
        }
    };
};

int main()
{
    linkedlist list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.printlist();

    // list.insert_before(9, 1);
    // list.insert_after(6, 5);
    // list.insert_pos(0, 1);
    // list.insert_pos(8, 0);
    // list.replace(6,9);
    // list.delete_first();
    // list.delete_pos(99);
    // list.delete_pos(7);
    // list.delete_node(1);
    // list.delete_node(7);
    // list.delete_node(8);
    // list.delete_node_before(3);
    // list.delete_node_before(7);
    // list.delete_node_before(1);
    // list.delete_node_after(1);
    // list.delete_node_after(6);
    // list.delete_node_after(7);
    // list.delete_node_after(8);
    // list.deleteAll();

    // list.printlist();
}