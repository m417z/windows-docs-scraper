# _NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO structure

## Description

Defines the group network virtualization information for a network buffer list (NBL).

## Members

### `VirtualSubnetId`

The originating virtual switch port ID for the network buffer list.

### `ReservedVsidBits`

This member is reserved and should be set to zero.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that is contained in **NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO**.
**Value** contains a pointer value that is type-compatible with the
**NetBufferListInfo** member in the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. (See the **VirtualSubnetInfo** constant in the [NDIS_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info) enumeration.)

## Remarks

This structure is used in the **NetBufferListInfo** member in the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

In NDIS 6.40 (Windows Server 2012 R2) and later, a **VirtualSubnetId** can be configured on a VM network adapter port as an external virtual subnet to support a third-party network virtualization solution. A Hyper-V extensible Switch forwarding extension may then modify the packet headers, as required, during forwarding. Packets that are being modified must be cloned, and their **ParentNetBufferList** pointers must be set to the original NBL.

## See also

[Cloning Packet Traffic](https://learn.microsoft.com/windows-hardware/drivers/network/cloning-or-duplicating-packet-traffic)

[Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions)

[NDIS_ISOLATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_isolation_mode)

[NDIS_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info)

[NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Overview of the Hyper-V Extensible Switch](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-the-hyper-v-extensible-switch)