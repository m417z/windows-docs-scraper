# _NDIS_IPSEC_OFFLOAD_V2 structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The NDIS_IPSEC_OFFLOAD_V2 structure provides information about Internet protocol security (IPsec)
version 2 task offload capabilities in the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure.

## Members

### `Encapsulation`

The MAC encapsulation types that are supported for IPsec offload. For more information about this
member, see the following Remarks section.

### `IPv6Supported`

A BOOLEAN value that is set to **TRUE** if IPsec offload processing on IPv6 traffic is supported.
Otherwise, this member is **FALSE**.

### `IPv4Options`

A BOOLEAN value that is set to **TRUE** if the NIC supports IPsec offload of packets with IPv4
options. Otherwise, this member is **FALSE**.

### `IPv6NonIPsecExtensionHeaders`

A BOOLEAN value that is set to **TRUE** if the NIC supports IPsec offload processing for packets with
non-IPsec IPv6 extension headers in addition to IPsec headers. Otherwise, this member is **FALSE**.

### `Ah`

A BOOLEAN value that is set to **TRUE** if the NIC can perform IPsec offload operations on send and
receive packets that contain an authentication header (AH) security payload. Otherwise, this member is
**FALSE**.

### `Esp`

A BOOLEAN value that is set to **TRUE** if the NIC can perform IPsec offload operations on send and
receive packets that contain an encapsulating security payload (ESP). Otherwise, this member is
**FALSE**.

### `AhEspCombined`

A BOOLEAN value that is set to **TRUE** if the NIC can perform IPsec offload operations on send and
receive packets that contain both an AH payload and an ESP payload. Otherwise, this member is
**FALSE**.

### `Transport`

A BOOLEAN value that is set to **TRUE** if the NIC can process security payloads for the
transport-mode portion of send and receive packets. (The transport-mode portion of a packet pertains to
an end-to-end connection.) Otherwise, this member is **FALSE**.

### `Tunnel`

A BOOLEAN value that is set to **TRUE** if the NIC can process security payloads for the tunnel-mode
portion of send and receive packets. (The tunnel-mode portion of a packet pertains to a tunnel
connection.) Otherwise, this member is **FALSE**.

**Note** When the IPsec layer sends tunnel packets over an IPsec task offload interface,
the IPsec layer ensures that large send offload (LSO) is not used for those packets.

### `TransportTunnelCombined`

A BOOLEAN value that is set to **TRUE** if the NIC can process security payloads for both the
transport-mode portion and the tunnel-mode portion of send and receive packets. Otherwise, this member
is **FALSE**. The transport-mode portion of a packet pertains to an end-to-end connection. The tunnel-mode
portion of a packet pertains to a tunnel connection.

### `LsoSupported`

A BOOLEAN value that is set to **TRUE** if the NIC supports large send offload (LSO). Otherwise, this
member is **FALSE**. Note that the LSO capabilities of the NIC are specified in the
**LsoV1** or
**LsoV2** members of the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure. The
**LsoSupported** flag indicates that the capabilities that are specified in those members are also
valid if the connection is secured with IPsec.

### `ExtendedSequenceNumbers`

A BOOLEAN value that is set to **TRUE** if the NIC supports IPsec extended sequence numbers.
Otherwise, this member is **FALSE**.

### `UdpEsp`

