# NdisZeroMemory macro

## Description

The
**NdisZeroMemory** function fills a block of memory with zeros.

## Parameters

### `Destination` [in]

The base virtual address of a block of memory.

### `Length` [in]

The number of bytes to fill with zeros.

## Remarks

**NdisZeroMemory** fills the specified range of memory with zeros. The given
*Destination* and
*Length* must be a proper subrange of a caller-accessible memory range.

As long as the given range was allocated from nonpaged pool, the caller can be running at any IRQL.
Otherwise, a caller must be running at IRQL < DISPATCH_LEVEL as, for example, when a caller clears a
structure it allocated on the stack.

## See also

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisZeroMappedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiszeromappedmemory)