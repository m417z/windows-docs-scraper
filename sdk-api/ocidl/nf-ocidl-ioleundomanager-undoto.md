# IOleUndoManager::UndoTo

## Description

Instructs the undo manager to invoke undo actions back through the undo stack, down to and including the specified undo unit.

## Parameters

### `pUU` [in]

Pointer to the top level unit to undo. If this parameter is **NULL**, the most recently added top level unit is used.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified undo unit is not on the undo stack. |
| **E_ABORT** | Both the undo attempt and the rollback attempt failed. The undo manager should never propagate the E_ABORT obtained from a contained undo unit. Instead, it should map any E_ABORT values returned from other undo units to E_FAIL. The undo manager should map any E_ABORT value returned from other undo units to E_FAIL because the caller of [IOleUndoManager::UndoTo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-undoto) knows that the undo attempt and the rollback attempt failed and this is the only reason for the return value of E_ABORT. |
| **E_UNEXPECTED** | The undo manager is disabled. |

## Remarks

This method calls the [IOleUndoUnit::Do](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundounit-do) method on each top-level undo unit. Then, it releases that undo unit.

Note that the specified undo unit must be a top-level unit, typically retrieved through [IOleUndoManager::EnumUndoable](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-enumundoable).

In case an error is returned from the undo unit, the undo manager needs to attempt to rollback the state of the document to recover from the error by performing actions on the redo stack.

No matter what the success of the rollback, the undo manager should always clear both stacks before returning the error.

If the undo manager has called the [Do](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundounit-do) method on more than one top-level unit, it should only rollback the unit that returned the error. The top-level units that succeeded should not be rolled back.

The undo manager must also keep track of whether units were added to the opposite stack so it won't attempt rollback if nothing was added. See the [IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager) interface for detailed description of error handling.

### Notes to Callers

It is possible for an undo unit to return E_ABORT as a failure, but that has no specific meaning on [IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit). Because the undo manager will typically return the error code given by the failed undo unit, and E_ABORT does have a specific meaning on **IOleUndoManager::UndoTo**, the undo manager should never pass on E_ABORT because the caller will interpret that as the rollback failing when in fact it may have succeeded.

## See also

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)

[IOleUndoManager::EnumUndoable](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-enumundoable)

[IOleUndoManager::RedoTo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-redoto)

[IOleUndoUnit::Do](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundounit-do)