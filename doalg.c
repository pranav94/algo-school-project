#include <string.h>;
#define MAXK 100

void insert_val_and_shift_right(int index, int val, int Best[], int K) {
    /*
     * Function: insert_val_and_shift_right
     * ------------------------------------
     * Inserts the value at the given index and shifts the next elements to the right.
     */
    int i;
    for (i = K - 1; i > index; i--) {
        Best[i] = Best[i - 1];
    }
    Best[index] = val;
}

int bin_ins(int low, int high, int val, int Best[]) {
    /* 
     * Function: bin_ins
     * -----------------
     * Performs a binary search for the index to insert the element at.
     */
    if (low == high)
        return low;
    int mid = low + (high - low) / 2;
    if (COMPARE(Best[mid], val) == 2)
        return bin_ins(low, mid, val, Best);
    else
        return bin_ins(mid + 1, high, val, Best);
}

int doalg(int n, int K, int Best[]) {
    memset(Best, 0, 100);
    int i;

    // Insert first k items into Best in a reverse sorted fashion.
    for (i = 1; i <= K; i++) {
        int insert_index = bin_ins(0, i - 1, i, Best);
        insert_val_and_shift_right(insert_index, i, Best, K);
    }

    // Iterate through all the items and insert to Best if required.
    for (i = K + 1; i <= n; i++) {
        if (COMPARE(Best[K - 1], i) == 1)
            continue;
        int insert_index = bin_ins(0, K - 1, i, Best);
        insert_val_and_shift_right(insert_index, i, Best, K);
    }

	return 1;

}
