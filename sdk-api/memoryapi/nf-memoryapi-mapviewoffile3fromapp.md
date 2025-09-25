# MapViewOfFile3FromApp function

## Description

Maps a view of a file mapping into the address space of a calling
Windows Store app.

Using this function, you can: for new allocations, specify a range of virtual address space and a power-of-2 alignment restriction; specify an arbitrary number of extended parameters; specify a preferred NUMA node for the physical memory as an extended parameter; and specify a placeholder operation (specifically, replacement).

To specify the NUMA node, see the *ExtendedParameters* parameter.

## Parameters

### `FileMapping` [in]

A **HANDLE** to a section that is to be mapped
into the address space of the specified process.

### `Process` [in]

A **HANDLE** to a process into which the section
will be mapped.

### `BaseAddress` [in, optional]

The desired base address of the view.
The address is rounded down to the nearest 64k boundary.

 If this parameter is **NULL**, the system picks the base
address.

If *BaseAddress* is not **NULL**, then
any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes.

### `Offset` [in]

The offset from the beginning of the section.
This must be 64k aligned.

### `ViewSize` [in]

The number of bytes to map. A value of zero (0)
specifies that the entire section is to be mapped.

The size must always be a multiple of the page size.

### `AllocationType` [in]

The type of memory allocation. This parameter can be zero (0) or one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_RESERVE**<br><br>0x00002000 | Maps a reserved view. |
| **MEM_REPLACE_PLACEHOLDER**<br><br>0x00004000 | Replaces a placeholder with a mapped view. Only data/pf-backed section views are supported (no images, physical memory, etc.). When you replace a placeholder, *BaseAddress* and *ViewSize* must exactly match those of the placeholder, and any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes.<br><br>After you replace a placeholder with a mapped view, to free that mapped view back to a placeholder, see the *UnmapFlags* parameter of [UnmapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffileex) and [UnmapViewOfFile2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile2).<br><br>A placeholder is a type of reserved memory region. |
| **MEM_LARGE_PAGES**<br><br>0x20000000 | Maps a large page view. See [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support). |

### `PageProtection` [in]

The desired page protection.

For file-mapping objects created with the **SEC_IMAGE** attribute, the
*PageProtection* parameter has no effect, and should be set to any valid value such as
**PAGE_READONLY**.

### `ExtendedParameters` [in, out, optional]

An optional pointer to one or more extended parameters of type [MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter). Each of those extended parameter values can itself have a *Type* field of either **MemExtendedParameterAddressRequirements** or **MemExtendedParameterNumaNode**. If no **MemExtendedParameterNumaNode** extended parameter is provided, then the behavior is the same as for the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)/[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) functions (that is, the preferred NUMA node for the physical pages is determined based on the ideal processor of the thread that first accesses the memory).

### `ParameterCount` [in]

The number of extended parameters pointed to by *ExtendedParameters*.

## Return value

Returns the base address of the mapped view, if successful. Otherwise, returns **NULL** and extended error status is available
using [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This API helps support high-performance games, and server applications, which have particular requirements around managing their virtual address space. For example, mapping memory on top of a previously reserved region; this is useful for implementing an automatically wrapping ring buffer. And allocating memory with specific alignment; for example, to enable your application to commit large/huge page-mapped regions on demand.

With one important exception, file views derived from any file mapping object that is backed by the same file
are coherent or identical at a specific time. Coherency is guaranteed for views within a process and for views
that are mapped by different processes.

The exception is related to remote files. Although
**MapViewOfFile3FromApp** works with remote files, it
does not keep them coherent. For example, if two computers both map a file as writable, and both change the same
page, each computer only sees its own writes to the page. When the data gets updated on the disk, it is not
merged.

 You can only successfully request executable protection if your app has the **codeGeneration** capability.

#### Examples

For a code example, see Scenario 1 in [Virtual2Alloc](https://msdn.microsoft.com/en-us/library/Mt832849(v=VS.85).aspx).

## See also

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[Creating a File View](https://learn.microsoft.com/windows/desktop/Memory/creating-a-file-view)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[MapViewOfFile3](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile3)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)