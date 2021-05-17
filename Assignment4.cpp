#include<iostream>
using namespace std;

class node
{
    int data;
    bool rbit;
    bool lbit;
    node *right;
    node *left;
    node();
    friend class tbt;
};
node::node()
{
    lbit=1;
    rbit=1;
}

class tbt
{
    node *head;
public:
    void create();
    void inorder();
    node *inordersuccr(node *temp);
    void preorder();
    tbt();
};
tbt::tbt()
{
    head=new node;
    head->rbit=0;
    head->left=head;
    head->right=head;
}

void tbt::create()
{
    node *root=new node;
    cout<<"\nEnter data for root : ";
    cin>>root->data;
    head->lbit=0;
    root->left=head;
    root->right=head;
    head->left=root;
    char ch;
    cout<<"\nDo you want to add more nodes? (y/n): ";
    cin>>ch;
    while (ch=='y' || ch=='Y')
    {
        int flag=0;
        char choice;
        node *temp=root;
        node *curr=new node;
        cout<<"\nEnter data : ";
        cin>>curr->data;
        while (flag==0)
        {
            cout<<"Do you want to attach to the left or right of "<<temp->data<<"? (l/r): ";
            cin>>choice;
            if (choice=='l' || choice=='L')
            {
                if(temp->lbit==1)
                {
                    curr->right=temp;
                    curr->left=temp->left;
                    temp->left=curr;
                    temp->lbit=0;
                    flag=1;
                }
                else
                    temp=temp->left;
            }
            if(choice=='r' || choice=='R')
            {
                if(temp->rbit==1)
                {
                    curr->left=temp;
                    curr->right=temp->right;
                    temp->right=curr;
                    temp->rbit=0;
                    flag=1;
                }
                else
                    temp=temp->right;
            }
        }
        cout<<"\nDo you want to add more nodes? (y/n): ";
        cin>>ch;
    }
}

void tbt::inorder()
{
    if (head->lbit==1)
    {
        cout<<"TBT doesn't exist!";
        return;
    }
    node *temp=head;
    while(1)
    {
        temp=inordersuccr(temp);
        if (temp==head)
            break;
        cout<<temp->data<<"\t";
    }
}
node* tbt::inordersuccr(node *temp)
{
    node *x=temp->right;
    if (temp->rbit==0)
    {
        while (x->lbit==0)
            x=x->left;
    }
    return x;
}

void tbt::preorder()
{
    if (head->lbit==1)
    {
        cout<<"TBT doesn't exist!";
        return;
    }
    node *temp=head->left;
    while (temp!=head)
    {
        cout<<temp->data<<"\t";
        while (temp->lbit!=1)
        {
            temp=temp->left;
            cout<<temp->data<<"\t";
        }
        while (temp->rbit==1)
            temp=temp->right;
        temp=temp->right;
    }
}

int main()
{
    tbt t;
    int option;
    do
    {
        cout<<"\n1. Create Threaded Binary Tree (TBT)\n2. Inorder Traversal\n3. Preorder Traversal\n4. Exit\n\nEnter your choice : ";
        cin>>option;
        switch (option)
        {
            case 1:
                t.create();
                break;

            case 2:
                cout<<"\n";
                t.inorder();
                cout<<"\n";
                break;

            case 3:
                cout<<"\n";
                t.preorder();
                cout<<"\n";
                break;

            case 4:
                cout<<"\n";
                break;

            default:
                cout<<"\nInvalid Choice!\n";
                break;
        }
    }while (option!=4);

    return 0;
}
