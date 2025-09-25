# IOleUndoManager::RedoTo

## Description

Instructs the undo manager to invoke undo actions back through the redo stack, down to and including the specified undo unit.

## Parameters

### `pUU` [in]

An [IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit) pointer to the top level unit to redo. If this parameter is **NULL**, the most recently added top level unit is used.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified undo unit is not on the redo stack. |
| **E_ABORT** | Both the undo attempt and the rollback attempt failed. The undo manager should never propagate the E_ABORT obtained from a contained undo unit. Instead, it should map any E_ABORT values returned from other undo units to E_FAIL. |
| **E_UNEXPECTED** | The undo manager is disabled. |

## Remarks

This method calls the [IOleUndoUnit::Do](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundounit-do) method on each top-level undo unit. Then, it releases that undo unit.

Note that the specified undo unit must be a top-level unit, typically retrieved through [IOleUndoManager::EnumRedoable](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-enumredoable).

In case an error is returned from the undo unit, the undo manager needs to attempt to rollback the state of the document to recover from the error by performing actions on the undo stack.

No matter what the success of the rollback, the undo manager should always clear both stacks before returning the error.

If the undo manager has called the [IOleUndoUnit::Do](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundounit-do) method on more than one top-level unit, it should only rollback the unit that returned the error. The top-level units that succeeded should not be rolled back.

The undo manager must also keep track of whether units were added to the opposite stack so it won't attempt rollback if nothing was added. See the [IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager) interface for detailed description of error handling.

## See also

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)

[IOleUndoManager::EnumRedoable](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-enumredoable)

[IOleUndoManager::UndoTo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-undoto)

[IOleUndoUnit::Do](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundounit-do)