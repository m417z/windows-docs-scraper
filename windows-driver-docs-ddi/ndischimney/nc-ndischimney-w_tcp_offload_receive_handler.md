# W_TCP_OFFLOAD_RECEIVE_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls the
*MiniportTcpOffloadReceive* function to post receive requests (receive buffers) on an offloaded TCP
connection.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The miniport driver provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MiniportOffloadContext` [in]

A pointer to a memory location that contains a PVOID value. This PVOID value references the
miniport offload context that contains the state object for the TCP connection on which the receive
requests are being posted. The offload target supplied this PVOID value when it offloaded the TCP
connection state object.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
Each NET_BUFFER_LIST structure in the list describes one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. The NET_BUFFER structure
maps to a chain of memory descriptor lists (MDLs). The NET_BUFFER_LIST and associated structures are
locked so that they remain resident in physical memory. However, they are not mapped into system
memory.

## Return value

NDIS_STATUS_PENDING is the only return value that is allowed. An offload target always completes
(returns) posted receive requests asynchronously by calling
[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete).

## Remarks

A client application can post receive requests on an offloaded TCP connection. The offload target uses
these requests to transfer data received on the connection to the client application. If receive requests
are posted on a connection, the offload target should always use them to transfer data that is received
on the connection. For more information, see
[Delivery Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/delivery-algorithm).

The offload target queues the posted NET_BUFFER_LIST structures in first in, first out (FIFO) order.
The offload target uses the
**MiniportReserved** member of each NET_BUFFER_LIST structure to queue the structure.

Each NET_BUFFER_LIST structure passed to the
*MiniportTcpOffloadReceive* function has only one NET_BUFFER structure associated with it.

The offload target should place receive data into the posted receive requests in FIFO order. That is,
data that was received first should be placed into the first posted receive request, and so on.

The host stack serializes calls to the
*MiniportTcpOffloadReceive* function on a per-connection basis. The host stack will not call the
*MiniportTcpOffloadReceive* function on a connection while a call to the
*MiniportTcpOffloadReceive* function on that connection is in progress. This ensures that receive
requests are always posted in the correct order to an offload target's
*MiniportTcpOffloadReceive* function.

Note, however, that the host stack can call the
*MiniportTcpOffloadReceive* function on a connection before the offload target has completed one or
more previous calls to the
*MiniportTcpOffloadReceive* function on that same connection. Note also that the host stack can call
an offload target's
*MiniportTcpOffloadReceive* function on one connection while one or more calls to the
*MiniportTcpOffloadReceive* function are in progress on another connection.

A posted receive request can optionally be in either of two modes:

* Push mode
* Nonpush mode

Note that an offload target must support both push mode and nonpush mode. .

To determine which mode a buffer is in, an offload target calls the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro to get the
value of
**TcpReceiveNoPush**. If the value is **TRUE**, the receive request is in nonpush mode.

If the receive request is in push mode, the offload target retrieves the value of
**TcpReceiveBytesTransferred** by calling the NET_BUFFER_LIST_INFO macro. If this value is non-zero,
the offload target immediately starts the
[push timer](https://learn.microsoft.com/windows-hardware/drivers/network/push-timer) for the connection. If this value is
zero, the offload target starts the push timer for the connection as soon as the offload target places
the first byte of receive data into the receive request. The offload target always completes filled
receive requests immediately. The offload target completes a partially filled receive request that is in
push mode if either of the following occurs:

* The push timer expires.
* The offload target receives a TCP segment on the connection that has the PSH bit set.

If the receive request is in nonpush mode, the offload target does not start a push timer. The offload
target completes the receive request only when the receive request is filled. The offload target ignores
the PSH bit in TCP segments that it receives on the connection.

If data is received on an offloaded connection while the push timer is running, the offload target
must restart the push timer for that connection.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete)