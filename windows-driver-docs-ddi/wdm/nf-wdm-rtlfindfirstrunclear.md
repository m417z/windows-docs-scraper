# RtlFindFirstRunClear function

## Description

The **RtlFindFirstRunClear** routine searches for the initial contiguous range of clear bits within a given bitmap.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `StartingIndex` [out]

Pointer to a variable in which the starting index of the initial clear run in the bitmap is returned. This is a zero-based value indicating the bit position of the first clear bit in the returned range. Its value is meaningless if **RtlFindFirstRunClear** cannot find a run of clear bits.

## Return value

**RtlFindFirstRunClear** returns either the number of bits in the run beginning at *StartingIndex*, or zero if it cannot find a run of clear bits within the bitmap.

## Remarks

A returned run can have a single clear bit. That is, once a clear bit is found, **RtlFindFirstRunClear** continues searching until it finds the next set bit, and then returns the number of clear bits in the run it found.

Callers of **RtlFindFirstRunClear** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlFindFirstRunClear** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindClearRuns](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearruns)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLastBackwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlastbackwardrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlFindNextForwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindnextforwardrunclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)

[RtlNumberOfClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofclearbits)

[RtlSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetbits)