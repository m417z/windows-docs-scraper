# MIB_IPFORWARDNUMBER structure

## Description

The
**MIB_IPFORWARDNUMBER** structure stores the number of routes in a particular IP routing table.

## Members

### `dwValue`

Specifies the number of routes in the IP routing table.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow)

[MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable)