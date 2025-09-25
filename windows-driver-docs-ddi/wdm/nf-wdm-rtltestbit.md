# RtlTestBit function

## Description

The **RtlTestBit** routine returns the value of a bit in a bitmap.

## Parameters

### `BitMapHeader` [in]

Pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `BitNumber` [in]

Specifies the zero-based index of the bit within the bitmap. The routine returns the value of this bit.

## Return value

**RtlTestBit** returns the value of the bit that the *BitNumber* parameter points to.

## Remarks

Callers of **RtlTestBit** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlTestBit** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)