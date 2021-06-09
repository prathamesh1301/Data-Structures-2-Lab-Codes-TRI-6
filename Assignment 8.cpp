# include<iostream>
# include<algorithm>
using namespace std;

class heap
{
    public:
    int H[20];
    int size=0;
    int n=0;
    void create();
    void insert(int);
    void display();
    void DELETE();
    void sort();
};

void heap::create()
{
    int i=0,r,element;
    char ch;
    cout<<"Enter Marks"<<endl;
    cin>>r;
    H[i++]=r;
    cout<<"Do you want to continue"<<endl;
    cin>>ch;
    while(ch=='y')
    {
        cout<<"Enter Marks"<<endl;
        cin>>element;
        H[i++]=element;
        insert(i);
        cout<<"Do you want to continue"<<endl;
        cin>>ch;
    }
    size=n=i;

}

void heap::insert(int n)
{
    int i=n;
    int element=H[i-1];
    while(i>0 && H[(i/2)-1]<element)
    {
        H[i-1]=H[(i/2)-1];
        i=i/2;
    }
    H[i-1]=element;
}

void heap::DELETE()
{
    int x,i,j;
    x=H[size-1];
    int temp=H[0];
    swap(H[0],H[size-1]);
    --size;
    i=0;
    j=i*2+1;
    while(j<size-1)
    {
        if(H[j+1]>H[j])
        j++;
        if(H[i]<H[j])
        {
            swap(H[i],H[j]);
            i=j;
            j=2*i+1;
        }
        else break;
    }

}

void heap::sort()
{
    for(int i=size-1;i>=0;i--)
    {
        DELETE();
    }
    for(int i=0;i<n;i++)
   {
       cout<<H[i]<<" ";
   }
   cout<<endl;
   cout<<"Max marks: "<<H[n-1]<<endl;
   cout<<"Min marks: "<<H[0]<<endl;
}
// heap code

void heap::display()
{
   for(int i=0;i<size;i++)
   {
       cout<<H[i]<<" ";
   }cout<<endl;
}

int main()
{
    heap h;
    h.create();
    h.display();
    cout<<"After sorting"<<endl;
    h.sort();
    return 0;

}
