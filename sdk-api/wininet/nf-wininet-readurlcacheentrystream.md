# ReadUrlCacheEntryStream function

## Description

Reads the cached data from a stream that has been opened using the
[RetrieveUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentrystreama) function.

## Parameters

### `hUrlCacheStream` [in]

Handle that was returned by the
[RetrieveUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentrystreama) function.

### `dwLocation` [in]

Offset to be read from.

### `lpBuffer` [in, out]

Pointer to a buffer that receives the data.

### `lpdwLen` [in, out]

Pointer to a variable that specifies the size of the
*lpBuffer* buffer, in bytes. When the function returns, the variable contains the number of bytes copied to the buffer, or the required size of the buffer, in bytes.

### `Reserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the buffer size is not sufficient,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER and sets
*lpdwLen* to the size necessary to contain all the information.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)