# RtlZeroMemory macro (minitape.h)

## Description

The **RtlZeroMemory** routine fills a block of memory with zeros, given a pointer to the block and the length, in bytes, to be filled.

## Parameters

### `Destination` [out]

A pointer to the memory block to be filled with zeros.

### `Length` [in]

The number of bytes to fill with zeros.

## Syntax

```cpp
VOID RtlZeroMemory(
  _Out_ VOID UNALIGNED *Destination,
  _In_  SIZE_T         Length
);
```

## Remarks

To zero out a memory buffer to erase security-sensitive data, use [RtlSecureZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsecurezeromemory) instead.

Callers of **RtlZeroMemory** can be running at any IRQL if the destination memory block is in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[RtlFillMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)

[RtlSecureZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsecurezeromemory)