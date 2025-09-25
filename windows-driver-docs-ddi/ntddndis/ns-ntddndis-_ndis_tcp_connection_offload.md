# _NDIS_TCP_CONNECTION_OFFLOAD structure

## Description

The NDIS_TCP_CONNECTION_OFFLOAD structure provides connection offload information for current
settings and for supported capabilities.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_TCP_CONNECTION_OFFLOAD structure. Set the
**Type** member of the structure that
**Header** specifies to
**NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to
**NDIS_TCP_CONNECTION_OFFLOAD_REVISION_1**, and the
**Size** member to
**NDIS_SIZEOF_TCP_CONNECTION_OFFLOAD_REVISION_1**.

### `Encapsulation`

Encapsulation settings for TCP chimney offload. For more information about this member, see the following Remarks section.

### `SupportIPv4`

A ULONG value that an offload target sets to indicate that it supports IPv4. The TCP/IP driver
stack sets this member to enable IPv4.

### `SupportIPv6`

A ULONG value that an offload target sets to indicate that it supports IPv6. The TCP/IP driver
stack sets this member to enable IPv6. Note that an offload target can support both IPv4 and
IPv6.

### `SupportIPv6ExtensionHeaders`

A ULONG value that an offload target sets to indicate that it supports IPv6 extension headers
(that is, routing, fragmentation/reassembly, authentication, encapsulation, hop-by-hop processing, and
destination options). The TCP/IP driver stack sets this member to enable IPv6 extension headers.

### `SupportSack`

A ULONG value that an offload target sets to indicate that it supports TCP selective
acknowledgments (SACKs) for both transmit and receive operations. The TCP/IP driver stack sets this
member to enable SACKs for both transmit and receive operations.

If an offload target sets the
**SupportSack** member, the target must be able to generate and consume SACK
segments. If an offload target does not support the SACK option, the target must be able to ignore the
SACK option and process the rest of the TCP segment normally.

### `CongestionAlgorithm`

Reserved for future use.

If you are an independent hardware vendor (IHV) and you want to implement nondefault congestion
control algorithms, for example Compound TCP, contact Microsoft at
[External TCP Offload Triage](mailto:offloadt@microsoft.com).

### `TcpConnectionOffloadCapacity`

A ULONG value that an offload target sets to indicate the maximum number of offloaded TCP
connections that it supports. This number includes both IPv4 and IPv6 connections.

### `Flags`

Reserved.

## Remarks

The NDIS_TCP_CONNECTION_OFFLOAD structure specifies the current or supported services that a miniport
adapter provides for TCP chimney offload.

The NDIS_TCP_CONNECTION_OFFLOAD structure is used in the
[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes) structure,
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure,
[OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-current-config) OID,
[OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities) OID, NDIS_STATUS_OFFLOAD_RESUME status indication,
and
[NDIS_STATUS_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-tcp-connection-offload-hardware-capabilities) status indication. (For information on
NDIS_STATUS_OFFLOAD_RESUME, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).)

Miniport drivers do not receive the OID queries. NDIS uses the information that the miniport driver
provides in attributes and status indications to provide responses to OID queries and to provide bind
parameters.

NDIS supplies an NDIS_TCP_CONNECTION_OFFLOAD structure in response to a query of
OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG or OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES. In
response to an OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG query, the NDIS_TCP_CONNECTION_OFFLOAD structure
specifies the offload target's current configuration settings. In response to an
OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES query, the NDIS_TCP_CONNECTION_OFFLOAD structure
specifies the offload target's hardware capabilities for offloading TCP connections from the TCP/IP
transport.

The
**Encapsulation** member of NDIS_TCP_CONNECTION_OFFLOAD defines the TCP chimney
offload encapsulation settings for the miniport adapter.

For an
[OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities) query request, NDIS provides a single flag that
indicates the hardware encapsulation capabilities, in the
**Encapsulation** member.

For an
[OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-current-config) query request, NDIS provides a bitwise OR of the
encapsulation flags, which indicates the current encapsulation settings.

The following flags are defined for the
**Encapsulation** member:

**Important** A miniport or mux driver that is chimney capable must set the **Encapsulation** member to NDIS_ENCAPSULATION_IEEE_802_3, NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED, or both. Otherwise, chimney capability will not be recognized.

###

### TCP Chimney Offload Queries

When an NDIS responds to a query of
[OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities) or
[OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-current-config) for an offload target, NDIS provides the
**SupportIp4**,
**SupportIp6**,
**SupportIp6ExtensionHeaders**, and
**SupportISack** members of the NDIS_TCP_CONNECTION_OFFLOAD structure. These
members can have one of the following values:

An offload target must support either IPv4 or IPv6 (or both). Offload targets can optionally
support IPv6 extension headers.

An offload target should not support any IPv4 options. The offload target must forward any received
IP datagrams that contain IPv4 options to the TCP/IP driver stack. The offload target indicates such
IP datagrams to the TCP/IP driver stack by calling
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists). The TCP/IP driver stack processes the IPv4 options and
returns the datagrams to the offload target's
[MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler) function. (For information on
*MiniportTcpOffloadForward*, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).)

The offload target must also provide a value for the
**TcpConnectionOffloadCapacity** member of NDIS_TCP_CONNECTION_OFFLOAD. This
value should be the maximum number of simultaneously offloaded TCP connections that the offload target
can support.

Note that an offload target cannot directly indicate new offload capabilities. Instead, the offload
target must request the TCP/IP driver stack to pause and then resume offloads. When the miniport
adapter is ready to resume offloading TCP connections, it issues an NDIS_STATUS_OFFLOAD_RESUME status
indication to report the new connection offload capabilities. For more information on
NDIS_STATUS_OFFLOAD_RESUME, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_STATUS_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-tcp-connection-offload-hardware-capabilities)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-current-config)

[OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities)