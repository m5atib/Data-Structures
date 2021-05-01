#include <iostream>
using namespace std;
const int size = 15;
template <class t>
class stack {
	t entry [size];
	int count ;
	public :
	stack (){
		count = 0;
	}
	bool full (){
		return (count==size-1);
	}
	bool push (t item){
	
		if (full())return 0;
		entry[count]= item;
		count++;
		return 1;
		
	}
	bool empty (){
		return (count==0);
	}
	bool pop (){
		if (empty())return 0;
		count--; return 1;
	}
	bool top (t &item){
		if (empty())return 0;
		item = entry[count-1];
		return 1;
	}
	void print(){
	//	if (empty())return 0;
		for (int i=count-1 ; i>=0 ; i--){
			cout<<entry[i]<<endl<<"__"<<endl;
		}
	//	return 1;
	}
	int Size(){
		return count;
	}
	void Reverse(){
		t temp;
	for (int i=0 ; i<(count-1)/2 ; i++)
	{
		temp = entry [i];
		entry [i] = entry[count-1-i];
		entry[count-1-i] = temp;
	}
	}
		
	
};

template <class t>
void printOrder(stack <t> test);
void deleteXItemStack (stack <int>&test , int X);
void deleteEvenItemStack (stack <int>&test);
template <class t>
void deleteTheMiddleItemStack(stack <t>&test);
template <class t>
bool ConcatenateTwoStacks(stack <t>&test1 , stack <t>test2);
int main(int argc, char *argv[])
{
	stack <int> s1 ,s2;
	s1.push(10);
	s2.push(66);
	s1.push(122);
	s1.push(334);
	s2.push(54);
	s2.push(12);
	s1.push(122);
	s2.push(40);
	
	s1.print();
	cout<<"___s1__"<<endl;
	s2.print();
	cout<<"___s2__"<<endl;
	ConcatenateTwoStacks(s1,s2);
	
	s1.print();
	cout<<"___s1__"<<endl;
	s2.print();
	cout<<"___s2__"<<endl;
	return 0;
}
template <class t>
bool ConcatenateTwoStacks(stack <t>&test1 , stack <t>test2){
	if (test2.empty())return 0;
	t item;
	int countPushed =0;
	stack <t> temp ;
	while (!test2.empty()){
		test2.top(item);
		temp.push(item);
		test2.pop();
	}
	while (!temp.empty()){
		temp.top(item);
		if (test1.push(item)){
			countPushed++;
		}
		else{
			for (int i=0; i<countPushed ; i++)
			test1.pop();
			return 0;
		}
		temp.pop();
		
	}
	return 1;
}
template <class t>
void deleteTheMiddleItemStack(stack <t>&test){
	stack <t> temp ;
	t item;
	int mid = (test.Size()-1)/2;
	int i=0;
	while (!test.empty()){
		if (i==mid)test.pop();
		test.top(item);
		temp.push(item);
		test.pop();
		i++;
	}
	
	while (!temp.empty()){
		temp.top(item);
		test.push(item);
		temp.pop();
	}
}
void deleteXItemStack (stack <int>&test , int X){
	stack <int> temp ;
	int item;
	bool flag =true;
	while (!test.empty()){
		test.top(item);
		if (item == X && flag==true){
			
			test.pop();
			test.top(item);
			
			flag=false;
			
		}
		temp.push(item);
		test.pop();
	}
	while (!temp.empty()){
		temp.top(item);
		test.push(item);
		temp.pop();
	}
	
}
void deleteEvenItemStack (stack <int>&test){
	stack <int> temp ;
	int item;
	while (!test.empty()){
		test.top(item);
		if (item%2==1){
			temp.push(item);
		} 	
		test.pop();
	}
	while (!temp.empty()){
		temp.top(item);
		test.push(item);
		temp.pop();
	}
}
template <class t>
void printOrder(stack <t> test){
	stack <t> temp ;
	t item;
	while (!test.empty())
	{
		test.top(item);
		temp.push(item);
		test.pop();	
	}
	while (!temp.empty()){
		temp.top(item);
		cout<<item<<endl<<"__"<<endl;
		temp.pop();
	}
	
}