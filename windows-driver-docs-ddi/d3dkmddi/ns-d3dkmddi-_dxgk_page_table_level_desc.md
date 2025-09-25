# _DXGK_PAGE_TABLE_LEVEL_DESC structure

## Description

The **DXGK_PAGE_TABLE_LEVEL_DESC** structure describes capabilities that are applied at the page level.

## Members

### `PageTableIndexBitCount`

The number of bits in the virtual address, which used as an index into the page table entry array. The number of entries in every page table is 2PageTableIndexBitCount. The video memory manager sets up the page table entries, assuming that each entry covers a 4 KB page. When the root page table is resizable, the value for this level should be set to an initial index bit count (it could be set to zero). The corresponding **DXGK_PAGE_TABLE_LEVEL_DESC::PageTableSizeInBytes** should also be set accordingly.

### `PageTableSegmentId`

A zero-based memory segment identifier. When the segment identifier points to the system memory, the page table size cannot be more than 4 KB. The value zero is reserved for system memory.

### `PagingProcessPageTableSegmentId`

A zero-based memory segment identifier for the paging process. When the segment identifier points to the system memory (zero), the page table size cannot be more than 4 KB. The value zero is reserved for system memory.

### `PageTableSizeInBytes`

The size of a page table in bytes. The number of entries in a page table is equal to 2PageTableIndexBitCount. The size must be a multiple of the CPU page size. When the root page table is resizable, the value for this level should be set to an initial page table size (it could be set to zero).

### `PageTableAlignmentInBytes`