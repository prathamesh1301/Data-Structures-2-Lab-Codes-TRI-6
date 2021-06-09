#include<iostream>
#include<string>
using namespace std;
class Student{
    public:
    int roll;
    string name;
    string grade;

    Student();
    friend class Hash;
};
Student::Student(){
    roll=-1;
    grade="";
    name="";

}
class Hash{
    Student hashTable[10];
public:
    Hash();
    void linear_without();
    void display();
    void linear_with();
};

Hash::Hash(){
    for(int i=0;i<10;i++){
        hashTable[i].roll=-1;
    }
}

int insert_fn(Student a[],Student s){
    int key=s.roll;
    int j=key%10;
    if(a[j].roll==-1){
        a[j]=s;
        return j;
    }else{
        int i=(j+1)%10;
        while(i!=j){
            if(a[i].roll==-1){
                a[i]=s;
                return i;
            }
            i=(i+1)%10;
        }
        if(i==j)
            cout<<"Hash is full\n";
    }
}

int insert_wr(Student a[],Student s){
    int key=s.roll;
    int loc=key%10;
    if(a[loc].roll==-1){
        a[loc]=s;
        return loc;
    }
    else{
        Student temp=s;
        int t=key;
        if(loc!=a[loc].roll%10){
            temp=a[loc];
            a[loc]=s;
        }
        int i=(loc+1)%10;
        while(i!=loc){
            if(a[i].roll==-1){
                a[i]=temp;
                return i;
            }
            i=(i+1)%10;
        }
        if(i==loc)
            cout<<"Hash is full"<<endl;
    }
}

void Hash::linear_without(){
    char choice;
    do{
        Student s;

        cout<<"Enter name: ";
        cin>>s.name;
        cout<<endl;
        cout<<"Enter Roll No: ";
        cin>>s.roll;
        cout<<endl;
        cout<<"Enter Grade: ";
        cin>>s.grade;
        cout<<endl;

        insert_fn(hashTable,s);
        cout<<"Want to add more(y/n): ";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
}

void Hash::linear_with(){
    char choice;
    do{
        Student s;

        cout<<"Enter name: ";
        cin>>s.name;
        cout<<endl;
        cout<<"Enter Roll No: ";
        cin>>s.roll;
        cout<<endl;
        cout<<"Enter Grade: ";
        cin>>s.grade;
        cout<<endl;

        insert_wr(hashTable,s);
        cout<<"Want to add more(y/n): ";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
}
 void Hash::display(){
     cout<<"Sno."<<"  "<<"Roll No"<<"\t\t"<<"Grade"<<"\t\t"<<"Name"<<endl;
    for(int i=0;i<10;i++){
            cout<<i<<"      "<<hashTable[i].roll<<"\t\t"<<hashTable[i].grade<<"\t\t"<<hashTable[i].name<<endl;

    }
 }
int main(){


    Hash h1,h2;
    int loop=1;
    int ch;
    while(loop>0){
        cout<<"1.Linear Probing without replacement\n2.Linear Probing with replacement\n3.Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch){
            case 1:h1.linear_without();
                    h1.display();
                    break;
            case 2: h2.linear_with();
                    h2.display();
                    break;

            case 3: loop=-1;
                    break;
        }

    }

    return 0;
}
