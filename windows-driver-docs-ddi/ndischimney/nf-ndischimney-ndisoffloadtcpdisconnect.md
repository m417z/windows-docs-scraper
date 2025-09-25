# NdisOffloadTcpDisconnect function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

A protocol or intermediate driver calls the
**NdisOffloadTcpDisconnect** function to close the send half of an offloaded TCP connection. In addition,
if the disconnect to be performed is a graceful disconnect, the protocol or intermediate driver can supply
application data that the underlying offload target must transmit on the offloaded TCP connection before it
sends a FIN segment.

## Parameters

### `NdisOffloadHandle` [in]

A pointer to an
[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle) structure in the
caller's context for the offloaded TCP connection. For more information, see
[Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).

### `NetBufferList` [in]

A pointer to a single
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Only one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure is associated with this
NET_BUFFER_LIST structure.

### `Flags` [in]

As one of the following values, the type of disconnect to be performed:

#### TCP_DISCONNECT_ABORTIVE_CLOSE

Specifies that the offload target perform an abortive disconnect by sending an RST
segment.

#### TCP_DISCONNECT_GRACEFUL_CLOSE

Specifies that the offload target perform a graceful disconnect by sending a FIN segment.

## Return value

The
**NdisOffloadTcpDisconnect** function always returns NDIS_STATUS_PENDING. The disconnect operation is
always completed asynchronously.

## Remarks

In response to a call to its
[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler) function, an intermediate driver calls the
**NdisOffloadTcpDisconnect** function to propagate the disconnect operation to the underlying
intermediate driver or offload target. For more information, see
[Propagating I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/network/propagating-i-o-operations).

To the
**NdisOffloadTcp*Xxx***
function, the intermediate driver passes the following:

* An
  *NdisOffloadHandle* function that references the NDIS_OFFLOAD_HANDLE structure stored in the
  intermediate driver's context for the offloaded TCP connection. For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The same PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *MiniportTcpOffloadDisconnect* function.
* The same
  *Flags* that NDIS passed to the intermediate driver's
  *MiniportTcpOffloadDisconnect* function.

When the underlying driver or offload target subsequently completes the disconnect operation by
calling the
**NdisTcpOffloadDisconnectComplete** function, NDIS calls the intermediate driver's
*ProtocolOffloadDisconnectComplete* function. The intermediate driver then calls the
**NdisTcpOffloadDisconnectComplete** function to propagate the completion of the disconnect
operation.

## See also

[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler)

[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete)

[ProtocolTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_disconnect_complete_handler)