# MmUnlockPages function

## Description

The **MmUnlockPages** routine unlocks the physical pages that are described by the specified memory descriptor list (MDL).

## Parameters

### `MemoryDescriptorList` [in, out]

A pointer to an MDL.

## Remarks

The memory described by the specified MDL must have been locked previously by a call to [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages). If the specified MDL is mapped to system address space, **MmUnlockPages** releases this mapping before it unlocks the pages.

For more information, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)