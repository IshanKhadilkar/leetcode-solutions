class MyHashSet {
private:
    static const int SIZE = 1000; // number of buckets
    vector<list<int>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        table.resize(SIZE);
    }
    
    void add(int key) {
        int h = hash(key);
        for (int k : table[h]) {
            if (k == key) return; // already exists
        }
        table[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = table[h].begin(); it != table[h].end(); ++it) {
            if (*it == key) {
                table[h].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (int k : table[h]) {
            if (k == key) return true;
        }
        return false;
    }
};