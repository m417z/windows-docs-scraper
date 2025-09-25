## Description

**DXGKCB_CREATEPHYSICALMEMORYOBJECT** creates physical memory for the driver.

## Parameters

### `pArgs` [in/out]

Pointer to a [**DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_create_physical_memory_object) structure that contains information about the physical memory to create.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS error code.

## Remarks

**DXGKCB_CREATEPHYSICALMEMORYOBJECT** and [**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject) create and destroy physical memory for the driver. Internally this memory can be represented in different forms, but will conform to the requirements and caching type specified in the arguments provided in [**DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_create_physical_memory_object).

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_create_physical_memory_object) and then call **DxgkCbCreatePhysicalMemoryObject** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_create_physical_memory_object)

[**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)