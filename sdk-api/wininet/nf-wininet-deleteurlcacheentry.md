# DeleteUrlCacheEntry function

## Description

Removes the file associated with the source name from the cache, if the file exists.

## Parameters

### `lpszUrlName` [in]

Pointer to a string that contains the name of the source that corresponds to the cache entry.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The file is locked or in use. The entry is marked and deleted when the file is unlocked. |
| **ERROR_FILE_NOT_FOUND** | The file is not in the cache. |

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)