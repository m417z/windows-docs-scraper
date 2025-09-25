# MIB_IPMCAST_GLOBAL structure

## Description

The
**MIB_IPMCAST_GLOBAL** structure stores global information for IP multicast on a particular computer.

## Members

### `dwEnable`

Specifies whether IP multicast is enabled on the computer.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_IF_ENTRY](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_if_entry)

[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe)

[MIB_IPMCAST_OIF](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_oif_w2k)