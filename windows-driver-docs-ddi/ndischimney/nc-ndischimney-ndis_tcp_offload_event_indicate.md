# NDIS_TCP_OFFLOAD_EVENT_INDICATE callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisTcpOffloadEventHandler** function to indicate an event that pertains to an offloaded TCP
connection.

## Parameters

### `NdisOffloadHandle` [in]

A handle that identifies the offloaded TCP connection on which the indication is being made. When
the connection was offloaded, this handle was supplied in the
**NdisOffloadHandle** member of the
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure that was associated with the connection state.

### `EventType` [in]

The event being indicated as one of the following **TCP_OFFLOAD_EVENT_TYPE** values:

#### TcpIndicateDisconnect

Indicates that the remote host has initiated a graceful disconnect by sending a FIN segment on
the connection.

#### TcpIndicateRetrieve

Indicates that the offload target is requesting the host stack to terminate the offload of a TCP
connection.

#### TcpIndicateAbort

Indicates that the remote host has initiated an abortive disconnect by sending an acceptable RST
segment on the connection.

#### TcpIndicateSendBacklogChange

Indicates a change in the preferred send backlog size.

### `EventSpecificInformation` [in]

Specifies additional information about the event being indicated as follows:

#### TcpIndicateDisconnect

Not meaningful.

#### TcpIndicateRetrieve

Indicates the reason for the upload request as a **TCP_UPLOAD_REASON** value. See the Remarks
section for more information.

#### TcpIndicateAbort

Not meaningful.

#### TcpIndicateSendBacklogChange

Specifies the optimum number of send data bytes that the host stack should have outstanding at
the offload target.

## Remarks

### Indicating a Graceful Disconnect

An offload target should indicate a graceful disconnect only when:

* It has received a FIN segment from the remote host.
* All data received on the connection prior to the reception of the FIN segment has been consumed by
  the client application (that is, there is no receive data to be indicated on the connection).

The offload target must not free the resources for the connection until the host stack terminates the
offload of the connection.

Note that a graceful disconnect shuts down only the receive half of the connection. It does not shut
down the send half of the connection.

### Indicating an Abortive Disconnect

When an offload target receives an acceptable RST segment on a TCP connection, it must:

1. In its internal state for the connection, mark the connection as aborted.
2. Call the
   **NdisTcpOffloadEventHandler** function with an
   *EventType* of
   **TcpIndicateAbort**.

   **Note** When the miniport indicates the **TcpIndicateAbort** event, the host TCP/IP stack will terminate the offload of the connection. The offload target is free to indicate the **TcpIndicateAbort** event as soon as the RST segment arrives.
3. Complete all outstanding send requests and disconnect requests on the connection with
   NDIS_STATUS_REQUEST_ABORTED. The offload target writes this status value to the
   **Status** member of each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure in the linked list that it passes to the
   [NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete) function or to the
   [NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete) function.

The offload target must not free the resources for the connection until the host stack terminates the
offload of the connection.

### Requesting Termination of a TCP Connection

The offload target specifies the reason for the termination request as a **TCP_UPLOAD_REASON** value in
the
*EventSpecificInformation* parameter that it passes to the
**NdisTcpOffloadEventHandler** function. In response, the host stack calls the
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function
of the offload target.

The offload target can request the termination of only one TCP connection per call to
**NdisTcpOffloadEventHandler**. The offload target cannot request the termination of a neighbor state
object or a path state object. Only the host stack can initiate the termination of a neighbor or path
state object.

The following table describes events or circumstances that can cause an offload target to request the
termination of the offload of a TCP connection.

The right-most column indicates, for each **TCP_UPLOAD_REASON**, whether the host stack always uploads the
connection (mandatory) or might or might not upload the connection (optional). In the mandatory cases, an
offload target does not continue processing the offloaded connection. In the optional cases, an offload
target must be able to continue processing on the offloaded connection if the host stack does not
terminate the offload of that connection.

| Event/Circumstance | TCP_UPLOAD_REASON | Host stack's termination of the TCP connection |
| --- | --- | --- |
| The hardware state used to track the connection is corrupt. | **HardwareFailure** | Mandatory |
| Offload target attempted to send data on a TCP connection that depends on an invalidated state object. | **InvalidState** | Mandatory |
| Offload target receives a segment with the URG bit set in the TCP header. Note that the offload target does not send an ACK to acknowledge the urgent data. | **ReceivedUrgentData** | Mandatory |
| A timeout occurred on the TCP connection. | **TimeoutExpiration** | Mandatory |
| The offload target is requesting an upload for an unspecified reason. | **UploadRequested** | Mandatory |
| The offload target has detected that too many transmit segments are being dropped on the TCP connection. | **HighDropRate** | Optional |
| The offload target has detected that too many fragments are being received on the TCP connection. | **HighFragmentation** | Optional |
| The offload target has received too many out-of-order segments on the TCP connection. | **HighOutofOrderPackets** | Optional |
| The activity (sends/receives) on the TCP connection is too low. | **LowActivity** | Optional |
| There are no preposted receive buffers for the TCP connection. | **NoBufferProposting** | Optional |
| The received buffers posted for the TCP connection are too small. | **SmallIO** | Optional |

The offload target must not initiate the termination of a half-closed TCP connection when that
connection is in one of the following states:

* FIN_WAIT1--The local host stack has closed the TCP connection, but the connection might still be
  receiving data from the remote endpoint.
* FIN_WAIT2--The local host has closed the TCP connection and received an ACK for the FIN segment that
  it sent, but the offloaded connection might still be receiving data from the remote host.
* CLOSE_WAIT--The local host might still be sending data.

An offload target can request the termination of all TCP connections that have been offloaded to it.
For more information, see
[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate).

### Indicating a Change in the Send Backlog Size

The send backlog size can be a function of the round-trip time (RTT) for the connection, the interface
bandwidth, and other parameters. The specific variables and algorithm that the offload target uses to
calculate the send backlog size are implementation-specific. An offload target could, for example, use
minimum of the bandwidth-delay product and the advertised receive window as the algorithm. Note, however,
that the send backlog size does not vary according to the number of data bytes that are currently posted
for transmission on the connection.

The offload target should implement a throttling mechanism to ensure that, if the value for
**SendBacklogSize** changes too frequently or by too small an amount, the offload target does not
indicate a
**SendBacklogSize** event. This will prevent a storm of event indications from occurring.

## See also

[Indicating TCP Chimney-Specific Events](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-tcp-chimney-specific-events)

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate)

[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete)

[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete)

[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete)

[ProtocolTcpOffloadEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_event_handler)

[Responding to
the Reception of a FIN or RST Segment](https://learn.microsoft.com/windows-hardware/drivers/network/responding-to-the-reception-of-a-fin-or-rst-segment)