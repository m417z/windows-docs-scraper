## Description

Creates an identity mapping for the provided MDL in the specified domain.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `Permissions` [_In_]

A ULONG variable that specifies the permissions for the mapping.

### `Mdl` [_In_]

A pointer to the MDL to map.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also