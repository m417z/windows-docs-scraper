## Description

The **DXGKARGCB_MAP_PHYSICAL_MEMORY** structure contains the information used by the [**DXGKCB_MAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory) callback function to map a CPU-visible virtual address to the underlying physical memory.

## Members

### `hPhysicalMemoryObject` [in]

The physical memory object that describes the underlying physical pages to be mapped. This object was created in a prior call to [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject).

### `AccessMode` [in]

A [**DXGK_ACCESS_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_access_mode) enum value that describes the access mode (user mode or kernel mode) for which the mapping should be made.

### `Offset` [in/out]

As an input, specifies the offset from the start of the physical memory object, in bytes. As an output, specifies the offset from the start of the mapped base address where the requested data resides, in bytes. See Remarks for more information.

### `Size` [in]

As an input, specifies the requested size of the mapped region, in bytes. As an output, specifies the actual mapped size, in bytes. See Remarks for more information.

### `pMappedAddress` [out]

On a successful call to [**DXGKCB_MAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory), this is a pointer to the underlying physical memory mapping. The start of the mapped memory range might not be exactly equal to the offset requested by the driver if rounding or alignment was required. As a result, the output value of **Offset** refers to the offset from the base address to the data requested by the driver. That is, ActualAddress = BaseAddress + Offset.

## Remarks

**Offset** and **Size** are both input and output parameters. As an input, these describe the region of physical memory that is requested by the caller. On output, these describe the actual mapped view. This is because the address that is mapped to the corresponding physical memory may not be exactly at the requested offset. The actual data requested by the caller will be equal to **pMappedAddress** + **Offset**. The size of the virtual address range that was mapped will be the output value of **Size**, which may be larger than the requested size.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGK_ACCESS_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_access_mode)

[**DXGKCB_MAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory)