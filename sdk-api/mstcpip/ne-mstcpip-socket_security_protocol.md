# SOCKET_SECURITY_PROTOCOL enumeration

## Description

The **SOCKET_SECURITY_PROTOCOL** enumeration indicates the type of security protocol to be used on a socket to secure network traffic.

## Constants

### `SOCKET_SECURITY_PROTOCOL_DEFAULT`

The default system security will be used.

### `SOCKET_SECURITY_PROTOCOL_IPSEC`

IPsec will be used.

### `SOCKET_SECURITY_PROTOCOL_IPSEC2`

### `SOCKET_SECURITY_PROTOCOL_INVALID`

The maximum possible value for the [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) enumeration type. This is not a legal value.

## Remarks

This enumeration is supported on Windows Vista and later.

Currently, the only type of security protocol that is supported is IPsec. So specifying an enumeration value of **SOCKET_SECURITY_PROTOCOL_DEFAULT** has the same effect as specifying **SOCKET_SECURITY_PROTOCOL_IPSEC**.

The **SOCKET_SECURITY_PROTOCOL** enumeration is used in the [SOCKET_PEER_TARGET_NAME](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_peer_target_name), [SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info), [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template), [SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings), and [SOCKET_SECURITY_SETTINGS_IPSEC](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings_ipsec) structures to indicate the type of security protocol to be used on a socket in the **SecurityProtocol** member. These structures are used by the [WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity), [WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname), and [WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity) functions.

In addition to identifying the security protocol, this type is also used to decide how to interpret a pointer passed to some of the secure socket functions. This is analogous to how the **sa_family** member of the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) type is used to interpret a pointer as either **sockaddr_in** or **sockaddr_in6**.

## See also

[SOCKET_PEER_TARGET_NAME](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_peer_target_name)

[SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info)

[SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template)

[SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings)

[SOCKET_SECURITY_SETTINGS_IPSEC](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings_ipsec)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)