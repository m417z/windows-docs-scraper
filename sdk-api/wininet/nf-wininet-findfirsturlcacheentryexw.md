# FindFirstUrlCacheEntryExW function

## Description

Starts a filtered enumeration of the Internet cache.

## Parameters

### `lpszUrlSearchPattern` [in]

A pointer to a string that contains the source name pattern to search for. This parameter can only be set to "cookie:", "visited:", or NULL. Set this parameter to "cookie:" to enumerate the cookies or "visited:" to enumerate the URL History entries in the cache. If this parameter is NULL, **FindFirstUrlCacheEntryEx** returns all content entries in the cache.

### `dwFlags` [in]

Controls the enumeration. No flags are currently implemented; this parameter must be set to zero.

### `dwFilter` [in]

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

### `GroupId` [in]

ID of the cache group to be enumerated. Set this parameter to zero to enumerate all entries that are not grouped.

### `lpFirstCacheEntryInfo` [out]

Pointer to a
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure to receive the cache entry information.

### `lpcbCacheEntryInfo` [in, out]

Pointer to variable that indicates the size of
the structure referenced by the *lpFirstCacheEntryInfo* parameter, in bytes.

### `lpGroupAttributes` [out]

This parameter is reserved and must be NULL.

### `lpcbGroupAttributes` [in, out]

This parameter is reserved and must be NULL.

### `lpReserved` [in]

This parameter is reserved and must be NULL.

## Return value

Returns a valid handle if successful, or NULL otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the function finds no matching files,
**GetLastError** returns ERROR_NO_MORE_FILES.

## Remarks

The handle returned from **FindFirstUrlCacheEntryEx** is used in all subsequent calls to [FindNextUrlCacheEntryEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcacheentryexa). At the end of the enumeration, the application should call
[FindCloseUrlCache](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findcloseurlcache).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FindFirstUrlCacheEntryEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)