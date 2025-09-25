# CommitUrlCacheEntryA function

## Description

Stores data in the specified file in the Internet cache and associates it with the specified URL.

## Parameters

### `lpszUrlName` [in]

Pointer to a string variable that contains the source name of the cache entry. The name string must be unique and should not contain any escape characters.

### `lpszLocalFileName` [in]

Pointer to a string variable that contains the name of the local file that is being cached. This should be the same name as that returned by
**CreateUrlCacheEntryA**.

### `ExpireTime` [in]

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the expire date and time (in Greenwich mean time) of the file that is being cached. If the expire date and time is unknown, set this parameter to zero.

### `LastModifiedTime` [in]

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the last modified date and time (in Greenwich mean time) of the URL that is being cached. If the last modified date and time is unknown, set this parameter to zero.

### `CacheEntryType` [in]

A bitmask indicating the type of cache entry and its properties. The cache entry types include: history entries (URLHISTORY_CACHE_ENTRY), cookie entries (COOKIE_CACHE_ENTRY), and normal cached content (NORMAL_CACHE_ENTRY).

This parameter can be zero or more of the following property flags, and cache type flags listed below.

| Value | Meaning |
| --- | --- |
| COOKIE_CACHE_ENTRY | Cookie cache entry. |
| EDITED_CACHE_ENTRY | Cache entry file that has been edited externally. This cache entry type is exempt from scavenging. |
| NORMAL_CACHE_ENTRY | Normal cache entry; can be deleted to recover space for new entries. |
| SPARSE_CACHE_ENTRY | Partial response cache entry. |
| STICKY_CACHE_ENTRY | Sticky cache entry; exempt from scavenging. |
| TRACK_OFFLINE_CACHE_ENTRY | Not currently implemented. |
| TRACK_ONLINE_CACHE_ENTRY | Not currently implemented. |
| URLHISTORY_CACHE_ENTRY | Visited link cache entry. |

### `lpHeaderInfo` [in]

Pointer to the buffer that contains the header information. If this parameter is not **NULL**, the header information is treated as extended attributes of the URL that are returned in the **lpHeaderInfo**
member of the [INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure.

### `cchHeaderInfo` [in]

Size of the header information, in **TCHARs**. If
*lpHeaderInfo* is not **NULL**, this value is assumed to indicate the size of the buffer that stores the header information. An application can maintain headers as part of the data and provide
*cchHeaderInfo* together with a **NULL** value for
*lpHeaderInfo*.

### `lpszFileExtension` [in]

This parameter is reserved and must be **NULL**.

### `lpszOriginalUrl` [in]

Pointer to a string that contains the original URL, if redirection has occurred.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code | Description |
| --- | --- |
| **ERROR_DISK_FULL** | The cache storage is full. |
| **ERROR_FILE_NOT_FOUND** | The specified local file is not found. |

## Remarks

The STICKY_CACHE_ENTRY type is used to make cache entries exempt from scavenging. The default exempt time for entries set using
**CommitUrlCacheEntryA** is ten minutes. The exempt time can be changed by setting the expires time parameter in the [INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure in the call to the
[SetUrlCacheEntryInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-seturlcacheentryinfoa) function.

If the cache storage is full,
**CommitUrlCacheEntryA** invokes cache cleanup to make space for this new file. If the cache entry already exists, the function overwrites the entry if it is not in use. An entry is in use when it has been retrieved with either
[RetrieveUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentrystreama) or
[RetrieveUrlCacheEntryFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentryfilea).

Clients that add entries to the cache should set the headers to at least "HTTP/1.0 200 OK\r\n\r\n"; otherwise, Microsoft Internet Explorer and other client applications should disregard the entry.

See [Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching) for example code calling **CreateUrlCacheEntryA**.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines CommitUrlCacheEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)