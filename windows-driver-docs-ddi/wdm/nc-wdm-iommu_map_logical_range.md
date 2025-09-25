## Description

Maps a range of pages into the address space of the specified domain.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `Permissions` [_In_]

A ULONG variable that specifies the permissions with which to map the pages.

### `Mdl` [_In_]

A pointer to the MDL to map. The provided MDL must specify a whole number of page.

### `LogicalAddress` [_In_]

The logical address at which mapping begins. The address must be page aligned.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also