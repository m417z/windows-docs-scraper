## Description

The **DXGKARGCB_DESTROY_PHYSICAL_MEMORY_OBJECT** structure contains the information used by the [**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject) callback function to destroy physical memory.

## Members

### `hPhysicalMemoryObject` [in]

Handle to the physical memory object created via [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject) to destroy.

### `hAdapterMemoryObject` [in]

Optional handle to an adapter memory object to close at the same time. This handle is provided for the purpose of creating a convenient mirror mapping with destroy. If **hAdapterMemoryObject** is not NULL, the driver must not also call [**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject).

## Remarks

If the driver attempts to destroy a physical object that still has an existing ADL created against it, the call will bugcheck the machine since the driver is leaking locked pages.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject)

[**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject)

[**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject)