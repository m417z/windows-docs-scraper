# _DXGK_ESCAPE_GPUMMUCAPS structure

## Description

The GPU memory management capabilities.

## Members

### `ReadOnlyMemorySupported`

Read-only memory is supported.

### `NoExecuteMemorySupported`

No execute memory is supported.

### `ZeroInPteSupported`

### `CacheCoherentMemorySupported`

Cache coherent memory is supported.

### `LargePageSupported`

When set to 1, all levels of page tables, except the leaf one, support large pages (LargePage bit in [DXGK_PTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_dxgk_pte)).

### `DualPteSupported`

When set to 1, the GPU supports two pointers to page tables in the level one page table (4 KB page table and 64 KB page table).

### `AllowNonAlignedLargePageAddress`

When set to 1, the Operating System is able to set the **LargePage** flag when the physical address of the large page entry is not aligned to the leaf page table coverage.

### `VirtualAddressBitCount`

The virtual address bit count.

### `PageTableLevelCount`

The number of page table levels supported.

### `PageTableLevelDesk`

The page table level descriptions.

## Remarks

## See also