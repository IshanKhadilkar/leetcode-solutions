class MyHashMap {
private:
    static const int SIZE = 1000; // number of buckets
    vector<list<pair<int,int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int h = hash(key);
        for (auto &p : table[h]) {
            if (p.first == key) {
                p.second = value; // update existing
                return;
            }
        }
        table[h].push_back({key, value}); // insert new
    }
    
    int get(int key) {
        int h = hash(key);
        for (auto &p : table[h]) {
            if (p.first == key) return p.second;
        }
        return -1; // not found
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = table[h].begin(); it != table[h].end(); ++it) {
            if (it->first == key) {
                table[h].erase(it);
                return;
            }
        }
    }
};