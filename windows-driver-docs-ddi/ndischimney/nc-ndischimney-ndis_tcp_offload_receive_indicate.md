# NDIS_TCP_OFFLOAD_RECEIVE_INDICATE callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisTcpOffloadReceiveHandler** function to indicate that received network data is available for
consumption by a client application.

## Parameters

### `NdisOffloadHandle` [in]

A handle that identifies the offloaded TCP connection on which the indication is being made. When
the connection was offloaded, this handle was supplied in the
**NdisOffloadHandle** member of the
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure that was associated with the connection state.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Each
**NET_BUFFER_LIST** structure
describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each
**NET_BUFFER** structure in the list maps to a
chain of
[memory descriptor lists (MDLs)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl). The MDLs contain the
received data. The MDLs are locked so that they remain resident, but they are not mapped into system
memory.

The
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure
specified by
*NetBufferList* must be a stand-alone structure and cannot be the first
structure in a linked list of
**NET_BUFFER_LIST** structures.
Offload targets can work around this limitation by chaining as many MDLs as necessary to the same
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) in an offload receive
indication.

### `Status` [in]

The offload target must supply the following status value:

#### NDIS_STATUS_SUCCESS

This indicates that the host stack can retain ownership of the NET_BUFFER_LIST structures and
associated structures until it returns these structures to the
[MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler) function of the offload target.

### `BytesConsumed` [out]

A pointer to a ULONG-typed variable that receives the number of bytes that were consumed by the
client application.

## Return value

The
**NdisTcpOffloadReceiveHandler** function can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The client application consumed all the indicated receive data. |
| **NDIS_STATUS_OFFLOAD_DATA_NOT_ACCEPTED** | The client application rejected all the indicated receive data. |
| **NDIS_STATUS_OFFLOAD_DATA_PARTIALLY_ACCEPTED** | The client application consumed a subset of the indicated receive data. The amount of data, in bytes, that was consumed by the client application is returned in the variable specified by the *BytesConsumed* parameter. |

## Remarks

Receive buffers are posted to the
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function of the offload target. If preposted receive requests (buffers
supplied by the client application) are available for the connection, the offload target should transfer
the receive data by calling the
[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete) function. For more information, see
[Delivery Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/delivery-algorithm).

All receive requests must be completed by the offload target (even if they are zero-byte receive requests).

After an offload target has indicated receive data and that data has been refused, the offload target
cannot indicate that data again until the host stack posts a receive request:

* Normal receive requests

  If the host stack posts normal receive requests, the offload target must complete these requests
  before making any receive indications. For more information see
  [Delivery Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/delivery-algorithm).
* Zero-byte receive requests

  The host stack can post a zero-byte receive request to enable receive indications by the offload
  target. A zero-byte receive request is one in which the value of the
  **DataLength** member (for more information, see
  [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure) is zero. A
  zero-byte receive request does not consume any buffered data.

During initialization, the offload target should allocate two pools of buffers, each of which contains
NET_BUFFER_LIST structures and NET_BUFFER structures. The offload target uses one pool for making receive
indications through the TCP chimney when calling the
**NdisTcpOffloadReceiveHandler** function. The offload target uses the other pool for making receive
indications through the nonoffload NDIS interface when calling the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function.

Each allocated NET_BUFFER_LIST structure must have only one NET_BUFFER structure associated with it.
The number of such structures to allocate is up to the driver writer. For more information about
allocating such structures, see
[Miniport Driver Buffer
Management](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-driver-buffer-management).

Provided that it is not making a delayed acknowledgment, the offload target should acknowledge
received data as soon as the offload target has internal buffers into which it can deposit the data. The
offload target can acknowledge received data before, during, or after calling the
**NdisTcpOffloadReceiveHandler** function.

The offload target always supplies a
*Status* value of NDIS_STATUS_SUCCESS when calling the
**NdisTcpOffloadReceiveHandler** function. This indicates that the host stack can retain ownership of
the NET_BUFFER_LIST structures and associated structures until it returns these structures to the offload
target.

* If the host stack returns NDIS_STATUS_SUCCESS, indicating that the client application accepted and
  consumed the receive data, the host stack will return the NET_BUFFER_LIST structures to the
  [MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler) function of the offload target. The host stack will set the
  variable specified by the
  *BytesConsumed* parameter to the number of bytes that were indicated by the offload target.
* If the host stack returns NDIS_STATUS_NOT_ACCEPTED, indicating that the client application rejected
  the receive data, the offload target resumes ownership of the indicated NET_BUFFER_LIST structures on
  return of the
  **NdisTcpOffloadReceiveHandler** function. The offload target must buffer the receive data in
  anticipation that the client application will post receive buffers on the connection. After the client
  application posts receive buffers, the offload target copies the buffered receive data into the posted
  buffers and completes the posted buffers by calling the
  [NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete) function. For more information, see
  [Delivery Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/delivery-algorithm). The host stack will
  set the variable specified by the
  *BytesConsumed* parameter to zero.
* If the host stack returns NDIS_STATUS_OFFLOAD_DATA_PARTIALLY_ACCEPTED, indicating that the client
  application consumed a subset of the receive data, the offload target resumes ownership of the
  indicated NET_BUFFER_LIST structures when the
  **NdisTcpOffloadReceiveHandler** function returns. The host stack will set the variable specified by
  the
  *BytesConsumed* parameter to a non-zero value that specifies the amount of data, in bytes, that was
  consumed by the client application. The offload target must buffer the remaining receive data in
  anticipation that the client application will post the receive buffers on the connection.

Note that the offload target never supplies a
*Status* value of NDIS_STATUS_RESOURCES when calling the
**NdisTcpOffloadReceiveHandler** function.

In the
**RcvIndicationSize** member of the TCP_OFFLOAD_STATE_CACHED structure, the host stack can specify the
optimum number of data bytes that the offload target should supply in a single call to the
**NdisTcpOffloadReceiveHandler** function. For more information, see
[Using the Specified
Receive Indication Size](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate).

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler)

[MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)