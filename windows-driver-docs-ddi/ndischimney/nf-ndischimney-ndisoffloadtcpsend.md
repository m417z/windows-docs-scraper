# NdisOffloadTcpSend function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

A protocol driver or intermediate driver calls the
**NdisOffloadTcpSend** function to transmit data on an offloaded TCP connection.

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
Each NET_BUFFER_LIST structure in the list describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each NET_BUFFER structure
in the list points to a chain of memory descriptor lists (MDLs). The MDLs contain the data to be
transmitted. The NET_BUFFER_LIST and associated structures are locked so that they remain resident in
physical memory. However, they are not mapped into system memory.

## Return value

The
**NdisOffloadTcpSend** function always returns NDIS_STATUS_PENDING. The send operation is always
completed asynchronously.

## Remarks

In response to a call to its
[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler) function,
an intermediate driver calls the
**NdisOffloadTcpSend** function to propagate the send operation to the underlying intermediate driver
or offload target. For more information, see
[Propagating I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/network/propagating-i-o-operations).

To the
**NdisOffloadTcpSend** function, the intermediate driver passes the following:

* An
  *NdisOffloadHandle* that references the NDIS_OFFLOAD_HANDLE structure stored in the intermediate
  driver's context for the offloaded TCP connection. For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The same PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *MiniportTcpOffloadSend* function.

When the underlying driver or offload target subsequently completes the send operation by calling the
**NdisTcpOffloadSendComplete** function, NDIS calls the intermediate driver's
*ProtocolOffloadSendComplete* function. The intermediate driver then calls the
**NdisTcpOffloadSendComplete** function to propagate the completion of the send operation.

## See also

[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler)

[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete)

[ProtocolTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_send_complete_handler)