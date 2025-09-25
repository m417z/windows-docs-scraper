# MmMapLockedPages function

## Description

The **MmMapLockedPages** routine is obsolete for Windows 2000 and later versions of Windows, and for Windows Me. It is supported only for WDM drivers that must run on Windows 98. Otherwise, use [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache).

The **MmMapLockedPages** routine maps the physical pages that are described by a given MDL.

## Parameters

### `MemoryDescriptorList` [in]

Pointer to an MDL that was updated by [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages).

### `AccessMode` [in]

Specifies the access mode in which to map the MDL, either **KernelMode** or **UserMode**. Almost all drivers should use **KernelMode**.

## Return value

**MmMapLockedPages** returns the starting address of the mapped pages. (For NT-based operating systems prior to Windows NT 4.0 Service Pack 4 (SP4), **MmMapLockedPages** returns the beginning address of the first page of the mapped pages.)

## Remarks

Use [MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages) to unmap the physical pages that were mapped by **MmMapLockedPages**.

If *AccessMode* is KernelMode and **MmMapLockedPages** cannot map the specified pages, the system issues a bug check. (For this reason, drivers should use [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache) when available; that routine returns **NULL** on failure, rather than causing a bug check.) If *AccessMode* is **UserMode** and the specified pages cannot be mapped, the routine raises an exception. Callers that specify **UserMode** must wrap the call to **MmMapLockedPages** in a **try/except** block. For more information, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

Callers of **MmMapLockedPages** must be running at IRQL <= DISPATCH_LEVEL if *AccessMode* is **KernelMode**. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[MmGetSystemAddressForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdl)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages)