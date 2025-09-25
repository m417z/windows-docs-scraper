# RtlFindClearRuns function

## Description

The **RtlFindClearRuns** routine finds the specified number of runs of clear bits within a given bitmap.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `RunArray` [out]

Pointer to the first element in a caller-allocated array for the bit position and length of each clear run found in the given bitmap variable.

### `SizeOfRunArray` [in]

Specifies the maximum number of clear runs to satisfy this request.

### `LocateLongestRuns` [in]

If **TRUE**, specifies that the routine is to search the entire bitmap for the longest clear runs it can find. Otherwise, the routine stops searching when it has found the number of clear runs specified by *SizeOfRunArray*.

## Return value

**RtlFindClearRuns** returns the number of clear runs found.

## Remarks

If *LocateLongestRuns* is **TRUE**, the clear runs indicated at *RunArray* are sorted from longest to shortest. A clear run can consist of a single bit.

Callers of **RtlFindClearRuns** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlFindClearRuns** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLastBackwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlastbackwardrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlFindNextForwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindnextforwardrunclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)