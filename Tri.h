#include<iostream>
using namespace std;

struct TriNode{
	int val;
	TriNode* left;
	TriNode* right;
	TriNode* down;
	TriNode(int x):val(x),left(NULL),right(NULL),down(NULL){}
};

class TriTree{
	TriNode *root;
	TriNode* deleteHelp(int x,TriNode* node);
	TriNode* findSucc(TriNode* node);
	bool findHelp(int x, TriNode* node);
public:
	TriTree(){root=NULL;}
	void insertVal(int x);
	void deleteVal(int x);
	bool find(int x);
};

//helper for find
bool TriTree::findHelp(int x,TriNode* node){
	if(node==NULL)
		return false;
	if(x==node->val)
		return true;
	else if(x<node->val)
		return findHelp(x,node->left);
	else
		return findHelp(x,node->right);
};

//find value x in the tree
bool TriTree::find(int x){
	return findHelp(x,this->root);
};

//insert x in to the tree
void TriTree::insertVal(int x){
	if(this->root==NULL){
		this->root=new TriNode(x);
		return;
	}
	TriNode *cur=this->root;
	TriNode *pre;		//remember the last node
	while(cur){
		pre=cur;
		if(x<cur->val)
			cur=cur->left;
		else if(x==cur->val)
			cur=cur->down;
		else
			cur=cur->right;
	}
	//insert the new node
	TriNode *nNode=new TriNode(x);
	if(x<pre->val)
		pre->left=nNode;
	else if(x==pre->val)
		pre->down=nNode;
	else
		pre->right=nNode;
	return;
};

//helper for delete
TriNode* TriTree::deleteHelp(int x, TriNode* node){
	if(node==NULL){
		cout<<"Cannot find the value to delete"<<endl;
		return NULL;
	}
	if(x<node->val)
		node->left=deleteHelp(x,node->left);
	else if(x>node->val)
		node->right=deleteHelp(x,node->right);
	else{
		if(node->left==NULL&&node->right==NULL&&node->down==NULL){
			delete node;
			return NULL;
		}
		if(node->down!=NULL)
			node->down=deleteHelp(x,node->down);
		else{
			if(node->left!=NULL&&node->right!=NULL){
				//both left and right are empty change 
				//the value to be the smallest value(successor)
				//in the right subtree, then delete the 
				//successor
				TriNode* successor=findSucc(node->right);
				node->val=successor->val;
				node->right=deleteHelp(successor->val,node->right);	
			}else if(node->left!=NULL){
				//only left is node empty
				TriNode* tmp=node->left;
				delete node;
				return tmp;
			}else{
				//only right is not empty
				TriNode* tmp=node->right;
				delete node;
				return tmp;
			}
		}
	}
	return node;
};
//delete value x from the tree
void TriTree::deleteVal(int x){
	this->root=deleteHelp(x,this->root);
}

TriNode* TriTree::findSucc(TriNode* node){
	if(node->left==NULL)
		return node;
	else
		return findSucc(node->left);
}
