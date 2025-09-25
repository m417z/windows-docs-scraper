# UDP_TABLE_CLASS enumeration

## Description

The **UDP_TABLE_CLASS** enumeration defines the set of values used to indicate the type of table returned by calls to [GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable).

## Constants

### `UDP_TABLE_BASIC`

A [MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) structure that contains all UDP endpoints on the local computer is returned to the caller.

### `UDP_TABLE_OWNER_PID`

A [MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid) or [MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid) structure that contains all UDP endpoints on the local computer is returned to the caller.

### `UDP_TABLE_OWNER_MODULE`

A [MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module) or [MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module) structure that contains all UDP endpoints on the local computer is returned to the caller.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **UDP_TABLE_CLASS** enumeration is defined in the *Iprtrmib.h* header file, not in the *Iphlpapi.h* header file. Note that the *Iprtrmib.h* header file is automatically included in *Iphlpapi.h* header file. The *Iprtrmib.h* header files should never be used directly.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)