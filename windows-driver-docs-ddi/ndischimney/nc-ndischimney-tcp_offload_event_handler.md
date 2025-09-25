# TCP_OFFLOAD_EVENT_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol driver's or intermediate driver's
*ProtocolIndicateOffloadEvent* function to post an indication that was initiated by an underlying
driver's or offload target's call to the
[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate) function.

## Parameters

### `OffloadContext` [in]

A pointer to the protocol or intermediate driver's
[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle) structure for the
TCP connection on which the indication is being made. The protocol or intermediate driver supplied this
pointer as an input parameter to the
[NdisInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisinitiateoffload) function when
offloading the connection.

### `EventType` [in]

The event being indicated as one of the following TCP_OFFLOAD_EVENT_TYPE values:

#### TcpIndicateDisconnect

Indicates that the remote host initiated a graceful disconnect by sending a FIN segment on the
connection.

#### TcpIndicateRetrieve

Indicates that the offload target is requesting the host stack to terminate the offload of a TCP
connection.

#### TcpIndicateAbort

Indicates that the remote host initiated an abortive disconnect by sending an acceptable RST
segment on the connection.

#### TcpIndicateSendBacklogChange

Indicates a change in the preferred send backlog size.

### `EventSpecificInformation` [in]

Specifies additional information about the event being indicated as follows:

#### TcpIndicateDisconnect

Not meaningful.

#### TcpIndicateRetrieve

Indicates the reason for the upload request as a TCP_UPLOAD_REASON value. For more information,
see
[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate).

#### TcpIndicateAbort

Not meaningful.

#### TcpIndicateSendBacklogChange

Specifies the optimum number of send data bytes that the host stack should have outstanding at
the offload target in order to achieve the best data throughput.

## Remarks

To propagate the indication to the overlying driver or host stack, the intermediate driver calls the
**NdisTcpOffloadEventHandler** function. The intermediate driver passes the following parameters to the
**NdisTcpOffloadEventHandler** function:

* The
  **NdisOffloadHandle** that the offload target stored in its context for the offloaded TCP connection.
  For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The
  *EventType* that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadEvent* function.
* The
  *EventSpecificInformation* that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadEvent* function.

## See also

[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate)