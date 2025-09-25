## Description

Flushes the TLB for all entries that match the specified domain's ASID and one of the addresses in the provided list.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `LastLevel` [_In_]

A boolean value that indicates whether only entries pertaining to the last level of translation require flushing.

### `Number` [_In_]

The number of entries in the VA list.

### `VaList` [_In_]

A pointer to a list of flush addresses.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also