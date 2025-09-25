# INTERNET_PROXY_INFO structure

## Description

Contains information that is supplied with the INTERNET_OPTION_PROXY value to get or set proxy information on a handle obtained from a call to the
[InternetOpen](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopena) function.

## Members

### `dwAccessType`

Access type. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_OPEN_TYPE_DIRECT** | Internet accessed through a direct connection. |
| **INTERNET_OPEN_TYPE_PRECONFIG** | Applies only when setting proxy information. |
| **INTERNET_OPEN_TYPE_PROXY** | Internet accessed using a proxy. |

### `lpszProxy`

Pointer to a string that contains the proxy server list.

### `lpszProxyBypass`

Pointer to a string that contains the proxy bypass list.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)

[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona)