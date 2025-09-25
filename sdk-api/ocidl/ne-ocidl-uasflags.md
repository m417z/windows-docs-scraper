# UASFLAGS enumeration

## Description

Provides information about the parent undo unit.

## Constants

### `UAS_NORMAL:0`

The currently open parent undo unit is in a normal, unblocked state and can accept any new units added through calls to its [Open](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-open) or [Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-add) methods.

### `UAS_BLOCKED:0x1`

The currently open undo unit is blocked and will reject any undo units added through calls to its [IOleParentUndoUnit::Open](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-open) or [IOleParentUndoUnit::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-add) methods. The caller need not create any new units since they will just be rejected.

### `UAS_NOPARENTENABLE:0x2`

The currently open undo unit will accept new units, but the caller should act like there is no currently open unit. This means that if the new unit being created requires a parent, then this parent does not satisfy that requirement and the undo stack should be cleared.

### `UAS_MASK:0x3`

When checking for a normal state, use this value to mask unused bits in the *pdwState* parameter to the [IOleParentUndoUnit::GetParentState](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-getparentstate) method for future compatibility. For example:

``` syntax
fNormal = ((pdwState & UAS_MASK) == UAS_NORMAL)
```

## See also

[IOleParentUndoUnit::GetParentState](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-getparentstate)