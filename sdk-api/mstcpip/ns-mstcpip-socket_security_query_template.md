# SOCKET_SECURITY_QUERY_TEMPLATE structure

## Description

The **SOCKET_SECURITY_QUERY_TEMPLATE** structure contains the security template used by the [WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity) function.

## Members

### `SecurityProtocol`

A [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) value that identifies the protocol used to secure the traffic.

### `PeerAddress`

The IP address of the peer for which security information is being queried. For connection-oriented sockets (protocol of **IPPROTO_TCP**), the connected socket uniquely identifies a peer. In this case, this parameter is ignored.

### `PeerTokenAccessMask`

The access mask used for opening the peer user application and computer token handles that are returned as part of the query information.

## Remarks

The **SOCKET_SECURITY_QUERY_TEMPLATE** structure is supported on Windows Vista and later.

The **SOCKET_SECURITY_QUERY_TEMPLATE** structure is used by the [WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity) function to specify the type of query information to return for a socket. The **SOCKET_SECURITY_QUERY_TEMPLATE** structure passed to the **WSAQuerySocketSecurity** function may contain zeros for all members to request default security information.

If the **SOCKET_SECURITY_QUERY_TEMPLATE** structure is specified with the **PeerTokenAccessMask** member not specified (set to zero), then the [WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity) function will not return the **PeerApplicationAccessTokenHandle** and **PeerMachineAccessTokenHandle** members in the [SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info) structure.

Currently, the only type of security protocol that is supported is IPsec. So specifying an enumeration value of **SOCKET_SECURITY_PROTOCOL_DEFAULT** for the **SecurityProtocol** member has the same effect as specifying **SOCKET_SECURITY_PROTOCOL_IPSEC**.

## See also

[SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol)

[SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)