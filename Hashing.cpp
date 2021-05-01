#include <iostream>
using namespace std;
const int size = 10;
template <class t>
struct node {
		t data;
		node <t> *next;
		node (){
			next = 0;
		}
		node (t item){
			data = item;
			next = 0;
		}
};
template <class t>
class Map {
		t entry [size];
		int colletion = 0;
		int hashFun(t key){
			return key%size;
		}
		int hashKeyChecked(int loc ){
			while (entry[loc]!=-1){
				loc++;
				colletion++;
			}
			return loc;
		}
		public : 
		bool add ( t key){
			entry[hashKeyChecked(key)]
		}
};
int main(int argc, char *argv[])
{
	
	return 0;
}