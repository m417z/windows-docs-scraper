# MIB_UDP6ROW structure

## Description

The
**MIB_UDP6ROW** structure contains an entry from the User Datagram Protocol (UDP) listener table for IPv6 on the local computer.

## Members

### `dwLocalAddr`

The IPv6 address of the UDP endpoint on the local computer. This member is stored in a character array in network byte order.

A value of zero indicates a UDP listener willing to accept datagrams for any IP interface associated
with the local computer.

### `dwLocalScopeId`

The scope ID for the IPv6 address of the UDP endpoint on the local computer. This member is stored in network byte order.

### `dwLocalPort`

The port number of the UDP endpoint on the local computer. This member is stored in network byte order.

## Remarks

The **MIB_UDP6ROW** structure is defined on Windows Vista and later.

The [GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table) function retrieves the UDP listener table for IPv6 on the local computer and returns this information in a [MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table) structure.

An array of **MIB_UDP6ROW** structures are contained in the **MIB_UDP6TABLE** structure.

The **dwLocalAddr** member is stored in an [in6_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure. The [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) or [RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw) functions may be used to convert the IPv6 address in the **dwLocalAddr** member to a string without loading the Windows Sockets DLL.

The **dwLocalScopeId** and **dwLocalPort** members are in network byte order. In order to use the **dwLocalScopeId** and **dwLocalPort** members, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The [MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table) structure contains the UDP listener table for IPv6 on the local computer. The name is based on the definition of this table in RFC 2454 published by the IETF. For more information, see
[http://www.ietf.org/rfc/rfc2454.txt](http://tools.ietf.org/html/rfc2454). This table contains UDP endpoints for IPv6 that have been bound to an address. It should be noted that an application can create a UDP socket and bind it to an address for the sole purpose of sending a UDP datagram, with no intention of receiving packets using this socket (functioning as a listener).

## See also

[GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table)

[GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable)

[MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[in6_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)