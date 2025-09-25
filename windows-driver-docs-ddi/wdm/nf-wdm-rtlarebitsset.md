# RtlAreBitsSet function

## Description

The **RtlAreBitsSet** routine determines whether a given range of bits within a bitmap variable is set.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `StartingIndex` [in]

Specifies the start of the bit range to be tested. This is a zero-based value indicating the position of the first bit in the range.

### `Length` [in]

Specifies how many bits to test.

## Return value

**RtlAreBitsSet** returns **TRUE** if *Length* consecutive bits beginning at *StartingIndex* are set (that is, all the bits from *StartingIndex* to (*StartingIndex* + *Length*)). It returns **FALSE** if any bit in the given range is clear, if the given range is not a proper subset of the bitmap, or if the given *Length* is zero.

## Remarks

Callers of **RtlAreBitsSet** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlAreBitsSet** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlCheckBit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcheckbit)

[RtlFindSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbits)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)

[RtlSetAllBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetallbits)