# MIB_TCP6TABLE_OWNER_PID structure

## Description

The **MIB_TCP6TABLE_OWNER_PID** structure contains a table of process IDs (PIDs) and the IPv6 TCP links that are context bound to these PIDs.

## Members

### `dwNumEntries`

The number of [MIB_TCP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row_owner_pid) elements in the **table**.

### `table`

Array of [MIB_TCP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row_owner_pid) structures returned by a call to [GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable).

## Remarks

The **MIB_TCP6TABLE_OWNER_PID** structure is returned by a call to [GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable) with the *TableClass* parameter set to **TCP_TABLE_OWNER_PID_LISTENER**, **TCP_TABLE_OWNER_PID_CONNECTIONS**, or **TCP_TABLE_OWNER_PID_ALL** from the [TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class) enumeration and the *ulAf* parameter set to **AF_INET6**.

The **MIB_TCP6TABLE_OWNER_PID** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_TCP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row_owner_pid) array entry in the **table** member. Padding for alignment may also be present between the **MIB_TCP6ROW_OWNER_PID** array entries in the **table** member. Any access to a **MIB_TCP6ROW_OWNER_PID** array entry should assume padding may exist.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)

[MIB Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures)