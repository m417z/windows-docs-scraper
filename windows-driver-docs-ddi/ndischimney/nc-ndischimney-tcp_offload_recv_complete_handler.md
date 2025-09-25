# TCP_OFFLOAD_RECV_COMPLETE_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol or intermediate driver's
*ProtocolTcpOffloadReceiveComplete* function to complete a receive operation that the driver previously
initiated by calling the
[NdisOffloadTcpReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpreceive) function.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area allocated by the protocol driver. The driver maintains the per binding
context information in this context area. The driver supplied this handle to NDIS when the driver called
the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be stand-alone or the first structure in a linked list of NET_BUFFER_LIST structures. The driver
supplied this pointer as an input parameter in a previous call to the
[NdisOffloadTcpReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpreceive) function.

## Remarks

In response to an underlying driver's or offload target's call to the
[NdisOffloadTcpReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete) function, NDIS calls the overlying protocol driver's or intermediate
driver's
*ProtocolTcpOffloadReceiveComplete* function.

To propagate the completion of the I/O operation to the overlying driver, the intermediate driver
itself calls the
**NdisOffloadTcpReceiveComplete** function, passing in the following:

* A
  *ProtocolBindingContext*, which is a handle that uniquely identifies the intermediate driver.
* The PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadReceiveComplete* function.

In response, NDIS calls the overlying driver's
*ProtocolTcpOffloadReceiveComplete* function, passing a
*ProtocolBindingContext* handle and the PNET_BUFFER_LIST pointer supplied by the intermediate driver
to the
**NdisOffloadTcpReceiveComplete** function.

## See also

[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisOffloadTcpReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpreceive)

[NdisOffloadTcpReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)