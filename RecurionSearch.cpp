#include <iostream>
using namespace std;
template<class t>
int secSer (t entry[] , int s , int e , t X);
template<class t>
int binSer (t entry[] , int f , int l , t X );
int main(int argc, char *argv[])
{
	int arr [5] = {
		10 ,20 ,30 ,40 , 50 
	};
	cout<<binSer(arr , 0 , 5, 10)<<endl;
	return 0;
}
template<class t>
int secSer (t entry[] , int s , int e , t X){
	if (s>e)return -1;
	if (entry[s] == X) return s;
	s++;
	return secSer(entry , s , e, X);
}
template<class t>
int binSer (t entry[] , int f , int l , t X ){
	
	if (f>l)return -1;
	int mid = (f+l)/2;
	if (entry[mid]==X)return mid;
	else if (entry[mid]>X) return binSer (entry , f , l-1 ,X);
	else  return binSer (entry , f+1 , l, X);
}