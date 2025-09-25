# RtlFindClearBitsAndSet function

## Description

The **RtlFindClearBitsAndSet** routine searches for a range of clear bits of a requested size within a bitmap and sets all bits in the range when it has been located.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `NumberToFind` [in]

Specifies how many contiguous clear bits will satisfy this request.

### `HintIndex` [in]

Specifies a zero-based bit position from which to start looking for a clear bit range of the given size.

## Return value

**RtlFindClearBitsAndSet** either returns the zero-based starting bit index for a clear bit range of the requested size that it set, or it returns 0xFFFFFFFF if it cannot find such a range within the given bitmap variable.

## Remarks

For a successful call, the returned bit position is not necessarily equivalent to the given *HintIndex*. If necessary, **RtlFindClearBitsAndSet** searches the whole bitmap to locate a clear bit range of the requested size. However, it starts searching for the requested range from *HintIndex*, so callers can have such a range reset more quickly when they can supply appropriate hints about where to start looking.

Callers of **RtlFindClearBitsAndSet** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlFindClearBitsAndSet** can be called at any IRQL.

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

[RtlSetAllBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetallbits)

[RtlSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetbits)