# IOleInPlaceSite::OnUIDeactivate

## Description

Notifies the container that it should reinstall its user interface and take focus, and whether the object has an undoable state.

## Parameters

### `fUndoable` [in]

Specifies whether the object can undo changes (TRUE) or not (FALSE).

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

The object indicates whether it can undo changes through the *fUndoable* flag. If the object can undo changes, the container can (by the user invoking the **Edit Undo** command) call the [IOleInPlaceObject::ReactivateAndUndo](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-reactivateandundo) method to undo the changes.

### Notes to Callers

**IOleInPlaceSite::OnUIDeactivate** is called by the site's immediate child object when it is deactivating to notify the container that it should reinstall its own user interface components and take focus. The container should wait for the call to **IOleInPlaceSite::OnUIDeactivate** to complete before fully cleaning up and destroying any composite submenus.

## See also

[IOleInPlaceObject::ReactivateAndUndo](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-reactivateandundo)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)