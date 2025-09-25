# IOleUndoManager::DiscardFrom

## Description

Instructs the undo manager to discard the specified undo unit and all undo units below it on the undo or redo stack.

## Parameters

### `pUU` [in]

An [IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit) pointer to the undo unit to be discarded. This parameter can be **NULL** to discard the entire undo or redo stack. If the parameter is not **NULL** then the stack will not be discarded.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified undo unit was not found in the stacks. |
| **E_UNEXPECTED** | The undo manager is disabled. |

## Remarks

The undo manager first searches the undo stack for the given unit, and if not found there searches the redo stack. After it has been found, the given unit and all below it on the same stack are discarded. The undo unit may be a child of a parent unit contained by the undo manager, as determined by calling [IOleParentUndoUnit::FindUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-findunit). If it is a child unit, then the root unit containing the given unit and all units below it on the appropriate stack are discarded.

If there is an open parent unit and the **DiscardFrom** method is called and the *pUU* parameter is **NULL**, the undo manager should immediately release and discard the open parent unit without calling the [IOleUndoManager::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-close) first. When the object that opened the parent unit attempts to close it, **IOleUndoManager::Close** will return S_FALSE. If a parent unit is open, throw it away and discard the stack. If the parent unit is not open, just throw the stack away. If the *pUU* parameter is not **NULL**, then any open parent units should be left open.

## See also

[IOleParentUndoUnit::FindUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-findunit)

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)

[IOleUndoManager::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-close)