The types of UDP-encapsulated ESP data packets that the NIC can parse. For a description of the
UDP-encapsulation types, see
[UDP-ESP Encapsulation Types](https://learn.microsoft.com/windows-hardware/drivers/network/udp-esp-encapsulation-types). This
member can be one or more of the following flags:

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_NONE

IPsec offload processing is not available for any UDP encapsulation type.

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_TRANSPORT

IPsec offload is supported for an ESP-encapsulated transport-mode packet that is encapsulated by
UDP.

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_TUNNEL

IPsec offload is supported for the tunnel-mode portion of a packet that is UDP-encapsulated. The
transport-mode portion of the packet is not UDP-encapsulated and is not ESP-protected.

#### IPSEC_OFFLOAD_V2_TRANSPORT_OVER_UDP_ESP_ENCAPSULATION_TUNNEL

IPsec offload is supported for the tunnel-mode portion of a packet that is UDP-encapsulated. The
transport-mode portion of a packet is not UDP-encapsulated but is ESP-protected.

#### IPSEC_OFFLOAD_V2_UDP_ESP_ENCAPSULATION_TRANSPORT_OVER_TUNNEL

IPsec offload is supported for the tunnel-mode portion of a packet that is not UDP-encapsulated.
The transport-mode portion of a packet is UDP-encapsulated and ESP-protected.

### `AuthenticationAlgorithms`

A bit mask that identifies the IPsec authentication algorithms that the NIC supports. Miniport
drivers specify a bitwise OR of the following values:

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_MD5

The NIC can use the keyed message digest 5 (MD5) algorithm for computing or validating a
cryptographic checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_1

The NIC can use the secure hash algorithm (SHA) 1 algorithm for computing or validating a
cryptographic checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_256

The NIC can use the SHA 256 algorithm for computing or validating a cryptographic
checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_128

The NIC can use the Advanced Encryption Standard - Galois/Counter Mode (AES-GMAC) 128 algorithm
for computing or validating a cryptographic checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_192

The NIC can use the AES-GMAC 192 algorithm for computing or validating a cryptographic
checksum.

#### IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_256

The NIC can use the AES-GMAC 256 algorithm for computing or validating a cryptographic
checksum.

### `EncryptionAlgorithms`

A bit mask that identifies the IPsec encryption algorithms that the NIC supports. This bit mask is
a bitwise OR of the following values:

#### IPSEC_OFFLOAD_V2_ENCRYPTION_NONE

The NIC can use null encryption--that is, the ESP payload without encryption but with
authentication information.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_DES_CBC

The NIC can use the DES algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_3_DES_CBC

The NIC can use the triple-DES algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_128

The NIC can use the AES-GCM 128 algorithm for encrypting and computing a cryptographic checksum
or decrypting and validating a cryptographic checksum for an ESP payload. Note that this algorithm is
a combined mode algorithm.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_192

The NIC can use the AES-GCM 192 algorithm for encrypting and computing a cryptographic checksum
or decrypting and validating a cryptographic checksum for an ESP payload. Note that this algorithm is
a combined mode algorithm.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_256

The NIC can use the AES-GCM 256 algorithm for encrypting and computing a cryptographic checksum
or decrypting and validating a cryptographic checksum for an ESP payload. Note that this algorithm is
a combined mode algorithm.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_128

The NIC can use the Advanced Encryption Standard - cipher-block chaining mode (AES-CBC) 128
algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_192

The NIC can use the AES-CBC 192 algorithm for encrypting and decrypting ESP payloads.

#### IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_256

The NIC can use the AES-CBC 256 algorithm for encrypting and decrypting ESP payloads.

### `SaOffloadCapacity`

The number of SA bundles, which might include ESP or AH or both, that can be offloaded to the NIC.
The TCP/IP maintains a count of the number of offloaded SA bundles and should not add more than the
maximum number of SA bundles that the miniport driver reported.

## Remarks

In NDIS 6.1 and later versions, the NDIS_IPSEC_OFFLOAD_V2 structure is used in the
**IPsecV2** member of the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure. The
NDIS_IPSEC_OFFLOAD_V2 structure specifies the current or supported capabilities that a miniport adapter
provides for IPsec offload processing.

**Note** To support IPsec task offload, the miniport driver must specify **TRUE** in the
**Tunnel** member.

NDIS_OFFLOAD is used in the
[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes) structure,
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure,
[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure,
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config) OID, and the
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication.

For
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config),
the NDIS_OFFLOAD structure specifies the task offload capabilities that a miniport adapter supports. If
the current offload capabilities change, a miniport driver reports the new capabilities in an
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication.

The
**Encapsulation** member of NDIS_IPSEC_OFFLOAD_V2 defines the MAC encapsulations that a miniport
adapter supports for IPsec offload.

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

[NDIS_IPSEC_OFFLOAD_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v1)

[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config)