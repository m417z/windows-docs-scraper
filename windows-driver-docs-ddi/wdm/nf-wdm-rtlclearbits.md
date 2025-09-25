# RtlClearBits function

## Description

The **RtlClearBits** routine sets all bits in the specified range of bits in the bitmap to zero.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `StartingIndex` [in]

The index of the first bit in the bit range that is to be cleared. If the bitmap contains N bits, the bits are numbered from 0 to N-1.

### `NumberToClear` [in]

Specifies how many bits to clear. If the bitmap contains N bits, this parameter can be a value in the range 1 to (N - *StartingIndex*).

## Return value

This routine does not return a value.

## Remarks

If the *NumberToClear* parameter is zero, **RtlClearBits** simply returns control without clearing any bits.

The sum (*StartingIndex* + *NumberToClear*) must not exceed the *SizeOfBitMap* parameter value specified in the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) call that initialized the bitmap.

Callers of **RtlClearBits** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlClearBits** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsset)

[RtlClearAllBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlclearallbits)

[RtlFindSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbits)

[RtlFindSetBitsAndClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbitsandclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)

[RtlNumberOfSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofsetbits)