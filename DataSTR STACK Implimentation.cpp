#include <iostream>
using namespace std;
const int maxsize =100;

template <class t>

class Sack {
	int top;
	t item[maxsize];
	public :
	Sack ():top (-1){}
	void push (t Element)
	{
		if (top>=maxsize-1 )
		{
			cout<<"the stack full "<<endl;
		}
		else{
			top++;
		item[top] = Element;	
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
void deleteEvenItem (Sack <t>&temp)
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
			if (x<xx && xTemp.getTOP()==INTbyUser)
			 // that play once time not each time 
			{
				xTemp.pop();
			 	x++;	
			} 
 			TEMP.push(xTemp.getTOP());
 			xTemp.pop();
		}
}
template <class t>
void DeleteITEMmiddle(Sack <t>&T )
{
	Sack <t>xMiddle;
	int counter=0;
	while (!T.isEmpty())
	{
		xMiddle.push(T.getTOP());
		T.pop();
		counter++;
	}
	int i=counter/2;
	int j=0;
	
	while (!xMiddle.isEmpty())	
	{
		if (j==i)
		{
			xMiddle.pop();	
		}
		j++;
			T.push(xMiddle.getTOP());
		xMiddle.pop();
	}

	
}
int main(int argc, char *argv[])
{
	
		Sack <int>s1;
		s1.push(12);
		s1.push(3);
		s1.push(2);
		s1.push(3);
		s1.push(7);
		s1.push(3);
		s1.push(8);
		
		deletItemX(s1,7);
		DELfirstItemX(s1,3);
		deletItemX(s1,2);
		deletItemX(s1,8);
		s1.print();
		
	return 0;
}