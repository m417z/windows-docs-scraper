# NDIS_TCP_OFFLOAD_RECEIVE_COMPLETE callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisTcpOffloadReceiveComplete** function to return posted receive requests (receive buffers) to the
host stack. The offload target previously received the receive requests in one or more calls to its
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be stand-alone or the first structure in a linked list of NET_BUFFER_LIST structures. The offload
target obtained these structures in one or more calls to its
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function.

## Remarks

An offload target should use and return preposted receive requests in the order in which the requests
were posted to the
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function of the offload target. That is, the offload target should use
and return preposted receive requests in first in, first out (FIFO) order.

An offload target must serialize calls to the
**NdisTcpOffloadReceiveComplete** function and to the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function on a per -connection basis.

An offload target's
*MiniportTcpOffloadReceive* function can be called in the context of an offload target's call to the
**NdisTcpOffloadReceiveComplete** function. In this case, an offload target must not call the
**NdisTcpOffloadReceiveComplete** function again until the previous call to
**NdisTcpOffloadReceiveComplete** has returned.

To improve system performance, an offload target can create a linked list that contains the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures from multiple
calls to its
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function. The offload target can pass such a linked list in a single call
to the
**NdisTcpOffloadReceiveComplete** function. Note that, an offload target can distribute the receive
requests that were posted in a single call to the
*MiniportTcpOffloadReceive* function across more than one completion call as long the offload target
completes the receive requests in the same order that they were posted to the
*MiniportTcpOffloadReceive* function.

Before calling the
**NdisTcpOffloadReceiveComplete** function, the offload target does the following for each
NET_BUFFER_LIST structure that it passes to the function:

* Writes one of the following status values to the
  **Status** member:

  NDIS_STATUS_SUCCESS

  The offload target received all the data associated with the NET_BUFFER_LIST structures that are
  referenced by the
  *NetBufferList* parameter. The offload target also advanced the
  *RcvNxt* and
  *RcvWnd* variables in the TCP delegated state for the TCP connection. The offload target might or
  might not have generated an acknowledgment for the received data, depending on whether the offload
  target is waiting to send a delayed acknowledgment.

  NDIS_STATUS_REQUEST_ABORTED

  An error occurred while the offload target was processing the received data. If the offload
  target is supplying some valid data with the NET_BUFFER_LIST structures that are pointed to by the
  *NetBufferList* parameter, the offload target specifies the number of valid data bytes by calling
  the
  [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro. The
  offload target might or might not have acknowledged some portion of the received data.

  NDIS_STATUS_UPLOAD_IN_PROGRESS

  The connection on which the buffer was posted is being uploaded.

  NDIS_STATUS_INVALID_STATE

  The receive request was posted after the offload target indicated a disconnect by calling
  [NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate).

* Specifies the number of data bytes returned by calling the
  [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro with an
  *id* of
  **TcpOffloadBytesTransferred**.
* Calls the
  [NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) function. The
  *NetBufferList* parameter should point to the NET_BUFFER structure that is associated with the
  NET_BUFFER_LIST structure. The
  *DataOffsetDelta* parameter should specify the number of data bytes that the offload target placed
  in the memory descriptor lists (MDLs) associated with the NET_BUFFER structure. The
  *FreeMdl* parameter should be **NULL**.

## See also

[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)