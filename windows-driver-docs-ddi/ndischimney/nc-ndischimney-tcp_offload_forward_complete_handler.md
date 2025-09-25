# TCP_OFFLOAD_FORWARD_COMPLETE_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol or intermediate driver's
*ProtocolTcpOffloadForwardComplete* function to complete a forward operation that the driver previously
initiated by calling the
[NdisOffloadTcpForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpdisconnect) function.

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
**NdisOffloadTcpForward** function.

## Remarks

In response to an underlying driver's or offload target's call to the
**NdisOffloadTcpForwardComplete** function, NDIS calls the overlying protocol driver's or intermediate
driver's
*ProtocolTcpOffloadForwardComplete* function.

To propagate the completion of the forward operation to the overlying driver or host stack, the
intermediate driver calls the
**NdisOffloadTcpForwardComplete** function, passing in the following:

* A
  *ProtocolBindingContext*, which is a handle that uniquely identifies the intermediate driver.
* The PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadForwardComplete* function.

In response, NDIS calls the overlying driver's or host stack's
*ProtocolTcpOffloadForwardComplete* function, passing in a
*ProtocolBindingContext* handle and the PNET_BUFFER_LIST pointer supplied by the intermediate driver
to the
**NdisOffloadTcpForwardComplete** function.

## See also

[MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisOffloadTcpForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpforward)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_forward_complete)