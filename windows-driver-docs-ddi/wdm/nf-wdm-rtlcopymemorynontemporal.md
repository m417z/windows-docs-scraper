# RtlCopyMemoryNonTemporal function

## Description

This function copies the contents from one buffer to another using non-temporal moves that do not pollute the cache. Note that the buffers shouldn’t overlap.

## Parameters

### `Length`

The number of bytes to copy from the source to the destination.

### `Source`

A pointer to the source memory block to copy the bytes from.

### `Destination`

A pointer to the destination memory block to copy the bytes to.

## Return value

None.

## Remarks

**RtlCopyMemoryNonTemporal** only performs a non-temporal copy for x64-based systems, and only when the **Length** parameter is 8 bytes or greater. Otherwise, this function is equivalent to [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory).

Callers of RtlCopyMemoryNonTemporal can be running at any IRQL if the source and destination memory blocks are in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)