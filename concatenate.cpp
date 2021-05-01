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
bool Concinate (Sack<t>&s1 ,Sack<t>&s2)
{
	
  t Item ;
  Sack <t> nwTemp;
  
  while (!s2.isEmpty())
  {
  s2.getTOP(Item);
    nwTemp.push(Item);
    s2.pop();
  }
  int c=0;
  while (!nwTemp.isEmpty())
  {
    nwTemp.getTOP(Item);
    if (s1.push(Item)==0){
      for (int i=0 ;i<c; i++  )
      {
      s1.getTOP(Item);
      nwTemp.push(Item);
        s1.pop();
      }
      while (!nwTemp.isEmpty())
      {
        nwTemp.getTOP(Item);
        s2.push(Item);
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
	s1.print();
	return 0;
}