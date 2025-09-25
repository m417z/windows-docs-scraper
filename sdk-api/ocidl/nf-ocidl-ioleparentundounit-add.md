# IOleParentUndoUnit::Add

## Description

Adds a simple undo unit to the collection.

## Parameters

### `pUU` [in]

An [IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit) pointer to the undo unit to be added.

## Return value

This method returns S_OK if the specified unit was successfully added or the parent unit was blocked.

## Remarks

The parent undo unit or undo manager must accept any undo unit given to it, unless it is blocked. If it is blocked, it should do nothing but return S_OK.

## See also

[IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit)

[IOleUndoManager::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-add)