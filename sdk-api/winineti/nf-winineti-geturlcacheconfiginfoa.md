# GetUrlCacheConfigInfoA function

## Description

Retrieves information about cache configuration.

## Parameters

### `lpCacheConfigInfo` [in, out]

A pointer to an
[INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure
that receives information about the cache configuration. The **dwStructSize** field of
the structure should be initialized to the size of
**INTERNET_CACHE_CONFIG_INFO**.

### `lpcbCacheConfigInfo`

This parameter is reserved and must be **NULL**.

### `dwFieldControl` [in]

Determines the behavior of the function, as one of the following values.

| Value | Meaning |
| --- | --- |
| **CACHE_CONFIG_FORCE_CLEANUP_FC**<br><br>0x00000020 | Not used. |
| **CACHE_CONFIG_DISK_CACHE_PATHS_FC**<br><br>0x00000040 | Not used. |
| **CACHE_CONFIG_SYNC_MODE_FC**<br><br>0x00000080 | Reserved. |
| **CACHE_CONFIG_CONTENT_PATHS_FC**<br><br>0x00000100 | The **CachePath** field of the [INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure specified in the *lpCachedConfigInfo* parameter is filled with a pointer to a string identifying the content path. This cannot be used at the same time as **CACHE_CONFIG_HISTORY_PATHS_FC** or **CACHE_CONFIG_COOKIES_PATHS_FC**. |
| **CACHE_CONFIG_HISTORY_PATHS_FC**<br><br>0x00000400 | The **CachePath** field of the [INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure specified in the *lpCachedConfigInfo* parameter is filled with a pointer to a string identifying the history path. This cannot be used at the same time as **CACHE_CONFIG_CONTENT_PATHS_FC** or **CACHE_CONFIG_COOKIES_PATHS_FC**. |
| **CACHE_CONFIG_COOKIES_PATHS_FC**<br><br>0x00000200 | The **CachePath** field of the [INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure specified in the *lpCachedConfigInfo* parameter is filled with a pointer to a string identifying the cookie path. This cannot be used at the same time as **CACHE_CONFIG_CONTENT_PATHS_FC** or **CACHE_CONFIG_HISTORY_PATHS_FC**. |
| **CACHE_CONFIG_QUOTA_FC**<br><br>0x00000800 | The **dwQuota** field of the [INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure specified in the *lpCachedConfigInfo* is set to the cache limit for the container specified in the **dwContainer** field. |
| **CACHE_CONFIG_USER_MODE_FC**<br><br>0x00001000 | Reserved. |
| **CACHE_CONFIG_CONTENT_USAGE_FC**<br><br>0x00002000 | The **dwNormalUsage** field of the [INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure specified in the *lpCachedConfigInfo* is set to the cache size for the container specified in the **dwContainer** field. |
| **CACHE_CONFIG_STICKY_CONTENT_USAGE_FC**<br><br>0x00004000 | The **dwExemptUsage** field of the [INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa) structure specified in the *lpCachedConfigInfo* is set to the exempt usage, the amount of bytes exempt from scavenging, for the container specified in the **dwContainer** field. (This field must be the content container.) |

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get
extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The winineti.h header defines GetUrlCacheConfigInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[INTERNET_CACHE_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/winineti/ns-winineti-internet_cache_config_infoa)