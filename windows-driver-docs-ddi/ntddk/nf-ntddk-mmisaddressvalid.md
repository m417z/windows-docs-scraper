## Description

The **MmIsAddressValid** routine checks whether a page fault will occur for a read or write operation at a given virtual address.

> [!WARNING]
> We do not recommend using this function.

## Parameters

### `VirtualAddress` [in]

A pointer to the nonpaged virtual address to check. The caller must ensure that this address cannot be paged out or deleted for the duration of this call. Even after the return from the call, you must not page out or delete this address. If you do page out or delete this address, the return value might be unreliable. Paging out or deleting this address might cause the computer to stop responding (that is, *crash*).

## Return value

If no page fault would occur from reading or writing at the given virtual address, **MmIsAddressValid** returns **TRUE**.

## Remarks

Even if **MmIsAddressValid** returns **TRUE**, accessing the address can cause page faults unless the memory has been locked down or the address is a valid nonpaged pool address.

## See also

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)