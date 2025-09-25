# WIN32_MEMORY_REGION_INFORMATION structure

## Description

Contains information about a memory region. A memory region is a single allocation that is created using a memory allocation function, such as [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) or [MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile).

## Members

### `AllocationBase`

The base address of the allocation.

### `AllocationProtect`

The page protection value that was specified when the allocation was created. Protections of individual pages within the allocation can be different from this value. To query protection values of individual pages, use the [VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery) function.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Represents all memory region flags as a single ULONG value. Applications should not use this field. Instead, test the individual bit field flags defined below.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Private`

A value of 1 indicates that the allocation is private to the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MappedDataFile`

A value of 1 indicates that the allocation is a mapped view of a data file.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MappedImage`

A value of 1 indicates that the allocation is a mapped view of an executable image.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MappedPageFile`

A value of 1 indicates that the allocation is a mapped view of a pagefile-backed section.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MappedPhysical`

A value of 1 indicates that the allocation is a view of the **\Device\PhysicalMemory** section.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DirectMapped`

A value of 1 indicates that the allocation is a mapped view of a direct-mapped file.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Reserved`

Reserved.

### `RegionSize`

The size of the allocation.

### `CommitSize`

The commit charge associated with the allocation. For private allocations, this is the combined size of pages in the region that are committed, as opposed to reserved. For mapped views, this is the combined size of pages that have copy-on-write protection, or have been made private as a result of copy-on-write.

## Remarks

The **WIN32_MEMORY_REGION_INFORMATION** structure contains information about a single memory allocation. In contrast, the [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information) structure that is returned by the [VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery) function describes a contiguous run of pages within a single allocation that all have the same type, state, and protection. The mapping between **WIN32_MEMORY_REGION_INFORMATION** fields and memory type values returned by **VirtualQuery** is as follows:

| WIN32_MEMORY_REGION_INFORMATION | MEMORY_BASIC_INFORMATION::Type |
| --- | --- |
| Private | MEM_PRIVATE |
| MappedDataFile | MEM_MAPPED |
| MappedImage | MEM_IMAGE |
| MappedPageFile | MEM_MAPPED |
| MappedPhysical | MEM_MAPPED |

## See also

[MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)