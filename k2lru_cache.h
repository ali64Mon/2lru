/*
 * Impelemented by Alireza Montazeri
 */

#ifndef K2LRU_CACHE_H_
#define K2LRU_CACHE_H_
#include <boost/unordered_map.hpp>
#include "base_cache.h"
#include "ccnsim.h"


using namespace std;
using namespace boost;


//Indicate the position within the virtual and  physical caches (both are implemented as lru caches). In order to look-up for an
//element it just suffices removing the element from the current position and
//inserting it within the head of the list
struct lru_pos{
    //older and newer track the lru_position within the 
    //lru cache
    lru_pos* older;
    lru_pos* newer;
    chunk_t k;
    simtime_t hit_time;
	//<aa>
	double cost; //meaningful only with cost aware caching
	//</aa>
};



//	A simple 2-LRU cache is defined by using a map and a list of positions within the map.
class k2lru_cache:public base_cache
{
    friend class statistics;
    public:
		k2lru_cache():base_cache(),actual_size(0),vc_mru(0),vc_lru(0),pc_mru(0),pc_lru(0){;}

		lru_pos* get_pc_mru();
		lru_pos* get_pc_lru();
		const lru_pos* get_eviction_candidate();
	
		bool full();

    protected:
		void data_store(chunk_t);
		bool data_lookup(chunk_t);
		bool fake_lookup(chunk_t);
		void initialize();

		void dump();

    private:
		uint32_t actual_size; 		// size of the physical cache (# objects).
		uint32_t vc_size;       	// size of the virtual cache (# objects).

		lru_pos* pc_mru; 			//	Least Recently Used object in physical cache.
		lru_pos* pc_lru; 			//	Most Recently Used object in physical cache.

		lru_pos* vc_mru; 			//	Least Recently Used object in virtual cache.
		lru_pos* vc_lru; 			//	Most Recently Used object in virtual cache.

		unordered_map<chunk_t, lru_pos*> pc;  // phyiscal cache
		unordered_map<chunk_t, lru_pos*> vc;  // virtual cache

};
#endif
