# ZwFreeVirtualMemory function

## Description

The **ZwFreeVirtualMemory** routine releases, decommits, or both, a region of pages within the virtual address space of a specified process.

## Parameters

### `ProcessHandle` [in]

A handle for the process in whose context the pages to be freed reside. Use the **NtCurrentProcess** macro, defined in Ntddk.h, to specify the current process.

### `BaseAddress` [in, out]

A pointer to a variable that will receive the virtual address of the freed region of pages.

If the MEM_RELEASE flag is set in the *FreeType* parameter, *BaseAddress* must be the base address returned by [**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory) when the region was reserved.

### `RegionSize` [in, out]

A pointer to a variable that will receive the actual size, in bytes, of the freed region of pages. The routine rounds the initial value of this variable up to the next host page size boundary and writes the rounded value back to this variable.

If the MEM_RELEASE flag is set in the *FreeType* parameter, the variable pointed to by *RegionSize* must be zero. **ZwFreeVirtualMemory** frees the entire region that was reserved in the initial allocation call to [**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory).

If the MEM_DECOMMIT flag is set in the *FreeType* parameter, **ZwFreeVirtualMemory** decommits all memory pages that contain one or more bytes in the range from the *BaseAddress* parameter to (*BaseAddress* + *RegionSize*). This means, for example, that if a two-byte region of memory straddles a page boundary, both pages are decommitted.

**ZwFreeVirtualMemory** decommits the entire region that was reserved by [**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory). If the following three conditions are met, the entire region enters the reserved state:

* The MEM_DECOMMIT flag is set.
* *BaseAddress* is the base address returned by **ZwAllocateVirtualMemory** when the region was reserved.
* *RegionSize<* is zero.

### `FreeType` [in]

A bitmask that contains flags that describe the type of free operation that **ZwFreeVirtualMemory** will perform for the specified region of pages. Possible values are the following:

* MEM_DECOMMIT
  * **ZwFreeVirtualMemory** will decommit the specified region of pages. The pages enter the reserved state.

  * **ZwFreeVirtualMemory** does not fail if you attempt to decommit an uncommitted page. This means that you can decommit a range of pages without first determining their current commitment state.

* MEM_RELEASE

  **ZwFreeVirtualMemory** will release the specified region of pages. The pages enter the free state.

 If you specify this flag, The variable that **RegionSize** points to must be zero, and **BaseAddress** must point to the base address returned by [**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory) when the region was reserved. **ZwFreeVirtualMemory** fails if either of these conditions is not met.

 If any pages in the region are currently committed, **ZwFreeVirtualMemory** first decommits and then releases them.

**ZwFreeVirtualMemory** does not fail if you attempt to release pages that are in different states, some reserved and some committed. This means that you can release a range of pages without first determining their current commitment state.

## Return value

**ZwFreeVirtualMemory** returns either STATUS_SUCCESS or an error status code. Possible error status codes include the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | A process has requested access to an object, but has not been granted those access rights. |
| STATUS_INVALID_HANDLE | An invalid *ProcessHandle* value was specified. |
| STATUS_OBJECT_TYPE_MISMATCH | There is a mismatch between the type of object required by the requested operation and the type of object that is specified in the request. |

## Remarks

Each page in the process's virtual address space is in one of the three states described as follows.

* State is FREE

 The page is neither committed nor reserved. The page is not accessible to the process. Attempting to read from or write to a free page results in an access violation exception.

 You can use **ZwFreeVirtualMemory** to put reserved or committed pages into the free state.

* State is RESERVED

 The page is reserved. The range of addresses cannot be used by other allocation functions. The page is not accessible to the process and has no physical storage associated with it. Attempting to read from or write to a reserved page results in an access violation exception.

 You can use **ZwFreeVirtualMemory** to put committed memory pages into the reserved state, and to put reserved memory pages into the free state.

* State is COMMITTED

 The page is committed. Physical storage in memory or in the paging file on disk is allocated for the page, and access is controlled by a protection code.

 The system initializes and loads each committed page into physical memory only at the first attempt to read from or write to that page.

 When a process terminates, the system releases all storage for committed pages.

 You can use [**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory) to put committed memory pages into either the reserved or free state.

**ZwFreeVirtualMemory** can perform the following operations:

* Decommit a region of committed or uncommitted pages. After this operation, the pages are in the reserved state.
* Release a region of reserved pages. After this operation, the pages are in the free state.
* Decommit and release a region of committed or uncommitted pages. After this operation, the pages are in the free state.

**ZwFreeVirtualMemory** can decommit a range of pages that are in different states, some committed and some uncommitted. This means that you can decommit a range of pages without first determining the current commitment state of each page. Decommitting a page releases its physical storage, either in memory or in the paging file on disk.

If a page is decommitted but not released, its state changes to reserved. You can subsequently call **ZwFreeVirtualMemory** to commit it, or **ZwFreeVirtualMemory** to release it. Attempting to read from or write to a reserved page results in an access violation exception.

**ZwFreeVirtualMemory** can release a range of pages that are in different states, some reserved and some committed. This means that you can release a range of pages without first determining the current commitment state of each page. The entire range of pages originally reserved by [**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory) must be released at the same time.

If a page is released, its state changes to free, and it is available for subsequent allocation operations. After memory has been released or decommitted, you can never refer to the memory again. Any information that may have been in that memory is gone forever. Attempting to read from or write to a free page results in an access violation exception. If you require information, do not decommit or free memory that contains that information.

For more information about memory management support for kernel-mode drivers, see [Memory Management for Windows Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

> [!NOTE]
> If the call to the **ZwFreeVirtualMemory** function occurs in user mode, you should use the name "**NtFreeVirtualMemory**" instead of "**ZwFreeVirtualMemory**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**ZwAllocateVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory)