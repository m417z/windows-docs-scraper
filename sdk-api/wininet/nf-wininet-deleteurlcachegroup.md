# DeleteUrlCacheGroup function

## Description

Releases the specified **GROUPID** and any associated state in the cache index file.

## Parameters

### `GroupId` [in]

ID of the cache group to be released.

### `dwFlags` [in]

Controls the cache group deletion. This can be set to
any member of the [cache group constants](https://learn.microsoft.com/windows/desktop/WinInet/cache-group-constants). When this parameter is set to [CACHEGROUP_FLAG_FLUSHURL_ONDELETE](https://learn.microsoft.com/windows/desktop/WinInet/cache-group-constants), it causes
**DeleteUrlCacheGroup** to delete all of the cache entries associated with this group, unless the entry belongs to another group.

### `lpReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)