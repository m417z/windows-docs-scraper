# MmGetPhysicalAddress function

## Description

The **MmGetPhysicalAddress** routine returns the physical address corresponding to a valid nonpaged virtual address.

## Parameters

### `BaseAddress` [in]

Pointer to the virtual address for which to return the physical address.

## Return value

**MmGetPhysicalAddress** returns the physical address that corresponds to the given virtual address.

Do not use this routine to obtain physical addresses for use with DMA operations. For information about the proper techniques for performing DMA operations, see [Adapter Objects and DMA](https://learn.microsoft.com/windows-hardware/drivers/kernel/adapter-objects-and-dma).

## Remarks

Callers of **MmGetPhysicalAddress** can be running at any IRQL, provided that the *BaseAddress* value is valid.

## See also

[MmIsAddressValid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmisaddressvalid)

[MmIsNonPagedSystemAddressValid](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)