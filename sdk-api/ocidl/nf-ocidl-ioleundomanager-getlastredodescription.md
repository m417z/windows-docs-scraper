# IOleUndoManager::GetLastRedoDescription

## Description

Retrieves the description for the top-level undo unit that is on top of the redo stack.

## Parameters

### `pBstr` [out]

A pointer to a string that contains a description of the top-level undo unit on the redo stack.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The undo stack is empty. |
| **E_UNEXPECTED** | The undo manager is disabled. |

## Remarks

This method provides a convenient shortcut for the host application to add a description to its **Edit Redo** menu item. The *pBstr* parameter is a string allocated with the standard string allocator. The caller is responsible for freeing this string.

## See also

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)

[IOleUndoManager::GetLastUndoDescription](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-getlastundodescription)