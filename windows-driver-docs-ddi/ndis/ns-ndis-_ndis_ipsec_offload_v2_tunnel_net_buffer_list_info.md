# _NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO structure specifies the security association
(SA) offload handle to the tunnel portion of a send packet.

## Members

### `Transmit`

A structure that contains the following members:

### `Transmit.TunnelHandle`

The tunnel SA handle in transport over tunnel.

## Remarks

Before the TCP/IP transport passes a send packet that a NIC will perform Internet protocol security
offload version 2 (IPsecOV2) tasks on to the miniport driver of the NIC, the transport updates the IPsec
information in the
[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info) structure that is associated with the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

The TCP/IP transport supplies a handle in the
**OffloadHandle** member of NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO that specifies the handle to the
outbound SA for the transport (end-to-end connection) portion of the send packet. If the send packet will
be transmitted through a tunnel, the TCP/IP transport also supplies an
NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO structure. This structure specifies the offload handle
to the outbound SA for the tunnel portion of the send packet.

The
**TunnelHandle** value that is supplied in the NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO
structure has the same value as the
**OffloadHandle** that was reported to the TCP/IP transport when the miniport driver successfully added
a set of SAs to a NIC. All the SAs were added when the miniport driver responded to the
[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa) request.

To set and get the IPsec tunnel information, use the
**IPsecOffloadV2TunnelNetBufferListInfo** index with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro.
NET_BUFFER_LIST_INFO returns an NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO structure.

## See also

[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)