# MIB_IPMCAST_BOUNDARY structure

## Description

The **MIB_IPMCAST_BOUNDARY** structure contains a row in a [MIB_IPMCAST_BOUNDARY_TABLE](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_ipmcast_boundary_table) structure that lists a router's scoped IPv4 multicast address boundaries.

## Members

### `dwIfIndex`

Type: **DWORD**

The index value for the interface to which this boundary applies. Packets with a destination address in the associated address/mask range are not forwarded with this interface.

### `dwGroupAddress`

Type: **DWORD**

The 32-bit integer representation of the IPv4 group address which, when combined with the corresponding value in **dwGroupMask**, identifies the group range for which the scoped boundary exists.

**Note** Scoped addresses must come from the range 239.*.*.* as specified in [RFC 2365](https://www.ietf.org/rfc/rfc2365.txt).

### `dwGroupMask`

Type: **DWORD**

The 32-bit integer representation of the IPv4 group address mask which, when combined with the corresponding value in **dwGroupAddress**, identifies the group range for which the scoped boundary exists.

### `dwStatus`

Type: **DWORD**

A status value that describes the current status of this entry in a MFE boundary table.

| Value | Meaning |
| --- | --- |
| 1 | The entry has **active** status. |
| 2 | The entry has **notInService** status. |
| 3 | The entry has **notReady** status. |
| 4 | The entry has **createAndGo** status. |
| 5 | The entry has **createAndWait** status. |
| 6 | The entry has **destroy** status. |

## Remarks

Note that the *Iprtrmib.h* header file is automatically included in the *Iphlpapi.h* header file. The *Iprtrmib.h* header file should never be used directly.

## See also

[MIB_IPMCAST_BOUNDARY_TABLE](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_ipmcast_boundary_table)