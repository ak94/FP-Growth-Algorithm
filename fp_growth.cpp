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

 int main(int argc, char const *argv[])
 {

 	scan_dataset();
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