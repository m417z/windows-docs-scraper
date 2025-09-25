# _NDIS_IPSEC_OFFLOAD_V1 structure

## Description

The **NDIS_IPSEC_OFFLOAD_V1** structure provides Internet protocol security (IPsec) task offload
information in the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure.

**Note** **NDIS_IPSEC_OFFLOAD_V1** is only for NDIS 6.0. For NDIS 6.1 and later, use [NDIS_IPSEC_OFFLOAD_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v2).

## Members

### `Supported`

A structure within NDIS_IPSEC_OFFLOAD_V1 that specifies support for IPsec task offload and that
contains the following information:

### `Supported.Encapsulation`

Encapsulation settings for IPsec. For more information about this member, see the following
Remarks section.

### `Supported.AhEspCombined`

A ULONG value that a miniport driver sets to indicate that the hardware can perform IPsec
operations on send and receive packets that contain both an authentication header (AH) security
payload and an encapsulating security payload (ESP). A value of zero in
**AhEspCombined** indicates that the NIC does not support this capability.

### `Supported.TransportTunnelCombined`

A ULONG value that a miniport driver sets to indicate that the NIC can process security payloads
for both the transport-mode portion and the tunnel-mode portion of send and receive packets. (The
transport-mode portion of a packet pertains to an end-to-end connection. The tunnel-mode portion of a
packet pertains to a tunnel connection.) A value of zero in
**TransportTunnelCombined** indicates that the NIC does not support this capability.

### `Supported.IPv4Options`

A ULONG value that a miniport driver sets to indicate that the NIC can perform IPsec operations
on IPv4 send and receive packets whose IP headers contain IP options. A value of zero in
**IPv4Options** indicates that the NIC does not support this capability.

### `Supported.Flags`

The types of UDP-encapsulated ESP data packets that the NIC can parse. For a description of the
UDP-encapsulation types, see
[UDP-ESP Encapsulation Types](https://learn.microsoft.com/windows-hardware/drivers/network/udp-esp-encapsulation-types).
This member can be one or more of the following flags:

| Value | Meaning |
| --- | --- |
| **IPSEC_TPT_UDPESP_ENCAPTYPE_IKE** | Reserved for internal use. |
| **IPSEC_TUN_UDPESP_ENCAPTYPE_IKE** | Reserved for internal use. |
| **IPSEC_TPTOVERTUN_UDPESP_ENCAPTYPE_IKE** | Reserved for internal use. |
| **IPSEC_TPT_UDPESP_OVER_PURE_TUN_ENCAPTYPE_IKE** | Reserved for internal use. |
| **IPSEC_TPT_UDPESP_ENCAPTYPE_OTHER** | When this flag is set, the NIC can parse UDP-encapsulated transport-mode packets.<br><br>When this flag is cleared, the NIC cannot parse UDP-encapsulated transport-mode packets. |
| **IPSEC_TUN_UDPESP_ENCAPTYPE_OTHER** | When this flag set, the NIC can parse UDP-encapsulated tunnel-mode packets.<br><br>When this flag is cleared, the NIC does not have this capability. |
| **IPSEC_TPTOVERTUN_UDPESP_ENCAPTYPE_OTHER** | When this flag is set, the NIC can parse transport over UDP-encapsulated tunnel-mode packets.<br><br>When this flag is cleared, the NIC does not have this capability. |
| **IPSEC_TPT_UDPESP_OVER_PURE_TUN_ENCAPTYPE_OTHER** | When this flag is set, the NIC can parse UDP-encapsulated transport over tunnel-mode packets.<br><br>When this flag is cleared, the NIC does not have this capability. |

A miniport driver whose NIC is incapable of parsing UDP-encapsulated ESP packets must not set any
flags in the
**Flags** member.

### `IPv4AH`

A structure within NDIS_IPSEC_OFFLOAD_V1 that specifies support for AH payloads and that contains
the following information:

### `IPv4AH.Md5`

A ULONG value that a miniport driver sets to indicate that the NIC can use the keyed MD5
algorithm for computing or validating a cryptographic checksum for an AH payload, ESP payload, or
both.

### `IPv4AH.Sha_1`

A ULONG value that a miniport driver sets to indicate that the NIC can use the SHA 1 algorithm
for computing or validating a cryptographic checksum for an AH payload, ESP payload, or both.

### `IPv4AH.Transport`

A ULONG value that a miniport driver sets to indicate that the NIC can calculate or validate the
cryptographic checksums for the portion of a packet that pertains to an end-to-end connection.

### `IPv4AH.Tunnel`

A ULONG value that a miniport driver sets to indicate that the NIC can calculate or validate
cryptographic checksums for the portion of a packet that pertains to a tunnel connection.

### `IPv4AH.Send`

A ULONG value that a miniport driver sets to indicate that the NIC can calculate cryptographic
checksums for send packets.

### `IPv4AH.Receive`

A ULONG value that a miniport driver sets to indicate that the NIC can validate cryptographic
checksums for receive packets.

### `IPv4ESP`

A structure within NDIS_IPSEC_OFFLOAD_V1 that specifies support for ESP payloads and that contains
the following information:

### `IPv4ESP.Des`

A ULONG value that a miniport driver sets to indicate that the NIC supports the DES algorithm
for encrypting and decrypting ESP payloads.

### `IPv4ESP.Reserved`

This member is reserved.

### `IPv4ESP.TripleDes`

A ULONG value that a miniport driver sets to indicate that the NIC supports the triple-DES
algorithm for encrypting and decrypting ESP payloads.

### `IPv4ESP.NullEsp`

A ULONG value that a miniport driver sets to indicate that the NIC supports null
encryption--that is, the ESP payload without encryption but with authentication information.

### `IPv4ESP.Transport`

A ULONG value that a miniport driver sets to indicate that the NIC can encrypt and decrypt ESP
data for the portion of a packet that pertains to an end-to-end connection.

### `IPv4ESP.Tunnel`

A ULONG value that a miniport driver sets to indicate that the NIC can encrypt and decrypt ESP
data for the portion of a packet that pertains to a tunnel connection.

### `IPv4ESP.Send`

A ULONG value that a miniport driver sets to indicate that the NIC can encrypt and decrypt ESP
payloads in send packets.

### `IPv4ESP.Receive`

A ULONG value that a miniport driver sets to indicate that the NIC can encrypt and decrypt ESP
payloads in receive packets.

## Remarks

The **NDIS_IPSEC_OFFLOAD_V1** structure is used in the
**IPsecV1** member of the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure. The
NDIS_IPSEC_OFFLOAD_V1 structure specifies the current or supported services that a miniport adapter
provides for Internet protocol security (IPsec).

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
**Encapsulation** member of **NDIS_IPSEC_OFFLOAD_V1** defines the IPsec offload encapsulation settings for
the miniport adapter.

In response to an
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config) query request, NDIS provides a bitwise OR of the encapsulation
flags, which indicate the supported encapsulation settings, in the
**Encapsulation** member. Miniport drivers must provide Ethernet encapsulation
(NDIS_ENCAPSULATION_IEEE_802_3). The other types of encapsulation are optional.

For an
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication, the miniport driver provides a bitwise
OR of the encapsulation flags, which indicate the current capabilities, in the
**Encapsulation** member.

The following flags are defined for the
**Encapsulation** member:

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_IPSEC_OFFLOAD_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v2)

[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config)