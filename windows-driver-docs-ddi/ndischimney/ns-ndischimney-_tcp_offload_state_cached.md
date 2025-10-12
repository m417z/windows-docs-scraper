# _TCP_OFFLOAD_STATE_CACHED structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The TCP_OFFLOAD_STATE_CACHED structure contains the cached variables of a TCP connection state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the TCP_OFFLOAD_STATE_CACHED structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `Flags`

A bitmask that can be set to zero or any of the following flags, combined with bitwise OR:

#### TCP_FLAG_KEEP_ALIVE_ENABLED

The host stack sets this flag to enable the keepalive option on the connection. The host stack
clears this flag to disable the keepalive option on the connection. For more information about the
keepalive option, see RFC 1122.

#### TCP_FLAG_NAGLING_ENABLED

The host stack sets this flag to enable the Nagle algorithm on the connection. The host stack
clears this flag to disable the Nagle algorithm on the connection. For more information about the
Nagle algorithm, see RFC 896.

#### TCP_FLAG_KEEP_ALIVE_RESTART

The host stack sets this flag to cause the offload target to reset its keepalive timer to
zero.

#### TCP_FLAG_MAX_RT_RESTART

The host stack sets this flag to cause the offload target to reset the TotalRT variable in the
TCP delegated state for the connection to zero.

#### TCP_FLAG_UPDATE_RCV_WND

The host stack sets this flag to indicate that the default receive window size (InitialRcvWnd in
the TCP_OFFLOAD_STATE_CACHED structure) has changed. If the value of InitialRcvWnd differs from the
offload target's current receive window size (RcvWnd in the TCP_OFFLOAD_STATE_DELEGATED structure),
the offload target must advertise a new receive window size to the peer.

### `InitialRcvWnd`

The default receive window (from socket option SO_RCVBUF).

### `RcvIndicationSize`

When non-**NULL**, the optimum number of data bytes that the offload target should supply in a single
call to the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function. This number, which is typically between tens and hundreds
of bytes, is a suggestion--not a requirement. The offload target can indicate more or less than
**RcvIndicationSize** data bytes. However, for optimum performance, the offload target should indicate
**RcvIndicationSize** data bytes. For more information, see
**NdisTcpOffloadReceiveHandler**.

When **NULL**,
**RcvIndicationSize** is unspecified. In this case, the offload target should ignore
**RcvIndicationSize** and indicate as much data as possible in calls to the
*NdisTcpOffloadReceiveHandler* function.

### `KaProbeCount`

The number of keepalive probes that the offload target should send to determine whether a TCP
connection is intact (see RFC 1122).

### `KaTimeout`

This member specifies, in clock ticks, the timeout interval for inactivity before sending a
keepalive probe (see RFC 1122).

### `KaInterval`

This member specifies, in clock ticks, the timeout after which to retransmit a keepalive frame if
no response is received to a keepalive probe (see RFC 1122).

### `MaxRT`

This member specifies, in clock ticks, the maximum time that the offload target should spend
retransmitting a segment. If the value of
**MaxRT** is non-zero,
**MaxRT** overrides
**TcpMaximumRetransmissions** in the
[NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_tcp_connection_offload_parameters) structure. The default value for is
**MaxRT** is zero, which means that
**TcpMaximumRetransmissions** sets the maximum number of times that the offload target should
retransmit a segment on a TCP connection. If the value of
**MaxRT** is FFFFFFFF (or -1), there is no limit on the maximum number of retransmissions. When
**MaxRT** is nonzero, the offload target should reset the
**TotalRT** variable in the TCP delegated state for the connection.
**TotalRT** indicates the total time, in clock ticks, that the offload target has spent retransmitting
the current TCP segment.

### `FlowLabel`

This member marks host-labeled packets for special handling by intervening routers--for example,
nondefault QoS or "real-time" service (see RFC 2460). This variable is set through a socket option and
can vary during the lifetime of the TCP connection. This variable is only meaningful if the TCP
connection is over IPv6.

### `TtlOrHopLimit`

If the TCP connection is over IPv4, then this member specifies the time to live (see RFC 791).
This variable is set through a socket option and can vary during the lifetime of the TCP connection.

If the TCP connection is over IPv6, then this member specifies the number of routers that the packet
can pass through (see RFC 2460). This variable is set through a socket option and can vary during the
lifetime of the TCP connection.

### `TosOrTrafficClass`

If the TCP connection is over IPv4, then this member specifies the type of service for routing a
packet (see RFC 2474). This variable is set through a socket option and can vary during the lifetime of
the TCP connection.

If the TCP connection is over IPv6, then this member prioritizes values for packets according to
traffic types, indicating how willing the sender is to have the packets discarded (see RFC 2460). This
variable is set through a socket option and can vary during the lifetime of the TCP
connection.

### `UserPriority`

A 3-bit priority value. If the offload target supports 802.1p packet information, it must insert
this priority value into the
[tag header](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff564233(v=vs.85)) of all packets that it transmits
on the offloaded TCP connection. If the offload target does not support 802.1p packet information, it
should ignore
**UserPriority** . For more information about supporting 802.1p packet information, see
[802.1Q
and 802.1p Processing on an Offloaded TCP Connection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached).

## Remarks

Cached variables are owned and maintained by the host stack. An offload target must not change the
value of a cached variable unless requested to do so by the host stack. If the value of a cached variable
changes, the host stack requests an update of the variable, which causes NDIS to call the offload
target's
[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler) function.
When the host stack terminates the offload of one or more state objects by causing NDIS to call the
offload target's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function, the offload target does not return the value of offloaded
constant variables to the host stack.

Note that if an offloaded TCP connection's TCP_FLAG_MAX_RT_RESTART flag is set, the offload target
must:

* Reset that connection's delegated KeepaliveProbeCount variable when the host stack updates that
  connection's cached KaProbeCount variable.
* Reset that connection's delegated KeepaliveTimeoutDelta variable when the host stack updates that
  connection's cached KaTimeout and/or KaInterval variables.

When passed to an offload target, a TCP_OFFLOAD_STATE_CACHED structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
**Revision** member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of
the TCP_OFFLOAD_STATE_CACHED structure.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)

[TCP_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_const)

[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated)