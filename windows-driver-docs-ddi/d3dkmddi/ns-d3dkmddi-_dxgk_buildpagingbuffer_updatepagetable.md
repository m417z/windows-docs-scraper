# _DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE structure

## Description

**DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE** is used as part of a page table update operation.

## Members

### `PageTableLevel`

Level of a page table, which is updated.

### `hAllocation`

Kernel mode driver handle of an allocation, which is mapped by the page table entries. The handle is returned by the kernel mode driver from [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation). The handle can be **NULL** for allocations, which do not have a kernel mode driver handle (page tables, page directories, etc.).

### `PageTableAddress`

Address of the page table to update. If **DXGK_VIRTUALADDRESSCAPS:: PageTableUpdateMode** is **DXGK_PAGETABLEUPDATE_CPU_VIRTUAL**, the CPU virtual address is in the **CpuVirtual** field. If **DXGK_VIRTUALADDRESSCAPS:: PageTableUpdateMode** is **DXGK_PAGETABLEUPDATE_GPU_VIRTUAL**, the GPU virtual address is in the **GpuVirtual** field. If **DXGK_VIRTUALADDRESSCAPS:: PageTableUpdateMode** is **DXGK_PAGETABLEUPDATE_GPU_PHYSICAL**, the GPU physical address is in the **GpuPhysical** field.

### `pPageTableEntries`

The entries which need to be copied. The index zero in the **pPageTableEntries** array corresponds to the **StartIndex** in the driver page table entry array.

### `StartIndex`

The starting index of a page table entry within the page table where the entries should be copied. The page table entry array index is zero-based.

### `NumPageTableEntries`

The number of entries which need to be copied.

### `Reserved0`

This member is reserved and should be set to zero.

### `Flags`

[DXGK_UPDATEPAGETABLEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_updatepagetableflags) structure describing the update operation.

### `DriverProtection`

Passed by UMD in MapGpuVirtualAddressRangeCb.

### `AllocationOffsetInBytes`

When **hAllocation** is non-NULL, this field specifies the relative offset, in bytes, from the beginning of the allocation to the first page being targeted by this update operation. If the update target multiple pages from **hAllocation**, those pages are guaranteed to be sequential. For example, video memory manager may be updating a GPU virtual address to page 4,5,6,7 in **hAllocation**. There will never be a case where a driver would see a single update operation which target non sequential pages (ex. 4,5,7). Note that although the pages are guaranteed to be sequential from the point of view of the allocation, they may not be physically contiguous in memory.

### `hProcess`

Kernel mode driver process handle for the process whose page table entries are updated. This is the value returned from [DxgkDdiCreateProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess).

### `UpdateMode`

Defines the meaning of **PageTableAddress**. When initializing page tables for the paging process, the update mode is always **DXGK_PAGETABLEUPDATE_CPU_VIRTUAL** and **pDmaBuffer** is set to **NULL**. In this case the driver must update page tables immediately. In other cases the **UpdateMode** is set to the value, which is specified in **DXGK_VIRTUALADDRESSCAPS::GpuMmu.PageTableUpdateMode**.

When updating page table entries for a leaf page table, video memory manager assumes that each entry covers a 4KB page. If a GPU page is bigger (4 KB * 2n), the video memory manager will provide entries in the array, which point within GPU pages. The kernel mode driver might only need to initialize page table entries, which point to the beginning of GPU pages. The following figure illustrates this for the case when GPU page is 16 KB.

### `pPageTableEntries64KB`

The entries which need to be copied from the 64KB page tables. The index zero in the **pPageTableEntries** array corresponds to the **StartIndex** in the driver page table entry array. The array should be use only when the **DXGK_GPUMMUCAPS::DualPteSupported** cap is set.

### `FirstPteVirtualAddress`

The GPU virtual address that is mapped by the first updated page table entry.