#include "bits/stdc++.h"
/**
 * include header file containing fp tree data structure
 */
#include "fp_tree_ds.hpp"

 using namespace std;
#define MAPI map<int,int>
#define FOR_MAP(ii,structure,T) for(structure::iterator (ii)=(T).begin();(ii)!=(T).end();(ii)++)
#define FOR_next_MAP(jj,ii,structure,T) for(structure::iterator (jj)=(ii);(jj)!=(T).end();(jj)++)

/**
 * minimum support count
 */
 const int MIN_SUP = 2;
/**
 * contains freq item in descending order
 */
 vector<pair<int,bool> > order_of_freq_item_id;
 node *root;

/**
 * scan transaction dataset.
 * Collect F, frequent_items and their support count.
 * sort F in support count descending order as L.
 */
void scan_dataset();
/**
 * generate order list of frequent data items in desc order
 * @param map_freq_set contains frequent data-item and their count
 */
void form_desc_order_list_of_freq_item(MAPI map_freq_set);
/**
 * Tree Formation
 * @param head            itemid to be inserted
 * @param list_of_items   items from transaction in desc order 
 * @param index_to_insert item currently to be inserted from list_of_items
 */
void insert(node *head,vector<int> list_of_items,int index_to_insert);
/**
 * scan database and insert items in tree
 */
void tree_creation();



















int main(int argc, char const *argv[])
 {
 	root=new node;
 	scan_dataset();
 	tree_creation();




 	return 0;
 }

 void scan_dataset()
 {
	/**
	 * map_freq_set contains freq_item_id and their support count
	 * support count >= MIN_SUP
	 */
	 MAPI map_freq_set;
	 map_freq_set.clear();


	 ifstream fin;
	/**
	 * dataset file name
	 */
	 fin.open("input.txt");

	 if(!fin)
	 {
	 	cout<<"ErrorID:FPG_1 Opening input file\n";
	 	exit(0);
	 }

	 int item_id;

	 while(fin>>item_id)
	 {
	 	if(item_id!=-1)
	 	{
			if(map_freq_set.count(item_id)>0)//if item_id is already present
				map_freq_set[item_id]++;
			else
				map_freq_set[item_id]=1;
		}
	}
	fin.close();

	MAPI map_temp;
	map_temp.clear();

	FOR_MAP(ii,MAPI,map_freq_set)
	{
		if (ii->second>=MIN_SUP)		
		{
			map_temp[ii->first]=ii->second;
		}
	}

	map_freq_set.clear();
	map_freq_set=map_temp;
	form_desc_order_list_of_freq_item(map_freq_set);

}

void form_desc_order_list_of_freq_item(MAPI map_freq_set)
{
	order_of_freq_item_id.clear();
	
	FOR_MAP(ii,MAPI,map_freq_set)
	{
		int max_count = 0;
		int max_item_id = 0;

		FOR_MAP(jj,MAPI,map_freq_set)
		{
			if(jj->second > max_count)
			{
				max_count = jj->second;
				max_item_id = jj->first;
			}
		}

		if (max_item_id > 0)
		{
			order_of_freq_item_id.push_back(make_pair(max_item_id,false));
			map_freq_set[max_item_id]=-1;
		}
	}

	/*for (int i = 0; i < order_of_freq_item_id.size(); ++i)
	{
		cout<<order_of_freq_item_id[i].first<<" "<<order_of_freq_item_id[i].second<<"\n";
	}*/
}

void insert(node *head,vector<int> list_of_items,int index_to_insert)
{

}

void tree_creation()
{
	ifstream fin;
	fin.open("input.txt");
	int item_id;
	std::vector<int> items_to_be_inserted;
	items_to_be_inserted.clear();
	while(fin>>item_id)
	{
		if(item_id==-1)
		{
			/**
			 * check all those who are true in order_of_freq_list
			 * then add them to items_to_be_inserted
			 * then insert items_to_be_inserted in tree
			 */
			for(int ii=0;ii<order_of_freq_item_id.size();ii++)
			{
				if(order_of_freq_item_id[ii].second==true)
					items_to_be_inserted.push_back(order_of_freq_item_id[ii].first);
			}

			insert(root,items_to_be_inserted,0);

			items_to_be_inserted.clear();

			for(int ii=0;ii<order_of_freq_item_id.size();ii++)
				order_of_freq_item_id[ii].second=false;

		}else
		{
			for(int ii=0;ii<order_of_freq_item_id.size();ii++)
			{
				if(order_of_freq_item_id[ii].first == item_id)
				{
					order_of_freq_item_id[ii].second=true;
					break;
				}
			}
		}
	}
}