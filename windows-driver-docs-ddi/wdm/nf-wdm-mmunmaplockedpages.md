# MmUnmapLockedPages function

## Description

The **MmUnmapLockedPages** routine releases a mapping that was set up by a preceding call to the [MmMapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpages) or [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache) routine.

## Parameters

### `BaseAddress` [in]

Pointer to the base virtual address to which the physical pages were mapped.

### `MemoryDescriptorList` [in]

Pointer to an MDL.

## Remarks

Callers of **MmUnmapLockedPages** must be running at IRQL <= DISPATCH_LEVEL if the pages were mapped to system space. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

Note that if the call to **MmMapLockedPages** or **MmMapLockedPagesSpecifyCache** specified user mode, the caller must be in the context of the original process before calling **MmUnmapLockedPages**. This is because the unmapping operation occurs in the context of the calling process, and, if the context is incorrect, the unmapping operation could delete the address range of a random process.

## See also

[MmMapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpages)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)