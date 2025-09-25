# NdisMRegisterScatterGatherDma function

## Description

> [!CAUTION]
> For ARM and ARM64 processors, we strongly recommend that NDIS driver writers use WDF DMA or WDM DMA instead of NDIS Scatter/Gather DMA.
>
> For more information about WDF DMA, see [Handling DMA Operations in KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-dma-operations-in-kmdf-drivers).
>
> For more information about WDM DMA, see the DMA-related child topics of [Managing Input/Output for Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-input-output-for-drivers).

Bus master miniport drivers call the
**NdisMRegisterScatterGatherDma** function from
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) to initialize a
scatter/gather DMA channel.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport handle that NDIS passed to
*MiniportInitializeEx*.

### `DmaDescription` [in, out]

A pointer to an NDIS_SG_DMA_DESCRIPTION structure. This structure describes the scatter/gather DMA
properties of the miniport driver. The structure is defined as follows:

```
typedef struct _NDIS_SG_DMA_DESCRIPTION {
  NDIS_OBJECT_HEADER  Header;
  ULONG  Flags;
  ULONG  MaximumPhysicalMapping;
  MINIPORT_PROCESS_SG_LIST_HANDLER  ProcessSGListHandler;
  MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE_HANDLER  SharedMemAllocateCompleteHandler;
  ULONG  ScatterGatherListSize;
} NDIS_SG_DMA_DESCRIPTION, *PNDIS_SG_DMA_DESCRIPTION;

```

This structure includes the following members:

#### Header

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_SG_DMA_DESCRIPTION structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_SG_DMA_DESCRIPTION, the
**Revision** member to NDIS_SG_DMA_DESCRIPTION_REVISION_1, and the
**Size** member to NDIS_SIZEOF_SG_DMA_DESCRIPTION_REVISION_1.

#### Flags

A set of bit flags that define scatter/gather characteristics. Set this member to the bitwise OR
of all the required flags.

The NDIS_SG_DMA_64_BIT_ADDRESS flag specifies that the NIC can use 64-bit addressing for DMA
operations. Otherwise, the NIC uses 32-bit addressing.

Set this member to zero if 64-bit addressing is not required.

#### MaximumPhysicalMapping

The maximum number of bytes that the NIC can transfer in a single DMA operation. NDIS provides
this value to the hardware abstraction layer (HAL) when allocating a DMA channel, and HAL uses this
value to determine the maximum number of map registers to reserve for the NIC.

#### ProcessSGListHandler

The
[MiniportProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_process_sg_list) function
that NDIS calls when HAL is done building the scatter/gather list.

#### SharedMemAllocateCompleteHandler

The
[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete) function for miniport drivers that call
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex). This field is optional and it should be **NULL** if the miniport
driver does not call
**NdisMAllocateSharedMemoryAsyncEx**.

#### ScatterGatherListSize

The size, in bytes, of the memory that is required to hold a scatter/gather list. NDIS sets this
value before it returns from
**NdisMRegisterScatterGatherDma**. Miniport drivers should use this size to preallocate memory for
each scatter/gather list.

### `NdisMiniportDmaHandle` [out]

A pointer to a variable that the caller supplies and that NDIS fills with a handle. The handle
identifies a context area that NDIS uses to manage this DMA resource. The miniport driver passes this
handle to NDIS in subsequent calls to NDIS that involve this DMA resource.

## Return value

**NdisMRegisterScatterGatherDma** returns one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisMRegisterScatterGatherDma** successfully allocated resources for bus-master DMA operations. |
| **NDIS_STATUS_RESOURCES** | **NdisMRegisterScatterGatherDma** failed due to insufficient resources. |
| **NDIS_STATUS_NOT_SUPPORTED** | **NdisMRegisterScatterGatherDma** failed because the miniport did not specify that it supports NDIS 6.0 or later versions, or because the miniport driver did not specify that its NIC is a bus-master DMA device. A miniport driver specifies its NDIS version when it calls [NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver). A miniport driver specifies that it supports bus-master DMA devices when it calls [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes). |
| **NDIS_STATUS_BAD_VERSION** | The current version of NDIS does not support the version specified in the **Revision** member of the **Header** structure of *DmaDescription* . |

## Remarks

An NDIS bus-master miniport driver calls
**NdisMRegisterScatterGatherDma** within its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function to
initialize resources for scatter/gather DMA operations. The
*DmaDescription* parameter that the miniport driver passes to
**NdisMRegisterScatterGatherDma** contains the information that NDIS uses to initialize the
scatter/gather DMA resources. After
**NdisMRegisterScatterGatherDma** returns, the
**ScatterGatherListSize** member of
*DmaDescription* contains a buffer size that should be sufficient to hold a scatter/gather list.
Miniport drivers should use this size to preallocate the memory for scatter/gather lists.

The
**ProcessSGListHandler** member in the
*DmaDescription* parameter defines the entry point in the miniport driver for the
[MiniportProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_process_sg_list) function.
When a miniport driver calls
[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist), NDIS calls HAL to provide the scatter/gather list to the miniport
driver. HAL calls
*MiniportProcessSGList* after HAL finishes building the scatter/gather list. NDIS can call
*MiniportProcessSGList* outside the context of the call to
**NdisMAllocateNetBufferSGList**.

**NdisMRegisterScatterGatherDma** returns a pointer to a context area that is opaque to the miniport
driver. The miniport driver must use this handle in subsequent calls to NDIS scatter/gather DMA
functions.

Bus-master miniport drivers call
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) to dynamically allocate shared memory for data transfer
operations. This call is required when high network traffic causes the miniport driver to run low on the
shared memory space that the driver allocated during initialization. If
**NdisMAllocateSharedMemoryAsyncEx** returns NDIS_STATUS_PENDING, NDIS calls the
[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete) function to complete the operation at a later time. Miniport
drivers specify the entry point for the
*MiniportSharedMemoryAllocateComplete* function in the
**SharedMemAllocateCompleteHandler** member of the
*DmaDescription* parameter.

Miniport drivers call the
[NdisMDeregisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterscattergatherdma) function to deallocate the DMA resources that
**NdisMRegisterScatterGatherDma** allocated.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_process_sg_list)

[MiniportSharedMemoryAllocateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_allocate_shared_mem_complete)

[NDIS Scatter/Gather DMA](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-scatter-gather-dma)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist)

[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex)

[NdisMDeregisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterscattergatherdma)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)