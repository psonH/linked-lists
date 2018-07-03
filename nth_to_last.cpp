/*finding nth to last element in singly linked list*/
#include<iostream>
using namespace std;
class list;
class node
{
	int data;
	node *next;
	public:
		node(int n)
		{
			data=n;
			next=NULL;
		}
		friend class list;
};
class list{
	node *listptr; //pointer the head node
	public:
		list(){
			listptr=NULL;
		}
		void create();
		int length();
		int nth_to_last(int n);
};
void list::create()
{
	int n,data_item;
	node *temp;
	cout<<"Enter the number of nodes in the list:";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"Enter the data:";
		cin>>data_item;
		node *newnode=new node(data_item);
		if(listptr==NULL){
			listptr=temp=newnode;
		}else{
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
int list::length(){
	int leng=0;
	node *temp;
	for(temp=listptr;temp != NULL;temp=temp->next){
		leng++;
	}
	return leng;
}
int list::nth_to_last(int n)
{
	node *temp;
	if(n==0){
		for(temp=listptr;temp->next != NULL;temp=temp->next);
		return temp->data;
	}else{
		int leng=length();
		int pos=leng-n;
		for(temp=listptr;pos>0;pos--,temp=temp->next);
		return temp->data;
	}	
}
main()
{
	list l;
	int pos;
	l.create();
	cout<<"Enter the nth from last position to retrieve the data from:";
	cin>>pos;
	int value=l.nth_to_last(pos);
	cout<<"The value from nth to last:"<<value;
}
/*Enter the number of nodes in the list:6
Enter the data:2
Enter the data:7
Enter the data:1
Enter the data:3
Enter the data:9
Enter the data:8
Enter the nth from last position to retrieve the data from:2
The value from nth to last:9
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
