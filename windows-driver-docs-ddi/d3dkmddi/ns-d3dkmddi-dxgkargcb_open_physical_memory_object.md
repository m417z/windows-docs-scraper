## Description

The **DXGKARGCB_OPEN_PHYSICAL_MEMORY_OBJECT** structure contains the information used by the [**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject) callback function to open a physical memory object.

## Members

### `hPhysicalMemoryObject` [in]

The physical memory object handle that was returned from a call to [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject).

### `hAdapter` [in]

A handle to any adapter that is part of the logical adapter to open the physical object against. This can be any physical adapter that is linked together in a linked display adapter (LDA) chain.

### `hAdapterMemoryObject` [out]

Field in which a handle to the opened physical memory object for this adapter is returned.

## Remarks

If the driver [creates a physical memory object](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject) and specifies a non-NULL value for *hAdapter* in that call, then it must not call **DxgkCbOpenPhysicalObject** again. Doing so will return a failure indicating that the physical object is already opened against the adapter.

At this time, a physical memory object may only be opened by a single adapter. Attempting to open the object on a second adapter will fail.

Opening a physical memory object against one physical adapter is sufficient. This guarantees that all physical adapters in the logical adapter (all linked adapters) have a mirrored view of this memory.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject)

[**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject)