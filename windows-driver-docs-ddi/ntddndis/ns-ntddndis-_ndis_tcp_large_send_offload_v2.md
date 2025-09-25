# _NDIS_TCP_LARGE_SEND_OFFLOAD_V2 structure

## Description

The **NDIS_TCP_LARGE_SEND_OFFLOAD_V2** structure provides large send offload version 2 (LSOV2)
information in the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure.

## Members

### `IPv4`

A structure within **NDIS_TCP_LARGE_SEND_OFFLOAD_V2** that specifies IPv4 information and that
contains the following members:

### `IPv4.Encapsulation`

Encapsulation settings for IPv4. For more information about this member, see the following
Remarks section.

### `IPv4.MaxOffLoadSize`

The maximum bytes of user data that the transport can pass to the miniport driver in a single
packet. The transport will not pass a packet to the miniport driver that contains more user data bytes
than
**MaxOffLoadSize** specifies. If such a packet must be transmitted, the transport itself segments
the packet into smaller packets.

### `IPv4.MinSegmentCount`

The minimum number of segments that a large TCP packet must be divisible by before the transport
can offload it to the hardware for segmentation. The transport will not offload a large packet to the
miniport driver for segmentation unless the miniport driver can create at least as many segments as
**MinSegmentCount** specifies from the packet. If a large TCP packet does not meet the
minimum-segment requirement, the TCP/IP transport itself segments the packet into smaller
packets.

### `IPv6`

A structure within **NDIS_TCP_LARGE_SEND_OFFLOAD_V2** that specifies IPv6 information and that
contains the following members:

### `IPv6.Encapsulation`

Encapsulation settings for IPv6. For more information about this member, see the following
Remarks section.

### `IPv6.MaxOffLoadSize`

The maximum bytes of user data that the transport can pass to the miniport driver in a single
packet. The transport will not pass a packet to the miniport driver that contains more user data bytes
than
**MaxOffLoadSize** specifies. If such a packet must be transmitted, the transport itself segments
the packet into smaller packets.

### `IPv6.MinSegmentCount`

The minimum number of segments that a large TCP packet must be divisible by before the transport
can offload it to a NIC for segmentation. The transport will not offload a large packet to the
miniport driver for segmentation unless the miniport driver can create at least as many segments as
**MinSegmentCount** specifies from the packet. If a large TCP packet does not meet the
minimum-segment requirement, the TCP/IP transport itself segments the packet into smaller
packets.

### `IPv6.IpExtensionHeadersSupported`

A ULONG value that a miniport driver sets to indicate that the miniport adapter can segment a
large TCP packet whose IP header contains IPv6 extension headers.

### `IPv6.TcpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that the miniport driver can segment a
large TCP packet whose TCP header contains TCP options or to indicate that this capability is enabled
or disabled.

## Remarks

The **NDIS_TCP_LARGE_SEND_OFFLOAD_V2** structure is used in the
**LsoV2** member of the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure. The
**NDIS_TCP_LARGE_SEND_OFFLOAD_V2** structure specifies current or supported services that a miniport adapter
provides for segmenting large TCP packets into smaller packets. NDIS also provides large send offload
version 1 (LSOV1), which is an earlier version of LSOV2. For more information about LSOV1, see
[NDIS_TCP_LARGE_SEND_OFFLOAD_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_tcp_large_send_offload_v1).

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) is used in the
[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes) structure,
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure,
[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure,
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config) OID, and the
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication.

For
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config),
the [NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure specifies the task offload capabilities that a miniport adapter supports. If
the current offloads capabilities change, a miniport driver reports the new capabilities in an
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication.

The
**Encapsulation** members of **NDIS_TCP_LARGE_SEND_OFFLOAD_V2** define the LSOV2 encapsulation settings for
the miniport adapter.

In response to an
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config) query request, NDIS provides a bitwise OR of the encapsulation
flags, which indicate the supported encapsulation settings, in each of the
**Encapsulation** members. Miniport drivers must provide Ethernet encapsulation
(NDIS_ENCAPSULATION_IEEE_802_3). The other types of encapsulation are optional.

For an
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication, the miniport driver provides a bitwise
OR of the encapsulation flags, which indicate the current capabilities, in each of the
**Encapsulation** members.

The following flags are defined for the
**Encapsulation** members:

NDIS_ENCAPSULATION_NOT_SUPPORTED
Specifies that no encapsulation offload is supported.

NDIS_ENCAPSULATION_NULL
Specifies NULL encapsulation.

NDIS_ENCAPSULATION_IEEE_802_3
Specifies IEEE 802.3 encapsulation.

NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q
Specifies IEEE 802.3p and IEEE 802.3q encapsulation.

NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q_IN_OOB
Specifies that IEEE 802.3p and IEEE 802.3q encapsulation settings are specified in the NetBufferListInfo member of each NET_BUFFER_LIST structure.

NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED
Specifies logical link control (LLC) encapsulation for routed protocols, as described in RFC 1483. This flag is also used to indicate Ethernet LLC/SNAP encapsulation.

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config)

[NDIS_TCP_LARGE_SEND_OFFLOAD_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_tcp_large_send_offload_v1)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config)