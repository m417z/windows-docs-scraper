# VirtualAllocExNuma function

## Description

Reserves, commits, or changes the state of a region of memory within the virtual address space of the specified process, and
specifies the NUMA node for the physical memory.

## Parameters

### `hProcess` [in]

The handle to a process. The function allocates memory within the virtual address space of this process.

The handle must have the **PROCESS_VM_OPERATION** access right. For more information,
see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `lpAddress` [in, optional]

The pointer that specifies a desired starting address for the region of pages that you want to allocate.

If you are reserving memory, the function rounds this address down to the nearest multiple of the allocation
granularity.

If you are committing memory that is already reserved, the function rounds this address down to the nearest
page boundary. To determine the size of a page and the allocation granularity on the host computer, use the
[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function.

If *lpAddress* is **NULL**, the function determines where to
allocate the region.

### `dwSize` [in]

The size of the region of memory to be allocated, in bytes.

If *lpAddress* is **NULL**, the function rounds
*dwSize* up to the next page boundary.

If *lpAddress* is not **NULL**, the function allocates all
pages that contain one or more bytes in the range from *lpAddress* to
`(lpAddress+dwSize)`. This means, for example, that a 2-byte
range that straddles a page boundary causes the function to allocate both pages.

### `flAllocationType` [in]

The type of memory allocation. This parameter must contain one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_COMMIT**<br><br>0x00001000 | Allocates memory charges (from the overall size of memory and the paging files on disk) for the specified reserved memory pages. The function also guarantees that when the caller later initially accesses the memory, the contents will be zero. Actual physical pages are not allocated unless/until the virtual addresses are actually accessed.<br><br>To reserve and commit pages in one step, call the function with `MEM_COMMIT | MEM_RESERVE`.<br><br>Attempting to commit a specific address range by specifying **MEM_COMMIT** without **MEM_RESERVE** and a non-**NULL** *lpAddress* fails unless the entire range has already been reserved. The resulting error code is **ERROR_INVALID_ADDRESS**.<br><br>An attempt to commit a page that is already committed does not cause the function to fail. This means that you can commit pages without first determining the current commitment state of each page. |
| **MEM_RESERVE**<br><br>0x00002000 | Reserves a range of the process's virtual address space without allocating any actual physical storage in memory or in the paging file on disk.<br><br>You commit reserved pages by calling the function again with **MEM_COMMIT**. To reserve and commit pages in one step, call the function with `MEM_COMMIT | MEM_RESERVE`.<br><br>Other memory allocation functions, such as **malloc** and [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc), cannot use reserved memory until it has been released. |
| **MEM_RESET**<br><br>0x00080000 | Indicates that data in the memory range specified by *lpAddress* and *dwSize* is no longer of interest. The pages should not be read from or written to the paging file. However, the memory block will be used again later, so it should not be decommitted. This value cannot be used with any other value.<br><br>Using this value does not guarantee that the range operated on with **MEM_RESET** will contain zeros. If you want the range to contain zeros, decommit the memory and then recommit it.<br><br>When you use **MEM_RESET**, the function ignores the value of *fProtect*. However, you must still set *fProtect* to a valid protection value, such as **PAGE_NOACCESS**.<br><br>The function returns an error if you use **MEM_RESET** and the range of memory is mapped to a file. A shared view is only acceptable if it is mapped to a paging file. |
| **MEM_RESET_UNDO**<br><br>0x1000000 | **MEM_RESET_UNDO** should only be called on an address range to which **MEM_RESET** was successfully applied earlier. It indicates that the data in the specified memory range specified by *lpAddress* and *dwSize* is of interest to the caller and attempts to reverse the effects of **MEM_RESET**. If the function succeeds, that means all data in the specified address range is intact. If the function fails, at least some of the data in the address range has been replaced with zeroes.<br><br>This value cannot be used with any other value. If **MEM_RESET_UNDO** is called on an address range which was not **MEM_RESET** earlier, the behavior is undefined. When you specify **MEM_RESET**, the **VirtualAllocExNuma** function ignores the value of *flProtect*. However, you must still set *flProtect* to a valid protection value, such as **PAGE_NOACCESS**.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** The **MEM_RESET_UNDO** flag is not supported until Windows 8 and Windows Server 2012. |

This parameter can also specify the following values as indicated.

| Value | Meaning |
| --- | --- |
| **MEM_LARGE_PAGES**<br><br>0x20000000 | Allocates memory using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support).<br><br>The size and alignment must be a multiple of the large-page minimum. To obtain this value, use the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function.<br><br>If you specify this value, you must also specify **MEM_RESERVE** and **MEM_COMMIT**. |
| **MEM_PHYSICAL**<br><br>0x00400000 | Reserves an address range that can be used to map [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) pages.<br><br>This value must be used with **MEM_RESERVE** and no other values. |
| **MEM_TOP_DOWN**<br><br>0x00100000 | Allocates memory at the highest possible address. |

