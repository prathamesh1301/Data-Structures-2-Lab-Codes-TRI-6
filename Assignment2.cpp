# include <iostream>
#define MAX 1000
using namespace std;

class treenode
{

    char data[30];
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree
{
    treenode *root;
public:
    tree();
    void create();
    void create(treenode *);
    void nonrec();
    void inorder_r();
    void inorder_r(treenode *);
    void inorder_nr();
    void preorder_r();
    void preorder_r(treenode *);
    void preorder_nr();
    void postorder_r();
    void postorder_r(treenode *);
    void postorder_nr();
};

class stack
{
    int top;
    treenode *data[30];
public:
    stack()
    {
        top=-1;
    }
    void push(treenode *temp);
    treenode *pop();
    int empty();
    friend class tree;
};

void stack::push(treenode *temp)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
    }
    else {
        data[++top] = temp;
    }
}

treenode *stack::pop()
{
    treenode *temp;
    if(!empty()){
    temp=data[top];
    top--;
    return temp;
    }
}

int stack::empty()
{
    return (top < 0);
}


tree:: tree()
{
    root=NULL;
}

void tree::create()
{
    root = new treenode();
    cout<<"\nCreating Root Node..."<<endl;
    cout<<"Enter value of root: ";
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
    create(root);
}


void tree::create(treenode *temp)
{
    int l,r;
    treenode *curr;
    cout<<"Add data to left node of "<<temp->data<<"?(1/0)?";
    cin>>l;
        if(l==1)
        {
            curr= new treenode();
            cout<<"\nEnter number to insert in left node: ";
            cin>>curr->data;
            temp->left=curr;
            curr->left=curr->right=NULL;
            create(curr);
        }
    cout<<"Add data to right node of "<<temp->data<<"?(1/0)?";
    cin>>r;
        if(r==1)
        {
            curr= new treenode();
            cout<<"\nEnter number to insert in right node: ";
            cin>>curr->data;
            temp->right=curr;
            curr->left=curr->right=NULL;
            create(curr);
        }
}

void tree::nonrec()
{
    treenode *temp,*curr;
    char b='c';
    if(root==NULL){
        root=new treenode();

        cout<<"\nEnter the root data you want to store:";
        cin>>root->data;
        root->right=NULL;
        root->left=NULL;
        do{
            temp=root;
            int flag=0;
            char a;
            curr=new treenode();

            while(flag==0){
                cout<<"IF you want to add data to left side or right side of "<<temp->data<<" press 'l' or 'r':";
                cin>>a;

                if(a=='l'){
                    if(temp->left==NULL){
                        cout<<"Enter the data you want to store:";
                        cin>>curr->data;
                        temp->left=curr;
                        flag=1;
                    }
                    temp=temp->left;

                }else{
                    if(a=='r'){
                       if(temp->right==NULL){
                        cout<<"Enter the data you want to store:";
                        cin>>curr->data;
                        temp->right=curr;
                        flag=1;
                    }
                    temp=temp->right;
                    }
                }

            }
            cout<<"\nIf you want to continue press c or n:";
            cin>>b;
        }while(b=='c');
    }
}

void tree::inorder_r()
{
	inorder_r(root);
}

void tree::inorder_r(treenode *temp)
{
	if (temp!=NULL)
	{
		inorder_r(temp->left);//L
		cout<<temp->data<<" ";//D
		inorder_r(temp->right);//R
	}
}

void tree::inorder_nr()
{
    treenode *temp,*curr;
    stack s;
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            curr=temp;
            s.push(curr);
            temp=temp->left;
        }
        if(s.empty()) break;
        temp=s.pop();
        cout<<temp->data<<" ";
        temp = temp ->right;
    }

}

void tree::preorder_r()
{
	preorder_r(root);
}

void tree::preorder_r(treenode *temp)
{
    if (temp!=NULL)
        {
            cout<<temp->data<<" ";
            preorder_r(temp->left);//L
            preorder_r(temp->right);//R
        }
}

void tree::preorder_nr(){
    stack s;
    treenode *temp,*curr;
    temp=root;
    while(1){
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            curr=temp;
            s.push(curr);
            temp=temp->left;
        }
        if(s.empty()){
            break;
        }
            temp=s.pop();
            temp = temp ->right;
    }

}

void tree::postorder_r()
{
	postorder_r(root);
}
void tree::postorder_r(treenode *temp)
{
    if (temp!=NULL)
        {
            postorder_r(temp->left);
            postorder_r(temp->right);
            cout<<temp->data<<" ";
        }
}

void tree::postorder_nr()
{
    stack s;
    treenode *temp,*curr;
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            curr=temp;
            s.push(curr);
            temp=temp->left;
        }
        if(s.data[s.top]->right==NULL)
        {
            temp=s.pop();
            cout<<temp->data<<" ";
        }
        while(!s.empty() && s.data[s.top]->right==temp)
        {
            temp=s.pop();
            cout<<temp->data<<" ";
        }
        if(s.empty()) break;
        temp=s.data[s.top]->right;
    }
}


int main()
{
    tree bt;
    int o;
    while(1)
    {
    cout<<"\n*****"<<endl;
    cout<<"                                      MENU"<<endl;
    cout<<"***"<<endl;
    cout<<"1.Create Binary Tree(recursive)\n2.Create Binary Tree(Non-Recursive)\n3.In-Order Traversal\n4.Pre-Order Traversal\n5.Post-Order Traversal\n6.Non-Recursive Inorder\n7.Non-Recursive Preorder\n8.Non-Recursive Postorder\n9.Exit\n-> ";
    cin>>o;
    switch(o)
    {
    case 1:
        bt.create();
        break;
    case 2:
    {
        bt.nonrec();
        break;
    }
    case 3:
    {
        cout<<"In-order Traversal is: ";
        bt.inorder_r();
        break;
    }
    case 4:
    {
        cout<<"Pre-order Traversal is: ";
        bt.preorder_r();
        break;
    }
    case 5:
    {
        cout<<"Post-order Traversal is: ";
        bt.postorder_r();
        break;
    }
    case 6:
        cout<<"In-Order Traversal is:";
        bt.inorder_nr();
        break;
    case 7:
        cout<<"Pre-order Traversal is: ";
        bt.preorder_nr();
        break;
    case 8:
        cout<<"Post-order Traversal is: ";
        bt.postorder_nr();
        break;
    case 9:
        exit(0);
    default:
        cout<<"\nInvalid Choice!";
        break;
    }
    }
    return 0;
}
