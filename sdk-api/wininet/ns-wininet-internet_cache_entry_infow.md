# INTERNET_CACHE_ENTRY_INFOW structure

## Description

Contains information about an entry in the Internet cache.

## Members

### `dwStructSize`

Size of this structure, in bytes. This value can be used to help determine the version of the cache system.

### `lpszSourceUrlName`

Pointer to a null-terminated string that contains the URL name. The string occupies the memory area at the end of this structure.

### `lpszLocalFileName`

Pointer to a null-terminated string that contains the local file name. The string occupies the memory area at the end of this structure.

### `CacheEntryType`

A bitmask indicating the type of cache entry and its properties. The cache entry types include: history entries (URLHISTORY_CACHE_ENTRY), cookie entries (COOKIE_CACHE_ENTRY), and normal cached content (NORMAL_CACHE_ENTRY).

This member can be zero or more of the following property flags, and cache type flags listed below.

| Value | Meaning |
| --- | --- |
| **EDITED_CACHE_ENTRY** | Cache entry file that has been edited externally. This cache entry type is exempt from scavenging. |
| **SPARSE_CACHE_ENTRY** | Partial response cache entry. |
| **STICKY_CACHE_ENTRY** | Sticky cache entry that is exempt from scavenging for the amount of time specified by **dwExemptDelta**. The default value set by [CommitUrlCacheEntryA](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-commiturlcacheentrya) and [CommitUrlCacheEntryW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-commiturlcacheentryw) is one day. |
| **TRACK_OFFLINE_CACHE_ENTRY** | Not currently implemented. |
| **TRACK_ONLINE_CACHE_ENTRY** | Not currently implemented. |

The following list contains the cache type flags.

| Value | Meaning |
| --- | --- |
| **COOKIE_CACHE_ENTRY** | Cookie cache entry. |
| **NORMAL_CACHE_ENTRY** | Normal cache entry; can be deleted to recover space for new entries. |
| **URLHISTORY_CACHE_ENTRY** | Visited link cache entry. |

### `dwUseCount`

Current number of WinINEet callers using the cache entry.

### `dwHitRate`

Number of times the cache entry was retrieved.

### `dwSizeLow`

Low-order portion of the file size, in **bytes**.

### `dwSizeHigh`

High-order portion of the file size, in **bytes**.

### `LastModifiedTime`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the last modified time of this URL, in Greenwich mean time format.

### `ExpireTime`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the expiration time of this file, in Greenwich mean time format.

### `LastAccessTime`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the last accessed time, in Greenwich mean time format.

### `LastSyncTime`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the last time the cache was synchronized.

### `lpHeaderInfo`

Pointer to a buffer that contains the header information. The buffer occupies the memory at the end of this structure.

### `dwHeaderInfoSize`

Size of the
**lpHeaderInfo** buffer, in **TCHARs**.

### `lpszFileExtension`

Pointer to a string that contains the file name extension used to retrieve the data as a file. The string occupies the memory area at the end of this structure.

### `dwReserved`

### `dwExemptDelta`

Exemption time from the last accessed time, in seconds.

## Remarks

There is no cache entry size limit, so applications that need to enumerate the cache must be prepared to allocate variable-sized buffers. For more information, see
[Using Buffers](https://learn.microsoft.com/windows/desktop/WinInet/appendix-b-using-buffers).

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines INTERNET_CACHE_ENTRY_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FindFirstUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcacheentrya)

[FindFirstUrlCacheEntryEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcacheentryexa)

[FindNextUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcacheentrya)

[FindNextUrlCacheEntryEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcacheentryexa)

[GetUrlCacheEntryInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-geturlcacheentryinfoa)

[GetUrlCacheEntryInfoEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-geturlcacheentryinfoexa)

[SetUrlCacheEntryInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-seturlcacheentryinfoa)