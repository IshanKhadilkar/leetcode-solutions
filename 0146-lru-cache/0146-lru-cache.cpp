class LRUCache {
private:
    int capacity;
    list<pair<int,int>> cache; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> map; // key -> iterator in list

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1; // not found
        }
        // Move accessed node to front
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Key exists: update and move to front
            auto it = map[key];
            cache.erase(it);
        } else if ((int)cache.size() == capacity) {
            // Evict least recently used (back)
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }
        // Insert new node at front
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};