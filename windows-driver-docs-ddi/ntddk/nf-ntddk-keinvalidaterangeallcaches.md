# KeInvalidateRangeAllCaches function

## Description

The **KeInvalidateRangeAllCaches** routine flushes the specified virtual address range from all processor caches.

## Parameters

### `BaseAddress`

A pointer to the base of the region to be flushed.

### `Length`

The size of the region to be flushed, in bytes.

## Remarks

The **KeInvalidateRangeAllCaches** routine flushes the specified virtual address range on each processor's caches and marks each cache's contents invalid. The processor caches are guaranteed to have completed the flush operation before **KeInvalidateRangeAllCaches** returns.

This function is available on all platforms and supersedes **[KeInvalidateAllCaches](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keinvalidateallcaches)**. Not all architectures, such as Arm64, support a reliable way to flush the entire cache, so **[KeInvalidateAllCaches](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keinvalidateallcaches)** is not available on all platforms. It is also significantly more efficient to flush the particular memory range affected than the entire cache contents.

This function flushes the cache for all virtual mappings of the same underlying physical memory.

## See also

**[KeInvalidateAllCaches](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keinvalidateallcaches)**