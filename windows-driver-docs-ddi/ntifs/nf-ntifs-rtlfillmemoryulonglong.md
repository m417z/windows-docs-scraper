# RtlFillMemoryUlonglong macro

## Description

The **RtlFillMemoryUlonglong** routine fills a given range of memory with one or more repetitions of a given ULONGLONG value.

## Parameters

### `Destination` [out]

Pointer to the start of the range of memory to be filled. This address must be ULONGLONG-aligned.

### `Length` [in]

Number of bytes to fill. This value must be a multiple of **sizeof(**ULONGLONG**)**. (Note: SIZE_T is defined in *basetsd.h*.)

### `Pattern` [in]

ULONGLONG value with which to fill the range starting at *Destination* and extending for *Length* bytes.

## Remarks

If the range of memory starting at *Destination* is nonpaged, the caller can be running at any IRQL. Otherwise, callers of **RtlFillMemoryUlonglong** must be running at IRQL < DISPATCH_LEVEL.

For more information about managing buffered data and initializing driver-allocated buffers, see [Buffered Data and Buffer Initialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#buffered-data-and-buffer-initialization).

For AMD64 systems, this routine is a macro. For non-AMD64 systems, this routine is contained in Ntoskrnl.lib.

## See also

[RtlFillMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)

[RtlFillMemoryUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfillmemoryulong)

[RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)