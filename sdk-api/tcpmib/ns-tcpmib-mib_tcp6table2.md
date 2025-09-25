# MIB_TCP6TABLE2 structure

## Description

The
**MIB_TCP6TABLE2** structure contains a table of IPv6 TCP connections on the local computer.

## Members

### `dwNumEntries`

A value that specifies the number of TCP connections in the array.

### `table`

An array of
[MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2) structures containing TCP connection entries.

## Remarks

The **MIB_TCP6TABLE2** structure is defined on Windows Vista and later.

The [GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2) function retrieves the IPv6 TCP connection table on the local computer and returns this information in a **MIB_TCP6TABLE2** structure.

An array of [MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2) structures are contained in the **MIB_TCP6TABLE2** structure.

The **MIB_TCP6TABLE2** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2) array entry in the **table** member. Padding for alignment may also be present between the **MIB_TCP6ROW2** array entries in the **table** member. Any access to a **MIB_TCP6ROW2** array entry should assume padding may exist.

## See also

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2)

[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable)

[GetTcpTable2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable2)

[MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row)

[MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2)

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[MIB_TCPTABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable2)