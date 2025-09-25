# IOleInPlaceSite::DeactivateAndUndo

## Description

Deactivates the object, ends the in-place session, and reverts to the container's saved undo state.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

Called by the active object when the user invokes undo just after activating the object.

### Notes to Implementers

Upon completion of this call, the container should call [IOleInPlaceObject::UIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-uideactivate) to remove the user interface for the object, activate itself, and undo.

## See also

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)