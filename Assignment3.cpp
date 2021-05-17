#include<iostream>
using namespace std;

class node
{
    string word;
    string meaning;
    node *left;
    node *right;
    node();
    friend class tree;
};

node::node()
{
    left=NULL;
    right=NULL;
}

class tree
{
    node *root;
public:
    tree();
    void create();
    void inorder();
    void inorder(node *);
    void bfs();
    void bfs(node *);
    void copy_r();
    node *copy_r(node *);
    void copy_nr(tree);
    void search_r();
    node *search_r(node *, string);
    node *searchparent_r(node *, string);
    int search_nr(string element);
    void depth_r();
    int depth_r(node *);
    void depth_nr();
    void delnode();
    void delnode(node *, string);
    void mirror_r();
    void mirror_r(node *);
    void mirror_nr();
};

tree::tree()
{
    root=NULL;
}

class queue
{
    int front;
    int rear;
    node *data[25];
public:
    queue();
    void enqueue(node *);
    node *dequeue();
    friend class tree;
};

queue::queue()
{
    front=-1;
    rear=-1;
}

void queue::enqueue(node *temp)
{
    rear++;
    data[rear]=temp;
}

node* queue::dequeue()
{
    front++;
    node *deleted=data[front];
    return deleted;
}

class stack
{
    int top;
    node *data[25];
public:
    stack();
    void push(node *);
    node *pop();
    friend class tree;
};

stack::stack()
{
    top=-1;
}

void stack::push(node *temp)
{
    top++;
    data[top]=temp;
}

node* stack::pop()
{
    node *popped=data[top];
    top--;
    return popped;
}

void tree::create()
{
    if (root==NULL)
    {
        root=new node;
        cout<<"\nEnter Keyword for root : ";
        cin>>root->word;
        cout<<"Enter it's Meaning : ";
        cin.ignore();
        getline(cin, root->meaning);
    }
    char ch;
    cout<<"\nDo you want to add more node(s)? (y/n): ";
    cin>>ch;
    while (ch=='y' || ch=='Y')
    {
        node *temp=root;
        int flag=0;
        node *curr=new node;
        cout<<"\nEnter Keyword : ";
        cin>>curr->word;
        cout<<"Enter it's Meaning : ";
        cin.ignore();
        getline(cin, curr->meaning);
        while (flag==0)
        {
            if (curr->word<temp->word)
            {
                if (temp->left==NULL)
                {
                    temp->left=curr;
                    flag=1;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if (temp->right==NULL)
                {
                    temp->right=curr;
                    flag=1;
                }
                else
                    temp=temp->right;
            }
        }
        cout<<"\nDo you want to add more node(s)? (y/n): ";
        cin>>ch;
    }
}

void tree::inorder()
{
    if (root==NULL)
    {
        cout<<"\nBST doesn't exist!\n";
        return;
    }
    inorder(root);
    cout<<"\n";
}
void tree::inorder(node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout<<"\nWord - "<<root->word<<", Meaning - "<<root->meaning;
        inorder(root->right);
    }
}

void tree::bfs()
{
    cout<<"\n";
    bfs(root);
    cout<<"\n";
}
void tree::bfs(node *root)
{
    node *temp=root;
    if (root!=NULL)
    {
        queue q1, q2;
        q1.enqueue(temp);
        while (q1.front!=q1.rear || q2.front!=q2.rear)
        {
            while (q1.front!=q1.rear)
            {
                temp=q1.dequeue();
                cout<<temp->word<<"\t";
                if (temp->left!=NULL)
                    q2.enqueue(temp->left);
                if (temp->right!=NULL)
                    q2.enqueue(temp->right);
            }
            cout<<"\n";
            while (q2.front!=q2.rear)
            {
                temp=q2.dequeue();
                cout<<temp->word<<"\t";
                if (temp->left!=NULL)
                    q1.enqueue(temp->left);
                if (temp->right!=NULL)
                    q1.enqueue(temp->right);
            }
            cout<<"\n";
        }
    }
    else
        cout<<"BST doesn't exist!";
}

void tree::copy_r()
{
    if (root==NULL)
    {
        cout<<"\nBST doesn't exist!\n";
        return;
    }
    tree ob;
    ob.root=copy_r(root);
    cout<<"\nCopied BST is : ";
    inorder(ob.root);
}
node* tree::copy_r(node *root)
{
    node *temp=NULL;
    if (root!=NULL)
    {
        temp=new node;
        temp->word=root->word;
        temp->meaning=root->meaning;
        temp->left=copy_r(root->left);
        temp->right=copy_r(root->right);
    }
    return temp;
}

void tree::copy_nr(tree t2) //t2 is original tree
{
    if (t2.root==NULL)
    {
        cout<<"\nBST doesn't exist!\n";
        return;
    }
    node *root=new node;
    node *temp1=root;
    node *temp2=t2.root;
    stack s1, s2;
    temp1->word=temp2->word;
    temp1->meaning=temp2->meaning;
    temp1->left=NULL;
    temp1->right=NULL;
    while (1)
    {
        while (temp2!=NULL)
        {
            if (temp2->left!=NULL)
            {
                node *curr1=new node;
                temp1->left=curr1;
                temp1->left->word=temp2->left->word;
                temp1->left->meaning=temp2->left->meaning;
                temp1->left->left=NULL;
                temp1->left->right=NULL;
            }
            if (temp2->right!=NULL)
            {
                node *curr2=new node;
                temp1->right=curr2;
                temp1->right->word=temp2->right->word;
                temp1->right->meaning=temp2->right->meaning;
                temp1->right->left=NULL;
                temp1->right->right=NULL;
            }
            s1.push(temp1);
            s2.push(temp2);
            temp1=temp1->left;
            temp2=temp2->left;
        }
        if (s2.top==-1)
            break;
        else
        {
            temp1=s1.pop();
            temp2=s2.pop();
            temp1=temp1->right;
            temp2=temp2->right;
        }
    }
    cout<<"\nCopied BST is :";
    inorder(root);
    cout<<"\n";
}

void tree::search_r()
{
    node *curr;
    string key;
    cout<<"\nEnter a word to be searched : ";
    cin>>key;
    curr=search_r(root, key);
    if (curr!=NULL)
        cout<<key<<" was found!\n";
    else
        cout<<key<<" was not found!\n";
}
node* tree::search_r(node *temp, string element)
{
    node *curr=NULL;
    if (temp!=NULL)
    {
        if (element==temp->word)
        {
            curr=temp;
            return curr;
        }
        if (element<temp->word)
            curr=search_r(temp->left, element);
        if (element>temp->word)
            curr=search_r(temp->right, element);
    }
    return curr;
}

node* tree::searchparent_r(node *curr, string element)
{
    node *parent=NULL;
    if (element<curr->word && curr->left!=NULL)
    {
        if (element==curr->left->word)
        {
            parent=curr;
            return parent;
        }
        else
            parent=searchparent_r(curr->left, element);
    }
    if (element>curr->word && curr->right!=NULL)
    {
        if (element==curr->right->word)
        {
            parent=curr;
            return parent;
        }
        else
            parent=searchparent_r(curr->right, element);
    }
    return parent;
}

int tree::search_nr(string element)
{
    int flag=0;
    node *temp=root;
    while (flag==0)
    {
        if (temp!=NULL)
        {
            if (element==temp->word)
            {
                flag=1;
                break;
            }
            else if (element<temp->word)
                temp=temp->left;
            else
                temp=temp->right;
        }
        else
            break;
    }
    return flag;
}

void tree::depth_r()
{
    int d=depth_r(root);
    cout<<"\nDepth of a tree is "<<d<<"\n";
}
int tree::depth_r(node *root)
{
    int t1=0, t2=0;
    if (root==NULL)
        return 0;
    else
    {
        t1=depth_r(root->left);
        t2=depth_r(root->right);
        if (t1>t2)
            return ++t1;
        else
            return ++t2;
    }
}

void tree::depth_nr()
{
    int d=-1;
    node *temp=root;
    if (root!=NULL)
    {
        d=0;
        stack s;
        while (1)
        {
            while (temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
                if (d<s.top)
                    d=s.top;
            }
            if (s.data[s.top]->right==NULL)
                temp=s.pop();
            while (s.top!=-1 && s.data[s.top]->right==temp)
                temp=s.pop();
            if (s.top==-1)
                break;
            temp=s.data[s.top]->right;
        }
    }
    cout<<"\nDepth of a tree is "<<++d<<"\n";
}

void tree::delnode()
{
    string str;
    cout<<"\nEnter a node to be deleted : ";
    cin>>str;
    if (search_nr(str)==0)
    {
        cout<<"Node not found!\n";
        return;
    }
    node *curr;
    curr=search_r(root, str);
    delnode(curr, curr->word);
}
void tree::delnode(node *curr, string key)
{
    if (curr==root) //deletion of root
    {
        if (curr->right==NULL)
            root=root->left;
        else if (curr->left==NULL)
            root=root->right;
        else if (curr->right!=NULL && curr->left!=NULL)
        {
            node *temp=curr->left;
            root=curr->right;
            node *s=curr->right;
            while (s->left!=NULL)
                s=s->left;
            s->left=temp;
        }
        else
            root=NULL;
    }
    else //deletion of node which is not root
    {
        node *parent=searchparent_r(root, key);
        if (curr->left==NULL && curr->right==NULL ) //deletion of a leaf
        {
            if (parent->left==curr)
                parent->left=NULL;
            else
                parent->right=NULL;
        }
        else if (curr->left==NULL) //deletion of a single child
        {
            if (parent->left==curr)
                parent->left=curr->right;
            else
                parent->right=curr->right;
        }
        else if (curr->right==NULL) //deletion of a single child
        {
            if (parent->left==curr)
                parent->left=curr->left;
            else
                parent->right=curr->left;
        }
        else //deletion of a node having two child
        {
            node *s=curr->right;
            node *temp=curr->left;
            while (s->left!=NULL)
                s=s->left;
            s->left=temp;
            if (parent->left==curr)
                parent->left=curr->right;
            else
                parent->right=curr->right;
        }
    }
    cout<<curr->word<<" deleted successfully!\n";
    delete curr;
}

void tree::mirror_r()
{
    if (root==NULL)
    {
        cout<<"\nBST doesn't exist!\n";
        return;
    }
    mirror_r(root);
    bfs();
}
void tree::mirror_r(node *root)
{
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    if(root->left!=NULL)
        mirror_r(root->left);
    if(root->right!=NULL)
        mirror_r(root->right);
}

void tree::mirror_nr()
{
    node *temp=root;
    if (root!=NULL)
    {
        queue q;
        q.enqueue(temp);
        while (q.front!=q.rear)
        {
            temp=q.dequeue();
            node *curr=temp->left;
            temp->left=temp->right;
            temp->right=curr;
            if(temp->left!=NULL)
                q.enqueue(temp->left);
            if(temp->right!=NULL)
                q.enqueue(temp->right);
        }
        bfs();
    }
    else
        cout<<"\nTree is Empty!\n";
}

int main()
{
    tree bst1, bst2;
    string element;
    int flag, option;
    do
    {
        cout<<"\n1. Create BST / Insert Nodes\n2. Display (Inorder)\n3. Display Breadth First Traversal (Level-wise)\n4. Search (Recursive)\n5. Search (Non-Recursive)\n6. Find Depth (Recursive)\n7. Find Depth (Non-Recursive)\n8. Mirror-Image (Recursive)\n9. Mirror-Image (Non-Recursive)\n10. Delete a Node\n11. Copy BST (Recursive)\n12. Copy BST (Non-Recursive)\n13. Exit\n\nEnter your choice : ";
        cin>>option;
        switch (option)
        {
            case 1:
                bst1.create();
                break;

            case 2:
                bst1.inorder();
                break;

            case 3:
                bst1.bfs();
                break;

            case 4:
                bst1.search_r();
                break;

            case 5:
                cout<<"\nEnter a word to be searched : ";
                cin>>element;
                flag=bst1.search_nr(element);
                if (flag==1)
                    cout<<element<<" was found!\n";
                else
                    cout<<element<<" was not found!\n";
                break;

            case 6:
                bst1.depth_r();
                break;

            case 7:
                bst1.depth_nr();
                break;

            case 8:
                bst1.mirror_r();
                break;

            case 9:
                bst1.mirror_nr();
                break;

            case 10:
                bst1.delnode();
                break;

            case 11:
                bst1.copy_r();
                cout<<"\n";
                break;

            case 12:
                bst2.copy_nr(bst1);
                break;

            case 13:
                cout<<"\n";
                break;

            default:
                cout<<"\nInvalid Choice!";
                break;
        }
    }while (option!=13);

    return 0;
}
