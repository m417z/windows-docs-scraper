# MINIDUMP_MEMORY_INFO structure

## Description

Describes a region of memory.

## Members

### `BaseAddress`

The base address of the region of pages.

### `AllocationBase`

The base address of a range of pages in this region. The page is contained within this memory region.

### `AllocationProtect`

The memory protection when the region was initially allocated. This member can be one of the
[memory protection](https://learn.microsoft.com/windows/desktop/Memory/memory-protection) options, along with PAGE_GUARD or PAGE_NOCACHE, as needed.

### `__alignment1`

A variable for alignment.

### `RegionSize`

The size of the region beginning at the base address in which all pages have identical attributes, in bytes.

### `State`

The state of the pages in the region. This member can be one of the following values.

| State | Meaning |
| --- | --- |
| **MEM_COMMIT**<br><br>0x1000 | Indicates committed pages for which physical storage has been allocated, either in memory or in the paging file on disk. |
| **MEM_FREE**<br><br>0x10000 | Indicates free pages not accessible to the calling process and available to be allocated. For free pages, the information in the **AllocationBase**, **AllocationProtect**, **Protect**, and **Type** members is undefined. |
| **MEM_RESERVE**<br><br>0x2000 | Indicates reserved pages where a range of the process's virtual address space is reserved without any physical storage being allocated. For reserved pages, the information in the **Protect** member is undefined. |

### `Protect`

The access protection of the pages in the region. This member is one of the values listed for the **AllocationProtect** member.

### `Type`

The type of pages in the region. The following types are defined.

| Type | Meaning |
| --- | --- |
| **MEM_IMAGE**<br><br>0x1000000 | Indicates that the memory pages within the region are mapped into the view of an image section. |
| **MEM_MAPPED**<br><br>0x40000 | Indicates that the memory pages within the region are mapped into the view of a section. |
| **MEM_PRIVATE**<br><br>0x20000 | Indicates that the memory pages within the region are private (that is, not shared by other processes). |

### `__alignment2`

A variable for alignment.

## See also

[MINIDUMP_MEMORY_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_info_list)