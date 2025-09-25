# W_TCP_OFFLOAD_SEND_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls the
*MiniportTcpOffloadSend* function to transmit data on an offloaded TCP connection.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The offload target provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MiniportOffloadContext` [in]

A pointer to a memory location that contains a PVOID value. This PVOID value references the
miniport offload context that contains the state object for the TCP connection on which the data is to
be transmitted. The offload target supplied this PVOID value when it offloaded the TCP connection state
object.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
Each NET_BUFFER_LIST structure in the list describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each NET_BUFFER structure
in the list maps to a chain of memory descriptor lists (MDLs). The MDLs contain the data to be
transmitted. The NET_BUFFER_LIST and associated structures are locked so that they remain resident in
physical memory. However, they are not mapped into system memory.

## Return value

NDIS_STATUS_PENDING is the only return value that is allowed. An offload target always completes a
send request asynchronously by calling
[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete).

## Remarks

An offload target must transmit data in first in, first out (FIFO) order. The order of the linked list
of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that NDIS passes
at
*NetBufferList* represents the order in which the offload target must transmit the network data. In
addition, an offload target should send the data that it receives from multiple calls to the
*MiniportTcpOffloadSend* in the order in which the data was posted.

An offload target must accept all send requests made to its
*MiniportTcpOffloadSend* function. If an offload target cannot complete a send request immediately,
the offload target must queue the request until it can complete it. The offload target should use the
**MiniportReserved** member of a NET_BUFFER_LIST structure to queue send requests. While a send request
is pending, the offload target retains ownership of the NET_BUFFER_LIST structures and all the resources
associated with the NET_BUFFER_LIST structures.

The host stack serializes send requests on a per connection basis. The stack will not issue a send
request on a connection while another send request on that connection is in progress. This ensures that
the offload target always receives the send requests in the correct order.

Note, however, that the host stack can call the
*MiniportTcpOffloadSend* function on a connection before the offload target has completed one or more
previous calls to the
*MiniportTcpOffloadSend* function on that same connection. Note also that the host stack can call an
offload target's
*MiniportTcpOffloadSend* function on one connection while one or more calls to the
*MiniportTcpOffloadSend* function are in progress on another connection.

The
*MiniportTcpOffloadSend* function must synchronize access to its internal queues of network data with
the offload target's other
*MiniportXxx* functions that access the same queues. An offload target can use spin locks to
synchronize access to the queues.

The offload target should (but is not required to) set the PSH bit on each NET_BUFFER_LIST boundary.
The recommended way of doing this is to set the PSH bit in the last segment created from the data
associated with each NET_BUFFER_LIST structure (that is, the data described by the NET_BUFFER structures
associated with the NET_BUFFER_LIST structure). Alternatively, the offload target can set the PSH bit in
the last remaining segment in the send queue before the send queue is emptied.

The host stack will not request the offload target to send urgent data.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete)