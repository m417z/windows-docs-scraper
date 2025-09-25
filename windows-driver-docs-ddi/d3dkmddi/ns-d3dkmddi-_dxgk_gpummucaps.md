# DXGK_GPUMMUCAPS structure

## Description

The **DXGK_GPUMMUCAPS** structure is used by the kernel-mode driver to express virtual memory addressing capabilities.

## Members

### `ReadOnlyMemorySupported`

When set to 1, the driver supports read-only protection on memory pages.

### `NoExecuteMemorySupported`

When set to 1, the driver supports *no execute* protection on memory pages.

### `ZeroInPteSupported`

When set to 1, the GPU supports the *Zero DXGK_PTE* flag. This applies to all page table levels.

### `ExplicitPageTableInvalidation`

Indicates that all entries of a page table or page directory should be put into an invalid state explicitly, through **UpdatePageTable** before being freed. By default the video memory manager may free a page table, which contain previously valid entries, if these entries are no longer needed (ex. freeing a large GPU virtual address range resulting in the destruction of underlying page tables).

> [!NOTE]
> This flags is typically used by a software driver that needs to emulate page table and need to keep track of information on a per page table entry basis and require a clear init/deinit pair for all page table entry updates.

### `CacheCoherentMemorySupported`

Indicates that the driver supports the *CacheCoherent* bits in the page table entry and can do I/O coherent transfer to system memory.

### `PageTableUpdateRequireAddressSpaceIdle`

Indicates that the GPU doesn’t support updating page table entries or invalidating translation look-aside buffer for an address space that is currently in used by an engine. When this flags is set, video memory manager will ensure that all context sharing the address space are suspended when its page table entries are modified and when translation look-aside buffer is invalidated.

### `LargePageSupported`

When set to 1, all levels of page tables, except the leaf one, support large pages (**LargePage** bit in [**DXGK_PTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_dxgk_pte)).

### `DualPteSupported`

When set to 1, the GPU supports two pointers to page tables in the level one page table (4 KB page table and 64 KB page table).

### `AllowNonAlignedLargePageAddress`

When set to 1, the Operating System is able to set the **LargePage** flag when the physical address of the large page entry is not aligned to the leaf page table coverage. Available starting in Windows 10 version 1607 (WDDM 2.1).

### `SysMem64KBPageSupported`

The driver provides memory segment management at 64KB. Available starting in Windows 10 version 1607 (WDDM 2.1).

### `InvalidTlbEntriesNotCached`

When this bit is set, the driver will not receive calls to [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) for FlushTlb requests for VA ranges that are transitioning from an invalid to valid state. It is expected that the hardware’s TLB does not cache invalid translations

Available starting in Windows 10 version 1903 (WDDM 2.6).

### `SysMemLargePageSupported`

The driver provides large-page support. Available starting in Windows Server 2022 (WDDM 2.9).

### `CachedPageTables`

Cached page tables are supported. Available starting in WDDM 3.1.

### `Reserved`

Reserved for system use; don't use.

### `Value`

The value of the union's structure expressed as an integer.

### `PageTableUpdateMode`

Defines the type of addresses that are used in [**DxgkDdiUpdatePageTable**](https://learn.microsoft.com/windows-hardware/drivers/display/dxgkddiupdatepagetable) operations. When **DXGK_PAGETABLEUPDATE_GPU_VIRTUAL** is set, all paging operation will occur in the virtual address space of the system context. When page directories are located in a local GPU memory segment, the update mode cannot be set to **DXGK_PAGETABLEUPDATE_CPU_VIRTUAL**.

### `VirtualAddressBitCount`

The number of bits in the GPU virtual address.

### `LeafPageTableSizeFor64KPagesInBytes`

The size of a leaf page table when 64KB pages are used. The size must be a multiple of CPU page size (4096).

### `PageTableLevelCount`

The number of page table levels supported. The minimum value is 2 (defined as **DXGK_MIN_PAGE_TABLE_LEVEL_COUNT**). The maximum value is **DXGK_MAX_PAGE_TABLE_LEVEL_COUNT**.

When **PageTableLevelCount** is 2, the root page table is dynamically resizable and the size of the page table is determined through [**DxgkDdiGetRootPageTableSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getrootpagetablesize). When **PageTableLevelCount** is greater than 2, all page table levels have a fixed size, which is described through [**DXGK_PAGE_TABLE_LEVEL_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_page_table_level_desc)**::PageTableSizeInBytes**.

### `LegacyBehaviors`

### `LegacyBehaviors.SourcePageTableVaInTransfer`

When set to 1, video memory manager sets **SourcePageTable** address in **TransferVirtual** during allocation eviction.

### `LegacyBehaviors.Reserved`

Reserved; do not use.