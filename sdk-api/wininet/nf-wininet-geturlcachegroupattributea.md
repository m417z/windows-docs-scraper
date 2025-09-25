# GetUrlCacheGroupAttributeA function

## Description

Retrieves the attribute information of the specified cache group.

## Parameters

### `gid` [in]

Identifier of the cache group.

### `dwFlags` [in]

This parameter is reserved and must be 0.

### `dwAttributes` [in]

Attributes to be retrieved. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| CACHEGROUP_ATTRIBUTE_BASIC | Retrieves the flags, type, and disk quota attributes of the cache group. |
| CACHEGROUP_ATTRIBUTE_FLAG | Sets or retrieves the flags associated with the cache group. |
| CACHEGROUP_ATTRIBUTE_GET_ALL | Retrieves all the attributes of the cache group. |
| CACHEGROUP_ATTRIBUTE_GROUPNAME | Sets or retrieves the group name of the cache group. |
| CACHEGROUP_ATTRIBUTE_QUOTA | Sets or retrieves the disk quota associated with the cache group. |
| CACHEGROUP_ATTRIBUTE_STORAGE | Sets or retrieves the group owner storage associated with the cache group. |
| CACHEGROUP_ATTRIBUTE_TYPE | Sets or retrieves the cache group type. |

### `lpGroupInfo` [out]

Pointer to an
[INTERNET_CACHE_GROUP_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_group_infoa) structure that receives the requested information.

### `lpcbGroupInfo` [in, out]

Pointer to a variable that contains the size of the
*lpGroupInfo* buffer. When the function returns, the variable contains the number of bytes copied to the buffer, or the required size of the buffer, in bytes.

### `lpReserved` [in, out]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get specific error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GetUrlCacheGroupAttribute as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)