#include <stdio.h>

insert_val_and_shift_right(int i, int val, int Best[], int K) {
    /*
    * Function: insert_val_and_shift_right
    * ----------------------------
    *   Inserts the value at index i and shift the next elements to the right
    *
    *   i: Index ti insert the value at
    *   val: The value to insert
    *   Best[]: The array used for insertion.
    *   K: The max size of the array
    * 
    */
    int m;
    for(m=K-1; m>i; m--) {
        Best[m] = Best[m-1];
    }
    Best[i] = val;
    // for(i=0; i<K; i++) {
    //     printf("%d, ", Best[i]);
    // }
    // printf("\n");
}

add_item_to_best(int val, int Best[], int K) {
    /*
    * Function: add_item_to_best
    * ----------------------------
    *   Finds the index of best to insert an item and inserts it.
    *
    *   val: The value to insert
    *   Best[]: The array used for insertion.
    *   K: The max size of the array
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

update_best(int val, int Best[], int K) {
    /*
    * Function: add_item_to_best
    * ----------------------------
    *   Finds the index of best to insert an item and inserts it
    *   if the index is lesser than the size.
    *
    *   val: The value to insert
    *   Best[]: The array used for insertion.
    *   K: The max size of the array
    * 
    */
    int i = 0;
    while(i <= K - 1 && COMPARE(Best[i], val) == 1) {
        i++;
    }
    if (i <= K -1) {
        insert_val_and_shift_right(i, val, Best, K);
    }
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
        update_best(i, Best, K);
    }
}