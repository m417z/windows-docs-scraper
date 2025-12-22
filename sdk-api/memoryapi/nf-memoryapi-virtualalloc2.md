# VirtualAlloc2 function

## Description

Reserves, commits, or changes the state of a region of memory within the virtual address space of a specified process (allocated memory is initialized to zero).

## Parameters

### `Process` [in, optional]

The handle to a process. The function allocates memory within the virtual address space of this process.

The handle must have the **PROCESS_VM_OPERATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

If *Process* is **NULL**, the function allocates memory for the calling process.

### `BaseAddress` [in, optional]

The pointer that specifies a desired starting address for the region of pages that you want to allocate.

If *BaseAddress* is **NULL**, the function determines where to allocate the region.

If *BaseAddress* is not **NULL**, then
any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes,
and the base address must be a multiple of the system allocation granularity. To determine the allocation granularity, use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function.

If this address is within an enclave that you have not initialized by calling [InitializeEnclave](https://learn.microsoft.com/windows/desktop/api/enclaveapi/nf-enclaveapi-initializeenclave), **VirtualAlloc2** allocates a page of zeros for the enclave at that address. The page must be previously uncommitted, and will not be measured with the EEXTEND instruction of the Intel Software Guard Extensions programming model.

If the address is within an enclave that you initialized, then the allocation operation fails with the **ERROR_INVALID_ADDRESS** error. That is true for enclaves that do not support dynamic memory management (i.e. SGX1). SGX2 enclaves will permit allocation, and the page must be accepted by the enclave after it has been allocated.

### `Size` [in]

The size of the region of memory to allocate, in bytes.

The size must always be a multiple of the page size.

If *BaseAddress* is not **NULL**, the function allocates all pages that contain one or more bytes in the range from *BaseAddress* to *BaseAddress*+*Size*. This means, for example, that a 2-byte range that straddles a page boundary causes the function to allocate both pages.

### `AllocationType` [in]

The type of memory allocation. This parameter must contain one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_COMMIT**<br><br>0x00001000 | Allocates memory charges (from the overall size of memory and the paging files on disk) for the specified reserved memory pages. The function also guarantees that when the caller later initially accesses the memory, the contents will be zero. Actual physical pages are not allocated unless/until the virtual addresses are actually accessed.<br><br>To reserve and commit pages in one step, call **VirtualAlloc2** with `MEM_COMMIT \| MEM_RESERVE`.<br><br>Attempting to commit a specific address range by specifying **MEM_COMMIT** without **MEM_RESERVE** and a non-**NULL** *BaseAddress* fails unless the entire range has already been reserved. The resulting error code is **ERROR_INVALID_ADDRESS**.<br><br>An attempt to commit a page that is already committed does not cause the function to fail. This means that you can commit pages without first determining the current commitment state of each page.<br><br>If *BaseAddress* specifies an address within an enclave, *AllocationType* must be **MEM_COMMIT**. |
| **MEM_RESERVE**<br><br>0x00002000 | Reserves a range of the process's virtual address space without allocating any actual physical storage in memory or in the paging file on disk.<br><br>You commit reserved pages by calling **VirtualAlloc2** again with **MEM_COMMIT**. To reserve and commit pages in one step, call **VirtualAlloc2** with `MEM_COMMIT \| MEM_RESERVE`.<br><br>Other memory allocation functions, such as **malloc** and [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc), cannot use reserved memory until it has been released. |
| **MEM_REPLACE_PLACEHOLDER**<br><br>0x00004000 | Replaces a placeholder with a normal private allocation. Only data/pf-backed section views are supported (no images, physical memory, etc.). When you replace a placeholder, *BaseAddress* and *Size* must exactly match those of the placeholder, and any provided [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure must consist of all zeroes.<br><br>After you replace a placeholder with a private allocation, to free that allocation back to a placeholder, see the *dwFreeType* parameter of [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) and [VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex).<br><br>A placeholder is a type of reserved memory region. |
| **MEM_RESERVE_PLACEHOLDER**<br><br>0x00040000 | To create a placeholder, call **VirtualAlloc2** with `MEM_RESERVE \| MEM_RESERVE_PLACEHOLDER` and *PageProtection* set to **PAGE_NOACCESS**. To free/split/coalesce a placeholder, see the *dwFreeType* parameter of [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) and [VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex).<br><br>A placeholder is a type of reserved memory region. |
| **MEM_RESET**<br><br>0x00080000 | Indicates that data in the memory range specified by *BaseAddress* and *Size* is no longer of interest. The pages should not be read from or written to the paging file. However, the memory block will be used again later, so it should not be decommitted. This value cannot be used with any other value.<br><br>Using this value does not guarantee that the range operated on with **MEM_RESET** will contain zeros. If you want the range to contain zeros, decommit the memory and then recommit it.<br><br>When you use **MEM_RESET**, the **VirtualAlloc2** function ignores the value of *fProtect*. However, you must still set *fProtect* to a valid protection value, such as **PAGE_NOACCESS**.<br><br>**VirtualAlloc2** returns an error if you use **MEM_RESET** and the range of memory is mapped to a file. A shared view is only acceptable if it is mapped to a paging file. |
| **MEM_RESET_UNDO**<br><br>0x1000000 | **MEM_RESET_UNDO** should only be called on an address range to which **MEM_RESET** was successfully applied earlier. It indicates that the data in the specified memory range specified by *BaseAddress* and *Size* is of interest to the caller and attempts to reverse the effects of **MEM_RESET**. If the function succeeds, that means all data in the specified address range is intact. If the function fails, at least some of the data in the address range has been replaced with zeroes.<br><br>This value cannot be used with any other value. If **MEM_RESET_UNDO** is called on an address range which was not **MEM_RESET** earlier, the behavior is undefined. When you specify **MEM_RESET**, the **VirtualAlloc2** function ignores the value of *PageProtection*. However, you must still set *PageProtection* to a valid protection value, such as **PAGE_NOACCESS**.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** The **MEM_RESET_UNDO** flag is not supported until Windows 8 and Windows Server 2012. |

This parameter can also specify the following values as indicated.

| Value | Meaning |
| --- | --- |
| **MEM_LARGE_PAGES**<br><br>0x20000000 | Allocates memory using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support).<br><br>The size and alignment must be a multiple of the large-page minimum. To obtain this value, use the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function.<br><br>If you specify this value, you must also specify **MEM_RESERVE** and **MEM_COMMIT**. |
| **MEM_64K_PAGES**<br><br>0x20400000 | A hint to the operating system to map the memory using 64K pages, if possible.<br><br>A 64K page is a region of memory that is 64K in size, virtually and physically contiguous, and virtually and physically aligned on a 64K boundary.<br><br>By default, memory allocated using MEM_64K_PAGES is pageable, and physical pages backing the memory are allocated on demand (at the time of access). If physical memory is too fragmented to assemble a physically contiguous 64K page, all or part of a MEM_64K_PAGES allocation may be mapped using non-contiguous small pages instead.<br><br>If MEM_64K_PAGES is combined with the [MEM_EXTENDED_PARAMETER_NONPAGED](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter) attribute, the allocation will be mapped using non-paged 64K pages. In that case, if contiguous 64K pages cannot be obtained, the allocation will fail.<br><br>If MEM_64K_PAGES is specified, the Size and BaseAddress parameters must both be multiples of 64K (BaseAddress may be NULL). |
| **MEM_PHYSICAL**<br><br>0x00400000 | Reserves an address range that can be used to map [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) pages.<br><br>This value must be used with **MEM_RESERVE** and no other values. |
| **MEM_TOP_DOWN**<br><br>0x00100000 | Allocates memory at the highest possible address. This can be slower than regular allocations, especially when there are many allocations. |

### `PageProtection` [in]

The memory protection for the region of pages to be allocated. If the pages are being committed, you can specify any one of the [memory protection constants](https://learn.microsoft.com/windows/win32/Memory/memory-protection-constants).

If _BaseAddress_ specifies an address within an enclave, _PageProtection_ cannot be any of the following values:

- PAGE_NOACCESS
- PAGE_GUARD
- PAGE_NOCACHE
- PAGE_WRITECOMBINE

When allocating dynamic memory for an enclave, the _PageProtection_ parameter must be **PAGE_READWRITE** or **PAGE_EXECUTE_READWRITE**.

### `ExtendedParameters` [in, out, optional]

An optional pointer to one or more extended parameters of type [MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter). Each of those extended parameter values can itself have a *Type* field of either **MemExtendedParameterAddressRequirements** or **MemExtendedParameterNumaNode**. If no **MemExtendedParameterNumaNode** extended parameter is provided, then the behavior is the same as for the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)/[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) functions (that is, the preferred NUMA node for the physical pages is determined based on the ideal processor of the thread that first accesses the memory).

### `ParameterCount` [in]

The number of extended parameters pointed to by *ExtendedParameters*.

## Return value

If the function succeeds, the return value is the base address of the allocated region of pages.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function lets you specify:

- a range of virtual address space and a power-of-2 alignment restriction for new allocations
- an arbitrary number of extended parameters
- a preferred NUMA node for the physical memory as an extended parameter (see the *ExtendedParameters* parameter)
- a placeholder operation (specifically, replacement).

This API provides specialized techniques for managing virtual memory in support of high-performance games and server applications. For example, placeholders allow a reserved memory range to be explicitly partitioned, overlaid, and re-mapped; this can be used to implement arbitrarily extendable regions or virtual memory ring buffers. **VirtualAlloc2** also allows for allocating memory with a specific memory-alignment.

Each page has an associated [page state](https://learn.microsoft.com/windows/desktop/Memory/page-state). The **VirtualAlloc2** function can perform the following operations:

* Commit a region of reserved pages
* Reserve a region of free pages
* Simultaneously reserve and commit a region of free pages

**VirtualAlloc2** can commit pages that are already committed, but cannot reserve pages that are already reserved. This means you can commit a range of pages, regardless of whether they have already been committed, and the function will not fail. In general however, only a minimal range of mostly uncommitted pages should be specified, because committing a large number of pages that are already committed can cause the **VirtualAlloc2** call to take much longer.

You can use **VirtualAlloc2** to reserve a block of pages and then make additional calls to **VirtualAlloc2** to commit individual pages from the reserved block. This enables a process to reserve a range of its virtual address space without consuming physical storage until it is needed.

If the *lpAddress* parameter is not **NULL**, the function uses the *lpAddress* and *dwSize* parameters to compute the region of pages to be allocated. The current state of the entire range of pages must be compatible with the type of allocation specified by the *flAllocationType* parameter. Otherwise, the function fails and none of the pages is allocated. This compatibility requirement does not preclude committing an already committed page; see the preceding list.

To execute dynamically generated code, use **VirtualAlloc2** to allocate memory, and the [VirtualProtectEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotectex) function to grant **PAGE_EXECUTE** access.

The **VirtualAlloc2** function can be used to reserve an [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) region of memory within the virtual address space of a specified process. This region of memory can then be used to map physical pages into and out of virtual memory as required by the application. The **MEM_PHYSICAL** and **MEM_RESERVE** values must be set in the *AllocationType* parameter. The **MEM_COMMIT** value must not be set. The page protection must be set to **PAGE_READWRITE**.

The [VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex) function can decommit a committed page, releasing the page's storage, or it can simultaneously decommit and release a committed page. It can also release a reserved page, making it a free page.

When creating a region that will be executable, the calling program bears responsibility for ensuring cache coherency via an appropriate call to [FlushInstructionCache](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-flushinstructioncache) once the code has been set in place. Otherwise attempts to execute code out of the newly executable region may produce unpredictable results.

#### Examples

Scenario 1. Create a circular buffer by mapping two adjacent views of the same shared memory section.

```cpp
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

//
// This function creates a ring buffer by allocating a pagefile-backed section
// and mapping two views of that section next to each other. This way if the
// last record in the buffer wraps it can still be accessed in a linear fashion
// using its base VA.
//

void*
CreateRingBuffer (
    unsigned int bufferSize,
    _Outptr_ void** secondaryView
    )
{
    BOOL result;
    HANDLE section = nullptr;
    SYSTEM_INFO sysInfo;
    void* ringBuffer = nullptr;
    void* placeholder1 = nullptr;
    void* placeholder2 = nullptr;
    void* view1 = nullptr;
    void* view2 = nullptr;

    GetSystemInfo (&sysInfo);

    if ((bufferSize % sysInfo.dwAllocationGranularity) != 0) {
        return nullptr;
    }

    //
    // Reserve a placeholder region where the buffer will be mapped.
    //

    placeholder1 = (PCHAR) VirtualAlloc2 (
        nullptr,
        nullptr,
        2 * bufferSize,
        MEM_RESERVE | MEM_RESERVE_PLACEHOLDER,
        PAGE_NOACCESS,
        nullptr, 0
    );

    if (placeholder1 == nullptr) {
        printf ("VirtualAlloc2 failed, error %#x\n", GetLastError());
        goto Exit;
    }

    //
    // Split the placeholder region into two regions of equal size.
    //

    result = VirtualFree (
        placeholder1,
        bufferSize,
        MEM_RELEASE | MEM_PRESERVE_PLACEHOLDER
    );

    if (result == FALSE) {
        printf ("VirtualFreeEx failed, error %#x\n", GetLastError());
        goto Exit;
    }

    placeholder2 = (void*) ((ULONG_PTR) placeholder1 + bufferSize);

    //
    // Create a pagefile-backed section for the buffer.
    //

    section = CreateFileMapping (
        INVALID_HANDLE_VALUE,
        nullptr,
        PAGE_READWRITE,
        0,
        bufferSize, nullptr
    );

    if (section == nullptr) {
        printf ("CreateFileMapping failed, error %#x\n", GetLastError());
        goto Exit;
    }

    //
    // Map the section into the first placeholder region.
    //

    view1 = MapViewOfFile3 (
        section,
        nullptr,
        placeholder1,
        0,
        bufferSize,
        MEM_REPLACE_PLACEHOLDER,
        PAGE_READWRITE,
        nullptr, 0
    );

    if (view1 == nullptr) {
        printf ("MapViewOfFile3 failed, error %#x\n", GetLastError());
        goto Exit;
    }

    //
    // Ownership transferred, don't free this now.
    //

    placeholder1 = nullptr;

    //
    // Map the section into the second placeholder region.
    //

    view2 = MapViewOfFile3 (
        section,
        nullptr,
        placeholder2,
        0,
        bufferSize,
        MEM_REPLACE_PLACEHOLDER,
        PAGE_READWRITE,
        nullptr, 0
    );

    if (view2 == nullptr) {
        printf ("MapViewOfFile3 failed, error %#x\n", GetLastError());
        goto Exit;
    }

    //
    // Success, return both mapped views to the caller.
    //

    ringBuffer = view1;
    *secondaryView = view2;

    placeholder2 = nullptr;
    view1 = nullptr;
    view2 = nullptr;

Exit:

    if (section != nullptr) {
        CloseHandle (section);
    }

    if (placeholder1 != nullptr) {
        VirtualFree (placeholder1, 0, MEM_RELEASE);
    }

    if (placeholder2 != nullptr) {
        VirtualFree (placeholder2, 0, MEM_RELEASE);
    }

    if (view1 != nullptr) {
        UnmapViewOfFileEx (view1, 0);
    }

    if (view2 != nullptr) {
        UnmapViewOfFileEx (view2, 0);
    }

    return ringBuffer;
}

int __cdecl wmain()
{
    char* ringBuffer;
    void* secondaryView;
    unsigned int bufferSize = 0x10000;

    ringBuffer = (char*) CreateRingBuffer (bufferSize, &secondaryView);

    if (ringBuffer == nullptr) {
        printf ("CreateRingBuffer failed\n");
        return 0;
    }

    //
    // Make sure the buffer wraps properly.
    //

    ringBuffer[0] = 'a';

    if (ringBuffer[bufferSize] == 'a') {
        printf ("The buffer wraps as expected\n");
    }

    UnmapViewOfFile (ringBuffer);
    UnmapViewOfFile (secondaryView);
}

```

Scenario 2. Specify a preferred NUMA node when allocating memory.

```cpp

void*
AllocateWithPreferredNode (size_t size, unsigned int numaNode)
{
    MEM_EXTENDED_PARAMETER param = {0};

    param.Type = MemExtendedParameterNumaNode;
    param.ULong = numaNode;

    return VirtualAlloc2 (
        nullptr, nullptr,
        size,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE,
        &param, 1);
}

```

Scenario 3. Allocate memory in a specific virtual address range (below 4GB, in this example) and with specific alignment.

```cpp

void*
AllocateAlignedBelow2GB (size_t size, size_t alignment)
{
    MEM_ADDRESS_REQUIREMENTS addressReqs = {0};
    MEM_EXTENDED_PARAMETER param = {0};

    addressReqs.Alignment = alignment;
    addressReqs.HighestEndingAddress = (PVOID)(ULONG_PTR) 0x7fffffff;

    param.Type = MemExtendedParameterAddressRequirements;
    param.Pointer = &addressReqs;

    return VirtualAlloc2 (
        nullptr, nullptr,
        size,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE,
        &param, 1);
}

```

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAllocExNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocexnuma)

[VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)

[VirtualProtect](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotect)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)

[WriteProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-writeprocessmemory)