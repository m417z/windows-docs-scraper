# _OFFLOAD_IPSEC_ADD_UDPESP_SA structure

## Description

The OFFLOAD_IPSEC_ADD_UDPESP_SA structure contains information for each security association (SA)
that a miniport driver adds for UDP-encapsulated ESP packets to a NIC.

## Members

### `SrcAddr`

The IP address of the source host (the host sending the packets).

### `SrcMask`

The subnet mask for the source IP address.

### `DstAddr`

The IP address of the destination host (the host receiving the packets).

### `DstMask`

The subnet mask for the destination IP address.

### `Protocol`

The IP protocol. The encoding of
**Protocol** is identical to that of the Protocol field in an IP header. The
value should be 11 (hexadecimal), which specifies UDP.

### `SrcPort`

A source TCP or UDP port. If
**SrcPort** is set to zero, the SA applies to any source TCP/UDP port.

### `DstPort`

A destination TCP or UDP port. If DestPort is set to zero, the SA applies to any source TCP/UDP
port.

### `SrcTunnelAddr`

The IP address for the source endpoint, such as a connector, of a tunnel. The miniport driver uses
**SrcTunnelAddr** as the source address for the tunnel IP header of packets
sent on the SA.
**SrcTunnelAddr** is specified only for an SA that applies to the tunnel
portion of a packet.
**SrcTunnelAddr** is set to zero for an SA that applies to the transport
portion of a packet.

### `DstTunnelAddr`

The IP address for the destination endpoint, such as a connector, of a tunnel. The miniport driver
uses
**DestTunnelAddr** as the destination address for the tunnel IP header of
packets sent on the SA.
**DestTunnelAddr** is specified only for an SA that applies to the tunnel
portion of a packet.
**DestTunnelAddr** is set to zero for an SA that applies to the transport
portion of a packet.

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
**SecAssoc**. Each OFFLOAD_SECURITY_ASSOCIATION structure indicates the type
of operation--authentication or encryption/decryption--for which the SA specified in the structure is to
be used. The order of the OFFLOAD_SECURITY_ASSOCIATION structures in the array indicates the order in
which the miniport driver should perform the operations for each SA. Only one combination of operations
is supported: encryption/decryption (ESP) followed by authentication (AH).

### `OffloadHandle`

The handle to the newly created SA. The miniport driver supplies this handle before completing the
[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa) request.
The TCP/IP transport must specify this handle in the
[NDIS_IPSEC_PACKET_INFO](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557028(v=vs.85)) structure before
passing a send packet to the miniport driver. The TCP/IP transport must also specify this handle when
deleting the SA with an
[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80)) request.

### `EncapTypeEntry`

The UDP-ESP encapsulation type and destination port of a parser entry. This information is
formatted as an
[OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_udpesp_encaptype_entry) structure.

### `EncapTypeEntryOffldHandle`

When
**Flags**=
**OFFLOAD_INBOUND_SA** and
**EncapTypeEntryOffldHandle** is **NULL**, the miniport driver should check
whether the parser entry specified by
**EncapTypeEntry** is in the NIC's parser entry list. If it is not, the
miniport driver should create a parser entry, using the encapsulation type and destination port
specified in
**EncapTypeEntry**, add the parser entry to the parser entry list, and
offload the specified SAs. The miniport driver should return a handle in
**EncapTypeEntryOffldHandle** that identifies the newly created parser entry.
If the specified parser entry is already in the parser entry list, the miniport should simply return the
handle in
**EncapTypeEntryOffldHandle** for the existing parser entry.

When
**Flags**=
**OFFLOAD_INBOUND_SA** and
**EncapTypeEntryOffldHandle** is non-**NULL**,
**EncapTypeEntryOffldHandle** contains the handle to a parser entry that
already is in the NIC's parser entry list. In this case, the miniport driver should simply offload the
specified SAs.

When
**Flags**=
**OFFLOAD_OUTBOUND_SA**, the miniport driver should ignore the
**EncapTypeEntryOffldHandle** parameter.

### `KeyLen`

The length, in bytes, of the buffer at
**KeyMat**.

### `KeyMat`

A variable-length array that contains keys for the SAs specified at
**SecAssoc**. If both a confidentiality (encryption/decryption) algorithm and
an integrity (authentication) algorithm are specified by the
**ConfAlgo** and
**IntegrityAlgo** of an
[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association) structure, the buffer at
**KeyMat** contains key information for the confirmation algorithm first,
followed immediately by key information for the integrity algorithm.

The length of each key in the buffer at
**KeyMat** is specified by
**algoKeyLen** in the
[OFFLOAD_ALGO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_algo_info) structure that
specifies the confidentiality or integrity algorithm. (An OFFLOAD_ALGO_INFO structure is a member of an
OFFLOAD_SECURITY_ASSOCIATION structure.)

## Remarks

The OFFLOAD_IPSEC_ADD_UDPESP_SA structure is used with the
[OID_TCP_TASK_IPSEC_ADD_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-udpesp-sa) OID.

Note that the OFFLOAD_IPSEC_ADD_UDPESP_SA structure is almost identical to the
[OFFLOAD_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_add_sa) structure used in
the
[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa) request.
The only difference is that the OFFLOAD_IPSEC_ADD_UDPESP_SA structure contains the
**EncapTypeEntry** and the
**EncapTypeEntryOffldHandle** members.

## See also

[NDIS_IPSEC_PACKET_INFO](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557028(v=vs.85))

[OFFLOAD_ALGO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_algo_info)

[OFFLOAD_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_add_sa)

[OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_udpesp_encaptype_entry)

[OFFLOAD_SECURITY_ASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_security_association)

[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa)

[OID_TCP_TASK_IPSEC_ADD_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-udpesp-sa)

[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80))