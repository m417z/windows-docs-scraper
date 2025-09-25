# MapViewOfFile3 function

## Description

Maps a view of a file or a pagefile-backed section into the address space of the specified process.

## Parameters

### `FileMapping` [in]

A **HANDLE** to a section that is to be mapped into the address space of the specified process.

### `Process` [in]

A **HANDLE** to a process into which the section will be mapped.

### `BaseAddress` [in, optional]

The desired base address of the view (the address is rounded down to the nearest 64k boundary).

If this parameter is **NULL**, the system picks the base address.

If *BaseAddress* is not **NULL**, then any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) must consist of all zeroes.

### `Offset` [in]

The offset from the beginning of the section.

The offset must be 64k aligned or aligned to GetLargePageMinimum when MEM_LARGE_PAGES is used in AllocationType. Furthermore, the offset must be page-aligned to the underlying page size granted by VirtualAlloc2 when MEM_REPLACE_PLACEHOLDER is used in AllocationType.

### `ViewSize` [in]

The number of bytes to map. A value of zero (0) specifies that the entire section is to be mapped.

The size must always be a multiple of the page size.

### `AllocationType` [in]

The type of memory allocation. This parameter can be zero (0) or one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_RESERVE**<br><br>0x00002000 | Maps a reserved view. |
| **MEM_REPLACE_PLACEHOLDER**<br><br>0x00004000 | Replaces a placeholder with a mapped view. Only data/pf-backed section views are supported (no images, physical memory, etc.). When you replace a placeholder, *BaseAddress* and *ViewSize* must exactly match those of the placeholder, and any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes.<br><br>After you replace a placeholder with a mapped view, to free that mapped view back to a placeholder, see the *UnmapFlags* parameter of [UnmapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffileex) and [UnmapViewOfFile2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile2).<br><br>A placeholder is a type of reserved memory region.<br><br>The 64k alignment requirements on *Offset* and *BaseAddress* do not apply when this flag is specified. |
| **MEM_LARGE_PAGES**<br><br>0x20000000 | Maps a large page view. This flag specifies that the view should be mapped using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support). The size of the view must be a multiple of the size of a large page reported by the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function, and the file-mapping object must have been created using the **SEC_LARGE_PAGES** option. If you provide a non-null value for the *BaseAddress* parameter, then the value must be a multiple of **GetLargePageMinimum**.<br><br>The 64k alignment requirements on *Offset* do not apply when this flag is specified. |

### `PageProtection` [in]

The desired page protection.

For file-mapping objects created with the **SEC_IMAGE** attribute, the *PageProtection* parameter has no effect, and should be set to any valid value such as **PAGE_READONLY**.

### `ExtendedParameters` [in, out, optional]

An optional pointer to one or more extended parameters of type [MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter). Each of those extended parameter values can itself have a *Type* field of either **MemExtendedParameterAddressRequirements** or **MemExtendedParameterNumaNode**. If no **MemExtendedParameterNumaNode** extended parameter is provided, then the behavior is the same as for the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)/[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) functions (that is, the preferred NUMA node for the physical pages is determined based on the ideal processor of the thread that first accesses the memory).

### `ParameterCount` [in]

The number of extended parameters pointed to by *ExtendedParameters*.

## Return value

Returns the base address of the mapped view, if successful. Otherwise, returns **NULL** and extended error status is available using [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This API helps support high-performance games, and server applications, which have particular requirements around managing their virtual address space. For example, mapping memory on top of a previously reserved region; this is useful for implementing an automatically wrapping ring buffer. And allocating memory with specific alignment; for example, to enable your application to commit large/huge page-mapped regions on demand.

Using this function for new allocations, you can:

- specify a range of virtual address space and a power-of-2 alignment restriction
- specify an arbitrary number of extended parameters
- specify a preferred NUMA node for the physical memory as an extended parameter
- specify a placeholder operation (specifically, replacement).

To specify the NUMA node, see the *ExtendedParameters* parameter.

#### Examples

For a code example, see Scenario 1 in [VirtualAlloc2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc2).

## See also

[VirtualAlloc2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc2)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFile2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile2)

[MapViewOfFileNuma2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffilenuma2)