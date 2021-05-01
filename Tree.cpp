#include <iostream>
using namespace std;
template<class t >
struct dnode {
		t data;
    dnode<t> *right ,
    *left ;

    dnode() {
        right = left = 0;

    }

    dnode(t item) {
        data = item;
        right = left = 0;
    }
};
template<class t>
class BT {

        dnode<t> *root ;

        int Height(dnode<t>*root){
	if (root == 0) {
                return -1;
            }
            return (Max(Height(root -> left), Height(root -> right))) + 1;
        }
		bool CheckIfBST (dnode<t>*root){
			if (root==NULL)return 1;
			else if (root->left != NULL){
		
				 if (root->data >= root->left->data)
				 	{
				return (CheckIfBST (root->left)&& CheckIfBST (root->right));	
				}
			else if (root->right
				&& root->data <= root->right->data){
			}
			}
			else{
				return 0;
			}
			
		}
        int countLeaves(dnode<t>  
            *root){
	if (root == NULL) {
                return 0;
            }
            if (root -> left == NULL && root -> right == NULL) {
                return 1;
            }
            return countLeaves(root -> left) + countLeaves(root -> right);
        }

        int Size(dnode<t>*root){
	if (root == 0) {
                return 0;
            }
            return Size(root -> left) + Size(root -> right) + 1;
        }

        void PreOrder(dnode<t>*root){
	
	if (root != NULL) {
                cout << root -> data << endl;
                PreOrder(root -> left);
                PreOrder(root -> right);
            }
        }

        void PostOrder(dnode<t>*root){ //LRV
	
				if (root != NULL) {
                PostOrder(root -> left);
                PostOrder(root -> right);
                cout << root -> data << endl;
           		 }
        		}

        void InOrder(dnode<t>*root) {//LVR
		
	
				if (root != NULL) {
                InOrder(root -> left);
                cout << root -> data << endl;
            	InOrder(root -> right);
            	}
        }
dnode<t>* Search(dnode<t>*root , t item){
		if (root != NULL) {
                if (root -> data == item) {
                    return root;
                }
                if (item < root->data) {
                    return Search(root->left, item);
                } else if (item > root -> data) {
                    return Search(root->right, item);
                }
            } else {
                return 0;
            }
        }

bool insert(dnode<t>*root , t item){
        	if (item <= root->data){
	        	if (root->left == NULL){
					root->left=new dnode<t> (item);
					return 1;
				}
	        	else{
	        		insert (root->left, item);
	        	}
	        }
	        else{
      				if (root->right == NULL)
					  {
					  	root->right =new dnode<t> (item);
					  	return 1;
						  }
	        		else{
	        		insert (root->right, item);
	        		}
        	}
        }
	
bool Delete(dnode<t>*root , t item){
	
        
        }
	
        int Max(int a, int b) {
            if (a >= b) {
                return a;
            } else {
                return b;
            }
        }
		int Min(int a, int b) {
            if (a <= b) {
                return a;
            } else {
                return b;
            }
        }
        public:
 	
        BT() {
            root = 0;
        }

        bool Search(t item) {
            if (root == NULL) {
                return 0;
            }
            if (Search(root, item) == NULL) {
                return 0;
            } else {
                return 1;
            }
        }

        bool insert(t item){
        	if (root==NULL) {root = new dnode<t> (item); return 1;}
        	else {
	        	insert (root , item);
	        }
        }

        bool Delete(t item){
        	if (root==NULL)return 0;
        	if (Search (item)==0)return 0;
       		else Delete (root , item);
        }

        int Height() {
            return Height(root);
            

        }
		bool CheckIfBST (){
			if (root==NULL)return 0;
			return (CheckIfBST(root));
		}
        int countLeaves() {
            return countLeaves(root);
        }

        int Size() {
             return Size(root);
        }

        void PreOrder() {
             PreOrder(root); //VLR
        }

        void InOrder() {
            InOrder(root);
        }

        void PostOrder() {
             PostOrder(root);

        }

    };
//dnode <t> *root
//int BT ::

    int main(int argc, char  *argv[])
{
	BT <int> TREE ;
	
	TREE.insert(10);
	TREE.insert(5);
	TREE.insert(19);
	TREE.insert(1);
	TREE.insert(6);
	TREE.insert(17);
	
	TREE.insert(21);
	TREE.insert(15);
	TREE.insert(18);
	if (TREE.CheckIfBST())
	cout<<"ext"<<endl;
	TREE.PreOrder();
	
        return 0;
    
}
