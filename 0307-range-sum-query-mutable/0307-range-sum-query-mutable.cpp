class NumArray {
private:
    vector<int> bit;   // Fenwick Tree
    vector<int> nums;  // original array
    int n;

    // Update Fenwick Tree at index i by delta
    void addBIT(int i, int delta) {
        for (++i; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    // Prefix sum up to index i
    int sumBIT(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            addBIT(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        addBIT(index, delta);
    }
    
    int sumRange(int left, int right) {
        return sumBIT(right) - sumBIT(left - 1);
    }
};