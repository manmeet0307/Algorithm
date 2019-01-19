#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

 node* createnode(int x)
{
      

    node * newnode= new node();
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
    
}


node * merge(node * a, node* b)
{

    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node * result=NULL; 
   
    if(a->data<b->data)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }
    
    return result;
}

node *  mergesort(node * head)
{
  if(head->next==NULL)
    return head ;
  node*temp=head;
  node*p1=temp;
  node*p2=temp->next;
  
  while(p2 && p2->next)
  {
    p1=p1->next;
    p2=p2->next->next;
  }
  node*mid=p1;
  node*h2=mid->next;
  mid->next=NULL;
  node*x= mergesort(head);
  node*y= mergesort(h2);
  head= merge(x,y);
  return head;


    
}

int main() {
    int n;
    node * temp=NULL;
    cin>>n;
    int x;
    cin>>x;
   node * head=createnode(x);

    int count=n-1;
    temp=head;
    while(count--)
    {
        cin>>x;
        node * newnode=createnode(x);
        temp->next=newnode;
        temp=temp->next;
    }
    head=mergesort(head);
    temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    
	return 0;
}
