# RtlPrefetchMemoryNonTemporal function

## Description

The **RtlPrefetchMemoryNonTemporal** routine provides a hint to the processor that a buffer should be temporarily moved into the processor cache.

## Parameters

### `Source` [in]

A pointer to the buffer to be moved into the processor cache.

### `Length` [in]

The length of the buffer to be moved.

## Return value

None.

## Remarks

You should use this routine only for a buffer that will be written to or read from exactly once. Note that **RtlPrefetchMemoryNonTemporal** is only a hint to the processor: the buffer is not guaranteed to be moved into the cache. On x86-based and x64-based systems, this routine uses the **prefetchnta** instruction.