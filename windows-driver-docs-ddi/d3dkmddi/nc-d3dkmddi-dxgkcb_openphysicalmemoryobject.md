## Description

A kernel-mode display miniport driver calls **DXGKCB_OPENPHYSICALMEMORYOBJECT** to open a physical memory object and associates it with an adapter.

## Parameters

### `pArgs` [in/out]

Pointer to a [**DXGKARGCB_OPEN_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_open_physical_memory_object) structure that contains information about the physical memory object to open.

## Return value

**DXGKCB_OPENPHYSICALMEMORYOBJECT** returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS error code.

## Remarks

In order to create an address descriptor list (ADL) from a physical memory object, it must first be associated with an adapter. This is normally done when the physical memory object is created by specifying the **hAdapter** parameter in a call to [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject). However, in some cases, the adapter handle is not available at the time the memory was allocated (for example, early in the boot process). In this case, the driver must call **DXGKCB_OPENPHYSICALMEMORYOBJECT** to associate the physical memory object with an adapter prior to calling [**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl).

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_OPEN_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_open_physical_memory_object) and then call **DxgkCbOpenPhysicalMemoryObject** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_OPEN_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_open_physical_memory_object)

[**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl)

[**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject)

[**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject)