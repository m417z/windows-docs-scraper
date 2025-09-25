# MIB_IPMCAST_MFE_STATS_EX_XP structure

## Description

The **MIB_IPMCAST_MFE_STATS_EX** structure stores the extended statistics associated with a Multicast Forwarding Entry (MFE).

## Members

### `dwGroup`

Type: **DWORD**

The multicast group for this MFE. A value of zero indicates a wildcard group.

### `dwSource`

Type: **DWORD**

The range of source addresses for this MFE. A value of zero indicates a wildcard source.

### `dwSrcMask`

Type: **DWORD**

The IPv4 subnet mask that corresponds to **dwSourceAddr**. The **dwSourceAddr** and **dwSourceMask** members are used together to define a range of sources.

### `dwUpStrmNgbr`

Type: **DWORD**

The upstream neighbor that is related to this MFE.

### `dwInIfIndex`

Type: **DWORD**

The index of the incoming interface to which this MFE is related.

### `dwInIfProtocol`

Type: **DWORD**

The routing protocol that owns the incoming interface to which this MFE is related.

### `dwRouteProtocol`

Type: **DWORD**

The client that created the route.

### `dwRouteNetwork`

Type: **DWORD**

The address associated with the route referred to by **dwRouteProtocol**.

### `dwRouteMask`

Type: **DWORD**

The mask associated with the route referred to by **dwRouteProtocol**.

### `ulUpTime`

Type: **ULONG**

The time, in 100ths of a seconds, since the MFE was created.

### `ulExpiryTime`

Type: **ULONG**

The time, in 100ths of a seconds, until the MFE will be deleted. Zero is specified if the MFE is not subject to aging requirements.

### `ulNumOutIf`

Type: **ULONG**

The number of interfaces in the outgoing interface list for this MFE.

### `ulInPkts`

Type: **ULONG**

The number of packets that have been forwarded that matched this MFE.

### `ulInOctets`

Type: **ULONG**

The number of octets of data forwarded that match this MFE.

### `ulPktsDifferentIf`

Type: **ULONG**

The number of packets matching this MFE that were dropped due to an incoming interface check.

### `ulQueueOverflow`

Type: **ULONG**

The number of packets matching this MFE that were dropped due to a queue overflow. There is one queue per MFE.

### `ulUninitMfe`

Type: **ULONG**

The number of uninitialized packets that matched this MFE.

### `ulNegativeMfe`

Type: **ULONG**

The number of packets matching this MFE discarded due to a negative error value.

### `ulInDiscards`

Type: **ULONG**

The number of discarded forwarded packets that matched this MFE.

### `ulInHdrErrors`

Type: **ULONG**

The number of packets matching this MFE discarded due to bad or malformed header values (such as a bad Time-to-Live value).

### `ulTotalOutPackets`

Type: **ULONG**

The total number of MFE packets transmitted across all associated interfaces. Note that one packet sent over N interfaces will count as N packets within this value.

### `rgmiosOutStats`

## Remarks

The **MIB_IPMCAST_MFE_STATS_EX** structure extends the functionality of [MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats) by including additional information on MFE packets.

This structure does not have a fixed size. Use the **SIZEOF_MIB_MFE_STATS_EX(X)** macro to determine the size of this structure. This macro is defined in the Iprtrmib.h header file.

The **dwRouteProtocol**, **dwRouteNetwork**, and **dwRouteMask** members uniquely identify the route to which this MFE is related.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats)

[MIB_MFE_STATS_TABLE_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_mfe_stats_table_ex_xp)