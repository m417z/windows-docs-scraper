# FindNextUrlCacheGroup function

## Description

Retrieves the next cache group in a cache group enumeration started by
[FindFirstUrlCacheGroup](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcachegroup).

## Parameters

### `hFind` [in]

The cache group enumeration handle, which is returned by
[FindFirstUrlCacheGroup](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findfirsturlcachegroup).

### `lpGroupId` [out]

Pointer to a variable that receives the cache group identifier.

### `lpReserved` [in, out]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Continue to call **FindNextUrlCacheGroup** until the last item in the cache is returned.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)