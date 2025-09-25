# MEMORY_BASIC_INFORMATION structure

## Description

Contains information about a range of pages in the virtual address space of a process. The
[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery) and
[VirtualQueryEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualqueryex) functions use this structure.

## Members

### `BaseAddress`

A pointer to the base address of the region of pages.

### `AllocationBase`

A pointer to the base address of a range of pages allocated by the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function. The page pointed to by the **BaseAddress** member is contained within this allocation range.

### `AllocationProtect`

The memory protection option when the region was initially allocated. This member can be one of the
[memory protection constants](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants) or 0 if the caller does not have access.

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

## Remarks

To enable a debugger to debug a target that is running on a different architecture (32-bit versus 64-bit), use one of the explicit forms of this structure.

```cpp
typedef struct _MEMORY_BASIC_INFORMATION32 {
    DWORD BaseAddress;
    DWORD AllocationBase;
    DWORD AllocationProtect;
    DWORD RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
} MEMORY_BASIC_INFORMATION32, *PMEMORY_BASIC_INFORMATION32;

typedef struct DECLSPEC_ALIGN(16) _MEMORY_BASIC_INFORMATION64 {
    ULONGLONG BaseAddress;
    ULONGLONG AllocationBase;
    DWORD     AllocationProtect;
    DWORD     __alignment1;
    ULONGLONG RegionSize;
    DWORD     State;
    DWORD     Protect;
    DWORD     Type;
    DWORD     __alignment2;
} MEMORY_BASIC_INFORMATION64, *PMEMORY_BASIC_INFORMATION64;
```

## See also

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)

[VirtualQueryEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualqueryex)