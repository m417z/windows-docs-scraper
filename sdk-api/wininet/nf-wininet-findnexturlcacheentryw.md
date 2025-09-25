# FindNextUrlCacheEntryW function

## Description

Retrieves the next entry in the Internet cache.

## Parameters

### `hEnumHandle` [in]

Handle to the enumeration obtained from a previous call to
[FindFirstUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcacheentrya).

### `lpNextCacheEntryInfo` [out]

Pointer to an
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure that receives information about the cache entry.

### `lpcbCacheEntryInfo` [in, out]

Pointer to a variable that specifies the size of the
*lpNextCacheEntryInfo* buffer, in bytes. When the function returns, the variable contains the number of bytes copied to the buffer, or the size of the buffer required to retrieve the cache entry, in bytes.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The size of *lpNextCacheEntryInfo* as specified by *lpdwNextCacheEntryInfoBufferSize* is not sufficient to contain all the information. The value returned in *lpdwNextCacheEntryInfoBufferSize* indicates the buffer size necessary to contain all the information. |
| **ERROR_NO_MORE_ITEMS** | The enumeration completed. |

## Remarks

Continue to call **FindNextUrlCacheEntry** until the last item in the cache is returned.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FindNextUrlCacheEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)