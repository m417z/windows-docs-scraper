# W_TCP_OFFLOAD_DISCONNECT_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The
*MiniportTcpOffloadDisconnect* function closes the send half of an offloaded TCP connection. In
addition, if the disconnect to be performed is a graceful disconnect, NDIS can supply application data to
*MiniportTcpOffloadDisconnect* function that the function must transmit before sending a FIN
segment.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The offload target provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MiniportOffloadContext` [in]

A pointer to a memory location that contains a PVOID value. This PVOID value references the
miniport offload context that contains the state object for the TCP connection to be disconnected. The
offload target supplied this PVOID value when it offloaded the TCP connection state object.

### `NetBufferList` [in]

A pointer to a single
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Only one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure is associated with this
NET_BUFFER_LIST structure.

### `Flags` [in]

As one of the following values, the type of disconnect that the offload target must perform:

#### TCP_DISCONNECT_ABORTIVE_CLOSE

The offload target must perform an abortive disconnect by sending an RST segment.

#### TCP_DISCONNECT_GRACEFUL_CLOSE

The offload target must perform a graceful disconnect by sending a FIN segment.

## Return value

The
*MiniportTcpOffloadDisconnect* function always returns NDIS_STATUS_PENDING. The offload target
completes the disconnect request asynchronously by calling
[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete).

## Remarks

Depending on the
*Flags* setting, the
*MiniportTcpOffloadDisconnect* function performs an abortive disconnect or a graceful disconnect on
the specified TCP connection.

**Abortive Disconnect**

If
*Flags* is set to
**TCP_DISCONNECT_ABORTIVE_CLOSE**, the offload target performs an abortive disconnect by sending an
RST segment on the specified TCP connection.

**Note** This is the only instance in which an offload target can send an RST
segment.

Before calling the
[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete) function to complete the abortive disconnect, the offload target
must complete all outstanding send requests on the connection with a status value of
NDIS_STATUS_REQUEST_ABORTED. The offload target writes this status value to the
**Status** member of each NET_BUFFER_LIST structure in the linked list that it passes to the
[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete) function.

It does not matter whether the offload target terminates the outstanding send requests before or after
it sends the RST segment.

If there are outstanding receive indications or event indications on the connection, the offload
target must not wait for these indications to complete before sending an RST segment. The offload target
must immediately stop processing receive segments on the connection and not acknowledge any receive
segments, including indicated receive data that have not been consumed by the client application.

When
*Flags* =
**TCP_DISCONNECT_ABORTIVE_CLOSE**, the NET_BUFFER structure associated with the NET_BUFFER_LIST structure referenced by the
*NetBufferList* pointer contains no data. That is, the
**DataLength** member of the
[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) structure in the
**NetBufferHeader** of the NET_BUFFER structure is zero.

**Graceful Disconnect**

If
*Flags* is set to
**TCP_DISCONNECT_GRACEFUL_CLOSE**, the offload target performs a graceful disconnect by sending a FIN
segment on the specified TCP connection.

If there is no user data to be sent before the FIN segment, the NET_BUFFER structure associated with
the NET_BUFFER_LIST structure referenced by the
*NetBufferList* pointer contains no data. If there is user data to be sent, the memory descriptor
lists (MDLs) associated with the NET_BUFFER structure contain the user data to be sent.

The offload target should not wait for an acknowledgment of transmitted user data before sending a FIN
segment. The offload target can send a separate FIN segment after transmitting the user data, or the
offload target can set the FIN bit in the TCP header of the last segment of user data that it sends.

From the perspective of the offload target, sending a FIN segment closes the send half of the
connection. Sending a FIN segment, however, does not close the receive half of the connection. The remote
host terminates the receive half of the connection by sending either of the following to the offload
target:

* A FIN segment, which requests a graceful disconnect.
* An RST segment, which requests an abortive disconnect.

After sending a FIN segment, the offload target can receive segments on the connection until the
remote host initiates a graceful or abortive disconnect or until the local host terminates the offload of
the connection or initiates an abortive disconnect.

Before the offload target calls
[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete), it must complete all outstanding send requests on the connection
in the same order in which they were delivered to the offload target.

**Mandatory Response to a Disconnect Request**

An offload target must not fail a disconnect request unless the specified TCP connection is being
uploaded or is being aborted (for example, because the remote host sent an RST segment on the
connection). If an offload target fails a disconnect request, the host stack will not reissue the
disconnect request later.

**Freeing Connection Resources**

The offload target must not free resources for the connection on which it has issued either an
abortive or graceful disconnect until the host stack terminates the offload of the connection.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete)

[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete)