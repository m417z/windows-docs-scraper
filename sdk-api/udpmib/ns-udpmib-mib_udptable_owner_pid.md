# MIB_UDPTABLE_OWNER_PID structure

## Description

The **MIB_UDPTABLE_OWNER_PID** structure contains the User Datagram Protocol (UDP) listener table for IPv4 on the local computer. The table also includes the process ID (PID) that issued the call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function for each UDP endpoint.

## Members

### `dwNumEntries`

The number of [MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid) elements in **table**.

### `table`

An array of [MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid) structures returned by a call to [GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable).

## Remarks

The **MIB_UDPTABLE_OWNER_PID** structure is returned by a call to [GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable) with the *TableClass* parameter set to **UDP_TABLE_OWNER_PID** from the [UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class) enumeration and the *ulAf* parameter set to **AF_INET4**. The **MIB_UDPTABLE_OWNER_PID** structure contains an array of [MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid) structures.

The **MIB_UDPTABLE_OWNER_PID** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid) array entry in the **table** member. Padding for alignment may also be present between the **MIB_UDPROW_OWNER_PID** array entries in the **table** member. Any access to a **MIB_UDPROW_OWNER_PID** array entry should assume padding may exist.

The **MIB_UDPTABLE_OWNER_PID** structure contains the UDP listener table for IPv4 on the local computer. The name is based on the definition of this table in RFC 1213 published by the IETF. For more information, see
[http://www.ietf.org/rfc/rfc1213.txt](http://tools.ietf.org/html/rfc1213). This table contains UDP endpoints for IPv4 that have been bound to an address. It should be noted that an application can create a UDP socket and bind it to an address for the sole purpose of sending a UDP datagram, with no intention of receiving packets using this socket (functioning as a listener).

The [MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module) structure is an enhanced version of the **MIB_UDPTABLE_OWNER_PID** structure that includes any available ownership data for each UDP endpoint in the table. The **MIB_UDPTABLE_OWNER_PID** is an enhanced version of the [MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) that includes the process ID (PID) that issued the call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function for each UDP endpoint in the table.

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

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module)

[UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)