#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node *prec;
	
	Node(int data){
		this->data=data;
		this->next=NULL;
		this->prec=NULL;
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
	cout<<"display list \n";
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
	cout<<endl;		
}
void reverse(Node *head)
{
	Node *h=head;
	Node *last=head;
	int len=length(head);
	while(last->next!=NULL)
		last=last->next;
		
	for(int i=0;i<len/2;i++)
	{
		int c=h->data;
		h->data=last->data;
		last->data=c;
		h=h->next;
		last=last->prec;
	}
	
}
void clear(Node **head_ref)
{
	Node *current=*head_ref;
	Node *next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		delete current;
		current=next;
	}
	*head_ref=NULL;
}
void unshift(Node **head_ref,const int & data)
{
	Node *newNode=new Node(data);
	newNode->next=*head_ref;
	(*head_ref)->prec=newNode;
	

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
	n->prec=last;	
}
void pop( Node *head_ref)
{
	Node *last=head_ref;
	bool found=false;
	while(last->next!=NULL)
	{
		last=last->next;
	}	
	last->prec->next=NULL;
	delete last;
}
void shift(Node **head_ref)
{
	
	Node *h=*head_ref;
	*head_ref=h->next;
	(*head_ref)->prec=NULL;
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
		(*head_ref)->prec=NULL;
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
	
	n->next=previous;
	n->prec=previous->prec;
	previous->prec->next=n;
	previous->prec=n;
}
void removeAt(Node **head_ref,const int & pos){
	if(length(*head_ref)<pos)
	{
			cout<<"cannot remove from a non existing position";
			return;
	}
	
	Node *element=*head_ref;

	
	bool found=false;
	int count=1;
	if(pos==1)
	{
		
		*head_ref=element->next;
		delete element;
		return;
	}
	
	while(!found && element!=NULL)
	{
		if(count==pos)	
			found=true;
		else
		{
			element=element->next;
			count++;
		}
		
	}
	element->prec->next=element->next;
	element->next->prec=element->prec;
	

	delete element;
	
	
}
main()
{


   

    Node * head  = new Node(1);
   

	unshift(&head,2);
	unshift(&head,3);
	
	append(&head,9);

    displayElements(head);
    /*
    pop(head);
    displayElements(head);
    
    shift(&head);
    displayElements(head);*/
    insertAt(&head,17,4);
    displayElements(head);
    
    removeAt(&head,3);
    displayElements(head);
    
    
    reverse(head);
    displayElements(head);
    
    clear(&head);
    displayElements(head);
    
    
}
