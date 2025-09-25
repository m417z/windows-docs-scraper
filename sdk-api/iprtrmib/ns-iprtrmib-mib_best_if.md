# MIB_BEST_IF structure

## Description

The
**MIB_BEST_IF** structure stores the index of the interface that has the best route to a particular destination IPv4 address.

## Members

### `dwDestAddr`

Specifies the IPv4 address of the destination.

### `dwIfIndex`

Specifies the index of the interface that has the best route to the destination address specified by the **dwDestAddr** member.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_BEST_IF** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetBestInterface](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterface)

[GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute)