# RtlCompareMemoryUlong function

## Description

The **RtlCompareMemoryUlong** routine returns how many bytes in a block of memory match a specified pattern.

## Parameters

### `Source` [in]

Pointer to a block of memory. Must be aligned on a ULONG boundary.

### `Length` [in]

Number of bytes over which the comparison should be done. Must be a multiple of **sizeof(**ULONG**)**.

### `Pattern` [in]

Pattern to be compared byte by byte, repeatedly, through the specified memory range.

## Return value

**RtlCompareMemoryUlong** returns the number of bytes that were compared and found to be equal. If all bytes compare as equal, the input *Length* is returned. **RtlCompareMemoryUlong** returns zero if *Source* is not ULONG-aligned or if *Length* is not a multiple of **sizeof(**ULONG**)**.

## Remarks

If the block of memory at *Source* is nonpaged, the caller can be running at any IRQL. Otherwise, callers of **RtlCompareMemoryUlong** must be running at IRQL < DISPATCH_LEVEL.

For more information about managing buffered data and initializing driver-allocated buffers, see [Buffered Data and Buffer Initialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#buffered-data-and-buffer-initialization).

## See also

[RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory)