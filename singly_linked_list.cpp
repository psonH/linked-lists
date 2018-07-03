/*Singly Linked List and its operations*/
/*Create, Display, Reverse, Concatenation of two lists, Union and Intersection, Copying operations*/
#include<iostream>
#include<conio.h>
using namespace std;
class List;
class Node{
	int data;
	Node *next;
	public:
		Node(int node_value){
		    data=node_value;
			next=NULL;
		}
		friend class List;
};
class List
{
	Node *listptr;
	public:
		List()
		{
			listptr = NULL;
		}
		void create();
		void display();
		void reverse();
		void concat(List);
		void union_lists(List,List);
		void intersection_lists(List,List);
		void copy(List);
};
void List::create()
{
	int nodes,value;
	Node *temp;
	cout<<"Enter the number of nodes in the list:";
	cin>>nodes;
	
	for(int i=0;i<nodes;i++)
	{
		cout<<"Enter the node value to insert:";
		cin>>value;
		Node *newnode = new Node(value);
		if(listptr == NULL)
		{
			listptr=temp=newnode;
		}
		else
		{
			temp->next = newnode;
			temp = temp->next;
		}
	}
}
void List::display()
{
	Node *temp;
	for(temp=listptr; temp != NULL; temp=temp->next)
	{
		cout<<temp->data<<"->";
	}
	cout<<"END";
}
void List::reverse()
{
	Node *fwd,*back,*curr;
	curr = listptr;
	back = NULL;
	fwd  = curr->next;
	while(fwd != NULL)
	{
		curr->next = back;
		back = curr;
		curr = fwd;
		fwd = fwd->next;
	}
	curr->next = back;
	listptr = curr;
	display();
}
void List::concat(List l)
{
	Node *t1,*t2;
	t1 = listptr;
	t2 = l.listptr;
	while(t1->next != NULL)
	   t1 = t1->next;
	t1->next = t2;
	display();
}
void List::copy(List l)
{
	Node *t1,*t2;
	t1 = l.listptr;
	t2 = listptr;
	while(t1 != NULL)
	{
		Node *newnode =  new Node(t1->data);
		if(listptr == NULL)
		{
			listptr=t2=newnode;
		}
		else
		{
			t2->next = newnode;
			t2 = t2->next;
		}
		t1 = t1->next;
	}
}
void List::union_lists(List l1,List l2)
{
	Node *t1,*t2,*t3;
	t1 = l1.listptr;
	t2 = l2.listptr;
	t3 = listptr;
	int flag = 1;   //indicates that list 2 node value should be in union list//
	
	while(t1 != NULL)
	{
		Node *newnode = new Node(t1->data);
		if(listptr == NULL){
			listptr=t3=newnode;
		}
		else{
			t3->next =  newnode;
			t3 = t3->next;
		}
		t1 = t1->next;
	}
	t1 = l1.listptr;
	while(t2 != NULL)
	{
		flag = 1;
		t1 = l1.listptr;
		while(t1 != NULL)
		{
			if(t2->data == t1->data)
			{
				flag = 0;
				break;
			}
			t1 = t1->next;
		}
		if( flag == 1)
		{
			Node *newnode = new Node(t2->data);
			t3->next = newnode;
			t3 = t3->next;			
		}
		t2 = t2->next;
	}
}
void List::intersection_lists(List l1,List l2)
{
	Node *t1,*t2,*t3;
	t1 = l1.listptr;
	t2 = l2.listptr;
	t3 = listptr;
	int flag = 0;  //indicates that when flag will be set the node value common to both list 1 and list 2 can be part of intersection list//
	
	while(t2 != NULL)
	{
		flag = 0;
		t1 = l1.listptr;
		while(t1 != NULL){
			if(t1->data == t2->data){
				flag = 1;
				break;
			}
			t1 = t1->next;
		}
		if(flag ==  1){
			Node *newnode = new Node(t1->data);
			if(listptr == NULL){
				listptr=t3=newnode;
			}
			else{
				t3->next = newnode;
				t3 = t3->next;
			}
		}
		t2 = t2->next;
	}
}
main()
{
	List l1,l2,u,i,cp;
	List u1,u2,i1,i2;
	int choice;
	char ch;
    do{
    	cout<<"\n*******MENU*******";
    	cout<<"\n 1. Create \n 2. Reverse \n 3. Concatenate lists \n 4. Union of lists \n 5. Intersection of lists \n 6. Copying \n";
    	cout<<"Enter the choice:";
    	cin>>choice;
    	
    	switch(choice)
    	{
    		case 1:
    			l1.create();
    			l1.display();
    			break;
    			case 2:
    				l1.reverse();
    				break;
    				case 3:
    					cout<<"\n****Create List 2****\n";
    					l2.create();
    					l1.concat(l2);
    					break;
    					case 4:
    						cout<<"\n****Create List 1****\n";
    						u1.create();
    						cout<<"\n****Create List 2****\n";
    					    u2.create();
    						u.union_lists(u1,u2);
							u.display();
							break;
							case 5:
								cout<<"\n****Create List 1****\n";
	    						i1.create();
	    						cout<<"\n****Create List 2****\n";
	    					    i2.create();
	    						i.intersection_lists(i1,i2);
								i.display();
								break;
								case 6:
									cp.copy(l1);
									cp.display();
									break;							
    	}
    	cout<<"\nDo you wish to continue ? [y/n] ";
    	ch=getch();
    }while(ch == 'y' || ch == 'Y');
}
