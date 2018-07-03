/*Josephus problem using Circular Linked List*/
/*There are n people standing in a circle waiting to be executed.
 The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. 
 In each step, a certain number of people are skipped and the next person is executed. 
 The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed),
 until only the last person remains, who is given freedom. 
 Given the total number of persons n and a number m which indicates that m-1 persons are skipped and m-th person is killed in circle.
 The task is to choose the place in the initial circle so that you are the last one remaining and so survive.*/
 
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
		int create();
		void display();
		void josephus(int);
};
int List::create(){
	int nodes,value;
	Node *temp;
	cout<<"\nEnter the number of persons:";
	cin>>nodes;
	for(int i=0;i<nodes;i++){
		cout<<"Enter the person:";
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
	return nodes;
}
void List::display(){
	cout<<"\n";
	Node *temp=listptr;
	do{
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp != listptr);
	cout<<"END";
}
void List::josephus(int n)
{
	int m;
	Node *temp_1;
	cout<<"\nChoose the number of persons to skip:";
	cin>>m;
	
	cout<<"\nAssuming that initially we start from position 1 itself.\n";
	Node *temp = listptr;
	/*loop runs until there is only 1 node left,therefore it's next will be itself*/	
	while(temp->next != temp){
		/*loop runs to skip m-1 people and reach m-th person*/
		for(int i=1; i < m-1; temp=temp->next,i++);
		/*m-th person executed,i.e,deleted*/
	    temp_1 = temp->next;
		cout<<"\nPerson executed:"<<temp_1->data;
		temp->next = temp_1->next;
		delete temp_1;
		/*set temp to the next person in queue*/
		temp=temp->next;
	}
	cout<<"\n"<<temp->data<<" survives";
}
main()
{
	List l;
	cout<<"\n***Create the circular list***";
	int persons = l.create();
	cout<<"\n***Initial State***";
	l.display();
	l.josephus(persons);
}

/*
***Create the circular list***
Enter the number of persons:8
Enter the person:1
Enter the person:2
Enter the person:3
Enter the person:4
Enter the person:5
Enter the person:6
Enter the person:7
Enter the person:8

***Initial State***
1->2->3->4->5->6->7->8->END
Choose the number of persons to skip:4

Assuming that initially we start from position 1 itself.

Person executed:4
Person executed:8
Person executed:5
Person executed:2
Person executed:1
Person executed:3
Person executed:7
6 survives
--------------------------------
Process exited with return value 0
Press any key to continue . . .*/
