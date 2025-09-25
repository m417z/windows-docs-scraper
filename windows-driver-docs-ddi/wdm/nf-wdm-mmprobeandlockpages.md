# MmProbeAndLockPages function

## Description

The **MmProbeAndLockPages** routine probes the specified virtual memory pages, makes them resident, and locks them in memory (say for a DMA transfer). This ensures the pages cannot be freed and reallocated while a device driver (or hardware) is still using them.

## Parameters

### `MemoryDescriptorList` [in, out]

A pointer to an MDL that specifies a virtual memory buffer. If the routine successfully locks the pages in memory, the MDL is updated to describe the underlying physical pages.

### `AccessMode` [in]

The access mode in which to probe the arguments, either **KernelMode** or **UserMode**.

### `Operation` [in]

The type of operation for which the caller wants the access rights probed and the pages locked. Set this parameter to **IoReadAccess**, **IoWriteAccess**, or **IoModifyAccess**. **IoReadAccess** indicates that the driver can examine the contents of the buffer but cannot change the contents. **IoWriteAccess** and **IoModifyAccess**, which are equivalent, indicate that the driver has both read and write access to the buffer.

## Remarks

The highest-level driver in a chain of layered drivers that use direct I/O calls this routine. Drivers that use buffered I/O never call **MmProbeAndLockPages**.

**MmProbeAndLockPages** performs the following operations:

1. If the specified memory range is paged to a backing store (disk, network, and so on), **MmProbeAndLockPages** makes it resident.
2. The routine then confirms that the pages permit the operation specified by the *Operation* parameter.
3. If the memory range permits the specified operation, the routine locks the pages in memory so that they cannot be paged out. Use the [MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages) routine to unlock the pages.
4. Finally, the routine updates the [page frame number](https://learn.microsoft.com/windows-hardware/drivers/) (PFN) array in the MDL to describe the locked physical pages.

A successful call to **MmProbeAndLockPages** locks the pages in an MDL and sets the MDL structure to the locked state. Every such call must be matched by a corresponding call to **MmUnlockPages** that unlocks the pages and sets the MDL to the unlocked state. After an **MmProbeAndLockPages** call sets an MDL to the locked state, a second call to MmProbeAndLockPages to lock the same MDL is not allowed until **MmUnlockPages** is first called to unlock the MDL.

If two or more MDLs describe the same physical page, the page can be locked multiple times—once for each MDL. The page is unlocked when the last MDL is set to the unlocked state.

A routine such as [MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool) or [IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl) updates an MDL to describe pages that are either nonpageable or already locked. A call to **MmProbeAndLockPages** or **MmUnlockPages** to lock or unlock such an MDL is not allowed.

Calls to **MmProbeAndLockPages** must be enclosed in a **try/except** block. If the pages do not support the specified operation, the routine raises the STATUS_ACCESS_VIOLATION or other exceptions. For more information, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

Callers of **MmProbeAndLockPages** must be running at IRQL <= APC_LEVEL for pageable addresses, or at IRQL <= DISPATCH_LEVEL for nonpageable addresses.

This routine does not provide any guarantees about the virtual address that describes these pages (that is, the virtual address might be unmapped, reused, and so on). However, the physical pages are guaranteed to be locked on successful return.

To avoid page faults, use [**VirtualLock**](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtuallock) to lock the virtual address so it will not be trimmed unless the app unlocks it or explicitly frees it by calling [**VirtualFree**](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or [**UnmapViewOfFile**](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile).

## See also

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)

[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool)

[MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages)