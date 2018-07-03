/*singly linked list and its operations*/
/*Inserting node at beginning, intermediate and end position*/
/*Deleting node from beginning, intermediate and end position*/
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
		void insert_beg();
		void insert_last();
		void insert_intermediate();
		void deletion_beg();
		void deletion_last();
		void deletion_intermediate();
};
void List::create()
{
	int nodes,value;
	Node *temp;
	cout<<"Enter the nodes to be created:";
	cin>>nodes;
	
	for(int i=0;i<nodes;i++){
		cout<<"Enter the node data to insert:";
		cin>>value;
		
		Node *newnode = new Node(value);
		if(listptr == NULL){
			listptr=temp=newnode;
		}else{
			temp->next = newnode;
			temp = temp->next;
		}
	}
}
void List::display(){
	Node *temp;
	for(temp=listptr ;temp != NULL; temp=temp->next){
		cout<<temp->data<<"->";
	}
	cout<<"END";
}
void List::insert_beg()
{
	int value;
	cout<<"Enter the node to insert:";
	cin>>value;
	Node *newnode = new Node(value);
	if(listptr == NULL){
		listptr=newnode;
	}
	else{
		newnode->next = listptr;
		listptr = newnode;
	}
}
void List::insert_last()
{
    int value;
	cout<<"Enter the node to insert:";
	cin>>value;
	Node *newnode = new Node(value);
	if(listptr == NULL){
		listptr=newnode;
	}else{
		Node *temp=listptr;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
void List::insert_intermediate()
{
	int value,pos;
	cout<<"Enter the node to insert:";
	cin>>value;
	cout<<"Enter the position to insert:";
	cin>>pos;
	Node *newnode = new Node(value);
	if(listptr == NULL){
		listptr=newnode;
	}
	else if(pos == 1){
		newnode->next = listptr;
		listptr = newnode;
	}else{
		Node *temp=listptr;
		for(int i=1; i<pos-1 && temp != NULL; temp=temp->next,i++);
		newnode->next = temp->next;
		temp->next = newnode;
	}
}
void List::deletion_beg(){
	if(listptr == NULL){
		cout<<"\nLIST IS EMPTY";
		return;
	}else{
		Node *temp=listptr;
		listptr = listptr->next;
		delete temp;
	}
}
void List::deletion_last()
{
	if(listptr == NULL){
		cout<<"\nLIST IS EMPTY";
		return ;
	}else{
		Node *temp=listptr;
		while(temp->next->next != NULL){
			temp=temp->next;
		}
		Node *temp_1 = temp->next;
		temp->next = NULL;
		delete temp_1;
	}
}
void List::deletion_intermediate(){
	int value;
	Node *temp;
	if(listptr == NULL){
		cout<<"\nLIST IS EMPTY";
		return;
	}
	else{
		cout<<"Enter the node value to delete:";
		cin>>value;
		temp=listptr;
		if ( value == temp->data){
			listptr = listptr->next;
			delete temp;
			return;
		}else{
			while(temp->next != NULL){
				if(value == temp->next->data){
					Node *temp_1 = temp->next;
					temp->next = temp_1->next;
					delete temp_1;
                    return;
				}
				temp = temp->next;
			}
			cout<<"The value doesn't exist in the list\n";
			return;
		}
	}
}
main()
{
	List l;
	int choice;
	char ch;
	do{
		cout<<"\n*****MENU*****\n";
		cout<<" 1. Create \n 2. Insert at beginning \n 3. Insert at last \n 4. Insert at intermediate \n 5. Deletion at beginning \n 6. Deletion at last \n 7. Deletion at intermediate \n";
		cout<<"\nEnter your choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				l.create();
				l.display();
				break;
				case 2:
					l.insert_beg();
					l.display();
					break;
					case 3:
						l.insert_last();
						l.display();
						break;
						case 4:
							l.insert_intermediate();
							l.display();
							break;
							case 5:
								l.deletion_beg();
								l.display();
								break;
								case 6:
									l.deletion_last();
									l.display();
									break;
									case 7:
										l.deletion_intermediate();
										l.display();
										break;				
		}
		cout<<"\n\nDo you wish to continue ? [y/n] ";
		ch=getch();
	}while(ch == 'y' || ch == 'Y');
}
