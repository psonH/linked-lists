/*Circular linked list*/
/*Basic Operations like --insertion at beginning, intermediate and last positions, likewise deletions*/
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
		void insertion_beg();
		void insertion_last();
		void insert_intermediate();
		void deletion_beg();
		void deletion_last();
		void deletion_intermediate();
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
void List::insertion_beg(){
	int value;
	cout<<"Enter the value to insert:";
	cin>>value;
	
	Node *newnode = new Node(value);
	if(listptr == NULL){
		listptr=newnode;
	}else{
		Node *temp=listptr;
		while(temp->next != listptr){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = listptr;
		listptr = newnode;
	}
}
void List::insertion_last(){
	int value;
	cout<<"Enter the value to insert:";
	cin>>value;
	
	Node *newnode = new Node(value);
	if(listptr == NULL){
		listptr=newnode;
	}else{
		Node *temp=listptr;
		while(temp->next != listptr){
			temp=temp->next;
		}
		temp->next = newnode;
		newnode->next=listptr;
	}
}
void List::insert_intermediate(){
	int value,pos;
	cout<<"Enter the value to insert:";
	cin>>value;
	cout<<"Enter the position to insert:";
	cin>>pos;
	
	Node *newnode = new Node(value);
	if(listptr == NULL){
		listptr=newnode;
	}else if(pos == 1){
		Node *temp=listptr;
		while(temp->next != listptr){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = listptr;
		listptr = newnode;
	}else{
		Node *temp=listptr;
		for(int i=1; i<pos-1 && temp->next != listptr; temp=temp->next,i++);
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
		while(temp->next != listptr){
			temp=temp->next;
		}
		Node *temp_1 = temp->next;
		listptr = listptr->next;
		temp->next = listptr;
		delete temp_1;
	}
}
void List::deletion_last(){
	if(listptr == NULL){
		cout<<"\nLIST IS EMPTY";
		return;
	}else{
		Node *temp=listptr;
		while(temp->next->next != listptr){
			temp=temp->next;
		}
		Node *temp_1 = temp->next;
		temp->next = temp_1->next;
		delete temp_1;	
	}
}
void List::deletion_intermediate(){
	int value;
	
	if(listptr == NULL){
		cout<<"\nLIST IS EMPTY";
		return;
	}else{
		cout<<"\nEnter the value to delete from the list:";
		cin>>value;
		Node *temp=listptr;
		do{
			if(temp->next->data == value)
			{
                 Node *temp_1 = temp->next;
                 temp->next = temp_1->next;
                 delete temp_1;
                 return;
			}
			temp = temp->next;
		}while(temp != listptr);
		cout<<"\nThe value doesn't exist in the list";
		return;
	}
}
main(){
	List l;
	char ch;
	int choice;
	do{
		cout<<"\n*****MENU*****";
		cout<<"\n1.Create\n2.Insert at beginning\n3.Insert at last\n4.Insert at intermediate\n5.Deletion from beginning\n6.Deletion from last\n7.Deletion from intermediate\n";
		cout<<"\nEnter your choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				l.create();
				l.display();
				break;
				case 2:
					l.insertion_beg();
					l.display();
					break;
					case 3:
						l.insertion_last();
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
		cout<<"\nDo you wish to continue ? [y/n] ";
		ch=getch();
	}while(ch == 'y' || ch == 'Y');
}



/*
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:1

Enter the number of nodes:5
Enter the data to insert:1
Enter the data to insert:2
Enter the data to insert:3
Enter the data to insert:4
Enter the data to insert:5
1->2->3->4->5->END
Do you wish to continue ? [y/n]
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:2
Enter the value to insert:12
12->1->2->3->4->5->END
Do you wish to continue ? [y/n]
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:3
Enter the value to insert:34
12->1->2->3->4->5->34->END
Do you wish to continue ? [y/n]
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:4
Enter the value to insert:65
Enter the position to insert:4
12->1->2->65->3->4->5->34->END
Do you wish to continue ? [y/n]
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:5
1->2->65->3->4->5->34->END
Do you wish to continue ? [y/n]
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:6
1->2->65->3->4->5->END
Do you wish to continue ? [y/n]
*****MENU*****
1.Create
2.Insert at beginning
3.Insert at last
4.Insert at intermediate
5.Deletion from beginning
6.Deletion from last
7.Deletion from intermediate

Enter your choice:7

Enter the value to delete from the list:65
1->2->3->4->5->END
Do you wish to continue ? [y/n]
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
