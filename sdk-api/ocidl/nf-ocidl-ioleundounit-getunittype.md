# IOleUndoUnit::GetUnitType

## Description

Retrieves the CLSID and a type identifier for the undo unit.

## Parameters

### `pClsid` [out]

A pointer to CLSID for the undo unit.

### `plID` [out]

A pointer to the type identifier for the undo unit.

## Return value

This method returns S_OK on success.

## Remarks

A parent undo unit can call this method on its child units to determine whether it can apply special handling to them. The CLSID returned can be the CLSID of the undo unit itself, of its creating object, or an arbitrary GUID. The undo unit has the option of returning CLSID_NULL, in which case the caller can make no assumptions about the type of this unit. The only requirement is that the CLSID and type identifier together uniquely identify this type of undo unit.

Note that the undo manager and parent undo units do not have the option of accepting or rejecting child units based on their type.

## See also

[IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit)