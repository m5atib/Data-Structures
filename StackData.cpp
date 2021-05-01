#include <iostream>
using namespace std;
const int maxsize =100;

template <class t>

class Sack {
	int top;
	t item[maxsize];
	public :
	Sack ():top (-1){}
bool push (t Element)
	{
		if (top>=maxsize-1 )
		{
			
			return 0;
		}
		else{
			top++;
		item[top] = Element;	
		return 1;
		}
		
	}
	bool isEmpty ()
	{
		if (top<0)
		return true;
		else return false;
	}
	void pop ()
	{
		if (isEmpty())
		cout<<"the stack is empty "<<endl;
		
		else
		top--;
	}
		void pop (t&Element)
	{
		if (isEmpty())
		cout<<"the stack is empty "<<endl;
		
		else
		Element = item [top];
		top--;
	}
	t getTOP ()
	{
		if (isEmpty())
		cout<<"the stack is empty "<<endl;
		else
		return item[top];
	}
	t getTOP (t&element)
	{
		if (isEmpty())
		cout<<"the stack is empty "<<endl;
		else
		element=item[top];
	}
	void print ()
	{
		cout<<"  ______"<<endl;
		for(int i=top; i>=0 ; i--)
		{
			cout<<" |  "<<item[i]<<"  |"<<endl;
			cout<<" ______"<<endl;
		}
		
	}
};
template <class t>
void deleteStack (Sack <t>&temp)
{
	Sack <t>temp2;
	while (!temp.isEmpty())
	{
		if (temp.getTOP()%2==0)
		{
			temp2.push(temp.getTOP());
				
		}
		temp.pop();
		
	}
	while (!temp2.isEmpty())
	{
		temp.push(temp2.getTOP());
		temp2.pop();
	}
}

template <class t>
void deletItemX ( Sack<t>&Temp , t X)
{
	Sack <t>Temp2;
	int x=0;
	while (!Temp.isEmpty())
	{
		if (Temp.getTOP()!=X)
		{
			Temp2.push(Temp.getTOP());
			
		}
		Temp.pop();
	}
	while (!Temp2.isEmpty())
	{
		Temp.push(Temp2.getTOP());
		Temp2.pop();
	}
	

}
template <class t>
void DELfirstItemX(Sack <t>&TEMP , t INTbyUser)
{
	int x=0,xx=1;
	Sack <t> xTemp;
		while (!TEMP.isEmpty())
		{
 			xTemp.push(TEMP.getTOP());
 			TEMP.pop();
		}
		while (!xTemp.isEmpty())
		{
			if (x<xx && xTemp.getTOP()==INTbyUser) // that play once time not each time 
			{
				xTemp.pop();
			 	x++;	
			} 
 			TEMP.push(xTemp.getTOP());
 			xTemp.pop();
		}
}
template <class t>
bool Concinate (Sack<t>&s1 ,Sack<t>&s2)
{
	
  t Item ;
  Sack <t> nwTemp;
  
  while (!s1.isEmpty())
  {
  s1.getTOP(Item);
    nwTemp.push(Item);
    s1.pop();
  }
  int c=0;
  while (!nwTemp.isEmpty())
  {
    nwTemp.getTOP(Item);
    if (s2.push(Item)==0){
      for (int i=0 ;i<c; i++  )
      {
      s2.getTOP(Item);
      nwTemp.push(Item);
        s2.pop();
      }
      while (!nwTemp.isEmpty())
      {
        nwTemp.getTOP(Item);
        s1.push(Item);
        nwTemp.pop();
      }
      return false;
    }
    else {
      c++;
      nwTemp.pop();
      
    }
  }
}
const int Maxsize=5;
template <class t>
class que {

  int front, rear, count;
  t entry[Maxsize];
  
  public:
  que ()
  {
    front=0;
    rear =Maxsize-1;
    count=0;
  
  }
  bool isEmpty()
  {
    if (count==0)
    return 1;
    return 0;
  }
  bool Append (t Item)
  {
  if (count==Maxsize)
  return 0;
  else{
  rear=(rear+1)%Maxsize;
    entry[rear]=Item;
    count++;
    return 1;
  }
  }
  bool serve()
  {
  if (count==0)
  return 0;
  else{
  front=(front+1)%Maxsize;
  
    count--;
    return 1;
    
  }
   
  }
  bool Retrieve(t &Item)
  {
    if (count==0)
    return 0;
    else
    {
      Item=entry[front];
      return 1;
    }
  }
  bool print()
  {
  if (count==0)
  return 0;
  else{
    for (int i=front; i!=rear; i=(i+1)%Maxsize){
    cout<<entry[i]<<"  ";}
    cout<<entry[rear];}
  
  return 1;
  }
};
template <class t>
bool filln(que <t>&q , int n){
int c=0;
t item;
int i=0;
t ITEM;
Sack <t> q1;
Sack <t> q2;

while (i<n+1)
{
cin>>item;
if (q.Append(item)==1)
{
  
}

else 
{
int h =1;
while (!q.isEmpty())
{

q.Retrieve(ITEM);
  q1.push(ITEM);
  q.serve();
  
}
while (!q1.isEmpty()){
if (h>=c)
{
  q1.getTOP(ITEM);
  q2.push(ITEM);
}
  h++;
  q1.pop();
}
while (!q2.isEmpty())
 { q2.getTOP(ITEM);
  q.Append(ITEM);
  q2.pop();}
  return 0;
}
c++;
i++;
}


return 1;
  
}

template <class t>
struct node 
{
  t data;
  node <t> *next;
  
  node ()
  {
    next=0;
  }
  node (t item)
  {
    data= item;
    next = 0;
  }
};
template <class t>
int size (node <t> *head){
  node <t> *temp= head ;
  int c=0;
  while( temp != 0)
  {
  c++;
    temp=temp->next;
  }
  return c;
}
template <class t>
bool AddFirst (node <t> *&head , t item)
{
  node <t> *temp = new node <t> (item) ;
  if (temp==0) return 0;
  temp -> next = head ;
  head = temp ;
  return 1;
}
template <class t>
bool print (node <t> *head)
{
node <t> *temp =head ;
  if (temp==0){
  //	cout<<"is empty "<<endl; 
  	return 0;
  } 
  else
  {
  
    while (temp!=0)
    {
    cout<<temp->data <<" ";
      temp=temp->next;
    }
   cout << "  "<<endl; ;
  }
  return 1;
}
template <class t>
bool AddLast (node <t> *&head , t item)
{
 
  node <t> *temp = head;
  if (temp==0) return 0;
  
  	
  
    while (temp->next!=NULL)
    {
	//cout<<temp->data;
	temp=temp->next;
	}
     node <t> *temp2 = new node <t> (item) ;
    temp->next=temp2;
    return 1;
  }

template <class t>
bool delFirst (node <t> *&head )
{
	if (head ==0)return 0;
	node <t> *temp = head ;
	head= head->next ;
	delete temp;
	
	 return 1;
}
template <class t>
bool delLast(node <t> *&head ) {
	
	//node <t> *temp = head ;
	node <t> *pre, *follow;
	if (head==0)return 0;
	pre=follow =head;
	while (follow->next!=0)
	{
		pre=follow;
		follow=follow->next;
	}
	pre->next=NULL;
	//delete follow;
	//cout<<follow->data; return 1;
}
template <class t>
bool delEven (node <t>*&head){
	
		node <t> *followUP, *follow ,*pre;
		pre=follow=followUP=head;
		if (head==0)return 0;
		while (follow != 0)
		{
			
		if (follow->data%2==0)
			{
			
			
			}
			
			follow=follow->next;
		}
		return 1;
}
int main(int argc, char *argv[])
{

	Sack <int>s1 ;
	Sack <int>s2;
	s1.push(10);
	s1.push(10);
	s1.push(10);
	s1.push(10);
	s2.push(20);
	s2.push(20);
	s2.push(20);
	s2.push(20);
//	s1.print();
	Concinate(s1,s2);
	s2.print();
	return 0;
}