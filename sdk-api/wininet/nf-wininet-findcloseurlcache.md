# FindCloseUrlCache function

## Description

Closes the specified cache enumeration handle.

## Parameters

### `hEnumHandle` [in]

Handle returned by a previous call to the
[FindFirstUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcacheentrya) function.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)