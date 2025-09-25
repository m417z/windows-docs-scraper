# IOleUndoManager::Close

## Description

Closes the specified parent undo unit.

## Parameters

### `pPUU` [in]

A pointer to an [IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit) interface for the currently open parent unit to be closed.

### `fCommit` [in]

Indicates whether to keep or discard the unit. If **TRUE**, the unit is kept in the collection. If **FALSE**, the unit is discarded. This parameter is used to allow the client to discard an undo unit under construction if an error or a cancellation occurs.

## Return value

This method returns S_OK if the undo manager had an open parent undo unit and it was successfully closed. If the undo manager is disabled, it should immediately return S_OK and do nothing else. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The parent undo unit did not have an open child and it was successfully closed. |
| **E_INVALIDARG** | If *pPUU* does not match the currently open parent undo unit, then implementations of this method should return E_INVALIDARG without changing any internal state unless the parent unit is blocked. |

## Remarks

This method is implemented the same as [IOleParentUndoUnit::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-close). A parent undo unit knows it is being closed when it returns S_FALSE from this method. At that time, it should terminate any communication with other objects which may be giving data to it through private interfaces.

### Notes to Callers

An error return indicates a fatal error condition.

The parent unit or undo manager must accept the undo unit if *fCommit* is **TRUE**.

### Note to Implementers

To process a close request, a parent undo unit first checks to see if it has an open child unit. If it does not, it returns S_FALSE.

If it does have a child unit open, it calls the **IOleUndoManager::Close** method on the child. If the child returns S_FALSE, then the parent undo unit verifies that *pPUU* points to the child unit, and closes that child undo unit. If the child returns S_OK then it handled the close internally and its parent should do nothing.

If the parent unit is blocked, it should check the *pPUU* parameter to determine the appropriate return code. If *pPUU* is pointing to itself, then it should return S_FALSE.

Otherwise, it should return S_OK; the *fCommit* parameter is ignored; and no action is taken.

If *pPUU* does not match the currently open parent undo unit, then implementations of this method should return E_INVALIDARG without changing any internal state. The only exception to this is if the unit is blocked.

## See also

[IOleParentUndoUnit::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-close)

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)