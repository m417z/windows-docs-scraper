# CreateUrlCacheContainerA function

## Description

Creates a cache container in the specified cache path to hold cache entries based on the specified name, cache prefix, and container type.

**Note** Note: This API is deprecated. Please use the [Extensible Storage Engine](https://learn.microsoft.com/previous-versions/windows/desktop/Gg269259(v=EXCHG.10)) instead.

## Parameters

### `Name` [in]

The name to give to the cache.

### `lpCachePrefix` [in]

The cache prefix to base the cache on.

### `lpszCachePath` [in, optional]

The cache prefix to create the cache in.

### `KBCacheLimit` [in]

The size limit of the cache in whole kilobytes, or 0 for the default size.

### `dwContainerType` [in]

The container type to base the cache on.

### `dwOptions` [in]

This parameter is reserved and must be 0.

### `pvBuffer`

This parameter is reserved and must be **NULL**.

### `cbBuffer` [in, out]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[CommitUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-commiturlcacheentryw)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)

## Remarks

> [!NOTE]
> The winineti.h header defines CreateUrlCacheContainer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).