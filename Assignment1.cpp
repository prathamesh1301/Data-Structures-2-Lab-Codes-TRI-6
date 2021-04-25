#include <iostream>
#include <math.h>
using namespace std;

class node
{
public:
    int coef, exp;
    class node *next;
    friend class poly;
};

class poly
{   node *head,*temp;
public: poly()
    {
        head = new node;
        head->next = head;
        head->coef = 0;
        head->exp = -1;

    }
    void create();
    void display();
    void add(poly p1, poly p2);
    void eval();
};

void poly ::create()
{
    cout << "\n*************************\n";
    cout << "\t\t\tCREATION OF POLYNOMIAL\n\n" << endl;\
    node *curr,*temp;
    temp=head;
    char a;

    do
    {
    	curr= new node;
    	cout<<"Enter the value of coefficient"<<endl;
    	cin>>curr->coef;
    	cout<<"Enter the value of Exponent"<<endl;
    	cin>>curr->exp;
    	temp->next=curr;
    	curr->next=head;
    	temp=curr;
    	cout<<"-------------------------"<<endl;
    	cout<<"Do you want to add more? Press 'y' "<<endl;
    	cin>>a;
	}while(a=='y');


}

void poly ::display()
{
    temp = head->next;
    while (temp != head)
    {
        if (temp->coef != 0)
        {
            cout << temp->coef << "x^" << temp->exp;
            temp = temp->next;
            if (temp == head)
                break;
            cout << " + ";
        }
        else
        {
            temp = temp->next;
        }
    }
}

void poly ::add(poly p1, poly p2)
{
    class node *expr1, *expr2, *result, *temp;
    expr1 = p1.head->next;
    expr2 = p2.head->next;
    temp = head;
    while (expr1->exp != -1 || expr2->exp != -1)
    {
        result = new node;
        if (expr1->exp == expr2->exp)
        {
            result->exp = expr1->exp;
            result->coef = expr1->coef + expr2->coef;
            result->next = head;
            expr1 = expr1->next;
            expr2 = expr2->next;
            temp->next = result;
            temp = result;
        }
        else if (expr1->exp > expr2->exp)
        {
            result->exp = expr1->exp;
            result->coef = expr1->coef;
            result->next = head;
            expr1 = expr1->next;
            temp->next = result;
            temp = result;
        }
        else if (expr1->exp < expr2->exp)
        {
            result->exp = expr2->exp;
            result->coef = expr2->coef;
            result->next = head;
            expr2 = expr2->next;
            temp->next = result;
            temp = result;
        }
    }

}

void poly::eval()
{
    int sum = 0, x;
    cout << "\nEnter value of x: ";
    cin >> x;
    temp = head->next;
    while (temp != head)
    {
        sum = sum + (temp->coef * pow(x, temp->exp));
        temp = temp->next;
    }
    cout << "Value of ";
    display();
    cout << " at x = " << x << " is " << sum;
}

int main()
{
    poly p1, p2, p3;
    int n;
    do
    {
        cout << "\n\n*************************\n";
        cout << "\t\t\t\tMENU" << endl;
        cout << "\n1. Create 1st Polynomial.\n2. Create 2nd Polynomial.\n3. Display Polynomials.\n4. Addition of Polynomials.\n5. Evaluate.\n6. Exit.\nEnter your choice:  ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            p1.create();
            break;
        }
        case 2:
        {
            p2.create();
            break;
        }
        case 3:
        {
            cout << "\n\n*************************\n";
            cout << "\t\t\tPOLYNOMIALS\n\n"
                 << endl;
            cout << "First Polynomial:\t";
            p1.display();
            cout << "\nSecond Polynomial:\t";
            p2.display();
            break;
        }
        case 4:
        {
            cout << "\n\n*************************\n";
            cout << "\t\t\tADDITION OF POLYNOMIAL\n\n";
            p1.display();
            cout << "\n+" << endl;
            p2.display();
            cout << "\n------------------------------------------" << endl;
            p3.add(p1, p2);
            p3.display();
            break;
        }
        case 5:
        {
            cout << "\n\n*************************\n";
            cout << "\t\t\tEVALUATION OF POLYNOMIAL" << endl;
            p1.eval();
            p2.eval();
            break;
        }
        }
    } while (n < 6);
    return 0;
}
