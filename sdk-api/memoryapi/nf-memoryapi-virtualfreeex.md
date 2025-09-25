# VirtualFreeEx function

## Description

Releases, decommits, or releases and decommits a region of memory within the virtual address space of a specified process.

## Parameters

### `hProcess` [in]

A handle to a process. The function frees memory within the virtual address space of the process.

The handle must have the **PROCESS_VM_OPERATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `lpAddress` [in]

A pointer to the starting address of the region of memory to be freed.

If the *dwFreeType* parameter is **MEM_RELEASE**, *lpAddress* must be the base address returned by the
[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex) function when the region is reserved.

### `dwSize` [in]

The size of the region of memory to free, in bytes.

If the *dwFreeType* parameter is **MEM_RELEASE**, *dwSize* must be 0 (zero). The function frees the entire region that is reserved in the initial allocation call to
[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex).

If *dwFreeType* is **MEM_DECOMMIT**, the function decommits all memory pages that contain one or more bytes in the range from the *lpAddress* parameter to `(lpAddress+dwSize)`. This means, for example, that a 2-byte region of memory that straddles a page boundary causes both pages to be decommitted. If *lpAddress* is the base address returned by
[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex) and *dwSize* is 0 (zero), the function decommits the entire region that is allocated by
**VirtualAllocEx**. After that, the entire region is in the reserved state.

### `dwFreeType` [in]

The type of free operation. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_DECOMMIT**<br><br>0x00004000 | Decommits the specified region of committed pages. After the operation, the pages are in the reserved state.<br><br>The function does not fail if you attempt to decommit an uncommitted page. This means that you can decommit a range of pages without first determining the current commitment state.<br><br>The **MEM_DECOMMIT** value is not supported when the *lpAddress* parameter provides the base address for an enclave. This is true for enclaves that do not support dynamic memory management (i.e. SGX1). SGX2 enclaves permit MEM_DECOMMIT anywhere in the enclave. |
| **MEM_RELEASE**<br><br>0x00008000 | Releases the specified region of pages, or placeholder (for a placeholder, the address space is released and available for other allocations). After this operation, the pages are in the free state. <br><br>If you specify this value, *dwSize* must be 0 (zero), and *lpAddress* must point to the base address returned by the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function when the region is reserved. The function fails if either of these conditions is not met.<br><br>If any pages in the region are committed currently, the function first decommits, and then releases them.<br><br>The function does not fail if you attempt to release pages that are in different states, some reserved and some committed. This means that you can release a range of pages without first determining the current commitment state. |

When using **MEM_RELEASE**, this parameter can additionally specify one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_COALESCE_PLACEHOLDERS**<br><br>0x00000001 | To coalesce two adjacent placeholders, specify `MEM_RELEASE | MEM_COALESCE_PLACEHOLDERS`. When you coalesce placeholders, *lpAddress* and *dwSize* must exactly match the overall range of the placeholders to be merged. |
| **MEM_PRESERVE_PLACEHOLDER**<br><br>0x00000002 | Frees an allocation back to a placeholder (after you've replaced a placeholder with a private allocation using [VirtualAlloc2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc2) or [Virtual2AllocFromApp](https://msdn.microsoft.com/en-us/library/Mt832850(v=VS.85).aspx)).<br><br>To split a placeholder into two placeholders, specify `MEM_RELEASE | MEM_PRESERVE_PLACEHOLDER`. |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Each page of memory in a process virtual address space has a
[Page State](https://learn.microsoft.com/windows/desktop/Memory/page-state). The
**VirtualFreeEx** function can decommit a range of pages that are in different states, some committed and some uncommitted. This means that you can decommit a range of pages without first determining the current commitment state of each page. Decommitting a page releases its physical storage, either in memory or in the paging file on disk.

If a page is decommitted but not released, its state changes to reserved. Subsequently, you can call
[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex) to commit it, or
**VirtualFreeEx** to release it. Attempting to read from or write to a reserved page results in an access violation exception.

The **VirtualFreeEx** function can release a range of pages that are in different states, some reserved and some committed. This means that you can release a range of pages without first determining the current commitment state of each page. The entire range of pages originally reserved by [VirtualAllocEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex) must be released at the same time.

If a page is released, its state changes to free, and it is available for subsequent allocation operations. After memory is released or decommitted, you can never refer to the memory again. Any information that may have been in that memory is gone forever. Attempts to read from or write to a free page results in an access violation exception. If you need to keep information, do not decommit or free memory that contains the information.

The **VirtualFreeEx** function can be used on an AWE region of memory and it invalidates any physical page mappings in the region when freeing the address space. However, the physical pages are not deleted, and the application can use them. The application must explicitly call [FreeUserPhysicalPages](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-freeuserphysicalpages) to free the physical pages. When the process is terminated, all resources are automatically cleaned up.

**Windows 10, version 1709 and later and Windows 11:** To delete the enclave when you finish using it, call [DeleteEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-deleteenclave). You cannot delete a VBS enclave by calling the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or **VirtualFreeEx** function. You can still delete an SGX enclave by calling **VirtualFree** or **VirtualFreeEx**.

**Windows 10, version 1507, Windows 10, version 1511, Windows 10, version 1607 and Windows 10, version 1703:** To delete the enclave when you finish using it, call the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or **VirtualFreeEx** function and specify the following values:

- The base address of the enclave for the _lpAddress_ parameter.
- 0 for the _dwSize_ parameter.
- **MEM_RELEASE** for the _dwFreeType_ parameter.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Virtual Memory Functions](https://learn.microsoft.com/windows/win32/Memory/virtual-memory-functions)

[VirtualAllocEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex)