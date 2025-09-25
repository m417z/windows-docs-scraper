# _DXGK_UPDATEPAGETABLEFLAGS structure

## Description

**DXGK_UPDATEPAGETABLEFLAGS** is used as part of a page table update operation.

## Members

### `Repeat`

When set to **TRUE**, page table entries will point to a single page table entry value that needs to be replicated to all page table entries being updated.

### `InitialUpdate`

Indicates that the page table is initialized very first time after being made resident in memory.

### `NotifyEviction`

Indicates that the page table is about to be evicted.

### `Use64KBPages`

Indicates that page table entries point to page tables pointing to 64 KB pages.

### `Reserved`

This member is reserved and should be set to zero.