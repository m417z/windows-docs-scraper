# IoBuildPartialMdl function

## Description

The **IoBuildPartialMdl** routine builds a new memory descriptor list (MDL) that represents part of a buffer that is described by an existing MDL.

## Parameters

### `SourceMdl` [in]

A pointer to an MDL that describes the original buffer, of which a subrange is to be mapped.

### `TargetMdl` [in, out]

A pointer to a caller-allocated MDL. This MDL must be large enough to describe the pages in the subrange that are specified by *VirtualAddress* and *Length*.

### `VirtualAddress` [in]

A pointer to the base virtual address for the subrange to be described by the *TargetMdl*.

### `Length` [in]

Specifies the length, in bytes, to be mapped by the *TargetMdl*. This value, in combination with *VirtualAddress*, must specify a buffer that is a proper subrange of the buffer that is described by *SourceMdl*. If *Length* is zero, the subrange to be mapped starts at *VirtualAddress* and includes the remaining range described by the *SourceMdl*.

## Remarks

This routine builds a target MDL that describes a subrange of the buffer that is described by the source MDL. This subrange is specified by the *VirtualAddress* and *Length* parameters. The *SourceMdl* and *TargetMdl* parameters point to the source MDL and target MDL.

A driver can use **IoBuildPartialMdl** to split a large transfer request into smaller transfer requests. The physical pages that the source MDL describes must be locked before the driver calls **IoBuildPartialMdl**. Typically, the source MDL describes a buffer in user address space, and the driver calls the [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) routine to lock the pages in this buffer. However, the driver can build the source MDL from nonpaged memory by calling the [MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool), [MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex), or [MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl) routine.

When creating a partial MDL:

* If the original MDL was already mapped in system space, the partial MDL shares that mapping and there is no need to map it again.
* If the original MDL was not mapped in system space, the partial MDL is not either. If you need a system mode address, call [**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer) on the partial MDL.
* If you do not know which of the above applies, it is safe to call [**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer) regardless. If a partial MDL is built from a source MDL that is already mapped into the system address space, **MmGetSystemAddressForMdlSafe** uses the existing source mapping. Otherwise, **MmGetSystemAddressForMdlSafe** creates a new mapping.

To prevent this new mapping from being leaked, drivers must call [MmPrepareMdlForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpreparemdlforreuse) before reusing a partial MDL. In addition, the [IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl) routine releases the system-address-space mapping for a partial MDL, if such a mapping exists.

For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl)

[MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl)

[MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex)

[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[MmPrepareMdlForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpreparemdlforreuse)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)