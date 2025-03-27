void merge(int a[], int n, int b[], int m, int c[]){
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m){
        if (a[i] <= b[j]) c[cnt++] = a[i], ++i;
        if (a[i] > b[j]) c[cnt++] = b[j], ++j;
    }
    while (i < n) c[cnt++] = a[i], ++i;
    while (j < m) c[cnt++] = b[j], ++j;
}
