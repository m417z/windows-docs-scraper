# TCP_TABLE_CLASS enumeration

## Description

The **TCP_TABLE_CLASS** enumeration defines the set of values used to indicate the type of table returned by calls to [GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable).

## Constants

### `TCP_TABLE_BASIC_LISTENER`

A [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) table that contains all listening (receiving only) TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_BASIC_CONNECTIONS`

A [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) table that contains all connected TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_BASIC_ALL`

A [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) table that contains all TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_OWNER_PID_LISTENER`

A [MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid) or [MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid) that contains all listening (receiving only) TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_OWNER_PID_CONNECTIONS`

A [MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid) or [MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid) that structure that contains all connected TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_OWNER_PID_ALL`

A [MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid) or [MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid) structure that contains all TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_OWNER_MODULE_LISTENER`

A [MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module) or [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) structure that contains all listening (receiving only) TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_OWNER_MODULE_CONNECTIONS`

A [MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module) or [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) structure that contains all connected TCP endpoints on the local computer is returned to the caller.

### `TCP_TABLE_OWNER_MODULE_ALL`

A [MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module) or [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) structure that contains all TCP endpoints on the local computer is returned to the caller.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **TCP_TABLE_CLASS** enumeration is defined in the *Iprtrmib.h* header file, not in the *Iphlpapi.h* header file. Note that the *Iprtrmib.h* header file is automatically included in *Iphlpapi.h* header file. The *Iprtrmib.h* header files should never be used directly.

## See also

[GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable)