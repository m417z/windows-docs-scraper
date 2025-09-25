# NDIS_TCP_OFFLOAD_SEND_COMPLETE callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisTcpOffloadSendComplete** function to complete one or more send requests that were made to the
[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler) function of
the offload target.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
The offload target obtained these structures in one or more calls to its
[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler) function.

## Remarks

To improve system performance, an offload target can create a linked list that contains
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures from multiple
calls to the
[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler) function.
The driver can then pass such a linked list in a single call to the
**NdisTcpOffloadSendComplete** function.

Before completing one or more send requests, the offload target must do the following for each
NET_BUFFER_LIST structure that it passes to the
**NdisTcpOffloadSendComplete** function:

* Write a status value to the
  **Status** member:

  + NDIS_STATUS_SUCCESS indicates that all data associated with the NET_BUFFER_LIST was successfully
    sent by the offload target and that the offload target received from the remote host an acknowledgment
    for all the transmitted data. Note that this differs from the non-offload send function,
    [MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists), which does not monitor acknowledgments.
  + A status value other than NDIS_STATUS_SUCCESS--for example, a status value of
    NDIS_STATUS_REQUEST_ABORTED or NDIS_STATUS_UPLOAD_IN_PROGRESS--indicates that the send data was not
    successfully acknowledged. The offload target might or might not have sent the data. The offload
    target should fail the send operation for all subsequent NET_BUFFER_LIST structures in the linked list
    without sending any more data associated with these structures. The offload target writes a status
    value of NDIS_STATUS_UPLOAD_IN_PROGRESS when the offload of the TCP connection on which the data is to
    be sent is being terminated. In this case, the host stack queues and processes the TCP data. The
    offload target writes a status value of NDIS_STATUS_REQUEST_ABORTED if it has received an RST segment
    on the TCP connection on which the data is to be sent. In this case, the host stack does not process
    the TCP data.
  + The offload target should complete a partial send for, at most, one NET_BUFFER_LIST structure in
    linked list. The offload target writes a status value other than NDIS_STATUS_SUCCESS--for example, a
    status value of NDIS_STATUS_ABORTED or NDIS_STATUS_UPLOAD_IN_PROGRESS--to such a NET_BUFFER_LIST
    structure.
  + If an intermediate driver cannot allocate memory to propagate the send operation to an
    underlying offload target, it writes a status value of NDIS_STATUS_REQUEST_UPLOAD to the first
    NET_BUFFER_LIST structure in the linked list and NDIS_STATUS_UPLOAD_REQUESTED to all subsequent
    NET_BUFFER_LIST structures in the linked list. The intermediate driver must not propagate the
    NET_BUFFER_LIST structures to an underlying offload target. The host stack will perform the send
    operation.

* Specify the number of data bytes sent. The offload target does this by calling the
  [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro with an
  *id* of
  **TcpOffloadBytesTransferred**.
* Call the
  [NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) function for each NET_BUFFER structure that is associated with the
  NET_BUFFER_LIST structure. The
  *NetBuffer* parameter passed to the
  **NdisAdvanceNetBufferDataStart** function should point to the NET_BUFFER structure. The
  *DataOffsetDelta* parameter should specify the number of data bytes from the NET_BUFFER structure
  that were transmitted by the offload target and that were acknowledged by the remote host. The
  *FreeMdl* parameter is **NULL**.

## See also

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)