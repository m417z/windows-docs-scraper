# _TCP_OFFLOAD_STATE_DELEGATED structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The TCP_OFFLOAD_STATE_DELEGATED structure contains the delegated variables of a TCP connection state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the TCP_OFFLOAD_STATE_DELEGATED structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `State`

The current state of the TCP connection (see RFC 793) as one of the following
TCP_OFFLOAD_CONNECTION_STATE values:

#### TcpConnectionClosed

No connection state.

#### TcpConnectionListen

Waiting for a connection request from any remote TCP and port.

#### TcpConnectionSynSent

Waiting for a matching connection request after having sent a connection request.

#### TcpConnectionSynRcvd

Waiting for a confirming connection request acknowledgment after having both received and sent a
connection request.

#### TcpConnectionEstablished

An open connection: data received can be delivered to the user. The normal state for the data
transfer phase of the connection.

#### TcpConnectionFinWait1

Waiting for a connection termination request from the remote TCP, or an acknowledgment of the
connection termination request that was previously sent.

#### TcpConnectionFinWait2

Waiting for a connection termination request from the remote TCP.

#### TcpConnectionCloseWait

Waiting for a connection termination request from the local user.

#### TcpConnectionClosing

Waiting for a connection termination request acknowledgment from the remote TCP.

#### TcpConnectionLastAck

Waiting for an acknowledgment of the connection termination request previously sent to the
remote TCP, which includes an acknowledgment of its connection termination request.

#### TcpConnectionTimeWait

Waiting for enough time to pass to ensure that the remote TCP received the acknowledgment of its
connection termination request.

 Note that the host stack can offload a TCP connection when the connection is in any state
except
**TcpConnectionClosed**,
**TcpConnectionListen**,
**TcpConnectionSynRcvd**,

**TcpConnectionSynSent**, or
**TcpConnectionTimeWait** state. The host stack can query, update, invalidate, or terminate a TCP
connection regardless of the connection state.

### `Flags`

Reserved for system use.

### `RcvNxt`

The sequence number for the next receive segment (see RCV.NEXT in RFC 793).

### `RcvWnd`

The receive window size, in bytes (see RCV.WND in RFC 793).

### `SndUna`

The sequence number for the first byte of unacknowledged data (see SND.UNA in RFC 793). For more information, see [Send Data That Contains Data to Be Retransmitted](https://learn.microsoft.com/windows-hardware/drivers/network/send-data-that-contains-data-to-be-retransmitted).

### `SndNxt`

The sequence number for the next byte to send on the connection (see SND.NXT in RFC 793). For more information, see [Send Data That Contains Data to Be Retransmitted](https://learn.microsoft.com/windows-hardware/drivers/network/send-data-that-contains-data-to-be-retransmitted).

### `SndMax`

The maximum sequence number that has been sent on the connection. For more information, see [Send Data That Contains Data to Be Retransmitted](https://learn.microsoft.com/windows-hardware/drivers/network/send-data-that-contains-data-to-be-retransmitted).

### `SndWnd`

The send window size, in bytes (see SND.WND in RFC 793).

### `MaxSndWnd`

The maximum send window size, in bytes (see RFC 813).

### `SendWL1`

The segment sequence number used for the last window update (see SND.WL1 in RFC 793).

### `CWnd`

The congestion window size, in bytes (see cwnd in RFC 2581).

### `SsThresh`

The slow start threshold, in bytes (see ssthresh in RFC 2581).

### `SRtt`

The smoothed round-trip time, in clock ticks (see SRTT in RFCs 793 and 2988). Maintained on a per
connection basis because it takes into account path, host, and sometimes application behavior.

### `RttVar`

The round trip time variation, in clock ticks (see RTTVAR in RFC 2988).

### `TsRecent`

The timestamp value to send in the next ACK (see TS.Recent in RFC 1323)

### `TsRecentAge`

The length of time, in clock ticks, since the most recent timestamp was received (see RFC
1323).

### `TsTime`

The current value of the adjusted timestamp.

### `TotalRT`

The total time, in clock ticks, that has been spent retransmitting the current TCP segment.

### `DupAckCount`

The number of ACKs that have been accepted for the same sequence number (see RFC 1323).

### `SndWndProbeCount`

The current send window probe round. For a description of the send window probe round, see
[Persist Timer](https://learn.microsoft.com/windows-hardware/drivers/network/persist-timer).

### `KeepAlive`

This member is a union that consists of the following members:

### `KeepAlive.ProbeCount`

The number of keepalive probes that have been sent that have not received a response (see RFC
1122).

### `KeepAlive.TimeoutDelta`

The time remaining, in clock ticks, until the next keepalive timeout (see RFC 1122). Note that a
value of -1 immediately after the TCP connection was offloaded indicates that the keepalive timer was
not running when the connection was offloaded. If the offload target's keepalive timer is not running,
the offload target should return -1 in this member when responding to a call to the
MiniportQueryOffload function or the MiniportTerminateOffload function.

### `Retransmit`

This member is a union that consists of the following members:

### `Retransmit.Count`

The number of retransmits that have been sent (see RFC 2581).

### `Retransmit.TimeoutDelta`

The time, in clock ticks, remaining until the next retransmit timeout (see RFC 2581). Note that a
value of -1 immediately after the TCP connection was offloaded indicates that the retransmit timer was
not running when the connection was offloaded. The retransmit timer was not running because there was
no outstanding send data on the connection when the connection was offloaded. If the offload target's
retransmit timer is not running, the offload target should return -1 in this member when responding to
a call to the MiniportQueryOffload function or the MiniportTerminateOffload function.

### `SendDataHead`

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This
NET_BUFFER_LIST structure is in the linked list that is pointed to by the
**NetBufferListChain** member of the
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure that immediately precedes the
TCP_OFFLOAD_STATE_DELEGATED structure. If the
**NetBufferListChain** pointer is **NULL**,
**SendDataHead** is not significant.

The
**SendDataHead** pointer points to the first NET_BUFFER_LIST structure whose NET_BUFFER structure
has buffered the send data associated with it.

This variable is used only in an initiate offload or terminate offload operation. For more
information about how this variable is used, see
[Handling Outstanding Send Data During and After an Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-outstanding-send-data-during-and-after-an-offload-operation) and
[Handling Outstanding Send Data During a Terminate Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-outstanding-send-data-during-a-terminate-offload-operation).

### `SendDataTail`

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This
NET_BUFFER_LIST structure is in the linked list that is pointed to by the NetBufferListChain member of
the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure that immediately precedes the
TCP_OFFLOAD_STATE_DELEGATED structure. If the NetBufferListChain pointer is **NULL**, SendDataTail is not
significant.

The SendDataTail pointer points to the last NET_BUFFER_LIST structure whose NET_BUFFER structure
has buffered the send data associated with it.

This variable is used only in an initiate offload or terminate offload operation. For more
information about how this variable is used, see
[Handling Outstanding Send Data During and After an Offload
Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-outstanding-send-data-during-and-after-an-offload-operation) and
[Handling Outstanding Send Data During a Terminate Offload
Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-outstanding-send-data-during-a-terminate-offload-operation)

### `SendBacklogSize`

The offload target specifies this value to indicate the number of data bytes that the host stack
should have outstanding at the offload target for optimum performance. (This is the number of send
bytes that have been passed to the offload target but that have not yet been completed by the offload
target.) The specific variables and algorithm that the offload target uses to calculate the send
backlog size are implementation-specific. The send backlog size can be a function of the roundtrip
time (RTT) for the connection, the interface bandwidth, and other parameters. An offload target could,
for example, use the minimum of the bandwidth/delay product and the advertised received window. Note
however, that the send backlog size does not vary according to the number of data bytes that are
currently posted for transmission on the connection.

The host stack can query the TCP delegated state for the connection to obtain the send backlog
size. In addition, the offload target can indicate a change in the send backlog size by calling the
[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate) function.

If the offload target does not support the send-backlog-size feature, it must write a value of
0xFFFFFFFF to
**SendBacklogSize** when the TCP-delegated state for the connection is queried. The
**SendBacklogSize** variable is not used in the terminate offload operation.

### `BufferedData`

A pointer to buffered receive data. The host stack can pass such data to the offload target when
offloading a TCP connection. (For more information, see
[Handling Buffered Receive Data During and After an Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-buffered-receive-data-during-and-after-an-offload-operation).) The
offload target can pass such data to the host stack when uploading a TCP connection. (For more
information, see
[Handling Buffered Receive Data During a Terminate Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/push-timer).)

### `ReceiveBacklogSize`

The offload target specifies this value to indicate the number of receive data bytes that are
buffered in the offload target for the offloaded TCP connection. The host stack can query the TCP
delegated state for the connection to obtain this value. The host stack uses this value to post one or
more receive requests on the connection that are large enough to hold all of the buffered data.

If the offload target does not support the receive backlog size feature, it should write a value of
0xFFFFFFFF to
**ReceiveBacklogSize** .

### `DWnd`

## Remarks

The host stack provides initial values for the TCP delegated variables when it offloads these
variables to the offload target. After it is offloaded, the TCP delegated variables are owned and
maintained by the offload target. Only the offload target can change the value of an offloaded TCP
delegated variable. The offload target does not notify the host stack of changes to the values of
offloaded TCP delegated variables. However, the host stack can query the value of offloaded TCP delegated
variables, which causes NDIS to call the offload target's
[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler) function.
When the host stack terminates the offload of the TCP connection state object by causing NDIS to call the
offload target's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function, the offload target passes the value of the TCP delegated
variables in the terminated TCP connection state object back to the host stack.

When passed to an offload target, a TCP_OFFLOAD_STATE_DELEGATED structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
Revision member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of the
TCP_OFFLOAD_STATE_DELEGATED structure.

## See also

[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)

[TCP_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached)

[TCP_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_const)