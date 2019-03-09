#include<iostream>
#define MAX_SIZE 5
using namespace std;
int top=-1;
int STACK[MAX_SIZE];
void push(int x)
{
    if(top==MAX_SIZE-1)
        cout<<"Stack is full\n";
    else
    {
        STACK[++top]=x;

    }
}
int pop()
{
    if(top==-1)
        cout<<"Stack is empty\n";
    else
    {
        return STACK[top--];
    }
}
int peep()
{
    if(top==-1)
        cout<<"Stack is empty\n";
    else
    return STACK[top];
}
void display()
{
    if(top==-1)
       cout<<"Stack is empty\n";
    else
    {
        for(int i=0;i<=top;i++)
            cout<<STACK[i]<<" ";
        cout<<endl;
    }

}
int main()
{
    int choice,data;
    while(1)
    {
        cout<<"1.Push\n2.Pop\n3.Peep\n4.display\n5.Exit\nEnter choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
               cout<<"enter element:";
               cin>>data;
               push(data);
               break;
        case 2:
              cout<<"Deleted element is "<<pop();
              break;
        case 3:
              cout<<peep()<<endl;
              break;
        case 4:
               display();
               break;
        case 5:
               return 0;
        }
    }
}
