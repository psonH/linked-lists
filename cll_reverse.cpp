/*Circular linked list*/
/*Operations: Reverse, Concatenation and Sorting*/
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
class List{
	Node *listptr;
	public:
		List(){
			listptr=NULL;
		}
		void create();
		void display();
		void reverse();
		void sorting();
		void concat(List);
};
void List::create(){
	int nodes,value;
	Node *temp;
	cout<<"\nEnter the number of nodes:";
	cin>>nodes;
	for(int i=0;i<nodes;i++){
		cout<<"Enter the data to insert:";
		cin>>value;
		Node *newnode = new Node(value);
		if(listptr == NULL){
			listptr=temp=newnode;
		}else{
			temp->next = newnode;
			newnode->next = listptr;
			temp = temp->next;
		}
	}
}
void List::display(){
	Node *temp=listptr;
	do{
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp != listptr);
	cout<<"END";
}
void List::sorting()
{
	int tmp;
	Node *temp,*temp_1;
	for(temp=listptr; temp->next != listptr; temp=temp->next){
		for(temp_1=temp->next ; temp_1 != listptr; temp_1 = temp_1->next){
			if(temp->data > temp_1->data){
				tmp=temp->data;
				temp->data=temp_1->data;
				temp_1->data=tmp;
			}
		}
	}
}
void List::concat(List l)
{
	Node *t2=l.listptr;
	Node *temp=listptr;
	do{
		temp=temp->next;
	}while(temp->next != listptr);
	temp->next = t2;
	temp=listptr;
	do{
		t2=t2->next;
	}while(t2->next != l.listptr);
	t2->next = temp;
}
void List::reverse()
{
	Node *fwd,*curr,*back;
	Node *temp=listptr;
	while(temp->next->next != listptr){
		temp=temp->next;
	}
	back = temp->next;
	curr=listptr;
	fwd=curr->next;
	while(fwd != listptr){
		curr->next=back;
		back=curr;
		curr=fwd;
		fwd=fwd->next;
	}
	curr->next=back;
	listptr=curr;
	display();
}
main()
{
	List l,al;
	int choice;
	char ch;
	do{
		cout<<"\n*****MENU*****\n";
		cout<<"1.Create\n2.Reverse\n3.Concatenate\n4.Sort the list\n";
		cout<<"\nEnter the choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				l.create();
				l.display();
				break;
				case 2:
					l.reverse();
					break;
					case 3:
						cout<<"\nCreate another list";
						al.create();
						l.concat(al);
						l.display();
						break;
						case 4:
							l.sorting();
							l.display();
							break;
		}
		cout<<"\nDo you wish to continue ? [y/n] ";
		ch=getch();
	}while(ch == 'y' || ch == 'Y');
}

