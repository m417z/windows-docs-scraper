# NdisMAllocateNetBufferSGList function

## Description

> [!CAUTION]
> For ARM and ARM64 processors, we strongly recommend that NDIS driver writers use WDF DMA or WDM DMA instead of NDIS Scatter/Gather DMA.
>
> For more information about WDF DMA, see [Handling DMA Operations in KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-dma-operations-in-kmdf-drivers).
>
> For more information about WDM DMA, see the DMA-related child topics of [Managing Input/Output for Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-input-output-for-drivers).

Bus-master miniport drivers call the
**NdisMAllocateNetBufferSGList** function to obtain a scatter/gather list for the network data that is
associated with a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Parameters

### `NdisMiniportDmaHandle` [in]

A handle to a context area that NDIS uses to manage a DMA resource. The caller obtained this
handle by calling the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function.

### `NetBuffer` [in]

A pointer to a NET_BUFFER structure.
**NdisMAllocateNetBufferSGList** allocates a scatter/gather list for the network data that is
associated with this NET_BUFFER structure. The scatter/gather list is generated from the data starting
at the beginning of the MDL that is specified at the
**CurrentMdl** member of the associated
[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) structure.

### `Context` [in]

A pointer to a context area that the caller created. HAL passes this pointer to
[MiniportProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_process_sg_list) after HAL
creates the scatter/gather list. The caller can use this context area for its own purposes.

### `Flags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to
zero. This function supports the NDIS_SG_LIST_WRITE_TO_DEVICE flag which; if set, indicates the
direction of the DMA transfer is from the NET_BUFFER to the device. If NDIS_SG_LIST_WRITE_TO_DEVICE is
clear, the transfer is from the device. Miniport drivers should set this flag on the send path when DMA
operation transfers data from a NET_BUFFER to the device. Miniport drivers that perform DMA operations
from the device to a pre-allocated NET_BUFFER, for example chimney offload capable NICs during receive
operations, should clear this flag.

### `ScatterGatherListBuffer` [in, optional]

If not **NULL**,
*ScatterGatherListBuffer* specifies a pointer to storage that the caller allocates to hold the
scatter/gather list. If **NULL**, NDIS allocates storage for the scatter/gather list.

### `ScatterGatherListBufferSize` [in]

If the
*ScatterGatherListBuffer* parameter is not **NULL**,
*ScatterGatherListBufferSize* specifies the size of the buffer that contains the scatter/gather
list. If this size is too small, NDIS allocates storage for the scatter/gather list. If the
*ScatterGatherListBuffer* parameter is **NULL**, this parameter is not used.

## Return value

**NdisMAllocateNetBufferSGList** returns one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisMAllocateNetBufferSGList** successfully built the scatter/gather list for the specified NET_BUFFER structure. |
| **NDIS_STATUS_RESOURCES** | **NdisMAllocateNetBufferSGList** failed due to insufficient resources. |

## Remarks

An NDIS bus-master miniport driver calls
**NdisMAllocateNetBufferSGList** from its
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function. The miniport driver calls
**NdisMAllocateNetBufferSGList** once for each
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure for which it must obtain a
scatter/gather list.

When a miniport driver calls
**NdisMAllocateNetBufferSGList**, NDIS calls HAL to build the scatter/gather list. After HAL builds
the scatter/gather list, it calls the
*MiniportProcessSGList* function that the miniport driver registered by calling
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma).

HAL can call
*MiniportProcessSGList* before or after NDIS returns from
**NdisMAllocateNetBufferSGList**. Miniport drivers must not attempt to access the scatter/gather list
until after HAL calls
*MiniportProcessSGList*.

To improve system performance, miniport drivers should preallocate buffers for the use in the
*ScatterGatherListBuffer* parameter of
**NdisMAllocateNetBufferSGList**. NDIS provides the recommended size for the buffers in the
**ScatterGatherListSize** member of the
*DmaDescription* parameter when the miniport driver calls
**NdisMRegisterScatterGatherDma**. Miniport drivers specify the size of the buffer in the
*ScatterGatherListBufferSize* parameter when they call
**NdisMAllocateNetBufferSGList**.

NDIS might allocate a buffer even if the miniport driver specifies a buffer in the
*ScatterGatherListBuffer* parameter. This can happen if the specified buffer is too small to hold the
scatter/gather list. Therefore, driver writers must not assume that the buffer specified in the
*ScatterGatherListBuffer* parameter contains the scatter/gather list. HAL passes the correct
scatter/gather list pointer to the miniport driver's
*MiniportProcessSGList* function.

To improve system performance, the scatter/gather list is generated from the network data starting at
the beginning of the MDL that is specified at the
**CurrentMdl** member of the associated
[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) structure. The start of the
network data in the SG list is offset from the beginning of the SG list by the value specified in the
**CurrentMdlOffset** member of the associated NET_BUFFER_DATA structure.

Miniport drivers must call the
[NdisMFreeNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreenetbuffersglist) function
to free a scatter/gather list.

## See also

[MiniportProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_process_sg_list)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[NDIS Scatter/Gather DMA](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-scatter-gather-dma)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data)

[NdisMFreeNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreenetbuffersglist)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)