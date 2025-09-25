# IOleParentUndoUnit::GetParentState

## Description

Retrieves state information about the innermost open parent undo unit.

## Parameters

### `pdwState` [out]

A pointer to the state information. This information is a value taken from the [UASFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-uasflags) enumeration.

## Return value

This method returns S_OK on success.

## Remarks

### Notes to Implementers

If the unit has an open child, it should delegate this method to that child. If not, it should fill in *pdwState* values appropriately and return. Note that a parent unit must never be blocked while it has an open child. If this happened it could prevent the child unit from being closed, which would cause serious problems.

### Notes to Callers

When checking for a normal state, use the UAS_MASK value to mask unused bits in the *pdwState* parameter to this method for future compatibility.

## See also

[IOleParentUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleparentundounit)