#include <iostream>
using namespace std;
const int maxsize = 40;

template <class t>
class stack {
	
	t arr[maxsize];
	int topindex;
	public : 
	
	stack ()
	{
		
		topindex = -1;
	}
	int sizeOfstack() {
		
		if (isEmpty())return 0;
		return topindex;
	}
	bool isFull ()
	{
		
		return(topindex==maxsize-1);
		
		
	}
	bool push (t item)
	{
		if (isFull())
		return 0;
		
		topindex++;
		arr[topindex] = item;
		return 1;
		
	}
	bool isEmpty ()
	{
		
		if (topindex==-1) return 1;
		return 0;
	}
	bool Top (t&item){
		
		if (isEmpty())return 0;
		item = arr [topindex];
		return 1;
	}
	bool print ()
	{
		if (isEmpty()) return 0;
		cout<<"_______"<<endl;
		for (int i=topindex ; i>=0 ; i--)
		{
			cout<<"  "<<arr[topindex]<<"  "<<endl; 
			cout<<"_______"<<endl;
		}
		
		return 1;
	}
	bool pop (){
		if (isEmpty ()) return 0;
		topindex--;
	}
	
};
template <class t>
void conctenateTwoStacks(stack<t>&s1 ,stack<t>&s2 );
template <class t>
void deleteMiddleItemInTheStack (stack <t> &s1);
template <class t>
void deletItemXlastfromTheStack (stack <t>&s1  , t X );
template <class t>
void deletItemXfromTheStack (stack <t>&s1 , t X);
template <class t>
void printStack (stack<t>s1);
template <class t>
bool deleteEvenItemFromStack(stack <t>&s1);

////////////////////////////////////////////////////////////////////////////////
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
	void reverseQueue (){
		stack <t> temp ;
		t item;
		while (!isEmpty())
		{	
			Retrive(item);
			temp.push(item);
			serveQueue();
		}
		while (!temp.isEmpty()){
			temp.Top(item);
			appendQueue(item);
			temp.pop();	
		}
	}
	
};
template <class t>
class lest {
	t entry[maxsize];
	int count;
	public :
	lest (){
		
		count = 0;
	}
	bool Full (){
		return (count==maxsize);
	}
	bool empty (){
		return (count==0);
	}
	bool insert (int pos,t item){
		if (Full())return 0;
		if ((pos<0)||(pos>count))return 0;
		if (pos==count)
		{
			entry[pos]=item;
			count++;
			return 1;
		}
		if (pos<count)
		{
			for (int i=count-1 ; i>=pos ; i--){
				entry[i+1] = entry[i];
			}
			entry[pos] = item;
			count++;
			return 1;
		}
	}
	void printList (){
		
		for (int i=0 ; i<count ; i++){
			cout<<entry[i]<<"	|	"<<i<<endl;
		}
		cout<<endl;
	}
	
	bool delItem (int pos ){
			if (empty())return 0;
			if ((pos<0)||(pos>=count))return 0;
		
			for (int i=pos ; i<count-1 ; i++){
				entry[i] = entry[i+1];
			}
			
			count--;
			return 1;
		
	}
	int SizeOfLest (){
		return count;
	}
	bool Ret (int pos , t &item){
		if (empty())return 0;
		if ((pos<0)||(pos>=count))return 0;
		item = entry [pos];
		return 1;
	}
	bool rep (int pos , t item){
		if (empty())return 0;
		if ((pos<0)||(pos>=count))return 0;
		entry[pos] = item;
		return 1;
	}

	void travers (void (*visit)(t)){
		for (int i=0 ; i<count ; i++){
			(visit )(entry[i]);
		}
	}
	void operator = (lest <t> &temp1){
		t data;
		for (int i=0 ; i<SizeOfLest() ; i++){
			Ret(i , data);
			temp1.insert(i , data);
		}
	}
};
template <class t>
void printqueue(queue <t> a1);
template <class t>
bool deleteEvenItemFromQueue (queue <t> &a1);
template <class t>
void PrintLastTwoItemInQueue (queue <t> a1);
template <class t>
void deleteMiddleItemInQueue (queue <t> &a1);
template <class t>
bool fillNitemsInQueue (queue <t> &a1 , int n);

void swapMaxMinInQueue(queue <int> &a1);


	



///////////////////////////////////////////////////////////////////////////////
template <class t>
struct node {
	
	t data ;
	node <t> *next ; 
	
	node (){
		next = 0;
	}
	node (t item)
	{
		next = 0 ;
		
		data = item;
	}
};
template <class t>
struct DNode {
	t item ; 
	DNode <t> *next ;
	DNode <t> *back;
	DNode (){
		next=back = NULL;
		
	}
};
template <class t>
int sizeOfnodes (node <t> *head);
template <class t>
bool addFirst (node <t>*&head , t item);
template <class t>
bool addLast (node <t> *&head , t item);
template <class t>
bool addIn (node <t> *&head , t item);
template <class t>
bool delFirst (node <t> *&head);
template <class t>
bool delLast (node <t> *&head);
template <class t>
bool delItemFromTheLinkedList (node <t> *&head,t item);

int findtheNofevenInLinkedList (node <int> *head);
void delEvenItemInTheLinkedList (node <int> *&head);
template <class t>
void printLinkedList (node <t> *head);
template <class t>
bool reverseLinkedList(node <t> *&head);

bool delMaxItemInTheLinked (node <int> *&head);
template <class t>
void printLastInLinkedList (node <t> *head);
template <class t>
void evenlistOf2linkedlist(node <int> *head1 , node <int> *head2);
	template <class t>
		void visit (t item){
		cout<<item<<endl;
	}
///////////////////////////////////////////////////////////////////////////////////////
template <class t>
bool swap2Item (lest <t> &l , int pos1 , int pos2){
	if ((pos1<0 )||(pos1 >=l.SizeOfLest() ))
	return 0;
	if ((pos2<0 )||(pos2 >=l.SizeOfLest() ))
	return 0;
	t item1,item2  ;
	l.Ret(pos1,item1);
	l.Ret(pos2,item2);
	l.rep(pos1,item2);
	return l.rep(pos2 , item1);
}
int maxItem (lest <int> l){
	if (l.empty())return -1;
	int mx ;
	int nw ;
	l.Ret(0 ,mx);
	
	for (int i=0 ; i<l.SizeOfLest() ; i++){
	l.Ret(i , nw);	
		if (nw >mx )
		mx = nw;
	}
	for (int i=0; i<l.SizeOfLest() ; i++){
		l.Ret(i , nw);
		if (mx == nw)
		return i;
	}
}
bool delEven (lest <int>&l){
	if (l.empty())return 0;
	int ch ;
	for (int i=l.SizeOfLest()-1; i>=0 ; i--){
		l.Ret(i , ch);
		if (ch%2==0)
		l.delItem(i);
	}
	return 1;
}
template <class t>
bool copies (lest <t> &temp1 , lest <t> &temp2);
template <class t>
bool des (lest <t> &temp1 , int pos);
template <class t>
bool remo (lest <t> &temp1 ,t item , t item2);
//template <class t>
void rearrang (lest <int> &temp1 );
int main(int argc, char *argv[])
{	

	lest <int> l1  ;
lest <int> l2;
	l1.insert(0, 10);

	l1.insert(1, 5);

	l1.insert(2, 30);

	l1.insert(3 ,-23);

	l1.insert(0 ,33);

	l1.insert(1 ,-14);

	l2.insert(2 ,13);

	//l1.printList();
	//int x;
	//l1.Ret(0,x);
	//cout<<x<<endl;
	l1 = l2; 
	l2.rep(3 , 34234);
	//int data;
	//int dataFirst , dataMid ;
	//l1.Ret(0 , dataFirst) ;
	//l1.Ret((l1.SizeOfLest()-1)/2, dataMid) ;
	//l1.rep(0 , dataMid) ;
	//l1.rep((l1.SizeOfLest()-1)/2, dataFirst) ;
	//remo(l1 , 50 , 33);
	//rearrang (l1);
	l2.printList();
	l1.printList();
	return 0;
}

void rearrang (lest <int> &temp1 ){
	lest <int> pos , neg ;
	int couPos=0 , couNeg = 0;
	int data;
	for (int i=0 ; i<temp1.SizeOfLest() ; i++)
	{
		temp1.Ret(i , data);	
		if (data >= 0)
		{
			pos.insert(couPos , data); couPos++;
		}
		else
		{
			neg.insert(couNeg , data); couNeg++;
		}
	} 
	int stop ;
	for (int i=0 ; i<pos.SizeOfLest(); i++){
			pos.Ret(i , data);
			temp1.rep(i , data);
			stop = i;
	}
	stop++;
	for (int i=0 ; i<neg.SizeOfLest(); i++){
			neg.Ret(i , data);
			temp1.rep(stop , data);
			stop++;
	}
}
template <class t>
bool remo (lest <t> &temp1 ,t item , t item2){
	int pos1 ,pos2;
	t data;
		for (int i=0 ; i<temp1.SizeOfLest() ; i++){
		temp1.Ret(i  , data);
		if (data==item)
		pos1 = i ;
		if (data == item2)
		pos2= i ;
	}
	if ((temp1.delItem(pos1))&&(temp1.delItem(pos2)))
	{
		return 1;
	}
	return 0;
}
template <class t>
bool des (lest <t> &temp1 , int pos){
	if (temp1.empty())return 0;
	if ((pos<0)||(pos>=temp1.SizeOfLest()))return 0;

	for (int i=temp1.SizeOfLest()-1 ; i>=pos ; i--){
			temp1.delItem(i);
	}
	return 1;
}
void evenlistOf2linkedlist(node <int> *head1 , node <int> *head2){
	node <int> *temp1 ,*temp2 ,*temp3;
	temp1 = head1;
	temp2=temp2;
	temp3 = new node <int> (temp1->data);
	while (temp1 != 0){
		if (!((temp1->data)%2))
		{
			
			temp3 = temp3->next;
			temp3 = new node <int> (temp1->data);
		}
		temp1=temp1->next;
		
	}
	while (temp2 != 0){
		if (!((temp2->data)%2))
		{
			temp3 = new node <int> (temp1->data);
			temp3 = temp3->next;
		}
		temp2=temp2->next;
		
	}
	printLinkedList(temp3);
	
}
template <class t>
void printLastInLinkedList (node <t> *head){
	
	node <t> *temp = head ;
	t item;
	
	while (temp != 0)
	{
		item = temp->data;
		temp=temp->next;
	}
	cout<<item<<endl;
}
bool delMaxItemInTheLinked (node <int> *&head)
{
	
	node <int> *temp,*pre ,*follow ;
	temp=pre=follow=head ;
	int max =temp->data;
	while (temp != 0 ){
		if ((temp->data)>max)
		max = temp->data;
		temp= temp->next;
	}
	
	
	while (follow!= 0){
		
		if (follow->data == max)
		{
			if (pre==follow)
			{
				head=follow->next;
				
			}
			else
			{
				pre->next=follow->next;
	
			}
		}
		pre=follow;
		follow=follow->next;
	}
	
}
template <class t>
void printLinkedList (node <t> *head)
{
	node<t>*temp = head ;
	cout<<"[ ";
	while ( temp != 0)
	{
		cout<<temp->data<<" | ";
		temp=temp->next;
	}
	cout<<" ]"<<endl;
}
template <class t>
bool reverseLinkedList(node <t> *&head){
	
	if (head==0)return 0;
	stack <t> temp ;
	node<t> *temp1 = head;
	t item;
	while (temp1->next != 0)
	{
		temp.push(temp1->data);
		temp1 = temp1->next;
	}
	node<t> *temp2 = head;
	while (!temp.isEmpty()){
		temp.Top(item);
		temp2->data = item;
		temp2 = temp2->next;
		temp.pop();
	}
	
	return 1;


}
void delEvenItemInTheLinkedList (node <int> *&head){
	
	
	node <int> *pre , *follow;
	pre =follow	= head ;
	while (follow->next !=0 ){
		if (!((follow->data)%2))
		{
				if (pre==follow)
				{
					head = follow ->next;
				}
				else
				{
					pre->next = follow ->next ;
				}
		}
		pre =follow;
		follow=follow->next;
	}
	
	
}
int findtheNofevenInLinkedList (node <int> *head){
	
	node <int> *temp = head;
	int count =0 ;
	while (temp != 0){
		if (!((temp->data)%2))
		count++;
		temp=temp->next;
	}
	return count;
}
template <class t>
bool delItemFromTheLinkedList (node <t> *&head ,t item){
	
	
	node <t> *pre , *follow;
	pre = follow = head ;
	
	while ((follow != 0)&& ((follow->data)!=item) ){
		pre = follow;
		follow =follow ->next;
	}
	if (follow==0)return 0;
	if (follow == pre)
	{head = follow->next ; }
	else
	{pre->next= follow->next;
	delete follow ;}
	return 1;
	
}
template <class t>
bool delLast (node <t> *&head){
	if (head==0)return 0;
	node <t> *temp = head ;
	node <t> *temp2 = temp ;
	while (temp->next!=0){
		temp2 = temp;
		temp=temp->next;
	}
	temp2->next= NULL;
	delete temp;
	return 1;
	
}
template <class t>
bool delFirst (node <t> *&head){
	
	if (head ==0)return 0;
	node <t> *temp = head;
	head = head->next;
	delete temp;
	return 1;
	
	
	
}
template <class t>
bool addIn (node <t> *&head , t item){
	
	node <t> *temp = new node <t> (item);
	if (temp==0) return 0;
	node <t> *pre , *follow ;
	pre = follow = head ;
	
	while ((follow !=0) && ((follow->data) < item) ){
		
		pre = follow;
		follow = follow->next;
		
	}
	temp->next = follow ;
	 if (pre == follow)
	 head = temp;
	 else
	 pre->next = temp;
	return 1;
	
}
template <class t>
bool addLast (node <t> *&head , t item){
	node <t> *temp = new node <t> (item);
	if (temp==0) return 0;
	node <t> *temp2 =head ; 
	while (temp2->next != 0)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp ;
	return 1;
	
}




template <class t>
bool addFirst (node <t>*&head,t item){
	node <t> *temp = new node <t> (item) ; 
	if (temp==0) return 0;
	temp->next = head ;
	head = temp;
	return 1;
}
template <class t>
int sizeOfnodes (node <t> *head){
	
	node <t> *temp ;
	temp =head ;
	int count=0;
	while (temp!=0){
		count++;
		temp= temp->next;
	}
	return count;
}
























void swapMaxMinInQueue(queue <int> &a1){
	
	int max=0;
	int min=0;
	a1.Retrive(max);
	a1.Retrive(min);
	int item;
	queue <int> temp;
	while (!a1.isEmpty()){
		a1.Retrive(item);
		if (item>max)
		max=item;
		if (item<min)
		min=item;
		temp.appendQueue(item);
		a1.serveQueue();
	}
	while (!temp.isEmpty())
	{
		
		temp.Retrive(item);
		if (item == max)
		item = min;
	 	else if (item == min)
		item = max;
		a1.appendQueue(item);
		temp.serveQueue();
	}
	
	
}
template <class t>
bool fillNitemsInQueue (queue <t> &a1 , int n){
	t item;
	int count=0;
	for (int i= 0 ; i <n ; i++){
		if (!a1.appendQueue(i))
		{
			stack <t> temp;
			while (!a1.isEmpty())
			{	
				a1.Retrive(item);
				temp.push(item);
				a1.serveQueue();
			}
			for (int i=0 ; i<count ; i++)
			{
				temp.pop();
			}
			while (!temp.isEmpty()){
				temp.Top(item);
				a1.appendQueue(item);
				temp.pop();
			}
			return 0;
			
		}
		
		count++;
	}
	return 1;
	
}

template <class t>
void deleteMiddleItemInQueue (queue <t> &a1){
	
	t item;
	queue <t> a2;
	int count = 0 ;
	while (!a1.isEmpty()){
		a1.Retrive(item);
		a2.appendQueue(item);
		a1.serveQueue();
		count++;
	}
	int i=1;
	while (!a2.isEmpty())
	{
		a2.Retrive(item);
		if (i==count/2)
		a2.serveQueue();
		
		a1.appendQueue(item);
		a2.serveQueue();
			i++;
	}
}
template <class t>
void PrintLastTwoItemInQueue (queue <t> a1){
	
	t last;
	t preLast;
	
	a1.Retrive(last);
	while (!a1.isEmpty()){
		preLast = last;
		a1.Retrive(last);
		a1.serveQueue();
		
		//cout<<last <<"  "<<preLast<<endl;
		
	}
	cout<< "preLast : "<<preLast<<endl;
	cout<< " last item : "<<last<<endl;
}
template <class t>
bool deleteEvenItemFromQueue (queue <t> &a1){
	if (a1.isEmpty())
	return 0;
	queue<t> a2;
	t item;
	while (!a1.isEmpty())
	{
		a1.Retrive(item);
		if (item%2)
		a2.appendQueue(item);
		a1.serveQueue();
			
	}
	while (!a2.isEmpty())
	{
		
		a2.Retrive(item);
		a1.appendQueue(item);
		a2.serveQueue();
	}
	return 1;
}
template <class t>
void printqueue(queue <t> a1){
	t item;
		cout<<"[ ";
	while (!a1.isEmpty())
	{
		a1.Retrive(item);
		cout<<item	<<" << ";
		a1.serveQueue();
	}
		cout<<" ] "<<endl;
}






































template <class t>
void printStack (stack<t>s1){
	t item;
	while (!s1.isEmpty())
	{
		s1.Top(item);
		cout<<item<<endl;
		s1.pop();
	}
}
template <class t>
bool deleteEvenItemFromStack(stack <t>&s1)
{
	
	stack <t> s2 ;
	t item;
	while (!s1.isEmpty())
	{
		s1.Top(item);
		if (item%2)
		s2.push(item);
		s1.pop();
	}
	while (!s2.isEmpty())
	{
		
		s2.Top(item);
		s1.push(item);
		s2.pop();
	}
}
template <class t>
void deletItemXfromTheStack (stack <t>&s1  , t X )
{
	t item;
	stack <t> s2;
	while (!s1.isEmpty())
	{
		s1.Top(item);
		if (X!= item)
		s2.push(item);
		s1.pop();
	}
	while (!s2.isEmpty())
	{
		
		s2.Top(item);
		s1.push(item);
		s2.pop();
	}
	
}
template <class t>
void deletItemXlastfromTheStack (stack <t>&s1  , t X )
{
	t item;
	stack <t> s2;
	int i=0 , j=1;;
	
	while (!s1.isEmpty())
	{
		s1.Top(item);
		s2.push(item);
		s1.pop();
	}
	while (!s2.isEmpty())
	{
		
		s2.Top(item);
		if (i<j && item==X  )
		{
			s2.pop();
			s2.Top(item);
			i++;
		}
		s1.push(item);
		s2.pop();
	}
	
	
}
template <class t>
void deleteMiddleItemInTheStack (stack <t> &s1)
{
	t item;
	stack <t> s2;
	int count=0;
	int c=0;
	while (!s1.isEmpty())
	{
		
		s1.Top(item);
		s2.push(item);
		s1.pop();
		count++;
		
		
	}

	
	while (!s2.isEmpty())
	{
		
			s2.Top(item);
		if (c==count/2){
			s2.pop();
			s2.Top(item);
		}
		s1.push(item);
		s2.pop();
		c++;
	}

}
template <class t>
void conctenateTwoStacks(stack<t>&s1 ,stack<t>&s2 )
{
	int count=0;
	t item ;
	while (!s2.isEmpty())
	{
		s2.Top(item);
		if (!s1.push(item))
		{
			for (int i=0 ; i <count ; i++){
				s1.Top(item);
				s2.push(item);
				s1.pop();
			}
			break;
		}
		
		s2.pop();
		count++;
		
	}
}
template <class t>
bool copies (lest <t> &temp1 , lest <t> &temp2){
	int count = 0;
	t data;

	int nw = temp2.SizeOfLest();
	int nw2=nw;
	for (int i=0 ; i<temp1.SizeOfLest() ; i++){
	temp1.Ret(i,data);
	if (temp2.insert(nw, data)){
		nw++;
		
	}
	else{
		for (int j=temp2.SizeOfLest()-1 ; j>=nw2 ; j--){
			temp2.delItem(j);
			
		}
		return 0;
	}
	}
	return 1;
}