# WinHttpDetectAutoProxyConfigUrl function

## Description

The **WinHttpDetectAutoProxyConfigUrl** function finds the URL for the Proxy Auto-Configuration (PAC) file. This function reports the URL of the PAC file, but it does not download the file.

## Parameters

### `dwAutoDetectFlags` [in]

A data type that specifies what protocols to use to locate the PAC file. If both the DHCP and DNS auto detect flags are set, DHCP is used first; if no PAC URL is discovered using DHCP, then DNS is used.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTO_DETECT_TYPE_DHCP** | Use DHCP to locate the proxy auto-configuration file. |
| **WINHTTP_AUTO_DETECT_TYPE_DNS_A** | Use DNS to attempt to locate the proxy auto-configuration file at a well-known location on the domain of the local computer. |

### `ppwstrAutoConfigUrl` [out]

 A data type that returns a pointer to a null-terminated Unicode string that contains the configuration URL that receives the proxy data. You must free the string pointed to by *ppwszAutoConfigUrl* using the [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_AUTODETECTION_FAILED** | Returned if WinHTTP was unable to discover the URL of the Proxy Auto-Configuration (PAC) file. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

WinHTTP implements the [Web Proxy Auto-Discovery (WPAD) protocol](https://www.ietf.org/archive/id/draft-ietf-wrec-wpad-01.txt), often referred to as *autoproxy*. For more information about well-known locations, see the [Discovery Process](https://www.ietf.org/archive/id/draft-ietf-wrec-wpad-01.txt) section of the WPAD protocol document.

Note that because the **WinHttpDetectAutoProxyConfigUrl** function takes time to complete its operation, it should not be called from a UI thread.

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)