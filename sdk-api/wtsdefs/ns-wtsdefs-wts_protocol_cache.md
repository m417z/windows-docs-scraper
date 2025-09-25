# WTS_PROTOCOL_CACHE structure

## Description

Contains the number of cache reads and cache hits.

## Members

### `CacheReads`

An integer that contains the number of times cached data was read.

### `CacheHits`

An integer that contains the number of times the cache was hit. A cache hit occurs if required data is found in the cache rather than in main memory or on disk. If the data is found in the cache, it is read from the cache.