## Description

**DXGKARGCB_ALLOCATE_ADL** contains the information used by the [**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl) callback function to create an address descriptor list (ADL).

## Members

### `hAdapterMemoryObject` [in]

The adapter memory object that describes the underlying logical memory used to build the ADL. This object was created via [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject) or later opened via [**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject).

### `Offset` [in]

The offset, in bytes, from the start of the physical memory object. This value must be a multiple of PAGE_SIZE.

### `Size` [in]

The total number of bytes to allocate for the ADL. This value must be a multiple of PAGE_SIZE, such that the number of pages in the ADL will be **Size**/PAGE_SIZE.

### `Flags`

### `Flags.RequireContiguous` [in]

Indicates that the driver is requesting an ADL that describes a contiguous range of memory, instead of scattered pages. This flag is only valid if the physical memory object represented by *hAdapterMemoryObject* was allocated as **DXGK_PHYSICAL_MEMORY_TYPE_CONTIGUOUS_MEMORY** or **DXGK_PHYSICAL_MEMORY_TYPE_IO_SPACE**.

### `Flags.PreferContiguous` [in]

Provides the driver with a way to optimally request a contiguous ADL when possible. When DMA remapping is enabled, ADLs will refer to ranges of logical address space; however, drivers might not be able to use contiguous ADLs in all code paths. Non-contiguous ADLs for logical memory can become costly since they require allocation of a separate PFN array, similar to an MDL, to represent the memory. When possible, the driver should specify this flag to indicate that an ADL can be represented with just the base address.

### `Flags.Reserved` [in]

Reserved; must be set to zero.

### `Flags.Value` [in]

An alternative way to access the bits.

### `pAdl` [out]

On a successful call to [**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl), points to the [**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl) structure with a list of page addresses that can be used to program the hardware.

## Remarks

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl)

[**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject)

[**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject)