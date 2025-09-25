# SetProcessWorkingSetSize function

## Description

Sets the minimum and maximum working set sizes for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose working set sizes is to be set.

The handle must have the **PROCESS_SET_QUOTA** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `dwMinimumWorkingSetSize` [in]

The minimum working set size for the process, in bytes. The virtual memory manager attempts to keep at least this much memory resident in the process whenever the process is active.

This parameter must be greater than zero but less than or equal to the maximum working set size. The default size is 50 pages (for example, this is 204,800 bytes on systems with a 4K page size). If the value is greater than zero but less than 20 pages, the minimum value is set to 20 pages.

If both *dwMinimumWorkingSetSize* and *dwMaximumWorkingSetSize* have the value (**SIZE_T**)–1, the function removes as many pages as possible from the working set of the specified process.

### `dwMaximumWorkingSetSize` [in]

The maximum working set size for the process, in bytes. The virtual memory manager attempts to keep no more than this much memory resident in the process whenever the process is active and available memory is low.

This parameter must be greater than or equal to 13 pages (for example, 53,248 on systems with a 4K page size), and less than the system-wide maximum (number of available pages minus 512 pages). The default size is 345 pages (for example, this is 1,413,120 bytes on systems with a 4K page size).

If both *dwMinimumWorkingSetSize* and *dwMaximumWorkingSetSize* have the value (**SIZE_T**)–1, the function removes as many pages as possible from the working set of the specified process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain extended error information.

## Remarks

The working set of a process is the set of memory pages in the virtual address space of the process that are currently resident in physical memory. These pages are available for an application to use without triggering a page fault. For more information about page faults, see [Working Set](https://learn.microsoft.com/windows/desktop/Memory/working-set). The minimum and maximum working set sizes affect the virtual memory paging behavior of a process.

The working set of the specified process can be emptied by specifying the value (**SIZE_T**)–1 for both the minimum and maximum working set sizes. This removes as many pages as possible from the working set. The [EmptyWorkingSet](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-emptyworkingset) function can also be used for this purpose.

If the values of either *dwMinimumWorkingSetSize* or *dwMaximumWorkingSetSize* are greater than the process' current working set sizes, the specified process must have the **SE_INC_WORKING_SET_NAME** privilege. All users generally have this privilege. For more information about security privileges, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

**Windows Server 2003 and Windows XP:** The specified process must have the **SE_INC_BASE_PRIORITY_NAME** privilege. Users in the Administrators and Power Users groups generally have this privilege.

The operating system allocates working set sizes on a first-come, first-served basis. For example, if an application successfully sets 40 megabytes as its minimum working set size on a 64-megabyte system, and a second application requests a 40-megabyte working set size, the operating system denies the second application's request.

Using the **SetProcessWorkingSetSize** function to set an application's minimum and maximum working set sizes does not guarantee that the requested memory will be reserved, or that it will remain resident at all times. When the application is idle, or a low-memory situation causes a demand for memory, the operating system can reduce the application's working set. An application can use the [VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)function to lock ranges of the application's virtual address space in memory; however, that can potentially degrade the performance of the system.

When you increase the working set size of an application, you are taking away physical memory from the rest of the system. This can degrade the performance of other applications and the system as a whole. It can also lead to failures of operations that require physical memory to be present (for example, creating processes, threads, and kernel pool). Thus, you must use the
**SetProcessWorkingSetSize** function carefully. You must always consider the performance of the whole system when you are designing an application.

## See also

[GetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-getprocessworkingsetsize)

[Process Working Set](https://learn.microsoft.com/windows/desktop/ProcThread/process-working-set)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SetProcessWorkingSetSizeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setprocessworkingsetsizeex)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)