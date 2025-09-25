# MIB_UDP6TABLE structure

## Description

The
**MIB_UDP6TABLE** structure contains the User Datagram Protocol (UDP) listener table for IPv6 on the local computer.

## Members

### `dwNumEntries`

The number of entries in the table.

### `table`

A pointer to an array of
[MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row) structures.

## Remarks

The [GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table) function enumerates the UDP endpoints for IPv6 that have been bound to an address on the local computer and returns this information in a **MIB_UDP6TABLE** structure.

This table includes the local IPv6 address, scope ID, and port information for sending and receiving UDP datagrams on the local computer. An array of [MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row) structures are contained in the **MIB_UDP6TABLE** structure.

The **MIB_UDP6TABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row) array entry in the **table** member. Padding for alignment may also be present between the **MIB_UDP6ROW** array entries in the **table** member. Any access to a **MIB_UDP6ROW** array entry should assume padding may exist.

The **MIB_UDP6TABLE** structure contains the UDP listener table for IPv6 on the local computer. The name is based on the definition of this table in RFC 2454 published by the IETF. For more information, see
[http://www.ietf.org/rfc/rfc2454.txt](http://tools.ietf.org/html/rfc2454). This table contains UDP endpoints for IPv6 that have been bound to an address. It should be noted that an application can create a UDP socket and bind it to an address for the sole purpose of sending a UDP datagram, with no intention of receiving packets using this socket (functioning as a listener).

The [MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module) structure is an enhanced version of the [MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid) structure that includes any available ownership data for each UDP endpoint in the table. The **MIB_UDP6TABLE_OWNER_PID** is an enhanced version of the **MIB_UDP6TABLE** that includes the process ID (PID) that issued the call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function for each UDP endpoint in the table.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table)

[GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable)

[MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row)

[MIB_UDP6ROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_module)

[MIB_UDP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_pid)

[MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module)

[MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)

[MIB_UDPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_module)

[MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid)

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module)

[MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)