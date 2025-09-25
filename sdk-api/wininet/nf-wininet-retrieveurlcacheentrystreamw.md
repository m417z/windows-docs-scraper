# RetrieveUrlCacheEntryStreamW function

## Description

Provides the most efficient and implementation-independent way to access the cache data.

## Parameters

### `lpszUrlName` [in]

Pointer to a null-terminated string that contains the source name of the cache entry. This must be a unique name. The name string should not contain any escape characters.

### `lpCacheEntryInfo` [out]

Pointer to an
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure that receives information about the cache entry.

### `lpcbCacheEntryInfo` [in, out]

Pointer to a variable that specifies the size, in bytes, of the
*lpCacheEntryInfo* buffer. When the function returns, the variable receives the number of bytes copied to the buffer or the required size, in bytes, of the buffer. Note that this buffer size must accommodate both the [INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure and the associated strings that are stored immediately following it.

### `fRandomRead` [in]

Whether the stream is open for random access. Set the flag to **TRUE** to open the stream for random access.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

If the function succeeds, the function returns a valid handle for use in the
[ReadUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-readurlcacheentrystream) and
[UnlockUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-unlockurlcacheentrystream) functions.

If the function fails, it returns **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The cache entry specified by the source name is not found in the cache storage. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of *lpCacheEntryInfo* as specified by *lpdwCacheEntryInfoBufferSize* is not sufficient to contain all the information. The value returned in *lpdwCacheEntryInfoBufferSize* indicates the buffer size necessary to contain all the information. |

## Remarks

**RetrieveUrlCacheEntryStream** does not do any URL parsing, so a URL containing an anchor (#) will not be found in the cache, even if the resource is cached. For example, if the URL http://adatum.com/example.htm#sample is passed, the function returns ERROR_FILE_NOT_FOUND even if http://adatum.com/example.htm is in the cache.

Cache clients that do not need URL data in the form of a file should use this function to access the data for a particular URL.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines RetrieveUrlCacheEntryStream as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)