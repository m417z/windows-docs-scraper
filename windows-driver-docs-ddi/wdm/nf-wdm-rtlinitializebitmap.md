# RtlInitializeBitMap function

## Description

The **RtlInitializeBitMap** routine initializes the header of a bitmap variable.

## Parameters

### `BitMapHeader` [out]

Pointer to an empty [RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap) structure.

### `BitMapBuffer` [in]

Pointer to caller-allocated memory for the bitmap itself. The base address of this buffer must be ULONG-aligned. The size of the allocated buffer must be an integer multiple of **sizeof**(ULONG) bytes.

### `SizeOfBitMap` [in]

Specifies the number of bits in the bitmap. This value can be any number of bits that will fit in the buffer allocated for the bitmap.

## Return value

None

## Remarks

A driver can use a bitmap variable as an economical way to keep track of a set of reusable items. For example, file systems use a bitmap variable to track which clusters/sectors on a disk have already been allocated to hold file data. The system-supplied SCSI port driver uses a bitmap variable to track which queue tags have been assigned to SCSI request blocks (SRBs).

**RtlInitializeBitMap** must be called before any other **Rtl*Xxx*** routine that operates on a bitmap variable. The *BitMapHeader* pointer is an input parameter in all subsequent **Rtl*Xxx*** calls that operate on the caller's bitmap variable at *BitMapBuffer*. The caller is responsible for synchronizing access to the bitmap variable.

**RtlInitializeBitMap** initializes the caller-supplied **RTL_BITMAP** structure by copying the caller-supplied *BitMapBuffer* and *SizeOfBitMap* values into it. Subsequently, the structure can be passed to other routines to manipulate the bitmap. **RtlInitializeBitMap** does not modify the contents of the bitmap.

## See also

[RTL_BITMAP](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#rtl_bitmap)

[RtlAreBitsClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsclear)

[RtlAreBitsSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlarebitsset)

[RtlCheckBit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcheckbit)

[RtlClearAllBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlclearallbits)

[RtlClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlclearbits)

[RtlFindClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbits)

[RtlFindClearBitsAndSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearbitsandset)

[RtlFindClearRuns](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindclearruns)

[RtlFindFirstRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindfirstrunclear)

[RtlFindLastBackwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlastbackwardrunclear)

[RtlFindLongestRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindlongestrunclear)

[RtlFindNextForwardRunClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindnextforwardrunclear)

[RtlFindSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbits)

[RtlFindSetBitsAndClear](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfindsetbitsandclear)

[RtlNumberOfClearBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofclearbits)

[RtlNumberOfSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlnumberofsetbits)

[RtlSetAllBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetallbits)

[RtlSetBits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetbits)