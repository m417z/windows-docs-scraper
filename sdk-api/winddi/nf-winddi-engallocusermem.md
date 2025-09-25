# EngAllocUserMem macro

## Description

The **EngAllocUserMem** function allocates a block of memory from the address space of the current process and inserts a caller-supplied tag before the allocation.

## Parameters

### `cj` [in]

Specifies the number of bytes to allocate.

### `tag` [in]

Specifies a 4-byte [pool tag](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the driver that does the memory allocation. For more information about pool tags, see [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-exallocatepoolwithtag).

## Remarks

A process in an NT-based operating system has 4 GB of virtual address space. The upper 2 GB is system memory that is accessible only to kernel-mode threads; this space is identical across all processes. The lower 2 GB is user memory that is accessible to both user-mode and kernel-mode threads; this space is unique to its process. The memory allocated by **EngAllocUserMem** is allocated from the unique 2 GB of user memory, and is thus accessible only when the graphics driver is called in the context of the thread in which the memory was allocated. Graphics drivers always execute in the context of the caller; that is, graphics drivers cannot switch process contexts.

**EngAllocUserMem** is particularly useful to a printer driver with large bitmaps that will only be used by the current process. Rather than allocating from the system pool, this driver can instead allocate space from the current process's address space. Drivers need to exercise care with memory allocated by **EngAllocUserMem**, as it is possible for the application to alter this memory. **EngAllocUserMem** should only be used to allocate relatively large chunks of memory, as each allocation takes at least 64 KB of virtual address space. Sensitive data structures should never be allocated using this function. Also, user memory allocated by this function cannot be passed to [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter) by the printer driver.

When the memory is no longer needed, it can be freed by a call to the [EngFreeUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeusermem) function.

To allocate user memory from the address space of a different process, use [EngAllocPrivateUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocprivateusermem).

## See also

[EngAllocPrivateUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocprivateusermem)

[EngFreeUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeusermem)