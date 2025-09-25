# IOleParentUndoUnit::FindUnit

## Description

Indicates whether the specified unit is a child of this undo unit or one of its children, that is if the specified unit is part of the hierarchy in this parent unit.

## Parameters

### `pUU` [in]

 An [IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit) pointer to the undo unit to be found.

## Return value

This method returns S_OK if the specified undo unit is in the hierarchy subordinate to this parent; otherwise, S_FALSE.

## Remarks

This is typically called by the undo manager in its implementation of its [IOleUndoManager::DiscardFrom](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-discardfrom) method in the rare event that the unit being discarded is not a top-level unit. The parent unit should look in its own list first, then delegate to each child that is also a parent unit, as determined by doing a [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit).

## See also

[IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit)

[IOleUndoManager::DiscardFrom](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-discardfrom)