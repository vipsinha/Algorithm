/*

146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

*/



#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;


class LRUCache {
public:
    
    int cache_size;
    
    // DLL to store the Least Recently Used Cache
    // Front -> Most Recently Used
    // Back -> Not so recently used / Last Element in Cache
    // Adding directly in front will be O(1) time.
	list<pair<int, int>> dll; 
    
    // Map to store the key and address of the node of the DLL.
    // This will help us retrieve the node in O(1) time.
	unordered_map<int, list<pair<int, int>>::iterator> map;
    
    // Size of the Cache is fixed, we evict the least recently used if required.
    LRUCache(int capacity) {
        cache_size = capacity;
    }
    
    int get(int key) {
        // If the key is present in the map, we find the value and return it
        // We must also bring that node to the "front" since it is USED now!!
        // To bring it to the front, 
        //      we delete the old node, 
        //      add a new node in front with same key,val
        //      update the map with address of new node
        
        if(map.find(key) == map.end()){
            return -1;
        }
        else{
            list<pair<int, int>>::iterator it0 = map[key];
            pair<int, int> node = *it0;
            
            dll.erase(map[key]);
            dll.push_front(make_pair(key, node.second));
            map[key] = dll.begin();
            
            return node.second;
        }
    }
    
    
    void put(int key, int value) {
        // If the key is NOT present in the map (it is NOT present in cache)
        //      If the cache is full
        //          We delete the last element from cache and map
        //          We add new element in front and its address in the map
        //      If the cache is vacant
        //          We add new element in front and its address in the map
        // If node is present in the map (it is present in the cache)
        //      Erase the node which was already present
        //          We add new element in front and its address in the map

        if(map.find(key) == map.end()){
            pair<int, int> last_element = dll.back();
            if(dll.size() == cache_size){
                dll.pop_back();
                map.erase(last_element.first);
            }
        }
        else {
            dll.erase(map[key]);
        }
        
        dll.push_front(make_pair(key, value));
        map[key] = dll.begin();
        // show();
    }
    
    
    // void show(){
    //     cout<<"DLL: ";
    //     for(auto l : dll){
    //         cout<<l.first<<","<<l.second<<" -> ";
    //     }
    //     cout<<endl;
    //     cout<<"Map: ";
    //     for(auto m: map){
    //         cout<<m.first<<" ";
    //     }
    //     cout<<endl<<"***"<<endl;
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key,value);
    return 0;
}