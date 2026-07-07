int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    int sum = 0;
    // Add every second element (the min in each pair)
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }

    return sum;
}