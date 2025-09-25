# RtlZeroMemory macro (ntddstor.h)

## Description

The **RtlZeroMemory** routine fills a block of memory with zeros, given a pointer to the block and the length, in bytes, to be filled.

## Parameters

### `Destination`

Datatype: void*. A pointer to the memory block to be filled with zeros.

### `Length`

Datatype: size_t. The number of bytes to fill with zeros.

## Remarks

To zero out a memory buffer to erase security-sensitive data, use [RtlSecureZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsecurezeromemory) instead.

Callers of **RtlZeroMemory** can be running at any IRQL if the destination memory block is in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[RtlFillMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)

[RtlSecureZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsecurezeromemory)To zero out a memory buffer to erase security-sensitive data, use [RtlSecureZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsecurezeromemory) instead.