# _NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO structure

## Description

The **NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure specifies information that is used in
offloading Internet protocol security (IPsec) tasks from the TCP/IP transport to a miniport driver.

## Members

### `Transmit`

A structure that contains the following members:

### `Transmit.OffloadHandle`

A handle to the outbound security association (SA) for a packet that has just one IPsec payload,
regardless of whether that payload is for a transport (end-to-end) connection or a tunnel
connection.

### `Receive`

A structure that contains the following members:

### `Receive.SaDeleteReq`

A USHORT value that, when set, indicates that the TCP/IP transport should issue the
[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80)) OID once to delete the inbound SA that the packet was received over
and once again to delete the outbound SA that corresponds to the deleted inbound SA. The network
interface card (NIC) must not remove either of these SAs before it receives the corresponding
OID_TCP_TASK_IPSEC_DELETE_SA request.

### `Receive.CryptoDone`

A USHORT value that, when set, indicates that a NIC performed IPsec checking on at least one
IPsec payload in the receive packet. When this value is cleared, it indicates that the NIC did not
perform IPsec checking on the packet.

### `Receive.NextCryptoDone`

A USHORT value that, when set, indicates that a NIC performed IPsec checking on both the tunnel
and transport portions of the receive packet.
**CryptoDone** must also be set in this case.
**NextCryptoDone** is set only if a packet has both tunnel and transport IPsec payloads; otherwise,
**NextCryptoDone** is set to zero.

### `Receive.Pad`

Reserved for NDIS.

### `Receive.CryptoStatus`

The result of IPsec checking that a NIC performed on a receive packet. This result can be
described as one of the following values:

| Value | Meaning |
| --- | --- |
| **CRYPTO_SUCCESS** | The packet was successfully decrypted, if necessary, and the authentication header (AH) checksums, encapsulating security payload (ESP) checksums, or both checksums in the packet were validated. |
| **CRYPTO_GENERIC_ERROR** | The packet failed the IPsec check for an unspecified reason. |
| **CRYPTO_TRANSPORT_AH_AUTH_FAILED** | The AH checksum for the transport portion of the packet was invalid. |
| **CRYPTO_TRANSPORT_ESP_AUTH_FAILED** | The ESP checksum for the transport portion of the packet was invalid. |
| **CRYPTO_TUNNEL_AH_AUTH_FAILED** | The AH checksum for the tunnel portion of the packet was invalid. |
| **CRYPTO_TUNNEL_ESP_AUTH_FAILED** | The ESP checksum for the tunnel portion of the packet was invalid. |
| **CRYPTO_INVALID_PACKET_SYNTAX** | The receive packet's length is invalid. |
| **CRYPTO_INVALID_PROTOCOL** | The IPsec protocols that were specified in the SA that the packet was received on do not match the IPsec protocols that were found in the packet. For example, this error occurs if the SA that the packet was received on specifies the AH protocol but the packet contained only an ESP header. |

## Remarks

Before the TCP/IP transport passes a send packet that a NIC will perform IPsec tasks on to the
miniport driver of the NIC, the transport updates the IPsec information in the
**NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure that is associated with the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

Specifically, the TCP/IP transport supplies a value for the
**OffloadHandle** member in the **NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure. The
**OffloadHandle** value specifies the handle to the outbound security association (SA) for a packet
that has just one IPsec payload, regardless of whether that payload is for a transport (end-to-end)
security association or a tunnel security association. The
**OffloadHandle** value that is supplied in the **NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure
has the same value as the
**OffloadHandle** value that the TCP/IP transport supplied when it set
[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa) to request
the miniport driver to add the outbound SA to the NIC.

Before a miniport driver indicates up a receive packet that has one or more IPsec payloads, the driver
updates the **NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure that is associated with the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure as follows:

* If the NIC performed IPsec checks on at least one IPsec payload in the packet, the miniport driver
  sets the
  **CryptoDone** member and indicates the results of the checksum validation tests by specifying the
  appropriate value in the
  **CryptoStatus** member.
* If the NIC performed IPsec checking on both the tunnel and transport portions of a receive packet,
  the miniport driver also sets the
  **NextCryptoDone** member.
  **NextCryptoDone** is set only if a packet has both tunnel and transport IPsec payloads; otherwise,
  **NextCryptoDone** is set to zero.
* If the NIC did not perform IPsec checks on the packet, the miniport driver does not set
  **CryptoDone** or
  **NextCryptoDone** and does not supply a
  **CryptoStatus** value.

To create space for another SA on the NIC, the miniport driver of the NIC can set
**SaDeleteReq** in the **NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure for a receive packet. The
TCP/IP transport subsequently issues
[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80)) once
to delete the inbound SA that the packet was received over and once again to delete the outbound SA that
corresponds to the deleted inbound SA. The NIC must not remove either of these SAs before receiving the
corresponding OID_TCP_TASK_IPSEC_DELETE_SA request. The miniport driver of the NIC can set
**SaDeleteReq** independently of
**CryptoDone** .

To set and get the IPsec information, use the
**IPsecOffloadV1NetBufferListInfo** index with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro.
**NET_BUFFER_LIST_INFO** returns the **NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO** structure.

## See also

[NDIS_IPSEC_OFFLOAD_V2_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_ipsec_offload_v2_net_buffer_list_info)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[OID_TCP_TASK_IPSEC_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-sa)

[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80))