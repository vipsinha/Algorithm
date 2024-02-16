#include <map>
#include <iostream>
#include <cassert>


template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val) : m_valBegin(val)
	{
		m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val );

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

template<typename K, typename V>
void interval_map<K, V>::assign( K const& keyBegin, K const& keyEnd, V const& val )
{
	if (!(keyBegin < keyEnd)){
		return;
	}
	else{
		// find the key range in map
		auto keyLowerBound = m_map.lower_bound(keyBegin);
		auto keyUpperBound = m_map.upper_bound(keyEnd);
		// previous to last key in the range
		auto keyUpperBoundPrev = std::prev(keyUpperBound);

		// iterators for keeping the range
		typename std::map<K, V>::iterator lowboundItr;
		typename std::map<K, V>::iterator upperboundItr;
		typename std::map<K, V>::iterator extraCell;

		// for upper end
		// if key is not the same value
		if((keyUpperBoundPrev->second != val) && (keyUpperBoundPrev->first <= keyEnd)){
			upperboundItr = m_map.insert_or_assign(keyUpperBoundPrev, keyEnd, val);
		}

		// TODO: this cell need to be deleted
		extraCell = upperboundItr;

		// for lower end
		if(keyLowerBound != m_map.begin()){
			//if(keyLowerBound->second != val){
				lowboundItr = m_map.insert_or_assign(keyLowerBound, keyBegin, val);
			//}
		} else {
			lowboundItr = m_map.insert_or_assign(keyLowerBound, keyBegin, val);
		}

		// insert the value in between
		for (auto itr = lowboundItr->first; itr < upperboundItr->first; ++itr){
			// this is for canonical, to make sure previous node does not contain same value
			if(m_map[itr-1] != val){
				++m_map.insert_or_assign(keyLowerBound, itr, val);
			}
		}
	}
}

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main() {
	interval_map<int, char> im('A');
	//im.assign(2,3,'B');
	im.assign(3,8,'C');
	im.assign(5,7,'X');
	im.assign(6,7,'T');
	im.assign(7,9,'N');
	assert(im[0]=='A');
	return 0;
}