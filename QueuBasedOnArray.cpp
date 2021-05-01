#include <iostream>
using namespace std;
const int maxsize = 100;
template <class t>
class queue {
	int front ;
	int rear;
	t arrQueue [maxsize];
	int count ;
	public :
	queue (){
		front =0;
		rear = maxsize-1;
		count = 0;
	}
	bool fullQueu() {
		return (count==maxsize);
	}
	int Size (){
		return count;
	}
	bool appendQueue (t item){
		
		if (fullQueu())
		return 0;
		rear = (rear + 1)%maxsize;
		arrQueue[rear] = item;
		count++;
		return 1;
	}
	bool isEmpty (){
		
		return (count==0);
	}
	bool serveQueue(){
		
		if (isEmpty())
		return 0;
		front = (front+1)%maxsize;
		count--;
		return 1;
	}
	bool Retrive (t &item){
		if (isEmpty())
		return 0;
		item = arrQueue[front];
		return 1;
	}
	bool printQueue (){
		cout<<"[ ";
		for (int i=front ;  i!=rear ; i=(i+1)%maxsize)
		cout << arrQueue[i]<<" << " ;
		cout<<arrQueue[rear]<<" ]"<<endl;
	}
	
	
};
bool delRevRepItemQue(queue<int>&q1) ;
int main()
{
	queue <int> q1 ,q2;
	q1.appendQueue(1);
	q1.appendQueue(2);
	q1.appendQueue(3);
	q1.appendQueue(4);
	q1.appendQueue(5);
	q1.appendQueue(6);
	q1.appendQueue(7);
	q1.appendQueue(8);
	q1.appendQueue(9);
	//q2.print();
	q1.printQueue();
	cout<<"------------"<<q1.Size()<<endl;
	delRevRepItemQue(q1);
	q1.printQueue();
	cout<<"------------"<<q1.Size()<<endl;
	return 0;
}

bool delRevRepItemQue(queue<int>&q1) 
{ 
 	if (q1.isEmpty())return 0;

 
    queue<int> TQ; 
  	int x;
    while (!q1.isEmpty()) { 
        for (int i=0; i<q1.Size()-1; i++) { 
            q1.Retrive(x);
            q1.serveQueue(); 
            q1.appendQueue(x); 
        } 

        q1.Retrive(x);
        TQ.appendQueue(x); 
        q1.serveQueue(); 
    } 
	while (!TQ.isEmpty()){
		TQ.Retrive(x);
		q1.appendQueue(x);
		TQ.serveQueue();
	}
    return 1; 
} 