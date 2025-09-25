## Description

The **WINHTTP_AUTOPROXY_OPTIONS** structure is used to indicate to the [WinHttpGetProxyForURL](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurl) function whether to specify the URL of the Proxy Auto-Configuration (PAC) file or to automatically locate the URL with DHCP or DNS queries to the network.

## Members

### `dwFlags`

Mechanisms should be used to obtain the PAC file.

| Value | Meaning |
| --- | --- |
||  |  |
| --- | --- |
| **WINHTTP_AUTOPROXY_ALLOW_AUTOCONFIG** | Enables proxy detection via autoconfig URL.<br><br>**Note** Support for this flag was introduced in Windows 10, version 1703 (10.0; Build 15063). |
| **WINHTTP_AUTOPROXY_ALLOW_CM** | Enables proxy detection via connection manager.<br><br>**Note** Support for this flag was introduced in Windows 10, version 1703 (10.0; Build 15063). |
 **WINHTTP_AUTOPROXY_ALLOW_STATIC** | Enables proxy detection via static configuration.<br><br>**Note** Support for this flag was introduced in Windows 10, version 1703 (10.0; Build 15063). |
| **WINHTTP_AUTOPROXY_AUTO_DETECT** | Attempt to automatically discover the URL of the PAC file using both DHCP and DNS queries to the local network. |
| **WINHTTP_AUTOPROXY_CONFIG_URL** | Download the PAC file from the URL specified by **lpszAutoConfigUrl** in the **WINHTTP_AUTOPROXY_OPTIONS** structure. |
| **WINHTTP_AUTOPROXY_HOST_KEEPCASE** | Maintains the case of the hostnames passed to the PAC script. This is the default behavior. |
| **WINHTTP_AUTOPROXY_HOST_LOWERCASE** | Converts hostnames to lowercase before passing them to the PAC script. |
| **WINHTTP_AUTOPROXY_NO_CACHE_CLIENT** | Disables querying a host to proxy cache of script execution results in the current process. |
| **WINHTTP_AUTOPROXY_NO_CACHE_SVC** | Disables querying a host to proxy cache of script execution results in the autoproxy service. |
| **WINHTTP_AUTOPROXY_NO_DIRECTACCESS** | Disables querying Direct Access proxy settings for this request. |
| **WINHTTP_AUTOPROXY_RUN_INPROCESS** | Executes the Web Proxy Auto-Discovery (WPAD) protocol in-process instead of delegating to an out-of-process WinHTTP AutoProxy Service, if available. This flag must be combined with one of the other flags.<br><br>This option has no effect when passed to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex).<br><br>**Note** This flag is deprecated. |
| **WINHTTP_AUTOPROXY_RUN_OUTPROCESS_ONLY** | By default, WinHTTP is configured to fall back to auto-discover a proxy in-process. If this fallback behavior is undesirable in the event that an out-of-process discovery fails, it can be disabled using this flag.<br><br>This option has no effect when passed to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex).<br><br>**Note** This flag is available on Windows Server 2003 only. |
| **WINHTTP_AUTOPROXY_SORT_RESULTS** | Orders the proxy results based on a heuristic placing the fastest proxies first. |

### `dwAutoDetectFlags`

If **dwFlags** includes the WINHTTP_AUTOPROXY_AUTO_DETECT flag, then **dwAutoDetectFlags** specifies what protocols are to be used to locate the PAC file. If both the DHCP and DNS auto detect flags are specified, then DHCP is used first; if no PAC URL is discovered using DHCP, then DNS is used.

If **dwFlags** does not include the WINHTTP_AUTOPROXY_AUTO_DETECT flag, then **dwAutoDetectFlags** must be zero.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTO_DETECT_TYPE_DHCP** | Use DHCP to locate the proxy auto-configuration file. |
| **WINHTTP_AUTO_DETECT_TYPE_DNS_A** | Use DNS to attempt to locate the proxy auto-configuration file at a well-known location on the domain of the local computer. |

### `lpszAutoConfigUrl`

If **dwFlags** includes the WINHTTP_AUTOPROXY_CONFIG_URL flag, the **lpszAutoConfigUrl** must point to a **null**-terminated Unicode string that contains the URL of the proxy auto-configuration (PAC) file.

If **dwFlags** does not include the WINHTTP_AUTOPROXY_CONFIG_URL flag, then **lpszAutoConfigUrl** must be **NULL**.

### `lpvReserved`

Reserved for future use; must be **NULL**.

### `dwReserved`

Reserved for future use; must be zero.

### `fAutoLogonIfChallenged`

Specifies whether the client's domain credentials should be automatically sent in response to an NTLM or Negotiate Authentication challenge when WinHTTP requests the PAC file.

If this flag is TRUE, credentials should automatically be sent in response to an authentication challenge. If this flag is FALSE and authentication is required to download the PAC file, the [WinHttpGetProxyForUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurl) function fails.

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)