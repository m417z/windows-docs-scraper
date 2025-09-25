# NtFreeVirtualMemory function

## Description

The **NtFreeVirtualMemory** routine releases, decommits, or both releases and decommits, a region of pages within the virtual address space of a specified process.

## Parameters

### `ProcessHandle` [in]

A handle for the process in whose context the pages to be freed reside. Use the **NtCurrentProcess** macro, defined in *Ntddk.h*, to specify the current process.

### `BaseAddress` [in, out]

A pointer to a variable that will receive the base virtual address of the freed region of pages.

If the MEM_RELEASE flag is set in the *FreeType* parameter, *\*BaseAddress* must be the base address returned by [**NtAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory) when the region was reserved.

### `RegionSize` [in, out]

A pointer to a variable that will receive the actual size, in bytes, of the freed region of pages. The routine rounds the initial value of this variable up to the next host page size boundary and writes the rounded value back to this variable.

If the MEM_RELEASE flag is set in *\*FreeType*, *\*RegionSize* must be zero. **NtFreeVirtualMemory** frees the entire region that was reserved in the initial allocation call to **NtAllocateVirtualMemory**.

If the MEM_DECOMMIT flag is set in *\*FreeType*, **NtFreeVirtualMemory** decommits all memory pages that contain one or more bytes in the range from *\*BaseAddress* to (*\*BaseAddress* + *\*RegionSize*). This means, for example, that if a two-byte region of memory straddles a page boundary, both pages are decommitted.

**NtFreeVirtualMemory** decommits the entire region that was reserved by **NtAllocateVirtualMemory**. If the following three conditions are met, the entire region enters the reserved state:

* The MEM_DECOMMIT flag is set.
* *\*BaseAddress* is the base address returned by **NtAllocateVirtualMemory** when the region was reserved.
* *\*RegionSize* is zero.

### `FreeType` [in]

A bitmask containing flags that describe the type of free operation that **NtFreeVirtualMemory** will perform for the specified region of pages. The possible values are listed in the following table.

| Flag | Meaning |
| ---- | ------- |
| MEM_DECOMMIT | **NtFreeVirtualMemory** will decommit the specified region of pages. The pages enter the reserved state. **NtFreeVirtualMemory** doesn't fail if you attempt to decommit an uncommitted page. This means that you can decommit a range of pages without first determining their current commitment state. |
| MEM_RELEASE | **NtFreeVirtualMemory** will release the specified region of pages. The pages enter the free state. If you specify this flag, **RegionSize** must be zero, and **BaseAddress** must point to the base address returned by [**NtAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory) when the region was reserved. **NtFreeVirtualMemory** fails if either of these conditions is not met. If any pages in the region are currently committed, **NtFreeVirtualMemory** first decommits and then releases them. **NtFreeVirtualMemory** doesn't fail if you attempt to release pages that are in different states, some reserved and some committed. This means that you can release a range of pages without first determining their current commitment state. |

## Return value

**NtFreeVirtualMemory** returns either STATUS_SUCCESS or an error status code. Possible error status codes include the following.

| Return code | Description |
| ----------- | ----------- |
| **STATUS_ACCESS_DENIED** | A process has requested access to an object, but has not been granted those access rights. |
| **STATUS_INVALID_HANDLE** | An invalid *ProcessHandle* value was specified.
| **STATUS_OBJECT_TYPE_MISMATCH** | There is a mismatch between the type of object required by the requested operation and the type of object that is specified in the request. |

## Remarks

Each page in the process's virtual address space is in one of the three states described in the following table.

| State | Meaning |
| ----- | ------- |
| FREE | The page is neither committed nor reserved. The page is not accessible to the process. Attempting to read from or write to a free page results in an access violation exception. You can use **NtFreeVirtualMemory** to put reserved or committed pages into the free state. |
| RESERVED | The page is reserved. The range of addresses cannot be used by other allocation functions. The page is not accessible to the process and has no physical storage associated with it. Attempting to read from or write to a reserved page results in an access violation exception. You can use **NtFreeVirtualMemory** to put committed memory pages into the reserved state, and to put reserved memory pages into the free state. |
| COMMITTED | The page is committed. Physical storage in memory or in the paging file on disk is allocated for the page, and access is controlled by a protection code. The system initializes and loads each committed page into physical memory only at the first attempt to read from or write to that page. When a process terminates, the system releases all storage for committed pages. You can use [**NtAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory) to put committed memory pages into either the reserved or free state. |

**NtFreeVirtualMemory** can perform the following operations:

* Decommit a region of committed or uncommitted pages. After this operation, the pages are in the reserved state.
* Release a region of reserved pages. After this operation, the pages are in the free state.
* Decommit and release a region of committed or uncommitted pages. After this operation, the pages are in the free state.

**NtFreeVirtualMemory** can decommit a range of pages that are in different states, some committed and some uncommitted. This means that you can decommit a range of pages without first determining the current commitment state of each page. Decommitting a page releases its physical storage, either in memory or in the paging file on disk.

If a page is decommitted but not released, its state changes to reserved. You can subsequently call **NtAllocateVirtualMemory** to commit it, or **NtFreeVirtualMemory** to release it. Attempting to read from or write to a reserved page results in an access violation exception.

**NtFreeVirtualMemory** can release a range of pages that are in different states, some reserved and some committed. This means that you can release a range of pages without first determining the current commitment state of each page. The entire range of pages originally reserved by [**NtAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory) must be released at the same time.

If a page is released, its state changes to free, and it is available for subsequent allocation operations. After memory has been released or decommitted, you can never refer to the memory again. Any information that may have been in that memory is gone forever. Attempting to read from or write to a free page results in an access violation exception. If you require information, do not decommit or free memory that contains that information.

For more information about memory management support for kernel-mode drivers, see [Memory Management for Windows Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

> [!NOTE]
> If the call to the **NtFreeVirtualMemory** function occurs in user mode, you should use the name "**NtFreeVirtualMemory**" instead of "**ZwFreeVirtualMemory**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**NtAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory)