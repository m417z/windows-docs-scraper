# RtlFindNextForwardRunClear function

## Description

The **RtlFindNextForwardRunClear** routine searches a given bitmap variable for the next clear run of bits, starting from the specified index position.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `FromIndex` [in]

Specifies a zero-based bit position at which to start looking for a clear run of bits.

### `StartingRunIndex` [out]

Pointer to a variable in which the starting index of the clear run found in the bitmap is returned. This is a zero-based value indicating the bit position of the first clear bit in the run. Its value is meaningless if **RtlFindNextForwardRunClear** cannot find a run of clear bits.

## Return value

**RtlFindNextForwardRunClear** returns either the number of bits in the run beginning at *StartingRunIndex*, or zero if it cannot find a run of clear bits following *FromIndex* in the bitmap.

## Remarks

Callers of **RtlFindNextForwardRunClear** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlFindNextForwardRunClear** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindClearRuns](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearruns)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLastBackwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlastbackwardrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)