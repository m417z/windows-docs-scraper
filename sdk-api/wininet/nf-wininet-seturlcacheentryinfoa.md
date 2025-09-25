# SetUrlCacheEntryInfoA function

## Description

Sets the specified members of the
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure.

## Parameters

### `lpszUrlName` [in]

Pointer to a null-terminated string that specifies the name of the cache entry. The name string should not contain any escape characters.

### `lpCacheEntryInfo` [in]

Pointer to an
[INTERNET_CACHE_ENTRY_INFO](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_cache_entry_infoa) structure containing the values to be assigned to the cache entry designated by
*lpszUrlName*.

### `dwFieldControl` [in]

Indicates the members that are to be set. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| CACHE_ENTRY_ACCTIME_FC | Sets the last access time. |
| CACHE_ENTRY_ATTRIBUTE_FC | Sets the cache entry type. |
| CACHE_ENTRY_EXEMPT_DELTA_FC | Sets the exempt delta. |
| CACHE_ENTRY_EXPTIME_FC | Sets the expire time. |
| CACHE_ENTRY_HEADERINFO_FC | Not currently implemented. |
| CACHE_ENTRY_HITRATE_FC | Sets the hit rate. |
| CACHE_ENTRY_MODTIME_FC | Sets the last modified time. |
| CACHE_ENTRY_SYNCTIME_FC | Sets the last sync time. |

## Return value

Returns TRUE if successful, or FALSE otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The specified cache entry is not found in the cache. |
| **ERROR_INVALID_PARAMETER** | The value(s) to be set is invalid. |

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines SetUrlCacheEntryInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)