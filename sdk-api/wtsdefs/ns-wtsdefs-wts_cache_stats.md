# WTS_CACHE_STATS structure

## Description

Contains protocol cache statistics.

## Members

### `Specific`

An integer index that specifies the [WTS_CACHE_STATS_UN](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_cache_stats_un) union member that contains the cache data. This can be one of the following values.

#### 1

The cache data is contained in the **ProtocolCache** member.

#### 2

The cache data is contained in the **TShareCacheStats** member.

#### 3

The cache data is contained in the **Reserved** member.

### `Data`

A [WTS_CACHE_STATS_UN](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_cache_stats_un) union that contains the cache statistics.

### `ProtocolType`

An integer that specifies the protocol type. This is not currently used by the Remote Desktop Services service.

### `Length`

An integer that contains the length of the data in the **Reserved** member of the [WTS_CACHE_STATS_UN](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_cache_stats_un) union. The maximum size is WTS_MAX_CACHE_RESERVED multiplied by the length of an unsigned long integer.

## Remarks

This structure is a member of the [WTS_PROTOCOL_STATUS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_protocol_status) structure.