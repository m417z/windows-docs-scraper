# NdisOffloadTcpReceive function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

A protocol driver or an intermediate driver calls the
**NdisOffloadTcpReceive** function to post receive requests (receive buffers) on an offloaded TCP
connection.

## Parameters

### `NdisOffloadHandle` [in]

A handle to an
[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle) structure in the
caller's context for the offloaded TCP connection. For more information, see
[Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
Each NET_BUFFER_LIST structure in the list describes one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. The NET_BUFFER structure
points to a chain of memory descriptor lists (MDLs). The NET_BUFFER_LIST and associated structures are
locked so that they remain resident in physical memory. However, they are not mapped into system
memory.

## Return value

The
**NdisOffloadTcpReceive** function always returns NDIS_STATUS_PENDING. The receive operation is always
completed asynchronously.

## Remarks

In response to a call to its
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function, an intermediate driver calls the
**NdisOffloadTcpReceive** function to propagate the receive operation to the underlying intermediate
driver or offload target. For more information, see
[Propagating I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/network/propagating-i-o-operations).

To the
**NdisOffloadTcpReceive** function, the intermediate driver passes the following:

* An
  *NdisOffloadHandle* function that references the NDIS_OFFLOAD_HANDLE structure stored in the
  intermediate driver's context for the offloaded TCP connection. For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The same PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *MiniportTcpOffloadReceive* function.

When the underlying driver or offload target subsequently completes the receive operation by calling
the
**NdisTcpOffloadReceiveComplete** function, NDIS calls the intermediate driver's
*ProtocolOffloadReceiveComplete* function. The intermediate driver then calls the
**NdisTcpOffloadReceiveComplete** function to propagate the completion of the forward operation.

## See also

[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler)

[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete)

[ProtocolTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_recv_complete_handler)