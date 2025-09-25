# INTERNET_DIAGNOSTIC_SOCKET_INFO structure

## Description

The **INTERNET_DIAGNOSTIC_SOCKET_INFO** structure is returned by the [InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) function when the INTERNET_OPTION_DIAGNOSTIC_SOCKET_INFO flag is passed to it together with a handle to an HTTP Request. The **INTERNET_DIAGNOSTIC_SOCKET_INFO** structure contains information about the socket associated with that HTTP Request.

## Members

### `Socket`

Descriptor that identifies the socket associated with the specified HTTP Request.

### `SourcePort`

The address of the port at which the HTTP Request and response was received.

### `DestPort`

The address of the port at which the response was sent.

### `Flags`

| Value | Meaning |
| --- | --- |
| **IDSI_FLAG_KEEP_ALIVE** | Set if the connection is from the "keep-alive" pool. |
| **IDSI_FLAG_SECURE** | Set if the HTTP Request is using a secure socket. |
| **IDSI_FLAG_PROXY** | Set if a proxy is being used to reach the server. |
| **IDSI_FLAG_TUNNEL** | Set if a proxy is being used to create a tunnel. |

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)