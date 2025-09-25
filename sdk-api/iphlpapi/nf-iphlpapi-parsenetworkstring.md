# ParseNetworkString function

## Description

The
**ParseNetworkString** function parses the input network string and checks whether it
is a legal representation of the specified IP network string type. If the string matches a type and its specification,
the function can optionally return the parsed result.

## Parameters

### `NetworkString` [in]

A pointer to the NULL-terminated network string to parse.

### `Types` [in]

The type of IP network string to parse. This parameter consists of one of network string types as defined in the *Iphlpapi.h*
header file.

| Value | Meaning |
| --- | --- |
| **NET_STRING_IPV4_ADDRESS**<br><br>0x00000001 | The *NetworkString* parameter points to an IPv4 address using Internet standard dotted-decimal notation. A network port or prefix must not be present in the network string. <br><br>An example network string is the following:<br><br>**192.168.100.10** |
| **NET_STRING_IPV4_SERVICE**<br><br>0x00000002 | The *NetworkString* parameter points to an IPv4 service using Internet standard dotted-decimal notation. A network port is required as part of the network string. A prefix must not be present in the network string. <br><br>An example network string is the following:<br><br>**192.168.100.10:80** |
| **NET_STRING_IPV4_NETWORK**<br><br>0x00000004 | The *NetworkString* parameter points to an IPv4 network using Internet standard dotted-decimal notation. A network prefix that uses the Classless Inter-Domain Routing (CIDR) notation is required as part of the network string. A network port must not be present in the network string. <br><br>An example network string is the following:<br><br>**192.168.100/24** |
| **NET_STRING_IPV6_ADDRESS**<br><br>0x00000008 | The *NetworkString* parameter points to an IPv6 address using Internet standard hexadecimal encoding. An IPv6 scope ID may be present in the network string. A network port or prefix must not be present in the network string. <br><br>An example network string is the following:<br><br>**21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A%2** |
| **NET_STRING_IPV6_ADDRESS_NO_SCOPE**<br><br>0x00000008 | The *NetworkString* parameter points to an IPv6 address using Internet standard hexadecimal encoding. An IPv6 scope ID must not be present in the network string. A network port or prefix must not be present in the network string. <br><br>An example network string is the following:<br><br>**21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A** |
| **NET_STRING_IPV6_SERVICE**<br><br>0x00000020 | The *NetworkString* parameter points to an IPv6 service using Internet standard hexadecimal encoding. A network port is required as part of the network string. An IPv6 scope ID may be present in the network string. A prefix must not be present in the network string. <br><br>An example network string with a scope ID is the following:<br><br>**[21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A%2]:8080** |
| **NET_STRING_IPV6_SERVICE_NO_SCOPE**<br><br>0x00000040 | The *NetworkString* parameter points to an IPv6 service using Internet standard hexadecimal encoding. A network port is required as part of the network string. An IPv6 scope ID must not be present in the network string. A prefix must not be present in the network string. <br><br>An example network string is the following:<br><br>**21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A:8080** |
| **NET_STRING_IPV6_NETWORK**<br><br>0x00000080 | The *NetworkString* parameter points to an IPv6 network using Internet standard hexadecimal encoding. A network prefix in CIDR notation is required as part of the network string. A network port or scope ID must not be present in the network string. <br><br>An example network string is the following:<br><br>**21DA:D3::/48** |
| **NET_STRING_NAMED_ADDRESS**<br><br>0x00000100 | The *NetworkString* parameter points to an Internet address using a Domain Name System (DNS) name. A network port or prefix must not be present in the network string. <br><br>An example network string is the following:<br><br>**www.microsoft.com** |
| **NET_STRING_NAMED_SERVICE**<br><br>0x00000200 | The *NetworkString* parameter points to an Internet service using a DNS name. A network port must be present in the network string. <br><br>An example network string is the following:<br><br>**www.microsoft.com:80** |
| **NET_STRING_IP_ADDRESS**<br><br>0x00000009 | The *NetworkString* parameter points to an IPv4 address using Internet standard dotted-decimal notation or an IPv6 address using the Internet standard hexadecimal encoding. An IPv6 scope ID may be present in the network string. A network port or prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_IPV4_ADDRESS** or **NET_STRING_IPV6_ADDRESS** types. |
| **NET_STRING_IP_ADDRESS_NO_SCOPE**<br><br>0x00000011 | The *NetworkString* parameter points to an IPv4 address using Internet standard dotted-decimal notation or an IPv6 address using Internet standard hexadecimal encoding. An IPv6 scope ID must not be present in the network string. A network port or prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_IPV4_ADDRESS** or **NET_STRING_IPV6_ADDRESS_NO_SCOPE** types. |
| **NET_STRING_IP_SERVICE**<br><br>0x00000022 | The *NetworkString* parameter points to an IPv4 service or IPv6 service. A network port is required as part of the network string. An IPv6 scope ID may be present in the network string. A prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_IPV4_SERVICE** or **NET_STRING_IPV6_SERVICE** types. |
| **NET_STRING_IP_SERVICE_NO_SCOPE**<br><br>0x00000042 | The *NetworkString* parameter points to an IPv4 service or IPv6 service. A network port is required as part of the network string. An IPv6 scope ID must not be present in the network string. A prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_IPV4_SERVICE** or **NET_STRING_IPV6_SERVICE_NO_SCOPE** types. |
| **NET_STRING_IP_NETWORK**<br><br>0x00000084 | The *NetworkString* parameter points to an IPv4 or IPv6 network. A network prefix in CIDR notation is required as part of the network string. A network port or scope ID must not be present in the network. <br><br>This type matches either the **NET_STRING_IPV4_NETWORK** or **NET_STRING_IPV6_NETWORK** types. |
| **NET_STRING_ANY_ADDRESS**<br><br>0x00000209 | The *NetworkString* parameter points to an IPv4 address in Internet standard dotted-decimal notation, an IPv6 address in Internet standard hexadecimal encoding, or a DNS name. An IPv6 scope ID may be present in the network string for an IPv6 address. A network port or prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_NAMED_ADDRESS** or **NET_STRING_IP_ADDRESS** types. |
| **NET_STRING_ANY_ADDRESS_NO_SCOPE**<br><br>0x00000211 | The *NetworkString* parameter points to an IPv4 address in Internet standard dotted-decimal notation, an IPv6 address in Internet standard hexadecimal encoding, or a DNS name. An IPv6 scope ID must not be present in the network string for an IPv6 address. A network port or prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_NAMED_ADDRESS** or **NET_STRING_IP_ADDRESS_NO_SCOPE** types. |
| **NET_STRING_ANY_SERVICE**<br><br>0x00000222 | The *NetworkString* parameter points to an IPv4 service or IPv6 service using IP address notation or a DNS name. A network port is required as part of the network string. An IPv6 scope ID may be present in the network string. A prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_NAMED_SERVICE** or **NET_STRING_IP_SERVICE** types. |
| **NET_STRING_ANY_SERVICE_NO_SCOPE**<br><br>0x00000242 | The *NetworkString* parameter points to an IPv4 service or IPv6 service using IP address notation or a DNS name. A network port is required as part of the network string. An IPv6 scope ID must not be present in the network string. A prefix must not be present in the network string. <br><br>This type matches either the **NET_STRING_NAMED_SERVICE** or **NET_STRING_IP_SERVICE_NO_SCOPE** types. |

### `AddressInfo` [out, optional]

On success, the function returns a pointer to a **NET_ADDRESS_INFO** structure that contains the parsed IP address information if a **NULL** pointer was not passed in this parameter.

### `PortNumber` [out, optional]

On success, the function returns a pointer to the parsed network port in host order if a **NULL** pointer was not passed in this parameter. If a network port was not present in the *NetworkString* parameter, then a pointer to a value of zero is returned.

### `PrefixLength` [out, optional]

On success, the function returns a pointer to the parsed prefix length if a **NULL** pointer was not passed in this parameter. If a prefix was not present in the *NetworkString* parameter, then a pointer to a value of -1 is returned.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer passed to the function is too small. This error is returned if the buffer pointed to by the *AddressInfo* parameter is too small to hold the parsed network address. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *NetworkString* parameter |

## Remarks

The **ParseNetworkString** function parses the input network string passed in the *NetworkString* parameter and checks whether it
is a legal representation of one of the string types as specified in
the *Types* argument. If the string matches a type and its specification,
the function succeeds and can optionally return the parsed result
to the caller in the optional *AddressInfo*, *PortNumber*, and *PrefixLength* parameters when these parameters are not **NULL** pointers.

The **ParseNetworkString** function can parse representations of IPv4 or IPv6 addresses,
services, and networks, as well as named Internet addresses and
services using DNS names.

The [NET_ADDRESS_INFO](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ns-iphlpapi-net_address_info) structure pointed to by the *AddressInfo* parameter. The SOCKADDR_IN and SOCKADDR structures are defined in the *Ws2def.h* header file which is automatically included by the *Winsock2.h* header file. The SOCKADDR_IN6 structure is defined in the *Ws2ipdef.h* header file which is automatically included by the *Ws2tcpip.h* header file. In order to use the **ParseNetworkString** function and the **NET_ADDRESS_INFO** structure, the *Winsock2.h* and *Ws2tcpip.h* header files must be included before the *Iphlpapi.h* header file.

## See also

[NET_ADDRESS_FORMAT](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ne-iphlpapi-net_address_format)

[NET_ADDRESS_INFO](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ns-iphlpapi-net_address_info)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

SOCKADDR_IN

SOCKADDR_IN6