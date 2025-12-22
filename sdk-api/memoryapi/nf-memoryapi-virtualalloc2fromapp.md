# VirtualAlloc2FromApp function

## Description

Reserves, commits, or changes the state of a region of pages in the virtual address space of the calling process.
Memory allocated by this function is automatically initialized to zero.

Using this function, you can: for new allocations, specify a range of virtual address space and a power-of-2 alignment restriction; specify an arbitrary number of extended parameters; specify a preferred NUMA node for the physical memory as an extended parameter; and specify a placeholder operation (specifically, replacement).

To specify the NUMA node, see the *ExtendedParameters* parameter.

## Parameters

### `Process` [in, optional]

The handle to a process. The function allocates memory within the virtual address space of this process.

The handle must have the **PROCESS_VM_OPERATION** access right. For more information,
see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `BaseAddress` [in, optional]

The pointer that specifies a desired starting address for the region of pages that you want to allocate.

If *BaseAddress* is **NULL**, the function determines where to
allocate the region.

If *BaseAddress* is not **NULL**, then
any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes,
and the base address must be a multiple of the system allocation granularity. To determine the allocation granularity, use the
[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function.

### `Size` [in]

The size of the region of memory to allocate, in bytes.

The size must always be a multiple of the page size.

If *BaseAddress* is not **NULL**, the function allocates all
pages that contain one or more bytes in the range from *BaseAddress* to
*BaseAddress*+*Size*. This means, for example, that a 2-byte
range that straddles a page boundary causes the function to allocate both pages.

### `AllocationType` [in]

The type of memory allocation. This parameter must contain one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_COMMIT**<br><br>0x00001000 | Allocates memory charges (from the overall size of memory and the paging files on disk) for the specified reserved memory pages. The function also guarantees that when the caller later initially accesses the memory, the contents will be zero. Actual physical pages are not allocated unless/until the virtual addresses are actually accessed.<br><br>To reserve and commit pages in one step, call **Virtual2AllocFromApp** with `MEM_COMMIT \| MEM_RESERVE`.<br><br>Attempting to commit a specific address range by specifying **MEM_COMMIT** without **MEM_RESERVE** and a non-**NULL** *BaseAddress* fails unless the entire range has already been reserved. The resulting error code is **ERROR_INVALID_ADDRESS**.<br><br>An attempt to commit a page that is already committed does not cause the function to fail. This means that you can commit pages without first determining the current commitment state of each page. |
| **MEM_RESERVE**<br><br>0x00002000 | Reserves a range of the process's virtual address space without allocating any actual physical storage in memory or in the paging file on disk.<br><br>You can commit reserved pages in subsequent calls to the **Virtual2AllocFromApp** function. To reserve and commit pages in one step, call **Virtual2AllocFromApp** with **MEM_COMMIT** \| **MEM_RESERVE**.<br><br>Other memory allocation functions, such as **malloc** and [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc), cannot use a reserved range of memory until it is released. |
| **MEM_REPLACE_PLACEHOLDER**<br><br>0x00004000 | Replaces a placeholder with a normal private allocation. Only data/pf-backed section views are supported (no images, physical memory, etc.). When you replace a placeholder, *BaseAddress* and *Size* must exactly match those of the placeholder, and any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes.<br><br>After you replace a placeholder with a private allocation, to free that allocation back to a placeholder, see the *dwFreeType* parameter of [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) and [VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex).<br><br>A placeholder is a type of reserved memory region. |
| **MEM_RESERVE_PLACEHOLDER**<br><br>0x00040000 | To create a placeholder, call [VirtualAlloc2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc2) with `MEM_RESERVE \| MEM_RESERVE_PLACEHOLDER` and *PageProtection* set to **PAGE_NOACCESS**. To free/split/coalesce a placeholder, see the *dwFreeType* parameter of [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) and [VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex).<br><br>A placeholder is a type of reserved memory region. |
| **MEM_RESET**<br><br>0x00080000 | Indicates that data in the memory range specified by *BaseAddress* and *Size* is no longer of interest. The pages should not be read from or written to the paging file. However, the memory block will be used again later, so it should not be decommitted. This value cannot be used with any other value.<br><br>Using this value does not guarantee that the range operated on with **MEM_RESET** will contain zeros. If you want the range to contain zeros, decommit the memory and then recommit it.<br><br>When you specify **MEM_RESET**, the **Virtual2AllocFromApp** function ignores the value of *Protection*. However, you must still set *Protection* to a valid protection value, such as **PAGE_NOACCESS**.<br><br>**Virtual2AllocFromApp** returns an error if you use **MEM_RESET** and the range of memory is mapped to a file. A shared view is only acceptable if it is mapped to a paging file. |
| **MEM_RESET_UNDO**<br><br>0x1000000 | **MEM_RESET_UNDO** should only be called on an address range to which **MEM_RESET** was successfully applied earlier. It indicates that the data in the specified memory range specified by *BaseAddress* and *Size* is of interest to the caller and attempts to reverse the effects of **MEM_RESET**. If the function succeeds, that means all data in the specified address range is intact. If the function fails, at least some of the data in the address range has been replaced with zeroes.<br><br>This value cannot be used with any other value. If **MEM_RESET_UNDO** is called on an address range which was not **MEM_RESET** earlier, the behavior is undefined. When you specify **MEM_RESET**, the **Virtual2AllocFromApp** function ignores the value of *Protection*. However, you must still set *Protection* to a valid protection value, such as **PAGE_NOACCESS**. |

This parameter can also specify the following values as indicated.

| Value | Meaning |
| --- | --- |
| **MEM_LARGE_PAGES**<br><br>0x20000000 | Allocates memory using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support).<br><br>The size and alignment must be a multiple of the large-page minimum. To obtain this value, use the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function.<br><br>If you specify this value, you must also specify **MEM_RESERVE** and **MEM_COMMIT**. |
| **MEM_PHYSICAL**<br><br>0x00400000 | Reserves an address range that can be used to map [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) pages.<br><br>This value must be used with **MEM_RESERVE** and no other values. |
| **MEM_TOP_DOWN**<br><br>0x00100000 | Allocates memory at the highest possible address. This can be slower than regular allocations, especially when there are many allocations. |
| **MEM_WRITE_WATCH**<br><br>0x00200000 | Causes the system to track pages that are written to in the allocated region. If you specify this value, you must also specify **MEM_RESERVE**.<br><br>To retrieve the addresses of the pages that have been written to since the region was allocated or the write-tracking state was reset, call the [GetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getwritewatch) function. To reset the write-tracking state, call **GetWriteWatch** or [ResetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-resetwritewatch). The write-tracking feature remains enabled for the memory region until the region is freed. |

### `PageProtection` [in]

The memory protection for the region of pages to be allocated. If the pages are being committed, you can
specify one of the
[memory protection constants](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants). The following constants generate an error:

* **PAGE_EXECUTE**
* **PAGE_EXECUTE_READ**
* **PAGE_EXECUTE_READWRITE**
* **PAGE_EXECUTE_WRITECOPY**

### `ExtendedParameters` [in, out, optional]

An optional pointer to one or more extended parameters of type [MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter). Each of those extended parameter values can itself have a *Type* field of either **MemExtendedParameterAddressRequirements** or **MemExtendedParameterNumaNode**. If no **MemExtendedParameterNumaNode** extended parameter is provided, then the behavior is the same as for the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)/[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) functions (that is, the preferred NUMA node for the physical pages is determined based on the ideal processor of the thread that first accesses the memory).

### `ParameterCount` [in]

The number of extended parameters pointed to by *ExtendedParameters*.

## Return value

If the function succeeds, the return value is the base address of the allocated region of pages.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This API helps support high-performance games, and server applications, which have particular requirements around managing their virtual address space. For example, mapping memory on top of a previously reserved region; this is useful for implementing an automatically wrapping ring buffer. And allocating memory with specific alignment; for example, to enable your application to commit large/huge page-mapped regions on demand.

You can call **Virtual2AllocFromApp** from Windows Store apps with just-in-time (JIT) capabilities to use JIT functionality. The app must include the **codeGeneration** capability in the app manifest file to use JIT capabilities.

Each page has an associated [page state](https://learn.microsoft.com/windows/desktop/Memory/page-state). The
**Virtual2AllocFromApp** function can perform the following
operations:

* Commit a region of reserved pages
* Reserve a region of free pages
* Simultaneously reserve and commit a region of free pages

**Virtual2AllocFromApp** cannot reserve a reserved page. It can
commit a page that is already committed. This means you can commit a range of pages, regardless of whether they
have already been committed, and the function will not fail.

You can use **Virtual2AllocFromApp** to reserve a block of pages
and then make additional calls to **Virtual2AllocFromApp** to commit
individual pages from the reserved block. This enables a process to reserve a range of its virtual address space
without consuming physical storage until it is needed.

If the *BaseAddress* parameter is not **NULL**, the function uses
the *BaseAddress* and *Size* parameters to compute the region of
pages to be allocated. The current state of the entire range of pages must be compatible with the type of
allocation specified by the *AllocationType* parameter. Otherwise, the function fails
and none of the pages are allocated. This compatibility requirement does not preclude committing an already
committed page, as mentioned previously.

**Virtual2AllocFromApp** does not allow the creation of executable pages.

The **Virtual2AllocFromApp** function can be used to reserve an
[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE)
region of memory within the virtual address space of a specified process. This region of memory can then be used
to map physical pages into and out of virtual memory as required by the application. The
**MEM_PHYSICAL** and **MEM_RESERVE** values must be set in the
*AllocationType* parameter. The **MEM_COMMIT** value must not be
set. The page protection must be set to **PAGE_READWRITE**.

The [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) function can decommit a committed
page, releasing the page's storage, or it can simultaneously decommit and release a committed page. It can also
release a reserved page, making it a free page.

When creating a region that will be executable, the calling program bears responsibility for ensuring cache
coherency via an appropriate call to
[FlushInstructionCache](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-flushinstructioncache) once the code has been set
in place. Otherwise attempts to execute code out of the newly executable region may produce unpredictable
results.

#### Examples

For code examples, see [Virtual2Alloc](https://msdn.microsoft.com/en-us/library/Mt832849(v=VS.85).aspx).

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex)

[VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)

[VirtualProtectFromApp](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotectfromapp)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)