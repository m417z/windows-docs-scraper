# SOCKET_PEER_TARGET_NAME structure

## Description

The **SOCKET_PEER_TARGET_NAME** structure contains the IP address and name for a peer target and the type of security protocol to be used on a socket.

## Members

### `SecurityProtocol`

A [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) value that identifies the type of protocol used to secure the traffic on the socket.

### `PeerAddress`

The IP address of the peer for the socket.

### `PeerTargetNameStringLen`

The length, in bytes, of the peer target name in the **AllStrings** member.

### `AllStrings`

The peer target name for the socket.

## Remarks

The **SOCKET_PEER_TARGET_NAME** structure is supported on Windows Vista and later.

The **SOCKET_PEER_TARGET_NAME** structure is used by the [WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname) function to specify the peer target name that corresponds to a peer IP address. This target name is meant to be specified by client applications to securely identify the peer that should be authenticated.

Currently, the only type of security protocol that is supported is IPsec. So specifying an enumeration value of **SOCKET_SECURITY_PROTOCOL_DEFAULT** has the same effect as specifying **SOCKET_SECURITY_PROTOCOL_IPSEC** in the **SecurityProtocol** member.

The implementation of IPsec on Windows Vista and Windows Server 2008 only supports computer-to-computer and user-to-computer authentication. As a result, the peer target name specified in the **AllStrings** member of the **SOCKET_PEER_TARGET_NAME** structure should refer to the peer computer principal.

## See also

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))

[SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)