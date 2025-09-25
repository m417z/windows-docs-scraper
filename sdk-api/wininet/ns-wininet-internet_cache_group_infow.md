# INTERNET_CACHE_GROUP_INFOW structure

## Description

Contains the information for a particular cache group.

## Members

### `dwGroupSize`

Size of the structure, **TCHARs**.

### `dwGroupFlags`

Group flags. Currently, the only value defined is CACHEGROUP_FLAG_NONPURGEABLE, which indicates that the cache entries in this group will not be removed by the cache manager.

### `dwGroupType`

Group type. Currently, the only value defined is CACHEGROUP_TYPE_INVALID.

### `dwDiskUsage`

Current disk usage of this cache group, in kilobytes.

### `dwDiskQuota`

Disk quota for this cache group, in kilobytes.

### `dwOwnerStorage`

Array that can be used by a client application to store information related to the group.

### `szGroupName`

Group name.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines INTERNET_CACHE_GROUP_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetUrlCacheGroupAttribute](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-geturlcachegroupattributea)

[SetUrlCacheGroupAttribute](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-seturlcachegroupattributea)