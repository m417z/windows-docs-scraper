## Description

**DXGK_PHYSICAL_MEMORY_TYPE** indicates the type of physical memory being created by the driver in a call to [**DxgkCbCreatePhysicalMemoryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject).

## Constants

### `DXGK_PHYSICAL_MEMORY_TYPE_MDL`

Allocate nonpageable memory in the form of an MDL. This is functionally equivalent to calling [**MmAllocatePagesForMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl).

### `DXGK_PHYSICAL_MEMORY_TYPE_CONTIGUOUS_MEMORY`

Allocate contiguous nonpageable memory. This is functionally equivalent to calling [**MmAllocateContiguousMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatecontiguousmemory).

### `DXGK_PHYSICAL_MEMORY_TYPE_SECTION`

Allocate memory that can be mapped into one or more processes. This represents memory that would normally be allocated from [**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection).

### `DXGK_PHYSICAL_MEMORY_TYPE_IO_SPACE`

Wrap an existing IO-space range provided by the driver.

## Remarks

**DXGK_PHYSICAL_MEMORY_TYPE** is passed as a member of the [**DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_create_physical_memory_object) arguments.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_create_physical_memory_object)

[**DxgkCbCreatePhysicalMemoryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject)