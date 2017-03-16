/*------------------------------------------------
PROGRAMMER:Shoeb Mohammed
PROGRAM: Assignment5
Implement Assignment5.h to reprensent a binary tree
of integers.
-------------------------------------------------*/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5
#include <iomanip>
#include <algorithm>
using namespace std;
//--------------------------
// You need to add definition of the Node class
//--------------------------

class Node {
 //   friend class binTree<int>;
//Node class definition
    public:
	int data;
	Node* leftChild;
	Node* rightChild;

	Node(int val){leftChild=0;
		      rightChild=0;
		      data=val;}

};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );
    protected:
        Node* root;
    private:
        void insert( Node*& root, int data );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};

binTree::binTree(){
	root = 0;
}
/*------------------------------------------------------
Height
Recursively counts down the right and left subtree
-------------------------------------------------------*/
unsigned binTree::height()const{
	return height(root);

}

unsigned binTree::height(Node* ptr)const{
	//int heightLeft=0;
	//int heightRight=0;
	if(ptr==0)
	{
		return 0;
	}

	else
	{
		return max(height(ptr->leftChild),height(ptr->rightChild))+1;
	}
	/*if(ptr->leftChild!=0)
	{
		heightLeft = height(ptr->leftChild);
	}
	if(ptr->rightChild!=0)
	{
		heightRight = height(ptr->rightChild);
	)
	if(heightLeft>heightRight)
	{
		return heightLeft+1;
	}else{
		return heightRight+1;
	     }*/
}
/*-------------------------------------------------------
Insert
Inserts the value wherever it is required to balance the
tree
-------------------------------------------------------*/
void binTree::insert(int val){
	insert(root,val);
}

void binTree::insert(Node*&ptr, int val){
	if (ptr==nullptr)
		ptr = new Node(val);
	else
	{
		if(height(ptr->rightChild)< height(ptr->leftChild))
			insert(ptr->rightChild,val);
		else
		{
			insert(ptr->leftChild,val);
		}
	}
}
/*-----------------------------------------------------
Inorder
Inorder, Left, Node, Right.
-------------------------------------------------------*/
void binTree::inorder(void(* p)(int)){
	inorder(root,p);
}

void binTree::inorder(Node*ptr,void(*p)(int)){
	if(ptr!=NULL)
	{
		inorder(ptr->leftChild,p);
		p( ptr->data);
		inorder(ptr->rightChild,p);
	}
}

/*----------------------------------------------------------
Preorder
Preorder, Node,Left,Right.
------------------------------------------------------------*/
void binTree::preorder(void(* p)(int)){
	preorder(root,p);
}

void binTree::preorder(Node*ptr,void(*p)(int)){
	if(ptr!=NULL)
	{
		p(ptr->data);
		preorder(ptr->leftChild,p);
		preorder(ptr->rightChild,p);
	}
}
/*----------------------------------------------------------
PostOrder
Postorder, Left,Right,Node
------------------------------------------------------------*/
void binTree::postorder(void(* p)(int)){
	postorder(root,p);
}

void binTree::postorder(Node*ptr,void(*p)(int)){
	if(ptr!=NULL)
	{
		postorder(ptr->leftChild,p);
		postorder(ptr->rightChild,p);
		p(ptr->data);
	}
}
/*---------------------------------------------------------------
Size
Recursively counts until total size found
-----------------------------------------------------------------*/
unsigned binTree::size()const{
	return size(root);
}

unsigned binTree::size(Node *ptr) const{
	if(ptr==NULL)
	return 0;
	else
		return(size(ptr->leftChild)+ 1 + size(ptr->rightChild));
}
#endif


