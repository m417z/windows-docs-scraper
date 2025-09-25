# SetUrlCacheEntryGroupA function

## Description

Adds entries to or removes entries from a cache group.

## Parameters

### `lpszUrlName` [in]

Pointer to a **null**-terminated string value that specifies the URL of the cached resource.

### `dwFlags` [in]

Determines whether the entry is added to or removed from a cache group. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_CACHE_GROUP_ADD | Adds the cache entry to the cache group. |
| INTERNET_CACHE_GROUP_REMOVE | Removes the entry from the cache group. |

### `GroupId` [in]

Identifier of the cache group that the entry will be added to or removed from.

### `pbGroupAttributes` [in]

This parameter is reserved and must be **NULL**.

### `cbGroupAttributes` [in]

This parameter is reserved and must be 0.

### `lpReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

A cache entry can belong to more than one cache group.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines SetUrlCacheEntryGroup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)