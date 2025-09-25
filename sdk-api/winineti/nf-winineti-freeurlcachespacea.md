# FreeUrlCacheSpaceA function

## Description

Frees space in the cache.

**Note** This API is deprecated. Please use the [Extensible Storage Engine](https://learn.microsoft.com/previous-versions/windows/desktop/Gg269259(v=EXCHG.10)) instead.

## Parameters

### `lpszCachePath`

The path for the cache.

### `dwSize`

The percentage of the cache to free (in the range 1 to 100, inclusive).

### `dwFilter` [in]

This parameter is reserved, and must be 0.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service nor when impersonating a security context. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The winineti.h header defines FreeUrlCacheSpace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[CreateUrlCacheContainer](https://learn.microsoft.com/windows/desktop/api/winineti/nf-winineti-createurlcachecontainera)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)