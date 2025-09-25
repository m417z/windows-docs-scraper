# _NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS structure provides TCP chimney offload information in the
[OID_TCP_CONNECTION_OFFLOAD_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/embedded/gg158102(v=winembedded.80)) OID.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to
**NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to
**NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS_ 1**, and the
**Size** member to
`sizeof(NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS)`.

### `Encapsulation`

An
[NDIS_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/encapsulationconfig/ns-encapsulationconfig-ndis_offload_encapsulation) structure that contains encapsulation settings for TCP chimney
offload.

### `TicksPerSecond`

A ULONG value that the TCP/IP driver stack sets to specify how many ticks of the host's clock
equal one second. The default value is 1000 (that is, 1 tick = 1 millisecond). An offload target must
support this member.

### `TcpAckFrequency`

A UCHAR value that the TCP/IP driver stack sets to specify the maximum number of segments that the
offload target can receive before the target sends an ACK. An offload target must support this
member.

### `TcpDelayedAckTicks`

A UCHAR value that the TCP/IP driver stack sets to specify how many ticks, starting from the
reception of a segment, that the offload target should wait for additional receive segments before the
target sends an ACK. An offload target uses this value to initialize its delayed-ACK timer. An offload
target must support this member.

### `TcpMaximumRetransmissions`

A UCHAR value that the TCP/IP driver stack sets to specify the maximum number of times that the
offload target should retransmit a segment on a TCP connection. When the retransmit counter for a TCP
connection exceeds this limit, the offload target can call the
[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate) function with an
**EventType** parameter of
**TcpIndicateRetrieve** to request that the TCP/IP driver stack terminate the
offload of the connection. An offload target must support this member.

### `TcpDoubtReachabilityRetransmissions`

A UCHAR value that the TCP/IP driver stack sets to specify the maximum number of times that the
offload target should retransmit a segment before the target indicates to the TCP/IP driver stack that
the reachability of a neighbor is in doubt. For more information about this indication, see
[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate). An
offload target should support this member.

### `TcpSwsPreventionTicks`

A ULONG value that the TCP/IP driver stack sets to specify the number of ticks for the offload
target's silly window syndrome (SWS) send and receive timers. When the SWS send timer times out, the
offload target sends a partial segment. When the SWS receive timer times out, the offload target sends a
window update. An offload target should support this member.

### `TcpDuplicateAckThreshold`

A ULONG value that the TCP/IP driver stack sets to specify the number of duplicate acknowledgments
that the offload target must receive before the target performs a fast retransmission. An offload target
must support this member.

### `TcpPushTicks`

A ULONG value that the TCP/IP driver stack sets to specify the number of ticks that an offload
target must wait before the target completes a pre-posted receive buffer. This interval starts
immediately after the offload target places the first byte in the pre-posted receive buffer. An offload
target uses this value to initialize its push timer. An offload target must support this member.

### `NceStaleTicks`

A ULONG value that the TCP/IP driver stack sets to indicate the number of ticks of inactivity that
make a neighbor state object stale. An offload target must support this member.

### `CongestionAlgorithm`

Reserved for future use.

If you are an independent hardware vendor (IHV) and you want to implement nondefault congestion control algorithms, for example Compound TCP, contact Microsoft at [External TCP Offload Triage](mailto:offloadt@microsoft.com).

## Remarks

In NDIS 6.0 and later versions, the NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS structure specifies the
current or requested parameters that a miniport adapter provides for TCP chimney offload.

To specify various offload parameter settings, NDIS and overlying drivers supply an
NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS structure when they set the
[OID_TCP_CONNECTION_OFFLOAD_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/embedded/gg158102(v=winembedded.80)) OID.

To obtain the current settings of various offload parameters, NDIS and overlying drivers query
OID_TCP_CONNECTION_OFFLOAD_PARAMETERS. The miniport driver returns the current settings in the
NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS structure.

The
**Encapsulation** member of NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS defines the TCP
chimney offload encapsulation settings for the miniport adapter. For more information, see the
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).

## See also

[Full TCP Offload](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/encapsulationconfig/ns-encapsulationconfig-ndis_offload_encapsulation)

[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate)

[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate)

[OID_TCP_CONNECTION_OFFLOAD_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/embedded/gg158102(v=winembedded.80))