# MmGetSystemAddressForMdl macro

## Description

The MmGetSystemAddressForMdl routine is obsolete. Use [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe) instead.

**MmGetSystemAddressForMdl** is a macro that returns a nonpaged system-space virtual address for the buffer described by the MDL. It maps the physical pages described by a given MDL into system space, if they are not already mapped to system space.

## Parameters

### `MDL` [in]

Pointer to a buffer whose corresponding base virtual address is to be mapped.

## Syntax

```cpp
PVOID MmGetSystemAddressForMdl(
   MDL
);
```

## Remarks

**MmGetSystemAddressForMdl** returns the base system-space virtual address that maps the physical pages described by the given MDL.

Drivers of PIO devices call this routine to translate a virtual address range, described by the MDL at **Irp->MdlAddress**, for a user buffer to a system-space address range.

The MDL must describe nonpageable memory. In other words, the input MDL must describe an already locked-down user-space buffer returned by [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages), a locked-down buffer returned by [MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool), or system-space memory allocated from nonpaged pool, contiguous memory, or non-cached memory.

The returned base address has the same offset as the virtual address in the MDL.

Window issues a bug check if the attempt to map to system space fails. Therefore, you should use [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe) instead).

## See also

[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)