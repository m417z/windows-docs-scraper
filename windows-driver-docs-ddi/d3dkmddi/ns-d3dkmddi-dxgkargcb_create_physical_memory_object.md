## Description

The **DXGKARGCB_CREATE_PHYSICAL_MEMORY_OBJECT** structure contains the information used by the [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject) callback function to create physical memory.

## Members

### `hAdapter`

The adapter for which this physical memory will be associated. This parameter is optional and can be NULL. If it is NULL, the driver must call [**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject) before creating an address descriptor list (ADL). See Remarks for more information.

### `Size`

The size, in bytes, of the physical memory being requested. If **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_IO_SPACE**, **Size** refers to the size of the IO space region provided by the driver.

### `Context`

A pointer-size piece of context data that *Dxgkrnl* will store alongside the physical memory object for debugging purposes. This value is never directly used or dereferenced by *Dxgkrnl* in any way. This may be any value of the driver's choosing, such as the memory address to a driver-owned object that owns this physical memory object.

### `Type`

A [**DXGK_PHYSICAL_MEMORY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_physical_memory_type) value that specifies the type of physical memory to create. If **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**, then the allocation attributes of the section object are always SEC_COMMIT (PF-mapped section), and the cache type is determines by **CacheType**.

### `CacheType`

The cache type of the pages. If **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**, **CacheType** must be either cached, or write-combined.

### `Mdl`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_MDL**.

### `Mdl.LowAddress`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_MDL**. See [**MmAllocatePagesForMdlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex) for details.

### `Mdl.HighAddress`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_MDL**. See [**MmAllocatePagesForMdlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex) for details.

### `Mdl.SkipBytes`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_MDL**. See [**MmAllocatePagesForMdlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex) for details.

### `Mdl.Flags`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_MDL**. See [**MmAllocatePagesForMdlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex) for details.

### `ContiguousMemory`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_CONTIGUOUS_MEMORY**.

### `ContiguousMemory.LowestAcceptableAddress`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_CONTIGUOUS_MEMORY**. See [**MmAllocateContiguousMemorySpecifyCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatecontiguousmemoryspecifycache) for details.

### `ContiguousMemory.HighestAcceptableAddress`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_CONTIGUOUS_MEMORY**. See [**MmAllocateContiguousMemorySpecifyCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatecontiguousmemoryspecifycache) for details.

### `ContiguousMemory.BoundaryAddressMultiple`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_CONTIGUOUS_MEMORY**. See [**MmAllocateContiguousMemorySpecifyCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatecontiguousmemoryspecifycache) for details.

### `Section`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**.

### `Section.DesiredAccess`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**. See [**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection) for details.

### `Section.ObjectAttributes`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**. See [**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection) for details.

### `Section.PageProtection`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**. This value should be one of the following values: PAGE_READONLY, PAGE_READWRITE, PAGE_EXECUTE, or PAGE_WRITECOPY. Do not specify cache attributes (e.g. SEC_WRITECOMBINED) in this field. The allocated attributes of the section object are always SEC_COMMIT (PF-mapped section), and the cache type is determines by **CacheType**. See [**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection) for details.

### `Section.AllocationAttributes`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_SECTION**. See [**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection) for details.

### `IOSpace`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_IO_SPACE**.

### `IOSpace.BaseAddress`

Used only when **Type** is **DXGK_PHYSICAL_MEMORY_TYPE_IO_SPACE**. Specifies the starting physical address of the IO space region. This value must be aligned to a multiple of PAGE_SIZE.

### `hPhysicalMemoryObject`

On a successful call to [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject), this is an opaque handle back to a *Dxgkrnl*-managed physical memory object. The physical memory object can be provided to other documented memory management functions to map a virtual address for CPU access. This handle can be closed by calling [**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject).

### `hAdapterMemoryObject`

On a successful call to [**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject), this is an opaque handle back to a *Dxgkrnl*-managed adapter memory object. The adapter memory object can be provided to other documented memory management functions to generate an ADL for GPU access. If **hAdapter** is NULL, this value will be NULL and the driver must call [**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject) to create this handle. This handle can be closed by calling [**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject), or may be provided to [**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject) (but not both).

## Remarks

The *hAdapter* field is optional when creating a physical memory object, but that object must be opened against an adapter in a call to [**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject) before an [ADL can be created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl). This is because an ADL represents logical memory, and each logical adapter has a unique domain. It does not matter which physical adapter the memory is created against. It will be opened by the logical adapter that the physical adapter belongs to and will be mapped to all linked physical adapters.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGK_PHYSICAL_MEMORY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_physical_memory_type)

[**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl)

[**DXGKCB_CLOSEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_closephysicalmemoryobject)

[**DXGKCB_CREATEPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject)

[**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject)

[**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject)

[**MmAllocateContiguousMemorySpecifyCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatecontiguousmemoryspecifycache)

[**MmAllocatePagesForMdlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex)

[**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection)