#include <iostream>
using namespace std;
const int size = 10;
template<class t>
class list {
	
	t entry [size];
	int count ;
	public : 
	list (){
		count = 0;
	}
	bool empty (){
		return count==0;
	}
	int Size (){
		return count;
	}
	bool full ()
	{
		return count==size-1;
	}
	bool insert (int pos,t item){
		if ((pos<0) || (pos>count))return 0;
		if (full())return 0;
		
		
		for (int i=count-1 ; i>=pos ; i--){
			entry[i+1] = entry [i];
		}
		entry[pos] = item;
		count++;
		return 1;
	}
	bool replace (int pos ,t item){
		if ((pos<0) || (pos>=count))return 0;
		if (empty())return 0;
		entry [pos] = item;	
		count++;
		return 1;
	}
	bool remove (int pos){
		if (empty())return 0;
		if ((pos<0) || (pos>=count))return 0;
		for (int i=pos ; i<count-1 ; i++){
			entry[i] = entry [i+1];
		}
		count--;
		return 1;
	} 
	void operator = (list <int> test){
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
	bool get (int pos,t &item){
		if (empty())return 0;
		if ((pos<0) || (pos>=count))return 0;
		item = entry[pos];
		return 1;
	}
	void print (){
		
		for (int i=0; i<count ;i++){
			cout << entry[i] << " | ";	
		}
		cout<<endl;
	}
};
int main(int argc, char *argv[])
{
	list <int> ll ,l2;
	l2.insert(0 , 70);
	ll.insert(0 , 10);
	l2.insert(1 , 20);
	ll.insert(1 , 40);
	ll.insert(0 , 56);
	ll.print();
	l2.print();
	l2=ll;
	cout<<"==========="<<endl;
	ll.print();
	//ll.remove(2);
	l2.print();
	
	return 0;
}