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
class LinkedStack {

	node <t> *head ;
	int count ;
	public :
	LinkedStack(){
		count=0;
		head =0;
	}
	bool push (t item){
		node <t> *temp = new node <t> (item);
		if (temp==0)return 0;
		temp->next = head;
		head= temp;
		count++;
		return 1;
	}
	bool empty (){
		return count==0;
	}
	bool pop() {
		
		if (empty())return 0;
		node <t> *test = head ;
		head = head->next ;
		count--;
		delete test;
		return 1;
	}
	bool top (t &item){
		
		if (empty())return 0;
		item = head->data;
		return 1;
	}
	void print (){
		node <t> *test = head ;
		while (test != 0 ){
			cout<<test->data<<" | ";
			test = test->next;
		}
		cout<<endl;
	}
	~LinkedStack (){
		while (!empty())
		pop();
	}
	LinkedStack (LinkedStack <t>&outer){
		while (!outer.empty()){
			outer.pop();
		}
		t load ;
		LinkedStack <t> inner ;
		
		while (!empty())
		{
			top(load);
			inner.push(load);
			pop();
		}
		while (!inner.empty()){
			inner.top(load);
			push(load);
			outer.push(load);
			inner.pop();
		}
	}
	void operator = (LinkedStack <t>&outer){
		while (!empty()){
			pop();
		}
		t load ;
		LinkedStack <t> inner ;
		
		while (!outer.empty())
		{
			outer.top(load);
			inner.push(load);
			
			outer.pop();
		}
		while (!inner.empty()){
			inner.top(load);
			push(load);
			outer.push(load);
			inner.pop();
		}
		
	}
		
		
	
};

int main(int argc, char *argv[])
{
	LinkedStack <int> s1 ;
	s1.push(10);
	//s2.push(66);
	s1.push(122);
	s1.push(334);
	//s2.push(54);
	//s2.push(12);
	s1.push(122);
	LinkedStack <int> s2;
	s1.print();
	cout<<"*********s1*******"<<endl;
	s2.print();
	cout<<"*********s2*******"<<endl;
	
	s1.print();
	cout<<"*********s1*******"<<endl;
	s2.print();
	cout<<"*********s2*******"<<endl;
	s1.push(44);
	s2.push(50);
	s1.print();
	cout<<"*********s1*******"<<endl;
	s2.print();
	cout<<"*********s2*******"<<endl;
	return 0;
}