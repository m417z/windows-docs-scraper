## Description

The **DXGKARGCB_CLOSE_PHYSICAL_MEMORY_OBJECT** structure contains the information used by the [**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject) callback function to close a physical memory object.

## Members

### `hAdapterMemoryObject`

The adapter memory object to close.

## Remarks

If the driver chooses to specify **hAdapterMemoryObject** as part of the [**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject) call, then it is not necessary to close it via **DXGKCB_CLOSEPHYSICALMEMORYOBJECT** as well.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject)

[**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject)

[**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject)