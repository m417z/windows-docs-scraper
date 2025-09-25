# SOCKET_ADDRESS structure

## Description

The
**SOCKET_ADDRESS** structure stores protocol-specific address information.

## Members

### `lpSockaddr`

A pointer to a socket address represented as a [SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `iSockaddrLength`

The length, in bytes, of the socket address.

## Remarks

The [SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the **lpSockaddr** member varies depending on the protocol or address family selected. For example, the **sockaddr_in6** structure is used for an IPv6 socket address while the **sockaddr_in4** structure is used for an IPv4 socket address. The address family is the first member of all of the **SOCKADDR** structures. The address family is used to determine which structure is used.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **SOCKET_ADDRESS** structure is defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[SOCKET_ADDRESS_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa385467(v=vs.85))

[Using SIO_ADDRESS_LIST_SORT](https://learn.microsoft.com/windows/desktop/WinSock/using-sio-address-list-sort)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[LPWSPIoctl](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566296(v=vs.85))