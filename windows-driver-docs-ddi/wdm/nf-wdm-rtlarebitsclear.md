# RtlAreBitsClear function

## Description

The **RtlAreBitsClear** routine determines whether a given range of bits within a bitmap variable is clear.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `StartingIndex` [in]

Specifies the start of the bit range to be tested. This is a zero-based value indicating the position of the first bit in the range.

### `Length` [in]

Specifies how many bits to test.

## Return value

**RtlAreBitsClear** returns **TRUE** if *Length* consecutive bits beginning at *StartingIndex* are clear (that is, all the bits from *StartingIndex* to (*StartingIndex* + *Length*) -1). It returns **FALSE** if any bit in the given range is set, if the given range is not a proper subset of the bitmap, or if the given *Length* is zero.

## Remarks

Callers of **RtlAreBitsClear** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlAreBitsClear** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsset)

[RtlCheckBit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcheckbit)

[RtlClearAllBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlclearallbits)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLastBackwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlastbackwardrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlFindNextForwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindnextforwardrunclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)