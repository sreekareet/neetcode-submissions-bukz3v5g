class LRUCache {
    int c;
    list<pair<int,int>> lst;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1; //key is not found
        }
        auto it = mp[key];
        int value = it -> second; //get the value to return
        //as the key is updated need to delete and insert in front -- as its recently used
        lst.erase(it); 
        lst.push_front({key,value});
        mp[key] = lst.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){ //already key exists then delete
            lst.erase(mp[key]);
            mp.erase(key);
        }
        if(mp.size() >= c){ //capacity exceeded so delete last element
            auto lru = lst.back();
            mp.erase(lru.first);
            lst.pop_back();
        }
        lst.push_front({key,value});
        mp[key] = lst.begin();
    }
};
