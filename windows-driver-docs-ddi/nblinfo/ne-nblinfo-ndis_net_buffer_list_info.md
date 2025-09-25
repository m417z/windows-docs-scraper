# _NDIS_NET_BUFFER_LIST_INFO enumeration

## Description

The **NDIS_NET_BUFFER_LIST_INFO** enumeration identifies information that is common to all
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer) structures in a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list) structure.

## Constants

### `TcpIpChecksumNetBufferListInfo`

Identifies checksum information that is used in offloading checksum tasks from the TCP/IP protocol
to a miniport driver. When
**TcpIpChecksumNetBufferListInfo** is specified, the [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro returns an
[NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_tcp_ip_checksum_net_buffer_list_info) structure. This structure contains a union that allows
the checksum information to be accessed as a single **PVOID** value or as bit fields.

### `TcpOffloadBytesTransferred`

Identifies a **ULONG** value that is the number of data bytes that were transferred in a TCP chimney
offload send, receive, or disconnect operation.

### `IPsecOffloadV1NetBufferListInfo`

Identifies Internet Protocol security (IPsec) information that is used in offloading IPsec tasks
from the TCP/IP protocol to a miniport driver. When
**IPsecOffloadV1NetBufferListInfo** is specified, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an
[NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v1_net_buffer_list_info) structure.

### `IPsecOffloadV2NetBufferListInfo`

Specifies Internet protocol security offload version 2 (IPsecV2) information that is used in
offloading IPsec tasks from the TCP/IP protocol to a miniport driver. When you specify
**IPsecOffloadV2NetBufferListInfo**, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an
[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info) structure.

### `TcpLargeSendNetBufferListInfo`

Identifies information that is used in offloading the segmentation of a large TCP packet from the
TCP/IP protocol to a miniport adapter for large send offload version 1 (LSOV1) and large send offload
version 2 (LSOV2). When
**TcpLargeSendNetBufferListInfo** is specified, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an
[NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_tcp_large_send_offload_net_buffer_list_info) structure. This structure contains a union that
enables the information to be accessed as a single PVOID value or as bit fields.

Before passing a large TCP packet to a miniport driver for segmentation, the TCP/IP protocol writes
the values in the
**LsoV1Transmit** member of the [NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_tcp_large_send_offload_net_buffer_list_info) structure for LSOV1
or the
**LsoV2Transmit** member for LSOV2. Before completing the send of a large TCP packet that it has
segmented into smaller packets, a miniport driver writes the values in the
**LsoV1TransmitComplete** member of the **NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO** structure for
LSOV1 or the
**LsoV2TransmitComplete** member for LSOV2. For LSOV1, the value that the miniport driver writes
includes the total number of TCP payload bytes that the miniport driver sent in the packets that it
segmented from the large TCP packet.

### `TcpReceiveNoPush`

Identifies a **Boolean** value that represents the push mode of a TCP chimney offload receive request.
If **TRUE**, the receive request is in non-push mode. Otherwise, the receive request is in push mode.

### `ClassificationHandleNetBufferListInfo`

Reserved.

### `Ieee8021QNetBufferListInfo`

Identifies 802.1Q information about a packet. When
**Ieee8021QNetBufferListInfo** is specified,
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns the
**Value** member of an
[NDIS_NET_BUFFER_LIST_8021Q_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_8021q_info) structure. This structure can specify 802.1p priority and VLAN
identifier information. 802.1p priority information is used to establish packet priority in shared-media
802 networks. Miniport drivers that support the 802.1Q tag in hardware must use the
**NDIS_NET_BUFFER_LIST_8021Q_INFO** structure for transmit and receive operations.

### `NetBufferListCancelId`

Identifies a **ULONG_PTR** value that is a cancellation identifier for the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list) structure. To cancel the
pending transmission of a marked **NET_BUFFER_LIST** structure, a protocol driver passes the packet's
cancellation identifier to
[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndiscancelsendnetbufferlists). Drivers must call
[NdisGeneratePartialCancelId](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndisgeneratepartialcancelid) to obtain a value that the driver must use as the high-order byte of a
cancellation identifier.

### `MediaSpecificInformation`

Identifies a PVOID value that is the address of a driver-allocated buffer. This buffer contains
any media-specific out-of-band data that accompanies the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer) structures that are associated with
the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list) structure. If a protocol driver allocated the out-of-band data, it configured the
data for a send operation. If a miniport driver allocated the data, it configured the data for a receive
indication.

### `NetBufferListFrameType`

Identifies a **USHORT** value that is the frame type of the received Ethernet packets.

### `NetBufferListProtocolId`

Identifies a **UCHAR** value that is a protocol identifier as one of the following values:

* NDIS_PROTOCOL_ID_DEFAULT

+ A default protocol driver identifier.

* NDIS_PROTOCOL_ID_TCP_IP

+ The TCP/IP protocol.

* NDIS_PROTOCOL_ID_IPX

+ The IPX protocol.

* NDIS_PROTOCOL_ID_NBF

+ The NetBEUI protocol.

### `NetBufferListHashValue`

On the receive path,
**NetBufferListHashValue** identifies a **ULONG** value that is the RSS hash value that a NIC calculated,
if any.

On the transmit path,
**NetBufferListHashValue** identifies a **ULONG** value that is the RSS hash value that TCP/IP calculated,
if any. In this case, all [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer) structures in a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list) structure that TCP/IP submitted
belong to the same UDP or TCP connection. Therefore, this hash value applies to all **NET_BUFFER**
structures that are in the **NET_BUFFER_LIST** structure.

For more information, see
[Indicating RSS Receive
Data](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-rss-receive-data).

### `NetBufferListHashInfo`

Identifies a **ULONG** value that is the RSS hash information, which includes the hash function and
hash type. For more information, see
[Indicating RSS Receive
Data](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-rss-receive-data).

### `WfpNetBufferListInfo`

Reserved for use by the Windows Filtering Platform (WFP). No drivers, including WFP callout
drivers, can store information by using this value.

### `IPsecOffloadV2TunnelNetBufferListInfo`

Specifies IPsecV2 tunnel information that is used in offloading IPsec tasks from the TCP/IP protocol
to a miniport driver. When you specify
**IPsecOffloadV2TunnelNetBufferListInfo**, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an
[NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v2_tunnel_net_buffer_list_info) structure.

### `IPsecOffloadV2HeaderNetBufferListInfo`

Specifies IPsecV2 header information that is used in offloading IPsec tasks from the TCP/IP protocol
to a miniport driver. When you specify **IPsecOffloadV2HeaderNetBufferListInfo**, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an
[NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v2_header_net_buffer_list_info) structure.

### `NetBufferListCorrelationId`

Reserved.

### `NetBufferListFilteringInfo`

Specifies filtering information that is used in the virtual machine queue (VMQ) interface, the single root I/O virtualization (SR-IOV) interface, and NDIS packet coalescing. When you specify
**NetBufferListFilteringInfo**, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an
[NDIS_NET_BUFFER_LIST_FILTERING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info) structure.

Starting with NDIS 6.20, receive indications made by miniport drivers that support VMQ, SR-IOV, or packet coalescing must include an [NDIS_NET_BUFFER_LIST_FILTERING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info) structure. The miniport drivers must set the VMQ queue identifier in the
**QueueId** member of the **NDIS_NET_BUFFER_LIST_FILTERING_INFO** structure. The driver also sets the **FilterId** member of the **NDIS_NET_BUFFER_LIST_FILTERING_INFO** structure to zero.

**Note** Starting with NDIS 6.30, the miniport driver that supports SR-IOV or packet coalescing must set the **QueueId** to **NDIS_DEFAULT_RECEIVE_QUEUE_ID** and the **FilterId** member to zero.

### `MediaSpecificInformationEx`

Identifies a pointer to a driver-allocated
[NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex) structure. This structure identifies any media-specific
out-of-band data that accompanies the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer) structures that are associated with the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list)
structure. NDIS 6.20 and later drivers should use the **NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX** structure
to specify media specific information. Any driver in an NDIS driver stack can allocate and manage
media-specific information.

### `NblOriginalInterfaceIfIndex`

Reserved.

### `NblReAuthWfpFlowContext`

Reserved.

### `TcpReceiveBytesTransferred`

Identifies a **ULONG** value that is the number of data bytes that were received by the host stack and
filled in the receive request that is being processed as a TCP chimney offload receive operation.

