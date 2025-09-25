# UnlockUrlCacheEntryStream function

## Description

Closes the stream that has been retrieved using the
[RetrieveUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentrystreama) function.

## Parameters

### `hUrlCacheStream` [in]

Handle that was returned by the
[RetrieveUrlCacheEntryStream](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-retrieveurlcacheentrystreama) function.

### `Reserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)