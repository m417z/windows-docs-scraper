# _NDIS_TCP_IP_CHECKSUM_OFFLOAD structure

## Description

The NDIS_TCP_IP_CHECKSUM_OFFLOAD structure provides checksum task offload information in the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure.

## Members

### `IPv4Transmit`

A structure within NDIS_TCP_IP_CHECKSUM_OFFLOAD that specifies IPv4 transmit information and that
contains the following members:

### `IPv4Transmit.Encapsulation`

Encapsulation settings for IPv4 transmit. For more information about this member, see the
following Remarks section.

### `IPv4Transmit.IpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate an
IP checksum for an IPv4 send packet that contains IP options or to indicate that this capability is
enabled or disabled.

### `IPv4Transmit.TcpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
TCP checksum for an IPv4 send packet that contains TCP options or to indicate that this capability is
enabled or disabled.

### `IPv4Transmit.TcpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
TCP checksum for an IPv4 send packet. The TCP/IP transport sets this value to enable this capability
or to indicate that this capability is enabled or disabled.

### `IPv4Transmit.UdpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
UDP checksum for an IPv4 send packet or to indicate that this capability is enabled or
disabled.

### `IPv4Transmit.IpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate an
IP checksum for an IPv4 send packet or to indicate that this capability is enabled or disabled.

### `IPv4Receive`

A structure within NDIS_TCP_IP_CHECKSUM_OFFLOAD that specifies IPv4 receive information and that
contains the following members:

### `IPv4Receive.Encapsulation`

Encapsulation settings for IPv4 receive. For more information about this member, see the
following Remarks section.

### `IPv4Receive.IpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can validate an IP
checksum for an IPv4 receive packet that contains IP options or to indicate that this capability is
enabled or disabled.

### `IPv4Receive.TcpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
TCP checksum for an IPv4 receive packet that contains TCP options or to indicate that this capability
is enabled or disabled.

### `IPv4Receive.TcpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can validate the
TCP checksum for an IPv4 receive packet or to indicate that this capability is enabled or
disabled.

### `IPv4Receive.UdpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can validate an
IPv4 receive packet's UDP checksum or to indicate that this capability is enabled or disabled.

### `IPv4Receive.IpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can validate an IP
checksum for an IPv4 receive packet or to indicate that this capability is enabled or disabled.

### `IPv6Transmit`

A structure within NDIS_TCP_IP_CHECKSUM_OFFLOAD that specifies IPv6 transmit information and that
contains the following members:

### `IPv6Transmit.Encapsulation`

Encapsulation settings for IPv6 transmit. For more information about this member, see the
following Remarks section.

### `IPv6Transmit.IpExtensionHeadersSupported`

A ULONG value that a miniport driver sets to indicate that the miniport adapter can calculate
checksums on IPv6 packets that contain extension headers.

### `IPv6Transmit.TcpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
TCP checksum for an IPv6 send packet that contains TCP options or to indicate that this capability is
enabled or disabled.

### `IPv6Transmit.TcpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
TCP checksum for an IPv6 send packet or to indicate that this capability is enabled or
disabled.

### `IPv6Transmit.UdpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
UDP checksum for an IPv6 send packet or to indicate that this capability is enabled or
disabled.

### `IPv6Receive`

A structure within NDIS_TCP_IP_CHECKSUM_OFFLOAD that specifies IPv6 receive information and that
contains the following members:

### `IPv6Receive.Encapsulation`

Encapsulation settings for IPv6 receive. For more information about this member, see the
following Remarks section.

### `IPv6Receive.IpExtensionHeadersSupported`

A ULONG value that a miniport driver sets to indicate that the miniport adapter can validate
checksums on IPv6 packets that contain extension headers.

### `IPv6Receive.TcpOptionsSupported`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can calculate a
checksum for an IPv6 receive packet whose TCP header contains TCP options or to indicate that this
capability is enabled or disabled.

### `IPv6Receive.TcpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can validate an
IPv6 receive packet's TCP checksum or to indicate that this capability is enabled or disabled.

### `IPv6Receive.UdpChecksum`

A ULONG value that a miniport driver sets to indicate that a miniport adapter can validate a UDP
checksum for an IPv6 receive packet or to indicate that this capability is enabled or disabled.

## Remarks

The NDIS_TCP_IP_CHECKSUM_OFFLOAD structure is used in the
**Checksum** member of the
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure. The
NDIS_TCP_IP_CHECKSUM_OFFLOAD structure specifies the current or supported services that a miniport
adapter provides for calculating IP, TCP, or UDP checksums (or all of them) for send packets and
validating such checksums for receive packets.

NDIS_OFFLOAD is used in the
[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes) structure,
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure,
[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure,
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config) OID, and the
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication.

For
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config),
the NDIS_OFFLOAD structure specifies the task offload capabilities that a miniport adapter supports. If
the current offloads capabilities change, a miniport driver reports the new capabilities in an
[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication.

The
**Encapsulation** members of NDIS_TCP_IP_CHECKSUM_OFFLOAD define the checksum offload encapsulation
settings for the miniport adapter.

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

- NDIS_ENCAPSULATION_NOT_SUPPORTED
Specifies that no encapsulation offload is supported.
- NDIS_ENCAPSULATION_NULL
Specifies NULL encapsulation.
- NDIS_ENCAPSULATION_IEEE_802_3
Specifies IEEE 802.3 encapsulation.
- NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q
Specifies IEEE 802.3p and IEEE 802.3q encapsulation.
- NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q_IN_OOB
Specifies that IEEE 802.3p and IEEE 802.3q encapsulation settings are specified in the NetBufferListInfo member of each NET_BUFFER_LIST structure.
- NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED
Specifies logical link control (LLC) encapsulation for routed protocols, as described in RFC 1483. This flag is also used to indicate Ethernet LLC/SNAP encapsulation.

The meaning of the values in the
**IpOptionsSupported**,
**TcpOptionsSupported**,
**IpExtensionHeadersSupported**,
**TcpChecksum**,
**UdpChecksum**, and
**IpChecksum** members of **NDIS_TCP_IP_CHECKSUM_OFFLOAD** depends on which OID or status indication
includes the task offload structure. These members can have one of the following values:

- NDIS_OFFLOAD_NOT_SUPPORTED
In [OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config), this value specifies that the miniport adapter does not support the feature that the member specifies.
- NDIS_OFFLOAD_SUPPORTED
In [OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config), this value specifies that the miniport adapter supports the feature that the member specifies.
- NDIS_OFFLOAD_SET_OFF
In the [NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication, this value specifies that the feature that the member specifies is disabled.
- NDIS_OFFLOAD_SET_ON
In the [NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication, this value specifies that the feature that the member specifies is enabled.

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config)