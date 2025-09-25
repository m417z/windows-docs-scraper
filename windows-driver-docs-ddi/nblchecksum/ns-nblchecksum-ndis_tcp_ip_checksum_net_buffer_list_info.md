# _NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO structure

## Description

The **NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure specifies information used in offloading
checksum tasks from the TCP/IP transport to a NIC. The **NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure
is part of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information (out-of-band data)
that is associated with a **NET_BUFFER_LIST** structure.

## Members

### `Transmit`

A structure that contains the following members:

### `Transmit.IsIPv4`

Set by the TCP/IP transport to indicate that the send packet contains IPv4 addresses.

### `Transmit.IsIPv6`

Set by the TCP/IP transport to indicate that the send packet contains IPv6 addresses.

### `Transmit.TcpChecksum`

Set by the TCP/IP transport to indicate that the NIC should calculate the packet's TCP
checksum.

### `Transmit.UdpChecksum`

Set by the TCP/IP transport to indicate that the NIC should calculate the packet's UDP
checksum.

### `Transmit.IpHeaderChecksum`

Set by the TCP/IP transport to indicate that the NIC should calculate the IP checksum for the
first IP header in the packet. If the packet contains both a tunnel IP header and a transport IP
header, the NIC should calculate the checksum for both IP headers.

### `Transmit.Reserved`

Reserved for NDIS.

### `Transmit.TcpHeaderOffset`

The offset, in bytes, of the TCP header from the beginning of the packet for TCP packets. Miniport drivers can use **TcpHeaderOffset** to determine the location of the TCP header so that they do not need to parse the MAC and IP header.

### `Receive`

A structure that contains the following members:

### `Receive.TcpChecksumFailed`

Set by the miniport driver to indicate that the TCP checksum calculated by the NIC did not match
the checksum in the receive packet's TCP header.

### `Receive.UdpChecksumFailed`

Set by the miniport driver to indicate that the UDP checksum calculated by the NIC did not match
the checksum in the receive packet's UDP header.

### `Receive.IpChecksumFailed`

Set by the miniport driver to indicate that the IP checksum calculated by the NIC did not match
the checksum in the receive packet's first IP header. If the receive packet contains both a tunnel IP
header and a transport IP header, the NIC validates the checksum for both IP headers.

**Note** For encapsulated packets that have both a tunnel (outer) IPv4 header and a transport (inner) IPv4 header, the miniport driver should set this flag if either of the IP header checksum validations failed.

### `Receive.TcpChecksumSucceeded`

Set by the miniport driver to indicate that the TCP checksum calculated by the NIC matched the
checksum in the receive packet's TCP header.

### `Receive.UdpChecksumSucceeded`

Set by the miniport driver to indicate that the UDP checksum calculated by the NIC matched the
checksum in the receive packet's UDP header.

### `Receive.IpChecksumSucceeded`

Set by the miniport driver to indicate that the IP checksum calculated by the NIC matched the
checksum in the receive packet's first IP header. If the receive packet contains both a tunnel IP
header and a transport IP header, the NIC validates the checksum for the both IP headers.

**Note** For encapsulated packets that have both a tunnel (outer) IPv4 header and a transport (inner) IPv4 header, the miniport driver should set this flag only if both IP header checksum validations succeeded.

### `Receive.Loopback`

NDIS uses this bit. The miniport driver must not examine or set this bit; the miniport driver
should just ignore this bit.

### `Receive.TcpChecksumValueInvalid`

A miniport driver that supports [Receive Segment Coalescing (RSC)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-segment-coalescing--rsc-) sets this flag to indicate that the TCP header checksum was validated by the NIC but the TCP header checksum value in the packet is not valid. For more information, see [Indicating Coalesced Segments](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-coalesced-segments).

Miniport drivers that do not support RSC should set this flag to zero.

**Note** This flag is supported in NDIS 6.30 and later miniport drivers in Windows 8, Windows Server 2012, and later.

### `Receive.IpChecksumValueInvalid`

A miniport driver that supports RSC sets this flag to indicate that for an IPv4 packet, the IP header checksum was validated by the NIC but the IP header checksum value in the packet is not valid. For a packet consisting of both a tunnel and a transport IP header, this bit is applicable only to the tunnel IP header. For more information, see [Indicating Coalesced Segments](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-coalesced-segments).

Miniport drivers that do not support RSC should set this flag to zero.

**Note** This flag is supported in NDIS 6.30 and later miniport drivers in Windows 8, Windows Server 2012, and later.

### `Value`

A **PVOID** version of the checksum information. Miniport drivers can use this member to access the
raw information instead of the specific fields.

## Remarks

The **NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure specifies information that is used in
offloading checksum tasks from the TCP/IP transport to a NIC. The
**NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure is part of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information (out-of-band
data) that is associated with a **NET_BUFFER_LIST** structure.

Before the TCP/IP transport passes to the miniport driver a TCP/IP packet on which the miniport driver will perform checksum tasks, the TCP/IP transport updates the **NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure that is associated with the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Specifically, the TCP/IP transport sets the **IsIPv4** or **IsIPv6** flag to indicate that the send packet is an IPv4 or IPv6 packet.

yyIf the TCP/IP transport does not set either the **IsIPv4** or **IsIPv6** flag, the miniport driver should not perform checksum tasks on the packet. If the TCP/IP transport sets the **IsIPv4** or **IsIPv6** flag, it also sets the appropriate flags that are required to indicate which checksums the miniport driver should calculate for the packet. For IPv4, this includes the **IpHeaderChecksum**, **TcpChecksum**, or **UdpChecksum** flags. For IPv6, this includes the **TcpChecksum** or **UdpChecksum** flags. In addition, for TCP packets, the TCP/IP transport sets the **TcpHeaderOffset** field when either the **IsIPv4** or **IPv6** flag is set. The transport does not set this field for UDP packets.

Before indicating up a receive TCP/IP packet on which it performs checksum tasks, a miniport driver sets the appropriate Xxx**ChecksumFailed** or Xxx**ChecksumSucceeded** flags in the **NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure.

**Note** Checksum offload is disabled until the miniport receives [OID_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-offload-encapsulation). After it receives this OID, the miniport is then permitted to start validating the checksums on some received packets. The miniport is not required to validate the checksum on every packet; if both the Xxx**ChecksumFailed** and Xxx**ChecksumSucceeded** flags are clear, the OS will fall back to validating the checksum in software. This behavior is independent of WHCP driver certification requirements, which may require the miniport to validate the checksum on all packets as other protocol drivers on the system may not have a fallback mechanism.

To obtain the **NDIS_TCP_IP_CHECKSUM_NET_BUFFER_LIST_INFO** structure, a driver should call the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro with an
*_Id* of
**TcpIpChecksumNetBufferListInfo**.

## See also

[Indicating Coalesced Segments](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-coalesced-segments)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)