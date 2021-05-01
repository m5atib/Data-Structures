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
class LinkedQueue {
	
	node <t> *front , *rear ;
	int count ;
	public :
		LinkedQueue(){
			count = 0;
			front=rear = 0;
		}
		bool empty(){
			return count==0;
		}
		bool append (t item){
			node <t> *temp = new node <t> (item); 
			if (temp==NULL)return 0;
			if (empty())front=rear=temp;
			else{
				rear->next = temp;
				rear =temp;
			}
			count++;
			return 1;
		}
		bool serve (){
			if (empty())return 0;
			node <t> *temp =  front;
			front = front->next;
			if (front == 0)
			rear =0;
			delete temp;
			count--;
			return 1;
		}
		bool size (){
			return count;
		}
		bool retrive (t &item){
			if (empty())return 0;
			item = front->data;
			return 1;
		}
		~LinkedQueue (){
			while (!empty())
			serve();
		}
		void operator = (LinkedQueue <t>&outer){
			while (!empty()){
				serve();
			}
			t load;
			LinkedQueue <t> temp ;
			while (!outer.empty()){
				outer.retrive(load);
				append(load);
				temp.append(load);
				outer.serve();
			}
			while (!temp.empty()){
				temp.retrive(load);
				outer.append(load);
				temp.serve();
			}
			
		}
		void print (){
		node <t> *test = front ;
		while (test != 0 ){
			cout<<test->data<<" | ";
			test = test->next;
		}
		cout<<endl;
	}
};
int main(int argc, char *argv[])
{
	LinkedQueue <int> q1 ,q2;
	q1.append(10);
	q2.append(66);
	q1.append(122);
	q1.append(334);
	q2.append(54);
	q2.append(12);
	q1.append(122);
	q2.append(40);
	q2=q1;

	q2.print();
	q2.append(40);
	q1.print();
	q2.print();
	return 0;
}