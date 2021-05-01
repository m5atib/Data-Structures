#include <iostream>
using namespace std;
template <class t>
struct dnode {
		t data;
		dnode <t> *next ,*back;
		dnode (){
			next = back = 0;
		}
		dnode (t item){
			data = item;
			next = back = 0;
		}
};
template <class t>
class ListLinkedList {
	
	int count , currentPos ;
	dnode <t> *current ;
	
	void setPos (int pos){
		
		if (pos < currentPos){
			while (pos !=currentPos)
			{
				current=current->back;
				currentPos--;
			}
		}
		else {
			while (pos !=currentPos)
			{
				current=current->next;
				currentPos++;
			}
		}
	
	}
	public : 
	ListLinkedList (){
		count=currentPos=0;
		current =0;
	}
	bool empty (){
		return count==0;
	}
	int Size (){
		return count;
	}
	bool insert (int pos,t item){
		if ((pos<0) || (pos>count))return 0;
		dnode <t> *temp = new dnode <t> (item);
		dnode <t> *pre =0 ,*follow =0;
		if (pos==0){
			if (empty()){ 
				follow =0;
			}
			else{
				setPos(0);
				follow =current;
			}
			pre=0;
		}
		else{
			setPos(pos-1);
			pre = current ;
			follow  = pre ->next ;
		}
		temp->back = pre;
		temp->next =follow;
		if (pre!=NULL){
			pre->next =temp;	
		}
		if (follow!=NULL){
			follow->back=temp;	
		}
		currentPos = pos;
		current = temp;
		count++;
		return 1;
	}
	bool remove (int pos){
	
		return 1;
	}
	void print (){
	
		for (int i=0 ; i<count ; i++){
			setPos(i);
			cout<<current->data<<" | ";
		}
		cout<<endl;
	}
	bool get (int pos , t&item){
		if (empty())return 0;
		if ((pos<0) || (pos>=count))return 0;
		setPos(pos);
		item = current->data;
		currentPos = pos;
		return 1;
	}
	void operator = (ListLinkedList <int>&test){
		int countOrg = count;
		
		for (int i=0 ; i<countOrg ; i++)
		{remove(0);}
		countOrg = test.Size(); 
		
		t data;
		for (int i=0 ; i<countOrg ; i++){
			test.get(i , data);
			insert (i , data);
		
		}
		
	}
	
};
int main(int argc, char *argv[])
{
	ListLinkedList <int> ll ,l2;
	l2.insert(0 , 70);
	ll.insert(0 , 10);
	l2.insert(1 , 20);
	ll.insert(1 , 40);
	
	ll.print();
	cout<<"l1========"<<endl;
	l2.print();
	cout<<"l2========"<<endl;
	l2=ll;
	cout<<"after edit"<<endl;
	ll.print();
	cout<<"l1========"<<endl;
	l2.print();
	cout<<"l2========"<<endl;
	return 0;
}