# _OFFLOAD_IPSEC_ADD_SA structure

## Description

The OFFLOAD_IPSEC_ADD_SA structure contains information for each security association (SA) that a
miniport driver adds to a NIC.

## Members

### `SrcAddr`

The IP address of the source host (the host sending the packets).

### `SrcMask`

The subnet mask for the source IP address.

### `DestAddr`

The IP address of the destination host (the host receiving the packets).

### `DestMask`

The subnet mask for the destination IP address.

### `Protocol`

The IP protocol. You can specify any combination of IP protocol types (such as TCP, UDP, or ICMP).
The encoding of
**Protocol** is identical to that of the Protocol field in an IP header. If
**Protocol** is set to zero, the SA applies to any IP protocol.

### `SrcPort`

A source TCP or UDP port. If
**SrcPort** is set to zero, the SA applies to any source TCP/UDP port.

### `DestPort`

A destination TCP or UDP port. If
**DestPort** is set to zero, the SA applies to any source TCP/UDP port.

### `SrcTunnelAddr`

The IP address for the source endpoint, such as a connector, of a tunnel. The miniport driver uses
**SrcTunnelAddr** as the source address for the tunnel IP header of packets that are sent on the SA.
**SrcTunnelAddr** is specified only for an SA that applies to the tunnel portion of a packet.
**SrcTunnelAddr** is set to zero for an SA that applies to the transport portion of a packet.

### `DestTunnelAddr`

The IP address for the destination endpoint, such as a connector, of a tunnel. The miniport driver
uses
**DestTunnelAddr** as the destination address for the tunnel IP header of packets sent on the SA.
**DestTunnelAddr** is specified only for an SA that applies to the tunnel portion of a packet.
**DestTunnelAddr** is set to zero for an SA that applies to the transport portion of a packet.

### `Flags`

A bitmask that indicates whether the SA that is being added is an inbound or outbound SA as
follows:

#### OFFLOAD_INBOUND_SA

Specifies an inbound SA.

#### OFFLOAD_OUTBOUND_SA

Specifies an outbound SA.

### `NumSAs`

The number of elements in the
**SecAssoc** array. Each element in the array is an
[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association) structure.

### `SecAssoc`

A variable-length array that contains the information about the Internet Protocol security (IPsec)
operations (AH or ESP) for the SA. The information for each IPsec operations is formatted as an
OFFLOAD_SECURITY_ASSOCIATION structure.

The TCP/IP transport specifies one or two OFFLOAD_SECURITY_ASSOCIATION structures in the buffer at
**SecAssoc** . Each OFFLOAD_SECURITY_ASSOCIATION structure indicates the type of
operation--authentication or encryption/decryption--for which the SA specified in the structure is to be
used. The order of the OFFLOAD_SECURITY_ASSOCIATION structures in the array indicates the order in which
the miniport driver should perform the operations for each SA. Only one combination of operations is
supported: encryption/decryption (ESP) followed by authentication (AH).

### `OffloadHandle`

The handle to the newly created SA. The miniport driver supplies this handle before completing the
[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa) request.
The TCP/IP transport must specify this handle in the
[NDIS_IPSEC_PACKET_INFO](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557028(v=vs.85)) structure before
passing a send packet to the miniport driver. The TCP/IP transport must also specify this handle when
deleting the SA with an
[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80)) request.

### `KeyLen`

The length, in bytes, of the buffer at
**KeyMat** .

### `KeyMat`

A variable-length array that contains keys for the SAs specified at
**SecAssoc** . If both a confidentiality (encryption/decryption) algorithm and an integrity
(authentication) algorithm are specified by the
**ConfAlgo** and
**IntegrityAlgo** members of an
[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association) structure, the buffer at
**KeyMat** contains key information for the confirmation algorithm first, followed immediately by key
information for the integrity algorithm.

The length of each key in the buffer at
**KeyMat** is specified by
**algoKeylen** in the
[OFFLOAD_ALGO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_algo_info) structure that
specifies the confidentiality or integrity algorithm. (An OFFLOAD_ALGO_INFO structure is a member of an
OFFLOAD_SECURITY_ASSOCIATION structure.)

## Remarks

The OFFLOAD_IPSEC_ADD_SA structure is used in the
[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa) OID.

## See also

[NDIS_IPSEC_PACKET_INFO](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557028(v=vs.85))

[OFFLOAD_ALGO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_algo_info)

[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association)

[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa)

[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80))