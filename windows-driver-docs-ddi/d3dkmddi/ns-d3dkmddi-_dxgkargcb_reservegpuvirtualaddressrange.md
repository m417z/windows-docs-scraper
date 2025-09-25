# DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE structure

## Description

**DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE** contains the arguments used by the [**DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange) callback function, to allow the kernel-mode display driver to reserve a graphics processing unit (GPU) virtual address range during creation of a process.

## Members

### `hDxgkProcess` [in]

The process handle that was passed to [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess).

### `SizeInBytes` [in]

The size in bytes of the virtual address range. **SizeInBytes** must be set to an integral multiple of the address space covered by a single page table entry.

### `Alignment` [in]

The number of bytes to align the start address to. Must be a multiple of the address space covered by a single page table entry and a power of 2.

### `StartVirtualAddress` [out]

The starting location of the reserved address range.

### `BaseAddress` [in]

The base virtual address of the virtual address range in bytes. It must be aligned to the size of the address space, covered by a single page table entry.

### `AllowUserModeMapping` [in]

When set, allows the user-mode driver to map allocations to the range.

### `Flags` [in]

A single value containing the flags set in the structure.

## See also

[**DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)