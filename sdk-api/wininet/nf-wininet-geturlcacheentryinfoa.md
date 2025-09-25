# GetUrlCacheEntryInfoA function

## Description

Retrieves information about a cache entry.

## Parameters

### `lpszUrlName` [in]

A pointer to a null-terminated string that contains the name of the cache entry. The name string should not contain any escape characters.

### `lpCacheEntryInfo` [out]

A pointer to an
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure that receives information about the cache entry. A buffer should be allocated for this parameter.

Since the required size of the buffer is not known in advance, it is best to allocate a buffer adequate to handle the size of most [INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) entries. There is no cache entry size limit, so applications that need to enumerate the cache must be prepared to allocate variable-sized buffers.

### `lpcbCacheEntryInfo` [in, out]

A pointer to a variable that specifies the size of the
*lpCacheEntryInfo* buffer, in bytes. When the function returns, the variable contains the number of bytes copied to the buffer, or the required size of the buffer, in bytes.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The specified cache entry is not found in the cache. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of *lpCacheEntryInfo* as specified by *lpdwCacheEntryInfoBufferSize* is not sufficient to contain all the information. The value returned in *lpdwCacheEntryInfoBufferSize* indicates the buffer size necessary to contain all the information. |

## Remarks

**GetUrlCacheEntryInfo** does not do any URL parsing, so a URL containing an anchor (#) will not be found in the cache, even if the resource is cached. For example, if the URL `http://example.com/example.htm#sample` is passed, the function returns **ERROR_FILE_NOT_FOUND** even if `http://example.com/example.htm` is in the cache.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GetUrlCacheEntryInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)