### `NrtNameResolutionId`

Reserved.

### `UdpRecvSegCoalesceOffloadInfo`

Identifies UDP Receive Segment Coalescing Offload (URO) information. When **UdpRecvSegCoalesceOffloadInfo** is specified, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_info) returns an [NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbluro/ns-nbluro-ndis_udp_rsc_offload_net_buffer_list_info) structure. This structure contains a union that enables drivers to access the information as a single PVOID value.

### `SwitchForwardingReserved`

Reserved for NDIS.

### `SwitchForwardingDetail`

Identifies a pointer to a driver-allocated [NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) structure. This structure specifies the information for forwarding a packet to one or more ports of a Hyper-V extensible switch. The driver allocates this structure by calling [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) and frees the structure by calling [FreeNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nc-ndis-ndis_switch_free_net_buffer_list_forwarding_context).

### `VirtualSubnetInfo`

Identifies a pointer to a driver-allocated [NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_virtual_subnet_info) structure.

### `IMReserved`

Reserved for NDIS.

### `TcpRecvSegCoalesceInfo`

Identifies receive segment coalescing (RSC) information. When **TcpRecvSegCoalesceInfo** is specified, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an [NDIS_RSC_NBL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nblrsc/ns-nblrsc-ndis_rsc_nbl_info) union. This union enables drivers to access the information as a single PVOID value.

### `UdpSegmentationOffloadInfo`

Identifies information that is used in offloading the segmentation of a large UDP packet from the TCP/IP protocol to a miniport adapter for UDP Segmentation Offload (USO). When **UdpSegmentationOffloadInfo** is specified, [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) returns an [NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_udp_segmentation_offload_net_buffer_list_info) structure. This structure contains a union that enables drivers to access the information as a single PVOID value or as bit fields.

### `RscTcpTimestampDelta`

Identifies a **ULONG** value containing RSC timestamp information. For more information, see the [NDIS_RSC_NBL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nblrsc/ns-nblrsc-ndis_rsc_nbl_info) documentation.

### `TcpSendOffloadsSupplementalNetBufferListInfo`

Identifies a pointer to a driver-allocated [NDIS_TCP_SEND_OFFLOADS_SUPPLEMENTAL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_tcp_send_offloads_supplemental_net_buffer_list_info) structure containing additional out-of-band information for encapsulated packets.

### `GftOffloadInformation`

Generic Flow Table (GFT) Offload information.

### `GftFlowEntryId`

The flow entry ID for GFT.

### `NetBufferListInfoReserved3`

Reserved.

### `NetBufferListInfoReserved1`

Reserved for NDIS.

### `NetBufferListInfoReserved2`

Reserved for NDIS.

### `SwitchForwardingDetail_b0_to_b31`

Identifies a pointer to a driver-allocated [NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) structure. **SwitchForwardingDetail_b0_to_b31** and **SwitchForwardingDetail_b32_to_b63** are used to fit 64b OOB data for 32b mode. Available in NDIS 6.82 and higher.

### `SwitchForwardingDetail_b32_to_b63`

See **SwitchForwardingDetail_b0_to_b31**.

### `MaxNetBufferListInfo`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **NDIS_NET_BUFFER_LIST_INFO** enumeration is used in the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list) structure.

Use these enumeration values with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro to set and
get values in the
**NetBufferListInfo** array in a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list).

## See also

[NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v1_net_buffer_list_info)

[NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v2_header_net_buffer_list_info)

[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info)

[NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_ipsec_offload_v2_tunnel_net_buffer_list_info)

[NDIS_NBL_MEDIA_SPECIFIC_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_nbl_media_specific_information_ex)

[NDIS_NET_BUFFER_LIST_8021Q_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_8021q_info)

[NDIS_NET_BUFFER_LIST_FILTERING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info)

[NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_net_buffer_list_virtual_subnet_info)

[NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info)

[NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_tcp_ip_checksum_net_buffer_list_info)

[NDIS_TCP_LARGE_SEND_OFFLOAD_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_tcp_large_send_offload_net_buffer_list_info)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndiscancelsendnetbufferlists)

[NdisGeneratePartialCancelId](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndisgeneratepartialcancelid)

[**NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbluro/ns-nbluro-ndis_udp_rsc_offload_net_buffer_list_info)