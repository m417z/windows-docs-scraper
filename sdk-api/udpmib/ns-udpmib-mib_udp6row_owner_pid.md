# MIB_UDP6ROW_OWNER_PID structure

## Description

The **MIB_UDP6ROW_OWNER_PID** structure contains an entry from the User Datagram Protocol (UDP) listener table for IPv6 on the local computer. The entry also includes the process ID (PID) that issued the call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function for the UDP endpoint.

## Members

### `ucLocalAddr`

The IPv6 address for the local UDP endpoint. This member is stored in a character array in network byte order.

A value of zero indicates a UDP listener willing to accept datagrams for any IP interface associated
with the local computer.

### `dwLocalScopeId`

The scope ID for the IPv6 address of the UDP endpoint on the local computer. This member is stored in network byte order.

### `dwLocalPort`

The port number of the UDP endpoint on the local computer. This member is stored in network byte order.

### `dwOwningPid`

The PID of the process that issued a context bind for this endpoint. If this value is set to 0, the information for this endpoint is unavailable.

## Remarks

The [MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid) structure is returned by a call to [GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable) with the *TableClass* parameter set to a **UDP_TABLE_OWNER_PID** from the [UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class) enumeration and the *ulAf* parameter set to **AF_INET6**. The **MIB_UDP6TABLE_OWNER_PID** structure contains an array of **MIB_UDP6ROW_OWNER_PID** structures.

The **ucLocalAddr** member is stored in a character array in network byte order. On Windows Vista and later, the [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) or [RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw) functions may be used to convert the IPv6 address in the **ucLocalAddr** member to a string without loading the Windows Sockets DLL.

The **dwLocalScopeId** member is in network byte order. In order to use the **dwLocalScopeId** member, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **dwLocalPort** member are in network byte order. In order to use the **dwLocalPort** member, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The [MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid) structure contains the UDP listener table for IPv6 on the local computer. The name is based on the definition of this table in RFC 2454 published by the IETF. For more information, see
[http://www.ietf.org/rfc/rfc2454.txt](http://tools.ietf.org/html/rfc2454). This table contains UDP endpoints for IPv6 that have been bound to an address. It should be noted that an application can create a UDP socket and bind it to an address for the sole purpose of sending a UDP datagram, with no intention of receiving packets using this socket (functioning as a listener).

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Udpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Udpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Udpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)