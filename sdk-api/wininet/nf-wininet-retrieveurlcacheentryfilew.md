# RetrieveUrlCacheEntryFileW function

## Description

Locks the cache entry file associated with the specified URL.

## Parameters

### `lpszUrlName` [in]

Pointer to a string that contains the URL of the resource associated with the cache entry. This must be a unique name. The name string should not contain any escape characters.

### `lpCacheEntryInfo` [out]

Pointer to a cache entry information buffer. If the buffer is not sufficient, this function returns ERROR_INSUFFICIENT_BUFFER and sets
*lpdwCacheEntryInfoBufferSize* to the number of bytes required.

### `lpcbCacheEntryInfo` [in, out]

Pointer to an unsigned long integer variable that specifies the size of the
*lpCacheEntryInfo* buffer, in bytes. When the function returns, the variable contains the size, in bytes, of the actual buffer used or the number of bytes required to retrieve the cache entry file. The caller should check the return value in this parameter. If the return size is less than or equal to the size passed in, all the relevant data has been returned.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include:

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The cache entry specified by the source name is not found in the cache storage. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *lpCacheEntryInfo* buffer as specified by *lpdwCacheEntryInfoBufferSize* is not sufficient to contain all the information. The value returned in *lpdwCacheEntryInfoBufferSize* indicates the buffer size necessary to get all the information. |

## Remarks

**RetrieveUrlCacheEntryFile** does not do any URL parsing, so a URL containing an anchor (#) will not be found in the cache, even if the resource is cached. For example, if the URL http://adatum.com/example.htm#sample was passed, the function would return ERROR_FILE_NOT_FOUND even if http://adatum.com/example.htm is in the cache.

The file is locked for the caller when it is retrieved; the caller should unlock the file after the caller is finished with the file. The cache manager automatically unlocks the files after a certain interval. While the file is locked, the cache manager will not remove the file from the cache. It is important to note that this function may or may not perform efficiently, depending on the internal implementation of the cache. For instance, if the URL data is stored in a packed file that contains data for other URLs, the cache will make a copy of the data to a file in a temporary directory maintained by the cache. The cache will eventually delete the copy. It is recommended that this function be used only in situations where a file name is needed to launch an application.
[RetrieveUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentrystreama) and associated stream functions should be used in most cases.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines RetrieveUrlCacheEntryFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)