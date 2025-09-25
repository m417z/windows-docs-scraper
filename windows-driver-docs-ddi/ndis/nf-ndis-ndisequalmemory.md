# NdisEqualMemory macro

## Description

The
**NdisEqualMemory** function compares a specified number of characters in one block of memory with the
same number of characters in a second block of memory.

## Parameters

### `Source1`

A pointer to the first block of memory to be compared.

### `Source2`

A pointer to the second block of memory to be compared.

### `Length`

The number of bytes to be compared.

## Remarks

**NdisEqualMemory** compares two blocks of memory and uses the value that is specified in the
*Length* parameter for both blocks. The data type of anything in the compared memory blocks is
irrelevant.

Callers of
**NdisEqualMemory** can be running at IRQL <= DISPATCH_LEVEL if both memory blocks are resident. If
either block is pageable, callers must be running at IRQL < DISPATCH_LEVEL.

## See also

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)

[RtlFillMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)

[RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)