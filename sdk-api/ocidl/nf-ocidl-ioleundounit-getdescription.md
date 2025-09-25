# IOleUndoUnit::GetDescription

## Description

Retrieves a description of the undo unit that can be used in the undo or redo user interface.

## Parameters

### `pBstr` [out]

A pointer to string that describes this undo unit.

## Return value

This method returns S_OK on success.

## Remarks

All units are required to provide a user-readable description of themselves.

### Notes to Callers

The *pbstr* parameter is allocated with the standard string allocator. The caller is responsible for freeing this string.

## See also

[IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit)