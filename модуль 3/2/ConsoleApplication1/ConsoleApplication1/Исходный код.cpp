#include<iostream>
#include<vector>
using namespace std;
template<class T>
class CTree {
public:
	CTree() : root(0) {}
	~CTree() { /*clear(root);*/ }
//	void Remove(T& key) { }
private:
	struct CNode {
		T key;
		CNode* Left;
		CNode* Right;
	};
public:
	void in_order(CNode *node);
	void Add(T& key);
	CNode* root;
};

template<class T>
void CTree<T>::Add(T& key)
{
	if (!root){
		root = new CNode;
		root->key = key;
		root->Left = 0;
		root->Right = 0;
		return;
	}
	CNode *node = root;
	while (node){
		if (node->key < key){
			node = node->Right;
			continue;
		}
		else{
			node = node->Left;
			continue;
		}
	}
	node = new CNode;
	node->key = key;
	node->Left = 0;
	node->Right = 0;
}
template <class T>
void CTree<T>::in_order(CNode *node)
{
	if (node == 0) return;
	in_order(node->Left);
	in_order(node->Right);
	cout << node->key << " ";
}
int main()
{
	CTree<int> tree;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a = 0;
		cin >> a;
		tree.Add(a);
	}
	tree.in_order(tree.root);
	system("pause");
	return 0;
}