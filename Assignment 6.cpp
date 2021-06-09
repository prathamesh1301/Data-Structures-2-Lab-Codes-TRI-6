#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class graph
{
    int infty=999;
    int n;
    int cost[30][30];
    public:
        graph()
        {
            int i,j;
            cout<<"Enter the number of vertices:"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=infty;
                }
            }
        }
        void create();
        void prims();
        void print();
};
void graph::create()
{
    int i,j;
    char ch;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            cout<<"Is there an Edge present from "<<i<<"<----->"<<j<<"(y/n)?"<<endl;
            cin>>ch;
            if(ch=='y'||ch=='Y'){
                cout<<"Enter the cost for "<<i<<"<----->"<<j<<" Edge:"<<endl;
                cin>>cost[i][j];
                cost[j][i]=cost[i][j];

            }
        }
    }
}


void graph::prims()
{
    int i,j,k,stv;
    int nearest[30],t[30][30];
    int mincost=0;
    int r=0;

    cout<<"Enter the starting vertex:"<<endl;
    cin>>stv;

    if(stv<0||stv>=n)
    {
        cout<<"Enter between 0 to "<<n<<endl;
        return;
    }

    else{
        nearest[stv]=-1;
    }

    for(i=0;i<n;i++){
        if(i != stv){
            nearest[i]=stv;
        }
    }
   // r=1;

    for(int i=0;i<n-1;i++)
    {
        int min=999;
        for(int k=0;k<n;k++)
        {
            if(nearest[k]!=-1 && cost[k][nearest[k]]<min)
            {
                j=k;
                min=cost[k][nearest[k]];
            }
        }
        t[r][1]=j;
        t[r][2]=nearest[j];
        r=r+1;
        mincost=mincost+cost[j][nearest[j]];
        nearest[j]=-1;

        for(k=0;k<n;k++)
        {
            if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
                nearest[k]=j;
        }
    }

    cout<<"Minimum cost by Prims Algorithm= "<<mincost<<endl;}
void graph::print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            cout<<"\t\t"<<cost[i][j];
        }
        cout<<"\n";
    }
}
int main()
{
    graph g;
    g.create();
    g.print();
    g.prims();
    return 0;
}
