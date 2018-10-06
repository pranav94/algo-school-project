#include <stdio.h>

insert_after_rshift(int i, int val, int Best[], int K) {
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

bisect(int val, int Best[], int K) {
    int i = 0;
    while(i <= K - 1) {
        if (Best[i] == 0)
            break;
        if (COMPARE(Best[i], val) == 2)
            break;
        i++;
    }
    return i;
}

doalg(int n, int K, int Best[]) {
    // printf("Some output");
    int i, j;
    for(i=1; i<= K; i++) {
        int index = bisect(i, Best, K);
        insert_after_rshift(index, i, Best, K);
    }
    for(i=K+1; i<= n; i++) {
        int index = bisect(i, Best, K);
        if (index <= K -1) {
            insert_after_rshift(index, i, Best, K);
        }
    }
    // for(i=0; i<K; i++) {
    //     printf("%d", Best[i]);
    // }
}