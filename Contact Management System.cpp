#include<iostream>
#include <stdlib.h>
#include <string >
using namespace std;
struct node
{
   string name , number;
   node *next;
};
node *head = NULL , *newnode , *temp;
int len = 0 ;
void C_node ()
{
    newnode = new node;
    cout<<"Enter Name: ";
    cin>>newnode->name;
    cout<<"Enter number: ";
    cin>>newnode->number;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
void display ()
{
    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)
        {
            cout<<"\n\t\tName: "<<trav->name<<endl;
            cout<<"\t\tPhone Number: "<<trav->number<<endl;
            trav= trav->next;
            len++;
        }
        cout<<"Total contacts in the list = "<<len<<endl;
    }
}
void search_contact ()
{
    node *search_node = head;
    string srch;
    int count = 1;
    cout<<"Enter Name of the contact you want to search ";
    cin>>srch;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(srch == search_node->name || srch == search_node->number)
            {
                cout<<"\n\t\tFull name: "<<search_node->name<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                found =true;
                break;
            }
            search_node = search_node->next;
            count++;
        }
    }
    if(found == true)
    {

        cout<<"\t\tIndex of the Contact = "<<count<<endl;
    }
    else
    {
        cout<<"Sorry!! contact not found"<<endl;
    }
}
void at_given ()
{
    int pos ;
    node *next_node;
    temp = head;
    cout<<"Enter your desired position from where you want to delete contact "<<endl;
    cin>>pos;
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    else
    {
        for (int i = 1 ; i<pos ; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact has been deleted "<<endl;
    }
}
void clear_all ()
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        temp = head ;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\n\t\tALL contact list has been Erased "<<endl;
    }
}
void menu ()
{
    cout<<"Press 1 to Add Contact "<<endl;
    cout<<"Press 2 to Show All Contact "<<endl;
    cout<<"Press 3 to Search Contact "<<endl;
    cout<<"Press 4 to Delete Contact from where you want "<<endl;
    cout<<"Press 5 to Erase all record "<<endl;
}
int main ()
{
    int op;
    while (true )
    {
        menu();
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            break;
        case 2:
            len = 0;
            display();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clear_all();
            break;
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}

