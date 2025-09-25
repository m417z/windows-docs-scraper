# UnlockUrlCacheEntryFile function

## Description

Unlocks the cache entry that was locked while the file was retrieved for use from the cache.

## Parameters

### `lpszUrlName` [in]

Pointer to a **null**-terminated string that specifies the source name of the cache entry that is being unlocked. The name string should not contain any escape characters.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). ERROR_FILE_NOT_FOUND indicates that the cache entry specified by the source name is not found in the cache storage.

## Remarks

The application should not access the file after calling this function.

When this function returns, the cache manager is free to delete the cache entry.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)