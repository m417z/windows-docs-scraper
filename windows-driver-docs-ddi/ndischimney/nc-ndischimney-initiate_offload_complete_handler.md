# INITIATE_OFFLOAD_COMPLETE_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol driver's or intermediate driver's *ProtocolInitiateOffloadComplete* function to complete an offload operation that the driver previously initiated by calling the [NdisInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisinitiateoffload) function.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area allocated by the protocol driver. The driver maintains the per binding context information in this context area. The driver supplied this handle to NDIS when the driver called the [NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `OffloadBlockList` [in]

A pointer to an [NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_protocol_offload_block_list) structure that can be a stand-alone structure or the root of a linked list of such structures. These structures identify the state that was offloaded or that was attempted to be offloaded.

## Remarks

In response to an underlying offload target's or intermediate driver's call to the [NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete) function, NDIS calls the overlying protocol's or intermediate driver's *ProtocolInitiateOffloadComplete* function.

An intermediate driver must propagate the completion of the initiate offload operation to the driver above it by calling **NdisMInitiateOffloadComplete**. For more information, see [Propagating the Completion of a State-Manipulation Operation](https://learn.microsoft.com/windows-hardware/drivers/network/propagating-the-completion-of-a-state-manipulation-operation).

From the NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST structure that was passed to its *ProtocolInitiateOffloadComplete* function, the intermediate driver constructs an [NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure.

For more information, see [Reusing an NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST Structure](https://learn.microsoft.com/windows-hardware/drivers/network/reusing-an-ndis-protocol-offload-block-list-structure). When calling the **NdisMInitiateOffloadComplete** function, the intermediate driver passes a pointer (the *OffloadBlockList* parameter) to this newly constructed NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure.

## See also

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_protocol_offload_block_list)

[NdisInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisinitiateoffload)

[NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)