# IOleUndoManager::GetOpenParentState

## Description

Retrieves state information about the innermost open parent undo unit.

## Parameters

### `pdwState` [out]

A pointer to a variable that receives the state information. This information is a value taken from the [UASFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-uasflags) enumeration.

## Return value

This method returns S_OK if there is an open parent unit and its state was successfully returned or the undo manager is disabled; otherwise, S_FALSE.

## Remarks

### Notes to Callers

When checking for a normal state, use the UAS_MASK value to mask unused bits in the *pdwState* parameter to this method for future compatibility.

### Notes to Implementers

If there is an open parent unit, this method calls [IOleParentUndoUnit::GetParentState](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-getparentstate).

If the undo manager is disabled, it should fill the *pdwState* parameter with UAS_BLOCKED and return S_OK.

## See also

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)

[UASFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-uasflags)