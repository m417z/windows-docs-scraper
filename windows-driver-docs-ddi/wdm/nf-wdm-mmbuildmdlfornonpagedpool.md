# MmBuildMdlForNonPagedPool function

## Description

The **MmBuildMdlForNonPagedPool** routine receives an MDL that specifies a nonpaged virtual memory buffer, and updates it to describe the underlying physical pages.

## Parameters

### `MemoryDescriptorList` [in, out]

A pointer to an MDL that specifies a virtual memory buffer in nonpaged memory. The caller used the [IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl) routine to create the MDL for this buffer.

## Remarks

At entry, the specified MDL must describe a buffer in nonpaged system memory or in memory that is locked down (the physical pages cannot be traded), such as memory that is allocated by the [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) routine with *PoolType* = **NonPagedPool** or by the [MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache) routine. **MmBuildMdlForNonPagedPool** updates the MDL to describe the underlying physical pages.

**MmBuildMdlForNonPagedPool** may not be used with MDLs describing buffers allocated on a kernel stack. To build an MDL describing a kernel stack buffer, drivers must call [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages). This is because kernel stack pages can be traded unless they are probe-and-locked. This rule applies even if the driver guarantees that the kernel stack cannot be paged out.

Because the pages described by the MDL are already nonpageable and are already mapped to the system address space, drivers must not try to lock them by using the [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) routine, or to create additional system-address-space mappings by using the [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache) routine. Similarly, drivers must not try to unlock the pages by using the [MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages) routine, or to release the existing system-address-space mapping by using the [MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages) routine. If a driver performs any of these illegal operations on an MDL that is built by **MmBuildMdlForNonPagedPool,** the resulting behavior is undefined.

Passing an MDL built by **MmBuildMdlForNonPagedPool** to the [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe) routine is allowed. The **MmGetSystemAddressForMdlSafe** call, in this case, simply returns the starting virtual address of the buffer that is described by the MDL.

A driver can use the **MmMapLockedPagesSpecifyCache** routine to map an MDL that is built by **MmBuildMdlForNonPagedPool** into user virtual address space. However, the driver must perform this operation in a way that avoids certain security issues. For more information, see [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache).

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages)

[MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages)