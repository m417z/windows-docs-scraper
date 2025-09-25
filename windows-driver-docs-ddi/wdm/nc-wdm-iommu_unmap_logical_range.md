## Description

Unmaps a linear range from a domain.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `LogicalAddress` [_In_]

The logical address at which unmapping begins. The address must be page aligned.

### `NumberOfPages` [_In_]

The number of pages to unmap.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also