# NdisOffloadTcpReceiveReturn function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

A protocol driver or intermediate driver calls the
**NdisOffloadTcpReceiveReturn** function to return ownership of NET_BUFFER_LIST and associated structures
to an underlying offload target.

## Parameters

### `NdisBindingHandle` [in]

The handle that NDIS provided at the
*NdisBindingHandle* parameter of the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. This handle
identifies the binding between the caller and the underlying intermediate driver or offload
target.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
The linked list can contain NET_BUFFER_LIST structures from one or more calls to the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function.

## Remarks

In response to a call to its
[MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler) function, an intermediate driver calls the
**NdisOffloadTcpReceiveReturn** function to propagate the receive return operation to the underlying
intermediate driver or offload target. For more information, see
[Propagating I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/network/propagating-i-o-operations).

To the
**NdisOffloadTcpReceiveReturn** function, the intermediate driver passes the following:

* An
  *NdisOffloadHandle* function that references the NDIS_OFFLOAD_HANDLE structure stored in the
  intermediate driver's context for the offloaded TCP connection. For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The same PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *MiniportTcpOffloadReceiveReturn* function.

## See also

[MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler)

[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate)