# SOCKET_SECURITY_QUERY_INFO structure

## Description

The **SOCKET_SECURITY_QUERY_INFO** structure contains security information returned by the [WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity) function.

## Members

### `SecurityProtocol`

A [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) value that identifies the protocol used to secure the traffic.

### `Flags`

The set of possible security flags for the connection defined in the *Mstcpip.h* header file.

| Value | Meaning |
| --- | --- |
| **SOCKET_INFO_CONNECTION_SECURED**<br><br>0x00000001 | If present, traffic is being secured by a security protocol. If absent, the traffic is flowing in the clear. |
| **SOCKET_INFO_CONNECTION_ENCRYPTED**<br><br>0x00000002 | If present, the connection traffic is being encrypted. The **SOCKET_INFO_CONNECTION_SECURED** flag is always set when this flag is present. |

### `PeerApplicationAccessTokenHandle`

A handle to the access token that represents the account under which the peer application is running. After using the token for access checks, the application should close the handle using the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `PeerMachineAccessTokenHandle`

A handle to the access token for the peer computer's account during the course of the application. After using the token for access checks, the application should close the handle using the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

## Remarks

The **SOCKET_SECURITY_QUERY_INFO** structure is supported on Windows Vista and later.

The **SOCKET_SECURITY_QUERY_INFO** structure is used by the [WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity) function to return information about the security applied to a connection on a socket.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)