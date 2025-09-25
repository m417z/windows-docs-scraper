# FindNextUrlCacheEntryExA function

## Description

Finds the next cache entry in a cache enumeration started by the
[FindFirstUrlCacheEntryEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcacheentryexa) function.

## Parameters

### `hEnumHandle` [in]

Handle returned by
[FindFirstUrlCacheEntryEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcacheentryexa), which started a cache enumeration.

### `lpNextCacheEntryInfo` [in, out]

Pointer to the
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure that receives the cache entry information.

### `lpcbCacheEntryInfo` [in, out]

Pointer to a variable that indicates the size of the buffer, in bytes.

### `lpGroupAttributes`

This parameter is reserved and must be **NULL**.

### `lpcbGroupAttributes`

This parameter is reserved and must be **NULL**.

### `lpReserved`

This parameter is reserved.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Continue to call **FindNextUrlCacheEntryEx** until the last item in the cache is returned.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FindNextUrlCacheEntryEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)