# _NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO structure

## Description

The **NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO** structure specifies information that is used in
offloading large send offload (LSO) tasks from the TCP/IP transport to a miniport adapter. The
**NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO** structure is part of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information.

## Members

### `Transmit`

A structure within NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO that specifies transmit
information and that contains the following members:

### `Transmit.Unused`

A ULONG value that specifies unused space that is reserved for NDIS.

### `Transmit.Type`

The offload type that the miniport driver should run. Protocol drivers set this member to
NDIS_TCP_LARGE_SEND_OFFLOAD_V1_TYPE to specify large send offload version 1 (LSOV1) operations or to
NDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE to specify large send offload version 2 (LSOV2)
operations.

### `Transmit.Reserved2`

Reserved for NDIS.

### `LsoV1Transmit`

A structure within NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO that specifies LSO transmit
information and that contains the following members:

### `LsoV1Transmit.MSS`

The maximum segment size (MSS), in bytes, for each packet after segmentation. The TCP/IP
transport writes this value before passing a large TCP packet to a miniport driver for segmentation.
The size of TCP payload in each transmitted segment must not exceed this value.

### `LsoV1Transmit.TcpHeaderOffset`

The offset, in bytes, of the TCP header from the beginning of the packet for TCP packets.
Miniport drivers can use
**TcpHeaderOffset** to determine the location of the TCP header so that they do not have to parse
IP headers.

### `LsoV1Transmit.Type`

The offload type that the miniport driver should run. Protocol drivers set this member to
NDIS_TCP_LARGE_SEND_OFFLOAD_V1_TYPE to specify LSOV1 operations or to
NDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE to specify LSOV2 operations.

### `LsoV1Transmit.Reserved2`

Reserved for NDIS.

### `LsoV1TransmitComplete`

A structure within NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO that specifies LSO transmit
complete information and that contains the following members:

### `LsoV1TransmitComplete.TcpPayload`

The total number of TCP payload bytes in a set of packets that a network interface card (NIC)
created by segmenting a large packet. A miniport driver writes the TCP payload size before completing
the send of an LSO packet.

### `LsoV1TransmitComplete.Type`

The offload type that the miniport driver performed. The miniport drivers leaves this value the
same as it was when the overlying driver submitted the packet for transmit.

### `LsoV1TransmitComplete.Reserved2`

Reserved for NDIS.

### `LsoV2Transmit`

A structure within NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO that specifies LSOV2 transmit
information and that contains the following members:

### `LsoV2Transmit.MSS`

The MSS, in bytes, for each TCP segment. The TCP/IP transport writes this value before passing
a large TCP packet to a miniport driver for segmentation.

### `LsoV2Transmit.TcpHeaderOffset`

The offset, in bytes, of the TCP header from the beginning of the packet for TCP packets.
Miniport drivers can use
**TcpHeaderOffset** to determine the location of the TCP header so that they do not have to parse
IP headers.

### `LsoV2Transmit.Type`

The offload type that the miniport driver should run. Protocol drivers set this member to
NDIS_TCP_LARGE_SEND_OFFLOAD_V1_TYPE to specify LSOV1 operations or to
NDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE to specify LSOV2 operations.

### `LsoV2Transmit.IPVersion`

The IP version of the packet. For IPv4 packets,
**IPVersion** is set to NDIS_TCP_LARGE_SEND_OFFLOAD_IPv4. For IPv6 packets,
**IPVersion** is set to NDIS_TCP_LARGE_SEND_OFFLOAD_IPv6.

### `LsoV2TransmitComplete`

A structure within NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO that specifies LSOV2 transmit
complete information and that contains the following members:

### `LsoV2TransmitComplete.Reserved`

In general, this member is reserved for NDIS. However, when a send operation is complete, the miniport driver must set this member to zero.

### `LsoV2TransmitComplete.Type`

The offload type that the miniport driver performed. The miniport driver leaves this value the
same as it was when the overlying driver submitted the packet for transmit.

 For example, when a send operation is complete, the miniport driver sets this member to **NDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE**.

### `LsoV2TransmitComplete.Reserved2`

Reserved for NDIS.

### `Value`

A PVOID version of the LSO information. Use this member to access the raw information instead of
the specific fields.

## Remarks

The **NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO** structure specifies information for LSOV1 and
LSOV2 operations. The **NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO** structure is part of the
information that is included in a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

To set and get the LSOV1 or LSOV2 information, use the
**TcpLargeSendNetBufferListInfo** index with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro.
**NET_BUFFER_LIST_INFO** returns a ULONG value (not a pointer to a ULONG value).

The TCP/IP transport updates the
**MSS** and
**TcpHeaderOffset** members of the **NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO** structure before
sending a large packet to a miniport driver.

For LSOV1, miniport drivers write the TCP payload size in the
**TcpPayload** member before completing a send operation for a segmented packet.

**Note** Any [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that contains the LSOv1 or LSOv2 information also
contains a single
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[Offloading the Segmentation of Large TCP Packets](https://learn.microsoft.com/windows-hardware/drivers/network/offloading-the-segmentation-of-large-tcp-packets)