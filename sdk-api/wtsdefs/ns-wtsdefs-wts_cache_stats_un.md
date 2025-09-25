# WTS_CACHE_STATS_UN structure

## Description

Contains cache statistics.

## Members

### `ProtocolCache`

A [WTS_PROTOCOL_CACHE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_protocol_cache) structure that contains information about the number of times that requested data is found in and read from the cache.

### `ProtocolCache.case`

### `ProtocolCache.case.1`

### `TShareCacheStats`

Share cache statistics.

### `TShareCacheStats.case`

### `TShareCacheStats.case.2`

### `Reserved`

Reserved protocol specific data. The maximum size, in bytes, of this data is WTS_MAX_CACHE_RESERVED multiplied by the length of an unsigned long integer.

### `Reserved.case`

### `Reserved.case.3`

## Remarks

This union is a member of the [WTS_CACHE_STATS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_cache_stats) structure. The **Specific** member of that structure contains an integer index that specifies which member of the **WTS_CACHE_STATS_UN** union contains the cache data.