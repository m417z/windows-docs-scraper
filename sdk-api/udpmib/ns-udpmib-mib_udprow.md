# MIB_UDPROW structure

## Description

The
**MIB_UDPROW** structure contains an entry from the User Datagram Protocol (UDP) listener table for IPv4 on the local computer.

## Members

### `dwLocalAddr`

The IPv4 address of the UDP endpoint on the local computer.

A value of zero indicates a UDP listener willing to accept datagrams for any IP interface associated
with the local computer.

### `dwLocalPort`

The port number of the UDP endpoint on the local computer. This member is stored in network byte order.

## Remarks

The [GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable) function retrieves the IPv4 UDP listener table on the local computer and returns this information in a [MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) structure.

An array of **MIB_UDPROW** structures are contained in the **MIB_UDPTABLE** structure.

The **dwLocalAddr** member is stored as a **DWORD** in the same format as the [in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure. In order to use the **dwLocalAddr** member, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed. On Windows Vista and later, the [RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa) or [RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw) functions may be used to convert the IPv4 address in the **dwLocalAddr** member to a string without loading the Windows Sockets DLL.

The **dwLocalPort** member is in network byte order. In order to use the **dwLocalPort** member, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The [MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) structure contains the UDP listener table for IPv4 on the local computer. The name is based on the definition of this table in RFC 1213 published by the IETF. For more information, see
[http://www.ietf.org/rfc/rfc1213.txt](http://tools.ietf.org/html/rfc1213). This table contains UDP endpoints for IPv4 that have been bound to an address. It should be noted that an application can create a UDP socket and bind it to an address for the sole purpose of sending a UDP datagram, with no intention of receiving packets using this socket (functioning as a listener).

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Udpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Udpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Udpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table)

[GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable)

[MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row)

[MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table)

[MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats)

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)