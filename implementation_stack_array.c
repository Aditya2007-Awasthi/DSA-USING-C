#include<stdio.h>
#define Max 5
int stack[Max];
int top=-1;
//PUSH OPERATION
void push(int value)
{
    if(top==Max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=value;
        printf("%d pushed to stack\n",value);
    }
}
//POP OPERATION
void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n",stack[top]);
        top--;
    }
}
//PEEK OPERATION
void peek()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n",stack[top]);
    }
}
//DISPLAY OPERATION
void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{   printf("ADITYA AWASTHI\n");
    printf("Roll No: 2504231530007\n");
    printf("Stack implementation using array\n");
    printf("Program-5=>1\n");
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}