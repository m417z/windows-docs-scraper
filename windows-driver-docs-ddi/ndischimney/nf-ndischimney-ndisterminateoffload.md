# NdisTerminateOffload function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

A protocol driver or intermediate driver calls the
**NdisTerminateOffload** function to terminate the offload of one or more state objects

## Parameters

### `NdisBindingHandle` [in]

The handle that NDIS provided at the
*NdisBindingHandle* parameter of
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex). This handle
identifies the binding between the caller and the underlying intermediate driver or offload
target.

### `OffloadBlockList` [in, out]

A pointer to an
[NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_protocol_offload_block_list) structure that can be a stand-alone structure or the root of a
linked list of such structures. These structures identify the offloaded state objects that are being
terminated.

## Remarks

An intermediate driver calls the
**NdisTerminateOffload** function to propagate a terminate offload operation that was initiated by the
host stack. For more information, see
[Propagating
State-Manipulation Operations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisqueryoffloadstate).

From the
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure that was passed to its
*MiniportTerminateOffload* function, the intermediate driver constructs an
NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST structure. For more information, see
[Reusing an
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST Structure](https://learn.microsoft.com/windows-hardware/drivers/network/reusing-an-ndis-miniport-offload-block-list-structure). The intermediate driver passes a pointer (the
*OffloadBlockList* parameter) to this NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST structure when calling the
**NdisTerminateOffload** function.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_protocol_offload_block_list)

[NdisMTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismterminateoffloadcomplete)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-terminate_offload_complete_handler)