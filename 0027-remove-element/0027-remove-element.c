int removeElement(int* nums, int numsSize, int val) {
    int k = 0;  // index for next valid element

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
