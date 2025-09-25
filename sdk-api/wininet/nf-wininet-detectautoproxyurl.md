# DetectAutoProxyUrl function

## Description

Attempts to determine the location of a WPAD autoproxy script.

## Parameters

### `pszAutoProxyUrl` [in, out]

Pointer to a buffer to receive the URL from which a WPAD autoproxy script can be downloaded.

### `cchAutoProxyUrl` [in]

Size of
the buffer pointed to by *lpszAutoProxyUrl*, in bytes.

### `dwDetectFlags` [in]

Automation detection type. This parameter can be one or both of the following values.

| Value | Meaning |
| --- | --- |
| **PROXY_AUTO_DETECT_TYPE_DHCP** | Use a Dynamic Host Configuration Protocol (DHCP) search to identify the proxy. |
| **PROXY_AUTO_DETECT_TYPE_DNS_A** | Use a well qualified name search to identify the proxy. |

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetDeInitializeAutoProxyDll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa384580(v=vs.85))

[InternetGetProxyInfo](https://learn.microsoft.com/windows/desktop/WinInet/internetgetproxyinfo)

[InternetInitializeAutoProxyDll](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetinitializeautoproxydll)