# _TCP_OFFLOAD_STATE_CONST structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The TCP_OFFLOAD_STATE_CONST structure contains the constant variables of a TCP connection state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the TCP_OFFLOAD_STATE_CONST structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `Flags`

A bitmask that can be set to zero or any of the following flags, combined with bitwise OR:

#### TCP_FLAG_TIMESTAMP_ENABLED

The host stack sets this flag to enable the TCP timestamp option on the connection. (For more
information about the TCP timestamp option, see RFC 1323.) When this option is enabled, the offload
target must place a timestamp in each TCP segment that it sends. The host stack clears this flag to
disable the TCP timestamp option on the connection.

#### TCP_FLAG_SACK_ENABLED

The host stack sets this flag to enable selective acknowledgments (SACKs) on the connection.
(For more information about the SACKs, see RFC 2018.) When this option is enabled, the offload target
sends and receives SACK blocks over the TCP connection. The host stack clears this flag to disable
SACKs on the connection.

#### TCP_FLAG_WINDOW_SCALING_ENABLED

The host stack sets this flag to cause the offload target to use scale factors (SndWindScale and
RcvWindScale) to compute send and receive windows for the connection. (For more information about
window scale factors, see RFCs 2883 and 3517.) The host stack clears this flag to disable this
option.

### `RemotePort`

The destination port number (see RFC 793).

### `LocalPort`

The source port number (see RFC 793).

### `SndWindScale`

The send window scale factor (see RFC 1323).

### `RcvWindScale`

The receive window scale factor (see RFC 1323).

### `RemoteMss`

The initial maximum segment size (MSS) advertised by the remote endpoint during TCP connection
setup. (For more information about MSS, see RFC 2581.)

### `HashValue`

A 32-bit hash value that the offload target uses for
[receive side
scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-side-scaling-on-an-offloaded-tcp-connection) processing on the TCP connection if the offload target supports RSS.

## Remarks

The value of each TCP constant variable does not change during the life of a TCP connection. Neither
the host stack nor the offload target changes the values of a TCP constant variable. When the host stack
terminates the offload of the TCP connection state object by causing NDIS to call the offload target's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function, the offload target does not return the value of the offloaded
TCP constant variables to the host stack.

When passed to an offload target, a TCP_OFFLOAD_STATE_CONST structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
**Revision** member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of
the TCP_OFFLOAD_STATE_CONST structure.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)

[TCP_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached)

[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated)