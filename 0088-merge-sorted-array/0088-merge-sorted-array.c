void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;        // pointer for nums1's actual elements
    int j = n - 1;        // pointer for nums2
    int k = m + n - 1;    // pointer for placement in nums1 (end)

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining nums2 elements if any
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
