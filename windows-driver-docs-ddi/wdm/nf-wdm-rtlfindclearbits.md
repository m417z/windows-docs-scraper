## Description

The **RtlFindClearBits** routine searches for a range of clear bits of a requested size within a bitmap.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `NumberToFind` [in]

Specifies how many contiguous clear bits will satisfy this request.

### `HintIndex` [in]

Specifies a zero-based bit position from which to start looking for a clear bit range of the given size.

## Return value

**RtlFindClearBits** either returns the zero-based starting bit index for a clear bit range of at least the requested size, or it returns 0xFFFFFFFF if it cannot find such a range within the given bitmap.

## Remarks

For a successful call, the returned bit position is not necessarily equivalent to the given *HintIndex*. If necessary, **RtlFindClearBits** searches the whole bitmap to locate a clear bit range of the requested size. Callers can find such a range more quickly when they can supply appropriate hints about where to start looking.

If a matching range is not found between the hint index and the end of the bitmap, **RtlFindClearBits** continues searching from the beginning of the bitmap back to the hint index.

If you only want an index returned that is greater than or equal to some value, use [**RtlFindNextForwardRunClear**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindnextforwardrunclear) instead.

Callers of **RtlFindClearBits** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlFindClearBits** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlFindClearBitsAndSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbitsandset)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlFindSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbits)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)

[RtlNumberOfClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofclearbits)