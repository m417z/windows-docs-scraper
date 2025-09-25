# IOleUndoUnit::Do

## Description

Instructs the undo unit to carry out its action. Note that if it contains child undo units, it must call their Do methods as well.

## Parameters

### `pUndoManager` [in]

A pointer to the undo manager. See [IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager).

## Return value

This method returns S_OK on success.

## Remarks

The undo unit is responsible for carrying out its action. Performing its own undo action results in another action that can potentially be reversed. However, if *pUndoManager* is **NULL**, the undo unit should perform its undo action but should not attempt to put anything on the redo or undo stack.

If *pUndoManager* is not **NULL**, then the unit is required to put a corresponding unit on the redo or undo stack. As a result, this method either moves itself to the redo or undo stack, or it creates a new undo unit and adds it to the appropriate stack. After creating a new undo unit, this undo unit calls [IOleUndoManager::Open](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-open) or [IOleUndoManager::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-add). The undo manager will put the new undo unit on the undo or redo stack depending on its current state.

A parent unit must pass to its children the same undo manager, possibly **NULL**, that was given to the parent. It is permissible, but not necessary, when *pUndoManager* is **NULL** to open a parent unit on the redo or undo stack as long as it is not committed. A blocked parent unit ensures that nothing is added to the stack by child units.

If this undo unit is a parent unit, it should put itself on the redo or undo stack before calling the **Do** method on its children.

After calling this method, the undo manager must release the undo unit.

### Notes to Implementers

See the [IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager) interface for error handling strategies for undo units. The error handling strategy affects the implementation of this method, particularly for parent units.

## See also

[IOleUndoManager::Add](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-add)

[IOleUndoManager::Open](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleundomanager-open)

[IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit)