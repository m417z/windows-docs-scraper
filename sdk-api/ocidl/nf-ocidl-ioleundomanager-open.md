# IOleUndoManager::Open

## Description

Opens a new parent undo unit, which becomes part of its containing unit's undo stack.

## Parameters

### `pPUU` [in]

An [IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit) pointer to the parent undo unit to be opened.

## Return value

This method returns S_OK if the parent undo unit was successfully opened or if a currently open unit is blocked. If the undo manager is currently disabled, it will return S_OK and do nothing else.

## Remarks

This method is implemented the same as [IOleParentUndoUnit::Open](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-open). The specified parent unit is created and remains open. The undo manager then calls the [IOleUndoManager::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-add) or **IOleUndoManager::Open** methods on this parent unit to add new units to it. This parent unit receives any additional undo units until its [IOleUndoManager::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-close) method is called.

The parent unit specified by *pPUU* is not added to the undo stack until its [IOleUndoManager::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-close) method is called with the *fCommit* parameter set to **TRUE**.

The parent undo unit or undo manager must contain any undo unit given to it unless it is blocked. If it is blocked, it must return S_OK but should do nothing else.

## See also

[IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit)

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)