#include <stdio.h>
#include<string.h>
insert_val_and_shift_right(int i, int val, int Best[], int K) {
/*
* Function: insert_val_and_shift_right
* ----------------------------
* Inserts the value at index i and shift the next elements to the right
*
* i: Index ti insert the value at
* val: The value to insert
* Best[]: The array used for insertion.
* K: The max size of the array
*
*/
	int m;
	for(m=K-1; m>i; m--) 
	{
		Best[m] = Best[m-1];
	}
	Best[i] = val;
}


add_item_to_best(int val, int Best[], int K) {
/*
* Function: add_item_to_best
* ----------------------------
* Finds the index of best to insert an item and inserts it.
*
* val: The value to insert
* Best[]: The array used for insertion.
* K: The max size of the array
*
*/
	int i = 0;
	while(i <= K - 1) {
	if (Best[i] == 0)
	break;
	if (COMPARE(Best[i], val) == 2)
	break;
	i++;
	}
insert_val_and_shift_right(i, val, Best, K);
}

int bin_ins(int i, int j, int val, int Best[])
{	
/* 
* Function: bin_ins: Returns the index for incoming element to be inserted 
* ----------------------------
*/
	if(i==j)
	return i;
	int mid = i + (j-i)/2;
	if(COMPARE(Best[mid],val)==2)
		return bin_ins(i, mid, val, Best);
	else
		return bin_ins(mid + 1, j, val, Best);
}

update_best(int val, int Best[], int K) {
/*
* Function: update_best
* ----------------------------
* Finds the index of best to insert an item and inserts it
* if the index is lesser than the size.
*
* val: The value to insert
* Best[]: The array used for insertion.
* K: The max size of the array
*
*/
/*	int i = K -1;
	while(i >= 0 && COMPARE(Best[i], val) == 2) {
	i--;
	}
	if (i != K -1) {
	insert_val_and_shift_right(i+1, val, Best, K);
	}
*/
	
	int i = bin_ins(0,K-1,val,Best);
	if(i>K-1)
		return;
	else
		insert_val_and_shift_right(i, val, Best, K);
}

doalg(int n, int K, int Best[]) {
	memset(Best, 0, sizeof Best);
	int i, j;
	// Insert first k items into Best in a reverse sorted fashion.
	for(i=1; i<= K; i++) {
	add_item_to_best(i, Best, K);
	}
	// Iterate through all the items and update Best if required.
	for(i=K+1; i<= n; i++) {
	if(COMPARE(Best[K-1],i)==1)
		continue;
	update_best(i, Best, K);
}
}
