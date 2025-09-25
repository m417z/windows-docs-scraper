# MIB_IPMCAST_OIF_W2K structure

## Description

The
**MIB_IPMCAST_OIF** structure stores the information required to send an outgoing IP multicast packet.

## Members

### `dwOutIfIndex`

The index of the interface on which to send the outgoing IP multicast packet.

### `dwNextHopAddr`

The destination address for the outgoing IPv4 multicast packet.

### `pvReserved`

Reserved. This member should be **NULL**.

### `dwReserved`

Reserved. This member should be zero.

## Remarks

The **MIB_IPMCAST_MFE** structure is used by the [Multicast Group Manager functions](https://learn.microsoft.com/windows/desktop/RRAS/multicast-group-manager-functions). The **MIB_IPMCAST_OIF** structure is retrieved as a member of the **MIB_IPMCAST_MFE** structure using the [MgmGetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetmfe) function.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Server 2008and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe)

[MIB_IPMCAST_OIF_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_oif_stats_lh)

[MgmGetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetmfe)

[Multicast Group Manager functions](https://learn.microsoft.com/windows/desktop/RRAS/multicast-group-manager-functions)