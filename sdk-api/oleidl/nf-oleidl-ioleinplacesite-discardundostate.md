# IOleInPlaceSite::DiscardUndoState

## Description

Instructs the container to discard its undo state. The container should not call [IOleInPlaceObject::ReActivateAndUndo](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-reactivateandundo).

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

If an object is activated in place and the object's associated object application maintains only one level of undo, there is no need to have more than one entry on the undo stack. That is, after a change has been made to the active object that invalidates its undo state saved by the container, there is no need to maintain this undo state in the container.

### Notes to Callers

**DiscardUndoState** is called by the active object while performing some action that would discard the undo state of the object. The in-place object calls this method to notify the container to discard the object's last saved undo state.

## See also

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)

[IOleInPlaceSite::DiscardUndoState](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-discardundostate)