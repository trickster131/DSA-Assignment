#include <iostream>
using namespace std;

class node
{
public:
    int age;
    string name;
    node *previous;
    node *next;

    node(int age, string name)
    {
        this->age = age;
        this->name = name;
        this->previous = NULL;
        this->next = NULL;
    }
};

node *takeinput()
{
    int age;
    string name;
    int count = 0;
    // int terminator;
    node *head = NULL;
    node *temp = head;

    cout << "To end entering family member name enter 'End' in the name block" << endl;
    cout << "Please  enter the name of the family member : " << endl;
    cin >> name;
    if (name != "End")
    {
        cout << "Please  enter the age of the family member : " << endl;
        cin >> age;
    }
    while (name != "End")
    {
        node *newnode = new node(age, name);

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        if (temp->next == NULL)
        {
            newnode->previous = temp;
            temp->next = newnode;
            temp = temp->next;
        }
        else
        {

            newnode->previous = temp;
            temp->next = newnode;
            temp = temp->next;
        }

        cout << "Please enter the name of the family member : " << endl;
        cin >> name;
        if (name != "End")
        {
            cout << "Please enter the age of the family member : " << endl;
            cin >> age;
        }
    }
    return head;
}

void printdata(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "The name of the family member is  " << temp->name << " and age is " << temp->age << endl;
        temp = temp->next;
    }
}
int main()
{
    node *head = takeinput();
    printdata(head);
    
    return 0;
}