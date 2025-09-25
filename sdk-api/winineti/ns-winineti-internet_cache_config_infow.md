# INTERNET_CACHE_CONFIG_INFOW structure

## Description

Contains information about the configuration of the Internet cache.

## Members

### `dwStructSize`

Size of this structure, in bytes. This value can be used to help determine the version of the cache system.

### `dwContainer`

The container that the rest of the data in the struct applies to. 0 (zero) indicates the content container.

### `dwQuota`

The cache quota limit of the container specified in kilobytes.

### `dwReserved4`

Reserved.

### `fPerUser`

Reserved.

### `dwSyncMode`

Reserved.

### `dwNumCachePaths`

Reserved.

### `CachePath`

The cache path for the container in **dwContainer**.

### `dwCacheSize`

Reserved.

### `CachePaths`

Reserved.

### `dwNormalUsage`

The cache size of the container specified in kilobytes.

### `dwExemptUsage`

The number of kilobytes for this container exempt from scavenging.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The winineti.h header defines INTERNET_CACHE_CONFIG_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetUrlCacheConfigInfo](https://learn.microsoft.com/windows/desktop/api/winineti/nf-winineti-geturlcacheconfiginfoa)