#include "LRUCache.h"
#include <iostream>

int LRUCache::get(int key)
{
	auto find = myMap.find(key);
	if (find != myMap.end()) {
		auto iter = find->second;
		myList.splice(myList.begin(), myList, iter);
		myMap[key] = myList.begin();
		return myList.front().second;
	}
	else
		return -1;
}

void LRUCache::put(int key, int value)
{
	auto find = myMap.find(key);
	if (find != myMap.end())
	{
		auto iter = myMap[key];
		iter->second = value;
		myList.splice(myList.begin(), myList, iter);
		return;
	}
	if (capacity == myMap.size()) {
		int k = myList.back().first;
		myList.pop_back();
		myMap.erase(k);
	}
	myList.push_front(std::pair<int, int>(key, value));
	myMap.insert(std::pair<int, std::list<std::pair<int, int>>::iterator>(key, myList.begin()));
}

int main() {
	LRUCache* cache = new LRUCache(1);
	cache->put(2, 1);
	std::cout << cache->get(2) << "\n";
	cache->put(2, 2);
	std::cout << cache->get(2)<<"\n";
	std::cout << cache->get(3);
	return 0;
}