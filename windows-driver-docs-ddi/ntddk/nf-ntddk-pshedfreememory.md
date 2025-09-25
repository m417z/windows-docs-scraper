# PshedFreeMemory function

## Description

The **PshedFreeMemory** function frees a block of memory that was previously allocated by calling the [PshedAllocateMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedallocatememory) function.

## Parameters

### `Address` [in]

A pointer to the block of memory being freed.

## Return value

None

## Remarks

A PSHED plug-in calls the **PshedFreeMemory** function to free a block of memory that it previously allocated by calling the [PshedAllocateMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedallocatememory) function.

## See also

[PshedAllocateMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedallocatememory)