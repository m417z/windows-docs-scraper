# _MM_COPY_ADDRESS structure

## Description

The **MM_COPY_ADDRESS** structure contains either a virtual memory address or a physical memory address.

## Members

### `VirtualAddress`

A virtual memory address.

### `PhysicalAddress`

A physical memory address.

## Remarks

This structure is used by the [MmCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmcopymemory) routine.

## See also

[MmCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmcopymemory)