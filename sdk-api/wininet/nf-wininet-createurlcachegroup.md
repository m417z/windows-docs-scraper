# CreateUrlCacheGroup function

## Description

Generates cache group identifications.

## Parameters

### `dwFlags` [in]

Controls the creation of the cache group. This parameter can be set to
[CACHEGROUP_FLAG_GIDONLY](https://learn.microsoft.com/windows/desktop/WinInet/cache-group-constants), which causes
**CreateUrlCacheGroup** to generate a unique GROUPID, but does not create a physical group.

### `lpReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns a valid **GROUPID** if successful, or **FALSE** otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)