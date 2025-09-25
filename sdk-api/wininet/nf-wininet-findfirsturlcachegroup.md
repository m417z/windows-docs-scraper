# FindFirstUrlCacheGroup function

## Description

Initiates the enumeration of the cache groups in the Internet cache.

## Parameters

### `dwFlags` [in]

This parameter is reserved and must be 0.

### `dwFilter` [in]

Filters to be used. This parameter can be zero or one of the following values.

| Value | Meaning |
| --- | --- |
| CACHEGROUP_SEARCH_ALL | Search all cache groups. |
| CACHEGROUP_SEARCH_BYURL | Not currently implemented. |

### `lpSearchCondition` [in]

This parameter is reserved and must be **NULL**.

### `dwSearchCondition` [in]

This parameter is reserved and must be 0.

### `lpGroupId` [out]

Pointer to the ID of the first cache group that matches the search criteria.

### `lpReserved` [in, out]

This parameter is reserved and must be **NULL**.

## Return value

Returns a valid handle to the first item in the enumeration if successful, or **NULL** otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the function finds no matching files,
**GetLastError** returns ERROR_NO_MORE_FILES.

## Remarks

The handle returned from **FindFirstUrlCacheGroup** is used in subsequent calls to [FindNextUrlCacheGroup](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findnexturlcachegroup). At the end of the enumeration, the application should call
[FindCloseUrlCache](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-findcloseurlcache).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)