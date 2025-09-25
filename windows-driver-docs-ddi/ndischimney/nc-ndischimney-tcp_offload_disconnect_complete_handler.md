# TCP_OFFLOAD_DISCONNECT_COMPLETE_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol driver's or intermediate driver's
*ProtocolTcpOffloadDisconnectComplete* function to complete a disconnect operation that the driver
previously initiated by calling the
[NdisOffloadTcpDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpdisconnect) function.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area allocated by the protocol driver. The driver maintains the per binding
context information in this context area. The driver supplied this handle to NDIS when the driver called
the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `NetBufferList` [in]

When non-NULL, a pointer to a single
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. The driver
supplied this pointer as an input parameter in a previous call to the
[NdisOffloadTcpDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpdisconnect) function.

## Remarks

In response to an underlying driver's or offload target's call to the
[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete) function, NDIS calls the overlying protocol driver's or
intermediate driver's
*ProtocolTcpOffloadDisconnectComplete* function.

To propagate the completion of the disconnect operation to the overlying driver, the intermediate
driver calls the
**NdisOffloadTcpDisconnectComplete** function, passing in the following:

* A
  *ProtocolBindingContext*, which is a handle that uniquely identifies the intermediate driver.
* The same PNET_BUFFER_LIST pointer that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadDisconnectComplete* function.

In response, NDIS calls the overlying driver's
*ProtocolTcpOffloadDisconnectComplete* function, passing a
*ProtocolBindingContext* handle and the PNET_BUFFER_LIST pointer passed by the intermediate driver to
the
**NdisOffloadTcpDisconnectComplete** function.

Before returning, the
*ProtocolTcpOffloadDisconnectComplete* function should deallocate the memory for any context that it
created for the NET_BUFFER_LIST structure that was passed to the function.

Note that, if an intermediate driver exports more than one interface to overlying protocols, it must
determine which protocol should receive the completion of the disconnect. To make this determination, the
intermediate driver uses information that it stored in the
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure, which is associated with the NET_BUFFER_LIST structure.

## See also

[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisOffloadTcpDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpdisconnect)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete)