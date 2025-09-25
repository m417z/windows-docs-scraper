# RtlFillMemoryNonTemporal function

## Description

This function fills a block of memory with the specified fill value using non-temporal moves that do not pollute the cache.

## Parameters

### `Destination`

A pointer to the destination memory block to copy the bytes to.

### `Length`

The number of bytes to copy from the source to the destination.

### `Value`

The value to fill the destination memory block with. This value is copied to every byte in the memory block that is defined by *Destination* and *Length*.

## Return value

This function returns NTSYSAPI VOID.

## Remarks

**RtlFillMemoryNonTemporal** only performs a non-temporal fill for x64-based systems, and only when the *Length* parameter is 8 bytes or greater. Otherwise, this function is equivalent to [**RtlFillMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory).

## See also

[**RtlFillMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)