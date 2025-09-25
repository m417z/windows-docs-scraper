# RtlFillMemoryUlong function

## Description

The **RtlFillMemoryUlong** routine fills the specified range of memory with one or more repetitions of a ULONG value.

## Parameters

### `Destination` [out]

Pointer to a block of memory to be filled. Must be ULONG-aligned.

### `Length` [in]

Length in bytes of the memory to fill. Must be a multiple of **sizeof(**ULONG**)**. (Note: SIZE_T is defined in *basetsd.h*.)

### `Pattern` [in]

ULONG value with which to fill the memory block.

## Remarks

If the block of memory at *Destination* is nonpaged, the caller can be running at any IRQL. Otherwise, callers of **RtlFillMemoryUlong** must be running at IRQL < DISPATCH_LEVEL.

For more information about managing buffered data and initializing driver-allocated buffers, see [Buffered Data and Buffer Initialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#buffered-data-and-buffer-initialization).

## See also

[RtlFillMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)

[RtlFillMemoryUlonglong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfillmemoryulonglong)

[RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)