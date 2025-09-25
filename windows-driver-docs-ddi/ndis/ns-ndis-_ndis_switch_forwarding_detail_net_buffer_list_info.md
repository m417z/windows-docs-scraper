# _NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO structure

## Description

The **NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO** union specifies the information for forwarding a packet to one or more Hyper-V extensible switch ports.

This information is contained in the out-of-band (OOB) data of the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `AsUINT64`

The complete 64-bit **NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO** value.

### `NumAvailableDestinations`

A value that specifies the number of unused extensible switch destination ports elements within an [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. For more information, see the Remarks section.

### `SourcePortId`

The identifier of the source extensible switch port from which the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) originated.

### `SourceNicIndex`

A UINT32 value that specifies the index of the source network adapter that is connected to the extensible switch port specified by the **SourcePortId** member.

For more information on this index value, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

### `NativeForwardingRequired`

If this member is set to **TRUE**, packet is an NVGRE packet, and the Hyper-V Network Virtualization (HNV) component of the Hyper-V extensible switch will forward this packet. For more information, see [Hybrid Forwarding](https://learn.microsoft.com/windows-hardware/drivers/network/hybrid-forwarding).

This flag must not be written to by any extension.

**Note** This flag is available only in NDIS 6.40 and later.

### `Reserved1`

This member is reserved for future use by NDIS.

This member is reserved for future use by NDIS.

### `IsPacketDataSafe`

If this member is set to **TRUE**, all of the packet data comes from trusted
host memory.

### `SafePacketDataSize`

A value that specifies the number of consecutive bytes in the packet data that is located in trusted host memory. This value is in units of bytes from the start of the packet data. The rest of the packet data (if any) after the **SafePacketDataSize** value is located in untrusted
shared memory that is accessed by the Hyper-V child and parent partitions.

For more information, see the Remarks section.

**Note** This member is valid only if the **IsPacketDataSafe** member is set to **FALSE**.

### `IsPacketDataUncached`

If this flag is not set, the entire packet data is cached. If it is set, part or all of the data is *not* cached. When set, check the **IsSafePacketDataUncached** field to see if at least the SafePacketData portion is cached.

### `IsSafePacketDataUncached`

If the **IsPacketDataUncached** flag is set, this field indicates whether the SafePacketData part of the packet is cached. If so, see the **SafePacketDataSize** field for how many bytes are cached.

### `Reserved2`

This member is reserved for future use by NDIS.

## Remarks

Extensible switch extensions can use the [NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-switch-forwarding-detail) macro to access the **NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO** union in a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

The **NumAvailableDestinations** member of the **NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO** union specifies the number of unused extensible switch destination port elements within a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Each extensible switch destination port is specified by an [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) element within the [NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) structure of a **NET_BUFFER_LIST** structure. The extensible switch extension calls [GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations) to obtain the current **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** in a **NET_BUFFER_LIST** structure.

The **NativeForwardingRequired** member specifies whether the packet is an NVGRE packet or not. If it is **TRUE**, the packet is an NVGRE packet, and the forwarding extension doesn't determine the packet's forwarding destination port array, although it can add or exclude destination ports in the array. For more information, see [Hybrid Forwarding](https://learn.microsoft.com/windows-hardware/drivers/network/hybrid-forwarding).

The **IsPacketDataUncached** flag can help extensible switch extensions determine if part or all of the packet data is cached or not. If this flag is set, part or all of the data is *not* cached, and the **IsSafePacketDataUncached** flag tells the extension whether the safe packet data part is cached. If the safe packet data is cached, then the **SafePacketDataSize** member specifies how many bytes are cached.

**SafePacketDataSize** specifies the size of the packet data that is located in local, or *trusted*, memory in the parent operating system of the Hyper-V parent partition. This memory is not accessible by the child partition. Therefore, it is considered "safe" from unsynchronized updates by the guest operating system that runs in that partition.

If an extensible switch extension requires more trusted space in order to inspect the packet data, it must follow these steps:

1. The extension must duplicate the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure by allocating a **NET_BUFFER_LIST** and [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. The extension then calls [NdisCopyFromNetBufferToNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscopyfromnetbuffertonetbuffer) to duplicate the packet's **NET_BUFFER** structure. If this function completes successfully, the packet's data is copied to trusted memory.
2. The extension must call [CopyNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_copy_net_buffer_list_info) to copy the packet's OOB data to the duplicated packet.
3. After the original packet has been duplicated, the extension must obtain the **NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO** union in the duplicated packet by using the [NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-switch-forwarding-detail) macro. The extension must set the **IsPacketDataSafe** member to **TRUE**.

For more information on how to duplicate packets in the extensible switch interface, see [Originating Packet Traffic](https://learn.microsoft.com/windows-hardware/drivers/network/originating-packet-traffic).

## See also

[Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions)

[Forwarding Packets to Hyper-V Extensible Switch Ports](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-packets-to-hyper-v-extensible-switch-ports)

[Forwarding Packets to Physical Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-packets-to-physical-network-adapters)

[GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations)

[Hybrid Forwarding](https://learn.microsoft.com/windows-hardware/drivers/network/hybrid-forwarding)

[NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-switch-forwarding-detail)

[Overview of the Hyper-V Extensible Switch](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-the-hyper-v-extensible-switch)