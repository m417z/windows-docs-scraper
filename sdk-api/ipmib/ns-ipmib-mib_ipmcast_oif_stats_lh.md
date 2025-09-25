## Description

The
**MIB_IPMCAST_OIF_STATS** structure stores the statistics that are associated with an outgoing multicast interface.

## Members

### `dwOutIfIndex`

Type: **DWORD**

Specifies the outgoing interface to which these statistics are related.

### `dwNextHopAddr`

Type: **DWORD**

Specifies the address of the next hop that corresponds to **dwOutIfIndex**. The **dwOutIfIndex** and **dwIfNextHopIPAddr** members uniquely identify a next hop on point-to-multipoint interfaces, where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple-access (NBMA) interfaces, and the internal interface on which all dial-up clients connect.

For Ethernet and other broadcast interfaces, specify zero. Also specify zero for point-to-point interfaces, which are identified by only **dwOutIfIndex**.

### `dwDialContext`

TBD

### `ulTtlTooLow`

Type: **ULONG**

Specifies the number of packets on this outgoing interface that were discarded because the packet's time-to-live (TTL) value was too low.

### `ulFragNeeded`

Type: **ULONG**

Specifies the number of packets that required fragmentation when they were forwarded on this interface.

### `ulOutPackets`

Type: **ULONG**

Specifies the number of packets that were forwarded out this interface.

### `ulOutDiscards`

Type: **ULONG**

Specifies the number of packets that were discarded on this interface.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Server 2008and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_OIF](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_oif_w2k)