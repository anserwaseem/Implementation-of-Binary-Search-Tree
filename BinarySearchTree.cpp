#include<iostream>
#include<string>
#include<stack>
static int Leafcount=0;
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	node() : data(0), left (nullptr), right(nullptr) {}
};
class BST
{
	node* root;
	bool insertRec(node* root, int d)//rapper
	{
		if(d < root->data)
		{
			if(root->left==nullptr)
				{
					root->left=new node();
					root->left->data=d;
					return true;
				}
			else
				return insertRec(root->left,d);
		}
		if(d > root->data)
		{
			if(root->right==nullptr)
				{
					root->right=new node();
					root->right->data=d;
					return true;
				}
			else
				return insertRec(root->right,d);
		}
		return false;
	}
	void inorderRec(node* root)//rapper
	{
		if(root==nullptr)
			return;
		inorderRec(root->left);
		cout<<root->data<<" ";
		inorderRec(root->right);
	}
	int lengthRec(node* root)//rapper
	{
		if(root==nullptr)
			return 0;
		return 1+lengthRec(root->left)+lengthRec(root->right);//1 is because root != nullptr + left side node + right side nodes
	}
	node* searchRec(node* root, int key)
	{
		if(root->data==key)
			return root;
		else if(key < root->data)
		{
			if(root->left==nullptr)
			{
				cout<<key<<" not found\n";
				return nullptr;
			}
			return searchRec(root->left, key);
		}
		else if(key > root->data)
		{
			if(root->right==nullptr)
			{
				cout<<key<<" not found\n";
				return nullptr;
			}
			return searchRec(root->right, key);
		}
		cout<<key<<" not found\n";
		return nullptr;
	}
	void deleteKeyRec(node* root, node* parent, int key)
	{
		if(root->data==key)
		{
			if(root->left==nullptr && root->right==nullptr)//if leaf node
				{
					if(parent->data > root->data)
						parent->left=nullptr;
					else
						parent->right=nullptr;
				}
			else if(root->left==nullptr || root->right==nullptr)//if one child
				{
					if(parent->right->data==root->data)//if child is on right side
					{
						//check which side of the node to be deleted is not nullptr, move that side to parent
						if(root->left==nullptr)
							parent->right=root->right;
						else
							parent->right=root->left;
					}
					else if(parent->left->data==root->data)//if child is on left side
					{
						//check which side of the node to be deleted is not nullptr, move that side to parent
						if(root->left==nullptr)
							parent->left=root->right;
						else
							parent->left=root->left;
					}
				}
			else//if two children
			{
				node* temp=successor(root->right);
				if(root->right->data==temp->data)
				{
					// node* trl=root->left;
					// temp->left=root->left;
					// root=nullptr;
					// root=temp;
					root=copyRec(temp, root);
					root->left=this->root->left;
					this->root=root;
				}
				else
				{
					root->data=temp->data;
					node* c=root->right;
					while(c->left!=nullptr && c->left->left!=nullptr)
					{
						c=c->left;
					}
					c->left=nullptr;
				}
			}
		}
		else if(key < root->data)
		{
			if(root->left==nullptr)
			{
				cout<<key<<" not found (and not deleted as well).\n";
				return;
			}
			deleteKeyRec(root->left, root, key);
		}
		else if(key > root->data)
		{
			if(root->right==nullptr)
			{
				cout<<key<<" not found (and not deleted as well).\n";
				return;
			}
			deleteKeyRec(root->right, root, key);
		}
	}
	node* successor(node* subtree)
	{
		node* c;
		if(subtree->left==nullptr)
		{
			c=copyRec(subtree, c);
			return c;
		}
		c=subtree;
		while(c!=nullptr && c->left!=nullptr)
		c=c->left;
		return c;
	}
	node* copyRec(node* r,node* copying)
	{
		if(r == NULL)
        	return NULL;
    	else
		{
			copying=new node();
			copying->data = r->data;
			if(r->left!=nullptr)
				copying->left=copyRec(r->left, copying->left);
			if(r->right!=nullptr)
				copying->right=copyRec(r->right, copying->right);
			return copying;
		}
	}
	void leafNodesRecHelper(node* root)
	{
		if(root->left==nullptr && root->right==nullptr)
		{
			++Leafcount;
			return;
		}
		if(root->left==nullptr && root->right!=nullptr)
			leafNodesRecHelper(root->right);
		else if(root->left!=nullptr && root->right==nullptr)
			leafNodesRecHelper(root->left);
		else //if(root->left!=nullptr && root->right!=nullptr)
		{
			leafNodesRecHelper(root->left);
			leafNodesRecHelper(root->right);
		}
	}
	void delRec(node* r,node* p, int n)
	{
		if(r->data==n)
			{
				if(p->data==r->data)
					root=nullptr;
				else if(p->left!=nullptr)
					p->left=nullptr;
				else if(p->right!=nullptr)
					p->right=nullptr;
			}
		else if(n<r->data)
			delRec(r->left, r, n);
		else if(n>r->data)
			delRec(r->right, r, n);
		else
			return;
	}
	int FindHeightRec(node* treee)
	{
		if(treee==nullptr)
			return -1;
		return max(FindHeightRec(treee->left), FindHeightRec(treee->right)) + 1;
	}
	void PrintSpiralRec(node* Root, int depth, bool ltr)
	{
		if(Root==nullptr)
			return;
		if(depth==1)
			cout<<Root->data<<"\t";
		else
		{
			if(ltr)
			{
				PrintSpiralRec(Root->left, depth-1, ltr);
				PrintSpiralRec(Root->right, depth-1, ltr);
			}
			else
			{
				PrintSpiralRec(Root->right, depth-1, ltr);
				PrintSpiralRec(Root->left, depth-1, ltr);
			}
		}
	}
	void rem(node* r)
	{
		if(r==nullptr)
		{
			delete r;
			return;
		}
		else if(r->left!=nullptr)
		{
			rem(r->left);
			delete r->left;
		}
		else if(r->right!=nullptr)
		{
			rem(r->right);
			delete r->right;
		}
		else /*(r->left!=nullptr && r->right!=nullptr)*/
		{
			rem(r->left);
			delete r->left;
			rem(r->right);
			delete r->right;
		}
	}
public:
	BST()
	{
		root=nullptr;
	}
	BST(const BST &obj)
	{
		root=copyRec(root, obj.root);
	}
	void inorderPrint ()
	{
		inorderRec(root);
	}
	bool insert(int d)
	{
		if(root==nullptr)
		{
			root=new node();
			root->data=d;
			return true;
		}
		else
			return insertRec(this->root, d);
	}
	int length()//total number of elements of tree
	{
		return lengthRec(root);
	}
	node* search(int key)
	{
		return searchRec(root, key);
	}
	void deleteKey(int key)
	{
		deleteKeyRec(root, nullptr, key);
	}
	int leafNodes()//iterative
	{
		Leafcount=0;//removing old value
		node*parent=root;
		node* lc=parent->left;
		node* rc=parent->right;
		while(lc!=nullptr||rc!=nullptr)//for left
		{
			if(lc->left==nullptr && lc->right==nullptr)
			{
				Leafcount++;
				if(rc->left==nullptr && rc->left==nullptr)
					Leafcount++;
				break;
			}
			if(lc->left==nullptr && lc->right!=nullptr)
			lc=rc=lc->right;
			else if(lc->left!=nullptr && lc->right==nullptr)
			lc=lc->left;
			else //if(root->left!=nullptr && root->right!=nullptr)
			{
				lc=lc->left;
				rc=lc->right;
			}
		}
		lc=parent->left;
		rc=parent->right;
		while(lc!=nullptr||rc!=nullptr)//for left
		{
			if(rc->left==nullptr && rc->right==nullptr)
			{
				Leafcount++;
				if(lc->left==nullptr && lc->left==nullptr)
					Leafcount++;
				break;
			}
			if(rc->left==nullptr && rc->right!=nullptr)
			rc=lc=rc->right;
			else if(rc->left!=nullptr && rc->right==nullptr)
			lc=rc->left;
			else //if(root->left!=nullptr && root->right!=nullptr)
			{
				lc=rc->left;
				rc=rc->right;
			}
		}
		return Leafcount;
	}
	int leafNodesRec()//recursive
	{
		leafNodesRecHelper(root);
		return Leafcount;
	}
	void print()
	{
		stack<node*> temp_storage;
		node*ptr=root;
		while (ptr!=nullptr || !temp_storage.empty()) 
		{ 
			while (ptr!=nullptr) 
			{
				temp_storage.push(ptr); 
				ptr=ptr->left; 
			}
			ptr = temp_storage.top(); 
			temp_storage.pop();
			cout << ptr->data << " ";
			ptr = ptr->right;
		}
	}
	BST get_BST(int n)
	{
		BST subtree;
		node* foundORnot=searchRec(root, n);
		subtree.root=copyRec(foundORnot, subtree.root);
		return subtree;
	}
	void deleteSubTree(int n)
	{
		delRec(root,root, n);//(root node, parent node, key)
	}
	bool update(int key1, int key2)
	{
		node* foundORnot=searchRec(root, key1);
		if(foundORnot==nullptr)
			return false;
		deleteKey(key1);
		insert(key2);
		// foundORnot->data=key2;
		return true;
	}
	int FindHeight()
	{
		return FindHeightRec(this->root);
	}
	void PrintSpiral()
	{
		bool ltr=false;
		int maxx=FindHeight()+1;
		for(int depth=1;depth<=maxx;depth++)
		{
			PrintSpiralRec(this->root, depth, ltr);
			ltr = (ltr==true ? false : true);//flip ltr
		}
	}
	~BST()
	{
		rem(root);
	}
};

int main()
{
	BST *tree=new BST();

	//			4
	//		   / \
	//		  1	  6
	//		  \    \
	//		  3    10
	//		 /	   / \
	//		2	  8  11

	cout<<tree->insert(4)<<endl;
	cout<<tree->insert(6)<<endl;
	cout<<tree->insert(10)<<endl;
	cout<<tree->insert(4)<<endl;//repeating
	cout<<tree->insert(1)<<endl;
	cout<<tree->insert(8)<<endl;
	cout<<tree->insert(3)<<endl;
	cout<<tree->insert(8)<<endl;//repeating
	cout<<tree->insert(2)<<endl;
	cout<<tree->insert(11)<<endl;

	cout<<"inorder print: ";tree->inorderPrint();cout<<endl;
	cout<<"Length = "<<tree->length()<<endl;

	cout<<"Spiral Order:\t";	tree->PrintSpiral(); cout<<endl;
	
	int height=tree->FindHeight();
	cout<<"Height: "<<height<<endl;
	//searching 'key' in the tree
	int key;
	key=8;	node *s1=tree->search(key);	if(s1!=nullptr){cout<<key<<" found\n";}
	key=6;	node *s2=tree->search(key);	if(s2!=nullptr){cout<<key<<" found\n";}
	key=99;	node *s3=tree->search(key);	if(s3!=nullptr){cout<<key<<" found\n";}

	int leafNodesRECURSION=tree->leafNodesRec();	cout<<"Number of leaf nodes -> using recursion: "<<leafNodesRECURSION<<endl;
	int leafNodesITERATION=tree->leafNodes();	cout<<"Number of leaf nodes -> using iteration: "<<leafNodesITERATION<<endl;

	//deleting sub tree having 'key' as its root
	key=2;	tree->deleteSubTree(key);
	cout<<"Deleted SUBTREE with data->"<<key<<": ";	tree->print();cout<<endl;
	
	//making a new sub tree from original tree with root as 'key'
	key=66;	BST subb=tree->get_BST(key);
	cout<<"Sub tree with "<<key<<" as root: ";	subb.print();cout<<endl;
	
	//deleting the main root i.e, 'key'
	key=4;	tree->deleteKey(key); cout<<key<<" deleted\n";

	//replacing key1 with key2 and re-adjusting the BST
	int key1, key2;
	key1=8;key2=5;	tree->update(key1, key2);
	cout<<"Updated "<<key1<<" with "<<key2<<endl;
	cout<<"iterative printing: ";tree->print();cout<<endl;
	
	key1=6;key2=7;	tree->update(key1, key2);
	cout<<"Updated "<<key1<<" with "<<key2<<endl;
	cout<<"iterative printing: ";tree->print();cout<<endl;
	
	key1=1;key2=9;	tree->update(key1, key2);
	cout<<"Updated "<<key1<<" with "<<key2<<endl;
	cout<<"iterative printing: ";tree->print();cout<<endl;
	return 0;
}