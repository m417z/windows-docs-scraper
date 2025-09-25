# NdisOffloadTcpForward function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

A protocol driver or an intermediate driver calls the
**NdisOffloadTcpForward** function to forward unacknowledged received TCP segments to an underlying
driver or offload target.

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
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. Each NET_BUFFER structure
points to a chain of memory descriptor lists (MDLs). The MDLs associated with a NET_BUFFER structure
contain one and only one TCP segment that is being forwarded to the offload target. The first byte of
the first MDL is the first byte of the TCP header. The NET_BUFFER_LIST and associated structures are
locked so that they remain resident in physical memory. However, they are not mapped into system
memory.

## Return value

The
**NdisOffloadTcpForward** function always returns NDIS_STATUS_PENDING. The forward operation is always
completed asynchronously.

## Remarks

In response to a call to its
*MiniportTcpOffloadForward* function, an intermediate driver calls the
**NdisOffloadTcpForward** function to propagate the forward operation to the underlying driver or
offload target. For more information, see
[Propagating I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/network/propagating-i-o-operations).

To the
**NdisOffloadTcpForward** function, the intermediate driver passes the following:

* An
  *NdisOffloadHandle* function that references the NDIS_OFFLOAD_HANDLE structure stored in the
  intermediate driver's context for the offloaded TCP connection. For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The same PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  [MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler) function.

When the underlying driver or offload target subsequently completes the forward operation by calling
the
**NdisTcpOffloadForwardComplete** function, NDIS calls the intermediate driver's
*ProtocolOffloadForwardComplete* function. The intermediate driver then calls the
**NdisTcpOffloadForwardComplete** function to propagate the completion of the forward operation.

## See also

[MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler)

[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_forward_complete)

[ProtocolTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_forward_complete_handler)