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
 * scan transaction dataset.
 * Collect F, frequent_items and their support count.
 * sort F in support count descending order as L.
 */

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

	
}

int main(int argc, char const *argv[])
{
	
	scan_dataset();
	return 0;
}