### `flProtect` [in]

The memory protection for the region of pages to be allocated. If the pages are being committed, you can
specify any one of the
[memory protection constants](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants).

Protection attributes specified when protecting a page cannot conflict with those specified when allocating
a page.

### `nndPreferred` [in]

The NUMA node where the physical memory should reside.

Used only when allocating a new VA region (either committed or reserved). Otherwise this parameter is ignored
when the API is used to commit pages in a region that already exists

## Return value

If the function succeeds, the return value is the base address of the allocated region of pages.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Each page has an associated [page state](https://learn.microsoft.com/windows/desktop/Memory/page-state). The
**VirtualAllocExNuma** function can perform the
following operations:

* Commit a region of reserved pages
* Reserve a region of free pages
* Simultaneously reserve and commit a region of free pages

**VirtualAllocExNuma** cannot reserve a reserved
page. It can commit a page that is already committed. This means you can commit a range of pages, regardless of
whether they have already been committed, and the function will not fail.

You can use **VirtualAllocExNuma** to reserve a
block of pages and then make additional calls to
**VirtualAllocExNuma** to commit individual pages from
the reserved block. This enables a process to reserve a range of its virtual address space without consuming
physical storage until it is needed.

If the *lpAddress* parameter is not **NULL**, the function uses
the *lpAddress* and *dwSize* parameters to compute the region of
pages to be allocated. The current state of the entire range of pages must be compatible with the type of
allocation specified by the *flAllocationType* parameter. Otherwise, the function fails
and none of the pages is allocated. This compatibility requirement does not preclude committing an already
committed page; see the preceding list.

Because **VirtualAllocExNuma** does not allocate any
physical pages, it will succeed whether or not the pages are available on that node or elsewhere in the system.
The physical pages are allocated on demand. If the preferred node runs out of pages, the memory manager will use
pages from other nodes. If the memory is paged out, the same process is used when it is brought back in.

To execute dynamically generated code, use
**VirtualAllocExNuma** to allocate memory and the
[VirtualProtectEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotectex) function to grant
**PAGE_EXECUTE** access.

The **VirtualAllocExNuma** function can be used to
reserve an
[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions)
(AWE) region of memory within the virtual address space of a specified process. This region of memory can then be
used to map physical pages into and out of virtual memory as required by the application. The
**MEM_PHYSICAL** and **MEM_RESERVE** values must be set in the
*AllocationType* parameter. The **MEM_COMMIT** value must not be
set. The page protection must be set to **PAGE_READWRITE**.

The [VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex) function can decommit a committed
page, releasing the page's storage, or it can simultaneously decommit and release a committed page. It can also
release a reserved page, making it a free page.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600
or later.

#### Examples

For an example, see
[Allocating Memory from a NUMA Node](https://learn.microsoft.com/windows/desktop/Memory/allocating-memory-from-a-numa-node).

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex)

[VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)

[VirtualProtect](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotect)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)