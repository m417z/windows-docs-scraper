# MmFreeNonCachedMemory function

## Description

The **MmFreeNonCachedMemory** routine releases a range of noncached memory that was allocated by the [MmAllocateNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatenoncachedmemory) routine.

## Parameters

### `BaseAddress` [in]

Pointer to the virtual address of the memory to be freed.

### `NumberOfBytes` [in]

Specifies the size of the range to be freed. This value must match the size passed in a preceding call to **MmAllocateNonCachedMemory**.

## Remarks

The **MmFreeNonCachedMemory** routine performs the opposite action of [MmAllocateNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatenoncachedmemory).

## See also

[MmAllocateNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatenoncachedmemory)