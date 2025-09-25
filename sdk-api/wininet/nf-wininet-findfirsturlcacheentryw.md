# FindFirstUrlCacheEntryW function

## Description

Begins the enumeration of the Internet cache.

## Parameters

### `lpszUrlSearchPattern` [in]

A pointer to a string that contains the source name pattern to search for. This parameter can only be set to "cookie:", "visited:", or **NULL**. Set this parameter to "cookie:" to enumerate the cookies or "visited:" to enumerate the URL History entries in the cache. If this parameter is **NULL**, **FindFirstUrlCacheEntry** returns all content entries in the cache.

### `lpFirstCacheEntryInfo` [out]

Pointer to an
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure.

### `lpcbCacheEntryInfo` [in, out]

Pointer to a variable that specifies the size of the
*lpFirstCacheEntryInfo* buffer, in bytes. When the function returns, the variable contains the number of bytes copied to the buffer, or the required size needed to retrieve the cache entry, in bytes.

## Return value

Returns a handle that the application can use in the
[FindNextUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcacheentrya) function to retrieve subsequent entries in the cache. If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

ERROR_INSUFFICIENT_BUFFER indicates that the size of
*lpFirstCacheEntryInfo* as specified by
*lpdwFirstCacheEntryInfoBufferSize* is not sufficient to contain all the information. The value returned in
*lpdwFirstCacheEntryInfoBufferSize* indicates the buffer size necessary to contain all the information.

## Remarks

The handle returned from **FindFirstUrlCacheEntry** is used in all subsequent calls to [FindNextUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcacheentrya). At the end of the enumeration, the application should call
[FindCloseUrlCache](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findcloseurlcache).

**FindFirstUrlCacheEntry** and
[FindNextUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcacheentrya) return variable size information. If ERROR_INSUFFICIENT_BUFFER is returned, the application should allocate a buffer of the size specified by
*lpdwFirstCacheEntryInfoBufferSize*. For more information, see
[Using Buffers](https://learn.microsoft.com/windows/desktop/WinInet/appendix-b-using-buffers).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FindFirstUrlCacheEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)