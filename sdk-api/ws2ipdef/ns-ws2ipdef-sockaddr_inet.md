# SOCKADDR_INET structure

## Description

The **SOCKADDR_INET** union contains an IPv4, an IPv6 address, or an address family.

## Members

### `Ipv4`

Type: **SOCKADDR_IN**

An IPv4 address represented as a [SOCKADDR_IN](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure containing the address family and the IPv4 address. The address family is in host byte order and the IPv4 address is in network byte order.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the [SOCKADDR_IN](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure is defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

### `Ipv6`

Type: **SOCKADDR_IN6**

An IPv6 address represented as a [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure containing the address family and the IPv6 address. The address family is in host byte order and the IPv6 address is in network byte order.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure is defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

### `si_family`

Type: **ADDRESS_FAMILY**

The address family.

Possible values for the address family are listed in the *Ws2def.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used. The *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, the **SOCKADDR_INET** union can represent either the IPv4 or IPv6 address family. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |

## Remarks

The **SOCKADDR_INET** union is defined on Windows Vista and later.

The **SOCKADDR_INET** union is a convenience structure for accessing an IPv4 address, an IPv6 address, or the IP address family without having to cast the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

The **SOCKADDR_INET** union is the data type of the **Prefix** member in the [IP_ADDRESS_PREFIX](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-ip_address_prefix) structure

Note that the *Ws2ipdef.h* header file is automatically included in *Ws2tcpip.h* header file, and should never be used directly.

## See also

[IP_ADDRESS_PREFIX](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-ip_address_prefix)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)