# MmSetAddressRangeModified function

## Description

The **MmSetAddressRangeModified** routine marks currently valid pages in the specified range of the system cache as modified.

## Parameters

### `Address` [in]

Address of the start of the range.

### `Length` [in]

Length of the range in bytes.

## Return value

**MmSetAddressRangeModified** returns **TRUE** if it marked at least one page in the range as modified, **FALSE** otherwise.

## Remarks

The entire range specified by *Address* and *Length* must reside within the system cache.

For more information about memory management, see [Memory Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

Callers of **MmSetAddressRangeModified** must be running at IRQL < DISPATCH_LEVEL for pageable addresses, and IRQL <= DISPATCH_LEVEL for nonpageable addresses.

## See also

[CcIsThereDirtyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccistheredirtydata)