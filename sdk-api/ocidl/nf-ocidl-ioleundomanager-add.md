# IOleUndoManager::Add

## Description

Adds a simple undo unit to the collection. While a parent undo unit is open, the undo manager adds undo units to it by calling [IOleParentUndoUnit::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-add).

## Parameters

### `pUU` [in]

An [IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit) pointer to the undo unit to be added.

## Return value

This method returns S_OK if the specified unit was successfully added, the parent unit was blocked, or the undo manager is disabled.

## Remarks

This method is implemented the same as [IOleParentUndoUnit::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-add). The parent undo unit or undo manager must accept any undo unit given to it, unless it is blocked. If it is blocked, it should do nothing but return S_OK.

### Notes to Implementers

If the undo manager is in the base state, it should put the new unit on the undo stack and discard the entire redo stack. If the undo manager is in the undo state, it should put new units on the redo stack. If the undo manager is in the redo state, it should put units on the undo stack without affecting the redo stack.

## See also

[IOleParentUndoUnit::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-add)

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)