# MIB_IPMCAST_IF_ENTRY structure

## Description

The
**MIB_IPMCAST_IF_ENTRY** structure stores information about an IP multicast interface.

## Members

### `dwIfIndex`

The index of this interface.

### `dwTtl`

The time-to-live value for this interface.

### `dwProtocol`

The multicast routing protocol that owns this interface.

### `dwRateLimit`

The rate limit of this interface.

### `ulInMcastOctets`

The number of octets of multicast data received through this interface.

### `ulOutMcastOctets`

The number of octets of multicast data sent through this interface.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_IF_TABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_if_table)