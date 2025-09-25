# SOCKET_SECURITY_SETTINGS structure

## Description

The **SOCKET_SECURITY_SETTINGS** structure specifies generic security requirements for a socket.

## Members

### `SecurityProtocol`

A [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) value that identifies the type of security protocol to be used on the socket.

### `SecurityFlags`

A set of flags that allow applications to set specific security requirements on a socket. The possible values are defined in the *Mstcpip.h* header file.

| Value | Meaning |
| --- | --- |
| **SOCKET_SETTINGS_GUARANTEE_ENCRYPTION**<br><br>0x00000001 | Indicates that guaranteed encryption of traffic is required. This flag should be set if the default policy prefers methods of protection that do not use encryption. If this flag is set and encryption is not possible for any reason, no packets will be sent and a connection will not be established. |
| **SOCKET_SETTINGS_ALLOW_INSECURE**<br><br>0x00000002 | Indicates that clear text connections are allowed. If this flag is set, some or all of the sent packets will be sent in clear text, especially if security with the peer could not be negotiated.<br><br>**Note** If this flag is not set, it is guaranteed that packets will never be sent in clear text, even if security negotiation fails. |

## Remarks

The **SOCKET_SECURITY_SETTINGS** structure is supported on Windows Vista and later.

The **SOCKET_SECURITY_SETTINGS** structure is used by the [WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity) function to enable and apply security on a socket.

Security settings not addressed in this structure are derived from the system default policy or the administratively configured policy. It is recommended that most applications specify a value of **SOCKET_SECURITY_PROTOCOL_DEFAULT** for the [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) enumeration in the **SecurityProtocol** member. This makes the application neutral to security protocols and allows easier deployments among different systems.

Advanced applications can specify a security protocol and associated settings by casting them to the **SOCKET_SECURITY_SETTINGS** type.

## See also

[SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)