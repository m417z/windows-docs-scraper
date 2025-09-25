# RtlFindSetBits function

## Description

The **RtlFindSetBits** routine searches for a range of set bits of a requested size within a bitmap.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

### `NumberToFind` [in]

Specifies how many contiguous set bits will satisfy this request.

### `HintIndex` [in]

Specifies a zero-based bit position around which to start looking for a set bit range of the given size.

## Return value

**RtlFindSetBits** either returns the zero-based starting bit index for a set bit range of the requested size, or it returns 0xFFFFFFFF if it cannot find such a range within the given bitmap variable.

## Remarks

For a successful call, the returned bit position is not necessarily equivalent to the given *HintIndex*. If necessary, **RtlFindSetBits** searches the whole bitmap to locate a set bit range of the requested size. However, it starts searching for the requested range near *HintIndex*, so callers can find such a range more quickly when they can supply appropriate hints about where to start looking.

Callers of **RtlFindSetBits** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlFindSetBits** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsset)

[RtlClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlclearbits)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindSetBitsAndClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbitsandclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)

[RtlNumberOfSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofsetbits)