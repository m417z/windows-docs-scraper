# NET_ADDRESS_INFO structure

## Description

The **NET_ADDRESS_INFO** structure contains IP address information returned by the [ParseNetworkString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-parsenetworkstring) function.

## Members

### `Format`

Type: **NET_ADDRESS_FORMAT**

The format of the network address in the union in this structure. This member is an enumeration value from the [NET_ADDRESS_FORMAT](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ne-iphlpapi-net_address_format) enumeration declared in the *Iphlpapi.h* header file.

### `NamedAddress`

A DNS named address and port.

### `NamedAddress.Address`

Type: **WCHAR[DNS_MAX_NAME_BUFFER_LENGTH]**

A DNS name formatted as a **NULL**-terminated wide character string. The maximum length of this string is the **DNS_MAX_NAME_BUFFER_LENGTH** constant defined in the *Windns.h* header file.

### `NamedAddress.Port`

Type: **WCHAR[6]**

The network port formatted as a **NULL**-terminated wide character string.

### `Ipv4Address`

Type: **SOCKADDR_IN**

An IPv4 address represented as a [SOCKADDR_IN](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `Ipv6Address`

Type: **SOCKADDR_IN6**

An IPv6 address represented as a [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `IpAddress`

Type: **SOCKADDR**

An IPv4 or IPv6 address represented as a [SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

## Remarks

The **NET_ADDRESS_INFO** structure is defined on Windows Vista and later.

The **NET_ADDRESS_INFO** structure is returned by the [ParseNetworkString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-parsenetworkstring) function.

The [SOCKADDR_IN](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2), SOCKADDR_IN6, and SOCKADDR structures are used in the **NET_ADDRESS_INFO** structure. The SOCKADDR_IN and SOCKADDR structures are defined in the *Ws2def.h* header file which is automatically included by the *Winsock2.h* header file. The SOCKADDR_IN6 structure is defined in the *Ws2ipdef.h* header file which is automatically included by the *Ws2tcpip.h* header file. In order to use the **NET_ADDRESS_INFO** structure, the *Winsock2.h* and *Ws2tcpip.h* header files must be included before the *Iphlpapi.h* header file.

## See also

[NET_ADDRESS_FORMAT](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ne-iphlpapi-net_address_format)

[ParseNetworkString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-parsenetworkstring)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)