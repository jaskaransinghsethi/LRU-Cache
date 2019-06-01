#pragma once
#include <list>
#include <unordered_map>
class LRUCache
{
public:
	LRUCache(int capacity) : capacity(capacity) { }
	~LRUCache() { }
	int get(int key);
	void put(int key, int value);
private:
	int capacity;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> myMap;
	std::list<std::pair<int, int>> myList;
};

