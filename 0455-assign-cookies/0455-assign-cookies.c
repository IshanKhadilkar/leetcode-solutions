int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // Sort greed factors and cookie sizes
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int i = 0; // children index
    int j = 0; // cookies index

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            // Cookie satisfies child
            i++;
            j++;
        } else {
            // Cookie too small, try next cookie
            j++;
        }
    }

    return i; // number of content children
}