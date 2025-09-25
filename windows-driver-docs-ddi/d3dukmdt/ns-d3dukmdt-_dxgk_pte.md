# _DXGK_PTE structure

## Description

A page table entry (PTE) provides a physical address of a page and other attributes. The exact format of PTE depends on hardware implementation.

## Members

### `Valid`

When set, this indicates that the entry is valid. Accessing an invalid entry leads to an unrecoverable address fault, unless the **Zero** flag is set.

### `Zero`

When set with **Valid** = 1, the access to the entry lead to returning the zero value for the memory access. This is used to support tiled resources.

Supported starting with Windows 10.

### `CacheCoherent`

When set, this indicates that the memory page is cache coherent between CPU and GPU.

### `ReadOnly`

When set, this indicates that the memory page is read only.

### `NoExecute`

When set, this indicates that the memory page contains data, which should not be treated as executable commands.

Supported starting with Windows 10.

### `Segment`

A zero-based GPU memory segment identifier where the corresponding memory page is located. The segment zero is reserved for system memory.

### `LargePage`

The bit can be set only when the kernel mode driver sets the [DXGK_VIRTUALADDRESSCAPS](https://learn.microsoft.com/windows-hardware/drivers/display/dxgk-virtualaddresscaps)::**GpuMmu**.**LargePageSupported** cap. When set the page table address (**PageTableAddress** + **SegmentId**) is the memory address of an allocation. The allocation size is equal to the virtual address range, covered by the lower page table level. This flag cannot be set for the leaf page tables.

Supported starting with Windows 10.

### `PhysicalAdapterIndex`

Defines a physical adapter index in a linked display adapter configuration. PTEs of page tables on one physical adapter can point to memory on another physical adapter.

Supported starting with Windows 10.

### `PageTablePageSize`

For the level 1 page table entry defines the pages size of the leaf page table PTEs. The value is provided by the [DXGK_PTE_PAGE_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_dxgk_pte_page_size) enumerator. This value should be ignored when dual-PTE is supported.

Supported starting with Windows 10.

### `SystemReserved0`

### `Reserved`

Reserved for system use and will be set to zero.

### `Flags`

The unmasked value of the structure.

### `PageAddress`

The high 52 bits of the 64 bit physical address of a memory page. The low 12 bits are zero. The address is an offset from the start of the segment, defined by **Segment**, or a system memory address.

### `PageTableAddress`

The high 52 bits of the 64 bit physical address of a lower level page table. The low 12 bits are zero. The address is an offset from the start of the segment, defined by **Segment**, or a system memory address.

Supported starting with Windows 10.