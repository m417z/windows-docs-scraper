# AllocateUserPhysicalPages2 function

## Description

Allocates physical memory pages to be mapped and unmapped within any [Address Windowing Extensions (AWE)](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) region of a specified process, with extended parameters.

## Parameters

### `ObjectHandle` [in]

A handle to a process.

The function allocates memory that can later be mapped within the virtual address space of this process. The handle must have the **PROCESS_VM_OPERATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `NumberOfPages` [in,out]

The size of the physical memory to allocate, in pages.

To determine the page size of the computer, use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function. On output, this parameter receives the number of pages that are actually allocated, which might be less than the number requested.

### `PageArray` [out]

A pointer to an array to store the page frame numbers of the allocated memory.

The size of the array that is allocated should be at least the *NumberOfPages* times the size of the **ULONG_PTR** data type.

Do not attempt to modify this buffer. It contains operating system data, and corruption could be catastrophic. The information in the buffer is not useful to an application.

### `ExtendedParameters` [in,out]

Pointer to an array of [MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter) structures.

### `ExtendedParameterCount` [in]

The number of **MEM_EXTENDED_PARAMETER** in the *ExtendedParameters* array.

## Return value

If the function succeeds, the return value is **TRUE**.

Fewer pages than requested can be allocated. The caller must check the value of the *NumberOfPages* parameter on return to see how many pages are allocated. All allocated page frame numbers are sequentially placed in the memory pointed to by the *UserPfnArray* parameter.

If the function fails, the return value is **FALSE**, and no frames are allocated. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**AllocateUserPhysicalPages2** is the same as [AllocateUserPhysicalPages](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-allocateuserphysicalpages) but it adds the *ExtendedParameters* and *ExtendedParameterCount* parameters.

The **AllocateUserPhysicalPages2** function is used to allocate physical memory that can later be mapped within the virtual address space of the process. The **SeLockMemoryPrivilege** privilege must be enabled in the caller's token or the function will fail with **ERROR_PRIVILEGE_NOT_HELD**. For more information, see [Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants).

Memory allocated by this function must be physically present in the system. After the memory is allocated, it is locked down and unavailable to the rest of the virtual memory management system.

Physical pages cannot be simultaneously mapped at more than one virtual address.

Physical pages can reside at any physical address. You should make no assumptions about the contiguity of the physical pages.

## See also

[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-allocateuserphysicalpages)

[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions)

[AllocateUserPhysicalPagesNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpagesnuma)

[FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages)

[MapUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapuserphysicalpages)

[MapUserPhysicalPagesScatter](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapuserphysicalpagesscatter)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)