#include <iostream>
using namespace std;

template <class t>
struct node {
		t data;
		node <t> *next;
		node (){
			next = 0;
		}
		node (t item){
			data = item;
			next = 0;
		}
};
template <class t>
void printLinkedList (node <t> *test);
template <class t>
bool AddFirst (node <t> *&test , t item);
template <class t>
bool DelFirst (node <t> *&test );
template <class t>
bool AddLast (node <t> *&test , t item);
template <class t>
bool DelLast (node <t> *&test );
template <class t>
bool DelAny (node <t> *&test , t item);
bool AddInOrder (node <int> *&test , int item);
int main(int argc, char *argv[])
{	
	
	node <int> *head = new node <int> (10) ;
	AddLast(head , rand()%50);
	AddLast(head , rand()%50);
	AddLast(head , 13);
	AddLast(head , rand()%50);
	AddLast(head , 4);
	printLinkedList(head);
	DelAny (head ,44);
	
	printLinkedList(head);
	return 0;
}
template <class t>
bool DelAny (node <t> *&test , t item){
	if (test == 0)return 0;
	node <t> *follow ,*pre ;
	follow = pre = test ;
	
	while (follow!=0 && follow->data!=item){
		pre=follow;
		follow=follow->next;
	}
	if (follow ==NULL)return 0;
	if (pre==follow)
	test = follow->next;
	else
	pre->next=follow->next;
	delete follow;
	return 1;
	
	
	
}
template <class t>
bool DelLast (node <t> *&test ){
	if (test == 0)return 0;
	node <int> *follow ,*pre ;
	follow =  test ;
	pre =0;
	while (follow->next!=0){
		pre =follow ;
		follow = follow->next;
	}
	if (pre ==NULL)
	test= NULL;
	else
	pre->next =NULL;
	delete follow;
	return 1;
	
}
template <class t>
bool DelFirst (node <t> *&test ){
	if (test == 0)return 0;
	node <t> *temp = test ;
	test=test->next;
	delete temp;
	return 1;
}
bool AddInOrder (node <int> *&test , int item){
	node <int> *temp = new node <int> (item);
	if (temp == NULL)return 0;
	node <int> *follow ,*pre ;
	follow =  test ;
	pre =0;
	while (follow!=0 && follow->data <item){
		pre = follow ;
		follow = follow ->next;
	}
	temp->next= follow;
	if (pre == NULL)
	test= temp;
	else{
		pre->next = temp;
	}
	
	
	return 1;
}
template <class t>
bool AddLast (node <t> *&test , t item){
	node <t> *temp = new node <t> (item);
	if (temp == 0)return 0;
	node <t> *follow = test ;
	while (follow->next != NULL){
		follow = follow->next ;
	}
	follow->next = temp;
	return 1;
}
template <class t>
bool AddFirst (node <t> *&test , t item){
	node <t> *temp = new node <t> (item);
	if (temp == 0)return 0;
	temp->next = test;
	test = temp;
	return 1;
	
}
template <class t>
void printLinkedList (node <t> *test){
	
	node <t> *temp = test ;
	
	while (temp!= 0){
		
		cout<<temp->data<<" | ";
		temp = temp->next;
	}
	cout<<endl;
}
