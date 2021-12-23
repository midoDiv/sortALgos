#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
	
	
};

int length(Node *head)
{

	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	
	return count;
}
void displayElements(Node *head)
{
	if(head==NULL)
	{
		cout<<"the list is empty";
		return;
	}
		while(head!=NULL)
	{
		cout<<head->data<<" , ";
		head=head->next;
	}
		
}
void unshift(Node **head_ref,const int & data)
{
	Node *newNode=new Node(data);
	newNode->next=*head_ref;

	*head_ref=newNode; 
	
}
void append(Node **head_ref,const int & data)
{
	Node *n=new Node(data);
	Node *last=*head_ref;
	if(*head_ref==NULL)
	{
	 *head_ref=n;
	 return ;
	}
	
	while(last->next!=NULL)
		last=last->next;
		
	last->next=n;
	
	
}
void insertAt(Node **head_ref,const int & data,const int & pos)
{
	
	if(length(*head_ref)<pos)
	{
			cout<<"cannot insert in a non existing position";
			return;
	}
	
	Node *previous=*head_ref;
	Node *n=new Node(data);
	bool found=false;
	int count=1;
	if(pos==1)
	{
		n->next=*head_ref;
		*head_ref=n;
		return;
	}
	
	while(!found && previous!=NULL)
	{
		if(count==pos)	
			found=true;
		else
		{
			previous=previous->next;
			count++;
		}
		
	}
	
	n->next=previous->next;
	previous->next=n;
}

void pop( Node *head_ref)
{
	Node *prev_last=head_ref;
	Node *last=head_ref;
	bool found=false;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	while(!found)
	{
		if(prev_last->next==last)
			found=true;
		else
			prev_last=prev_last->next;			
	}
	prev_last->next=NULL;
	delete last;
}
void shift(Node **head_ref)
{
	Node *h=*head_ref;
	*head_ref=h->next;
}
void reverse(Node *head)
{
	Node *h=head;
	Node *la=NULL;
	
}
void removeAt(Node **head_ref,const int & pos){
	
		if(length(*head_ref)<pos)
	{
			cout<<"cannot remove from a non existing position";
			return;
	}
	
	Node *previous=*head_ref;
	Node *previous_prev=*head_ref;
	
	bool found=false;
	int count=1;
	if(pos==1)
	{
		
		*head_ref=previous->next;
		return;
	}
	
	while(!found && previous!=NULL)
	{
		if(count==pos)	
			found=true;
		else
		{
			previous=previous->next;
			count++;
		}
		
	}
	found=false;
		while(!found)
	{
		if(previous_prev->next==previous)
			found=true;
		else
			previous_prev=previous_prev->next;			
	}
	
	previous_prev->next=previous->next;
	delete previous;
	
	
}
void sort(Node **head)
{
	Node *i=*head;
	
	int l=length(*head);

	for(int q=0;q<l;q++)
	{
		Node *j=*head;
			int c=0;
		while(j!=NULL && c<l-1)
		{
			if(j->data>j->next->data)
			{
				int temp=j->data;
				j->data=j->next->data;
				j->next->data=temp;
				
			}
			j=j->next;
			c++;
		}
	}
	
}
main()
{


   

    Node * head  = new Node(1);
   

	unshift(&head,2);
	unshift(&head,3);
	append(&head,4);
	
	insertAt(&head,9,1);
   
    //cout<<length(head);
    
    displayElements(head);
   /* cout<<"\n delete pos n = "<<endl;
    removeAt(&head,1);
    displayElements(head);*/
    cout<<"\n sort "<<endl;
    sort(&head);
    displayElements(head);
    
    
	
}
