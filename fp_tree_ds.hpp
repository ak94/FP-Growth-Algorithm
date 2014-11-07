#ifndef FP_TREE_DS
#define FP_TREE_DS 

struct node
{
	int item; //item set
	int count; // item set count
	std::vector<node *> child; // its children node
	node *parent; // ptr to parent
	node()
	{
		parent=NULL;
	}
};

#endif