# _IPSEC_OFFLOAD_V2_ADD_SA structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The **IPSEC_OFFLOAD_V2_ADD_SA** structure defines information about a security association (SA) that a
miniport driver should add to a NIC.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
IPSEC_OFFLOAD_V2_ADD_SA structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_IPSEC_OFFLOAD_V2_ADD_SA_REVISION_1, and the
**Size** member to NDIS_SIZEOF_IPSEC_OFFLOAD_V2_ADD_SA_REVISION_1.

### `Next`

A pointer to an IPSEC_OFFLOAD_V2_ADD_SA structure that is the next structure in a linked list. If
the pointer is **NULL**, the current structure is the last structure in the list.

### `NumExtHdrs`

The number of IPsec extension headers. This member can be one of the following values.

| Type of security | Extension headers |
| --- | --- |
| AH authentication only | 1 |
| ESP authentication only | 1 |
| ESP encryption only | 1 |
| ESP authentication plus encryption | 1 |
| AH plus ESP authentication plus encryption | 2 |
| UDP ESP | 1 |

### `Flags`

A bitmask that indicates whether the SA that is being added is an inbound or outbound SA as
follows:

#### IPSEC_OFFLOAD_V2_IPv6

If this flag is set, the addresses are IPv6. Otherwise, the addresses are IPv4

#### IPSEC_OFFLOAD_V2_INBOUND

If this flag is set, the SA is inbound. Otherwise, the SA is outbound.

### `IPv4Endpoints`

The IPv4 endpoint addresses. This structure contains the following members:

### `IPv4Endpoints.SrcAddr`

The IPv4 address of the source host (the host that is sending the packets).

### `IPv4Endpoints.DestAddr`

The IPv4 address of the destination host (the host that is receiving the packets).

### `IPv6Endpoints`

The IPv6 endpoint addresses. This structure contains the following members:

### `IPv6Endpoints.SrcAddr`

The IPv6 address of the source host (the host that is sending the packets).

### `IPv6Endpoints.DestAddr`

The IPv6 address of the destination host (the host that is receiving the packets).

### `OffloadHandle`

The handle to the newly created SA. The miniport driver supplies this handle before completing the
[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa) request. The TCP/IP transport must specify this handle in the
[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info) or
[NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_tunnel_net_buffer_list_info) structure before passing a send packet to the
miniport driver. The TCP/IP transport must also specify this handle when deleting the SA with an
[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa) request.

### `UdpEspEncapsulation`

The UDP ESP encapsulation type. This member can be one or more of the following flags:

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_NONE

No UDP encapsulation is used.

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_TRANSPORT

An ESP-encapsulated transport-mode packet is encapsulated by UDP.

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_TUNNEL

The tunnel-mode portion of a packet is UDP-encapsulated. The transport-mode portion of the
packet is not UDP-encapsulated and is not ESP-protected.

#### IPSEC_OFFLOAD_V2_TRANSPORT_OVER_UDP_ESP_ENCAPSULATION_TUNNEL

The tunnel-mode portion of a packet is UDP-encapsulated. The transport-mode portion of a packet
is not UDP-encapsulated but is ESP-protected.

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_TRANSPORT_OVER_TUNNEL

The tunnel-mode portion of a packet is not UDP-encapsulated. The transport-mode portion of a
packet is UDP-encapsulated and ESP-protected.

### `SecAssoc`

An array with two elements that contain the information about the IPsec operations (AH, ESP, or
both) for the SA. The number of provided elements is specified in the
**NumExtHdrs** member. The information for each IPsec operations is formatted as an
[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association) structure, which is described below.

The TCP/IP transport specifies one or two IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structures in the
buffer at
**SecAssoc** . Each IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structure indicates the type of
operation--authentication or encryption/decryption--for which the SA specified in the structure is to be
used. The order of the IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION structures in the array indicates the order
in which the miniport driver should perform the operations for each SA. Only one combination of
operations is supported: encryption/decryption (ESP) followed by authentication (AH).

### `KeyLength`

The length, in bytes, of the buffer at
**KeyData** .

### `KeyData`

A variable-length array that contains keys for the SAs that are specified at
**SecAssoc** . If both an encryption algorithm and an authentication algorithm are specified by the
**EncryptionAlgorithm** and
**AuthenticationAlgorithm** members of an
[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association) structure, the buffer at
**KeyData** contains key information for one followed by the other. The beginning and the length of
the key are specified by the
**KeyOffsetBytes** and
**KeyLength** members, respectively.

## Remarks

This structure is obsolete, use [IPSEC_OFFLOAD_V2_ADD_SA_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa_ex) instead.

The IPSEC_OFFLOAD_V2_ADD_SA structure specifies a security SA that should be added and a pointer to
the next IPSEC_OFFLOAD_V2_ADD_SA structure in a linked list. The IPSEC_OFFLOAD_V2_ADD_SA structure is
used with the
[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa) OID.

The IPSEC_OFFLOAD_V2_ADD_SA structure specifies the source and destination, as well as the IP
protocols, to which the SAs apply. This filter pertains to a transport-mode connection--that is, an
end-to-end connection between two hosts. If the specified connection is made through a tunnel, the source
and destination addresses of the tunnel are specified.

If a member is set to zero, that parameter is not used to filter packets for the specified SAs. For
example, if
**SrcAddr** is set to zero, the specified SAs can apply to a packet that contains any source address.
If all of the filter parameters are set to zero, the specified SAs apply to any source host that is
sending any type of packet to any destination host.

## See also

[IPSEC_OFFLOAD_V2_ADD_SA_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_add_sa_ex)

[IPSEC_OFFLOAD_V2_ALGORITHM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_algorithm_info)

[IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ipsec_offload_v2_security_association)

[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info)

[NDIS_IPSEC_OFFLOAD_V2_TUNNEL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_tunnel_net_buffer_list_info)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)