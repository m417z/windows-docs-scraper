# sockaddr_gen structure

## Description

The **sockaddr_gen** union provides generic socket address information, and is used with the [INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-interface_info) structure.

## Members

### `Address`

IP address information expressed in a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `AddressIn`

IP address information expressed in a [sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `AddressIn6`

IP address information expressed in a [sockaddr_in6_old](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **sockaddr_gen** union is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[sockaddr_in6_old](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)