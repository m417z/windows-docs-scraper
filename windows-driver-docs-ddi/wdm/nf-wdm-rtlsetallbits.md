# RtlSetAllBits function

## Description

The **RtlSetAllBits** routine sets all bits in a given bitmap variable.

## Parameters

### `BitMapHeader` [in]

A pointer to the [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure that describes the bitmap. This structure must have been initialized by the [RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap) routine.

## Return value

None

## Remarks

Callers of **RtlSetAllBits** must be running at IRQL <= APC_LEVEL if the memory that contains the bitmap variable is pageable or the memory at *BitMapHeader* is pageable. Otherwise, **RtlSetAllBits** can be called at any IRQL.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlAreBitsSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsset)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindClearBitsAndSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbitsandset)

[RtlFindClearRuns](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearruns)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLastBackwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlastbackwardrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlFindNextForwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindnextforwardrunclear)

[RtlInitializeBitMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitializebitmap)

[RtlNumberOfSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofsetbits)

[RtlSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetbits)