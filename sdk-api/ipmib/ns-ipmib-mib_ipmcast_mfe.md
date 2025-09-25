# MIB_IPMCAST_MFE structure

## Description

The
**MIB_IPMCAST_MFE** structure stores the information for an Internet Protocol (IP) Multicast Forwarding Entry (MFE).

## Members

### `dwGroup`

Type: **DWORD**

The range of IPv4 multicast groups for this MFE. A value of zero indicates a wildcard group.

### `dwSource`

Type: **DWORD**

The range of IPv4 source addresses for this MFE. A value of zero indicates a wildcard source.

### `dwSrcMask`

Type: **DWORD**

The IPv4 subnet mask that corresponds to **dwSourceAddr**. The **dwSourceAddr** and **dwSourceMask** members are used together to define a range of sources.

### `dwUpStrmNgbr`

Type: **DWORD**

The upstream neighbor that is related to this MFE.

### `dwInIfIndex`

Type: **DWORD**

The index of the interface to which this MFE is related.

### `dwInIfProtocol`

Type: **DWORD**

The routing protocol that owns the incoming interface to which this MFE is related.

### `dwRouteProtocol`

Type: **DWORD**

The client that created the route.

### `dwRouteNetwork`

Type: **DWORD**

The IPv4 address associated with the route referred to by **dwRouteProtocol**.

### `dwRouteMask`

Type: **DWORD**

The IPv4 mask associated with the route referred to by **dwRouteProtocol**.

### `ulUpTime`

Type: **ULONG**

The time, in seconds, this MFE has been valid. This value starts from zero and is incremented until it reaches the **ulTimeOut** value, at which time the MFE is deleted.

### `ulExpiryTime`

Type: **ULONG**

The time, in seconds, that remains before the MFE expires and is deleted. This value starts from **ulTimeOut** and is decremented until it reaches zero, at which time the MFE is deleted.

### `ulTimeOut`

Type: **ULONG**

The total length of time, in seconds, that this MFE should remain valid. After the time-out value is exceeded, the MFE is deleted. This value is static.

### `ulNumOutIf`

Type: **ULONG**

The number of outgoing interfaces that are associated with this MFE.

### `fFlags`

Type: **DWORD**

Reserved. This member should be **NULL**.

### `dwReserved`

Type: **DWORD**

Reserved. This member should be **NULL**.

### `rgmioOutInfo`

Type: **MIB_IPMCAST_OIF[ANY_SIZE]**

A pointer to a table of outgoing interface statistics that are implemented as an array of
[MIB_IPMCAST_OIF](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_oif_w2k) structures.

## Remarks

The
**MIB_IPMCAST_MFE** structure does not have a fixed size. Use the **SIZEOF_MIB_MFE(X)** macro to determine the size of this structure. This macro is defined in the Iprtrmib.h header file.

The **dwRouteProtocol**, **dwRouteNetwork**, and **dwRouteMask** members uniquely identify the route to which this MFE is related.

The **MIB_IPMCAST_MFE** structure is used by the [Multicast Group Manager functions](https://learn.microsoft.com/windows/desktop/RRAS/multicast-group-manager-functions). The **MIB_IPMCAST_MFE** structure is retrieved using the [MgmGetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetmfe) function. An existing **MIB_IPMCAST_MFE** structure can be modified using the [MgmSetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmsetmfe) function.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_OIF](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_oif_w2k)

[MIB_MFE_TABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_mfe_table)

[MgmGetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetmfe)

[MgmSetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmsetmfe)

[Multicast Group Manager functions](https://learn.microsoft.com/windows/desktop/RRAS/multicast-group-manager-functions)