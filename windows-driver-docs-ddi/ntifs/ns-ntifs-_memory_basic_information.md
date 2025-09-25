# MEMORY_BASIC_INFORMATION structure

## Description

Contains information about a range of pages in the virtual address space of a process. The [**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory) routine uses this structure.

## Members

### `BaseAddress`

A pointer to the base address of the region of pages.

### `AllocationBase`

A pointer to the base address of a range of allocated pages. The page pointed to by the **BaseAddress** member is contained within this allocation range.

### `AllocationProtect`

The memory protection option when the region was initially allocated. This member can be one of the following constants defined in wdm.h, or 0 if the caller does not have access.

| Value | Meaning |
| ----- | ------- |
| PAGE_NOACCESS 0x01 | No access to the region of pages is allowed. An attempt to read, write, or execute within the region results in an access violation. |
| PAGE_EXECUTE 0x10 | Execute access to the region of pages is allowed. An attempt to read or write within the region results in an access violation. |
| PAGE_READONLY 0x02 | Read-only and execute access to the region of pages is allowed. An attempt to write within the region results in an access violation. |
| PAGE_READWRITE 0x04 | Read, write, and execute access to the region of pages is allowed. If write access to the underlying section is allowed, then a single copy of the pages are shared. Otherwise, the pages are shared read-only/copy-on-write. |
| PAGE_GUARD 0x100 | Read, write, and execute access to the region of pages is allowed; however, access to the region causes a "guard region entered" condition to be raised in the subject process. |
| PAGE_NOCACHE 0x200 | Disable the placement of committed pages into the data cache. |
| PAGE_WRITECOMBINE 0x400 | Disable the placement of committed pages into the data cache, combine the writes as well. |

### `PartitionId`

Reserved for system use.

### `RegionSize`

The size of the region in bytes beginning at the base address in which all pages have identical attributes.

### `State`

The state of the pages in the region. This member can be one of the following values.

| State | Meaning |
| ----- | ------- |
| MEM_COMMIT 0x1000 | Indicates committed pages for which physical storage has been allocated, either in memory or in the paging file on disk. |
| MEM_FREE 0x10000 | Indicates free pages not accessible to the calling process and available to be allocated. |
| MEM_RESERVE 0x2000 | Indicates reserved pages where a range of the process's virtual address space is reserved without any physical storage being allocated. |

### `Protect`

The access protection of the pages in the region. This member is one of the values listed for the **AllocationProtect** member.

### `Type`

The type of pages in the region. The following types are defined.

| Type | Meaning |
| ---- | ------- |
| MEM_IMAGE 0x1000000 | Indicates that the memory pages within the region are mapped into the view of an image section. |
| MEM_MAPPED 0x40000 | Indicates that the memory pages within the region are mapped into the view of a section. |
| MEM_PRIVATE 0x20000 | Indicates that the memory pages within the region are private (that is, not shared by other processes). |

## See also

[**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory)