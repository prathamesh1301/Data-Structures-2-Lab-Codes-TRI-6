#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    int vertex;
    node* next;
    friend class graph;
};

class graph{
private:
    int n;
    node *head[20];
    bool visited[20];

public:
    graph(){
        cout<<"Enter no. of vertices: ";
        cin>>n;
        cout<<"\n";
        for(int i=0;i<n;i++){
            head[i]=new node;
            head[i]->vertex=i;
            head[i]->next=NULL;
        }
    };

    void create();
    void display();
    void dfs();
    void dfs(int v);
    void bfs();
    void bfs(int v);
    void dft_nr();
    void dft_nr(int v);


};

class Stack{
    int top;
    int stck[20];
public:
    Stack(){
        top=-1;
    }
    void push(int);
    int pop();
    int isempty();
};

void Stack::push(int x){   //push
    top++;
    stck[top]=x;
}

int Stack::pop(){     //pop
    int ans=stck[top];
    top--;
    return ans;
}

int Stack::isempty(){   //empty
    if(top<=-1)
        return 1;
    return 0;
}

class Queue{
    int frontq,rear;
    int que[20];
};

void graph::create(){
    cout<<"Create\n";
    node* temp;
    char ch;
    int v;
    for(int i=0;i<n;i++){
            temp=head[i];
        do{
            cout<<"Enter adjacent node of "<<i<<": ";
            cin>>v;
            cout<<"\n";
            if(i==v){
                cout<<"No self loop allowed\n";
            }else{
                node* curr=new node;
                curr->vertex=v;
                temp->next=curr;
                curr->next=NULL;
                temp=temp->next;
            }
            cout<<"Want to add more[Y/N]";
            cin>>ch;
            cout<<"\n";
        }while(ch=='Y' or ch=='y');
    }
}
void graph::dfs(){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            dfs(i);
    }

}
void graph::dfs(int v){
    cout<<v<<" ";
    visited[v]=true;
    node* temp=head[v];
    while(temp!=NULL){
        if(!visited[temp->vertex]){
            dfs(temp->vertex);
        }
        temp=temp->next;
    }
}
void graph::display(){
    node* temp;
    for(int i=0;i<n;i++){
        temp=head[i];
        while(temp!=NULL){
            cout<<temp->vertex<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
void graph::bfs(){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        bfs(i);
    }
}
void graph::bfs(int v){
    queue<int> qt;
    qt.push(v);
    visited[v]=true;

    while(!qt.empty()){
        int t=qt.front();
        qt.pop();
        cout<<t<<" ";
        node* temp=head[t];
        while(temp!=NULL){
            if(!visited[temp->vertex]){
                //cout<<temp->vertex<<" ";
                visited[temp->vertex]=true;
            }
            temp=temp->next;
        }
    }
}
void graph::dft_nr(){
for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            dft_nr(i);
    }


    }
void graph::dft_nr(int v){
    Stack st;
    st.push(v);
    visited[v]=true;
    do{
        v=st.pop();

        cout<<v<<" ";
        node* temp=head[v];
        while(temp!=NULL){
            if(!visited[temp->vertex]){
                st.push(temp->vertex);
                visited[temp->vertex]=true;
            }
            temp=temp->next;
        }

    }while(st.isempty()!=1);
}

int main(){
    graph g;
    //g.create();
/*g.display();
cout<<"\n";
cout<<"DFS: ";
g.dfs();
cout<<"\n";
cout<<"BFS: ";
g.bfs();
cout<<"\n";
cout<<"DFT recursively: ";
g.dft_nr();
cout<<"\n";*/

    int choice;
    int loop=1;
    while(loop>0){
        cout<<"1.Create\n2.Display\n3.DFS\n4.BFS\n5.DFS NR\n6.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1: g.create();
                    cout<<endl;
                    break;
            case 2: g.display();
                    cout<<endl;
                    break;
            case 3: g.dfs();
                    cout<<endl;
                    break;
            case 4: g.bfs();
                    cout<<endl;
                    break;
            case 5: g.dft_nr();
                    cout<<endl;
                    break;
            case 6: loop=-1;
                    cout<<endl;
                    break;
            default:cout<<"Enter valid choice\n";
                    break;
        }
    }

    return 0;

}
