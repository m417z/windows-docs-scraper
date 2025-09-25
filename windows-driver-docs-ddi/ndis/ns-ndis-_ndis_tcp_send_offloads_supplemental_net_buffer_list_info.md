# _NDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO structure

## Description

The **NDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO** structure contains additional out-of-band information for encapsulated packets. For more information, see [Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_encapsulated_packet_task_offload) (NVGRE-TO).

## Members

### `EncapsulatedPacketOffsets`

### `EncapsulatedPacketOffsets.IsEncapsulatedPacket`

If this member is **TRUE**, this NBL represents a packet containing an inner Ethernet frame with a transport IP header. It is **FALSE** for normal packets. When **IsEncapsulatedPacket** is **TRUE**, the existing header offset fields, [NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_tcp_large_send_offload_net_buffer_list_info).**LsoV2Transmit**.**TcpHeaderOffset** and [NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_tcp_ip_checksum_net_buffer_list_info).**Transmit**.**TcpHeaderOffset**, will not have correct values and must not be used by the NIC or driver. Instead, the miniport driver must use the offsets specified in the other members of this structure.

### `EncapsulatedPacketOffsets.EncapsulatedPacketOffsetsValid`

If this member is **TRUE**, the **InnerFrameOffset**, **TransportIpHeaderRelativeOffset**, and **TcpHeaderRelativeOffset** members
have valid values.

### `EncapsulatedPacketOffsets.InnerFrameOffset`

Offset from the beginning of the packet to the first byte of the inner Ethernet frame.

### `EncapsulatedPacketOffsets.TransportIpHeaderRelativeOffset`

Offset to the first byte of the inner IP header relative to the **InnerFrameOffset**.

### `EncapsulatedPacketOffsets.TcpHeaderRelativeOffset`

Offset to the first byte of the inner (transport) header relative to the **TransportIpHeaderRelativeOffset**. This value is always set to the correct offset, even if the inner frame is not a TCP packet.

### `EncapsulatedPacketOffsets.IsInnerIPv6`

Set by the protocol driver to indicate that the inner IP header in the encapsulated packet contains IPv6 addresses.

### `EncapsulatedPacketOffsets.TcpOptionsPresent`

Set by the protocol driver when the inner TCP header contains TCP options. This allows a miniport driver to optimize the case when there are no options to assume the TCP header length to access the payload.

### `EncapsulatedPacketOffsets.Reserved`

Reserved for future use.

### `Value`

Reserved for future use.

## Remarks

The members of **NDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO** are meaningful if and only if **TcpIpChecksumNetBufferListInfo** or **TcpLargeSendNetBufferListInfo** is specified in the [NDIS_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info) structure.

If the **IsEncapsulatedPacket** member is **TRUE** and the **TcpIpChecksumNetBufferListInfo** out-of-band (OOB) information is valid, this indicates that NVGRE support is required and the NIC must compute the checksum for the tunnel (outer) IP header, the transport (inner) IP header, and the TCP or UDP header if one of them is present. An NVGRE packet will only be offloaded if the packet conforms to miniport-advertised capabilities. For example, a packet containing a UDP header will not be offloaded if the miniport did not advertise UDP Tx checksum offload support in its base capabilities. For more information, see [Offloading Checksum Tasks](https://learn.microsoft.com/windows-hardware/drivers/network/offloading-checksum-tasks).

## See also

[NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_encapsulated_packet_task_offload)

[NDIS_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info)

[Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_encapsulated_packet_task_offload)

[Offloading Checksum Tasks](https://learn.microsoft.com/windows-hardware/drivers/network/offloading-checksum-tasks)