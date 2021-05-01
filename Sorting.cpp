#include <iostream>
using namespace std;
void Swap (int &a , int &b);
void BubbleSort (int a[] , int n);
void printArr (int a[] , int size);
void selecSort (int a[] , int n);
void insSort (int a[] , int n);
int main(int argc, char *argv[])
{
	int a[4] = {57,55,75,27};
	insSort(a,4);
//	BubbleSort(a , 4);
	printArr(a,4);
	return 0;
}

void insSort (int a[] , int n){
	int pos=-1;
	for (int i=0 ; i<n-1 ; i++){
		
			pos = i+1;
			while (pos>0 && a[pos]<a[pos-1]){
				
				Swap(a[pos],a[pos-1]);
				pos--;
			}
		
	}
}
void selecSort (int a[] , int n){
	
	for (int i=0 ; i<n ; i++){
		int minPos=i;
		for (int j=i+1 ; j<n ; j++){
			if (a[j]<a[minPos])
			minPos=j;
		}
		Swap(a[i],a[minPos]);
	}
}
void BubbleSort (int a[] , int n){

		for (int i=0 ; i<n-1 ; i++){
			
		for (int j=0 ; j<n-i-1 ; j++){
			if (a[j]>a[j+1])
			{
				Swap(a[j],a[j+1]);
			}
		}
		printArr(a,4);
	
	}
}
void Swap (int &a , int &b){
	int temp = a;
	a=b;
	b=temp;
	
}
void printArr (int a[] , int size){
	cout<<"[";
	for (int i=0 ;i<size ; i++)
	cout<<a[i]<<" |";
	cout<<"]"<<endl;
}