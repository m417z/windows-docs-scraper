## Description

The **WINHTTP_PROXY_INFO** structure contains the session or default proxy configuration.

## Members

### `dwAccessType`

Unsigned long integer value that contains the access type. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINHTTP_ACCESS_TYPE_NO_PROXY** | Internet accessed through a direct connection. |
| **WINHTTP_ACCESS_TYPE_DEFAULT_PROXY** | Applies only when setting proxy information. |
| **WINHTTP_ACCESS_TYPE_NAMED_PROXY** | Internet accessed using a proxy. |

### `lpszProxy`

Pointer to a string value that contains the proxy server list.

### `lpszProxyBypass`

Pointer to a string value that contains the proxy bypass list.

## Remarks

This structure is used with
[WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) and
[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) to get or set the proxy configuration for the current session by specifying the WINHTTP_OPTION_PROXY flag.

This structure is used with
[WinHttpSetDefaultProxyConfiguration](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetdefaultproxyconfiguration) and
[WinHttpGetDefaultProxyConfiguration](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetdefaultproxyconfiguration) to get or set the default proxy configuration in the registry.

The proxy server list contains one or more of the following strings separated by semicolons or whitespace.

``` syntax
([<scheme>=][<scheme>"://"]<server>[":"<port>])
```

The proxy bypass list contains one or more server names separated by semicolons or whitespace. The proxy bypass list can also contain the string "\<local>" to indicate that all local intranet sites are bypassed. Local intranet sites are considered to be all servers that do not contain a period in their name.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## See also

[WinHTTP
Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)