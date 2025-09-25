# MIB_UDPTABLE structure

## Description

The
**MIB_UDPTABLE** structure contains the User Datagram Protocol (UDP) listener table for IPv4 on the local computer.

## Members

### `dwNumEntries`

The number of entries in the table.

### `table`

A pointer to an array of
[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow) structures.

## Remarks

The [GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable) function enumerates the table of UDP endpoints for IPv4 that have been bound to an address on the local computer and returns this information in a **MIB_UDPTABLE** structure.

This table includes the local IPv4 address and port information for sending and receiving UDP datagrams on the local computer. An array of [MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow) structures are contained in the **MIB_UDPTABLE** structure.

The **MIB_UDPTABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow) array entry in the **table** member. Padding for alignment may also be present between the **MIB_UDPROW** array entries in the **table** member. Any access to a **MIB_UDPROW** array entry should assume padding may exist.

The **MIB_UDPTABLE** structure contains the UDP listener table for IPv4 on the local computer. The name is based on the definition of this table in RFC 1213 published by the IETF. For more information, see
[http://www.ietf.org/rfc/rfc1213.txt](http://tools.ietf.org/html/rfc1213). This table contains UDP endpoints for IPv4 that have been bound to an address. It should be noted that an application can create a UDP socket and bind it to an address for the sole purpose of sending a UDP datagram, with no intention of receiving packets using this socket (functioning as a listener).

The [MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module) structure is an enhanced version of the [MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid) structure that includes any available ownership data for each UDP endpoint in the table. The **MIB_UDPTABLE_OWNER_PID** is an enhanced version of the **MIB_UDPTABLE** that includes the process ID (PID) that issued the call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function for each UDP endpoint in the table.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Udpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Udpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Udpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table)

[GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable)

[MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row)

[MIB_UDP6ROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_module)

[MIB_UDP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_pid)

[MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table)

[MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module)

[MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)

[MIB_UDPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_module)

[MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid)

[MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module)

[MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)