# IOleInPlaceSite::OnUIActivate

## Description

Notifies the container that the object is about to be activated in place and that the object is going to replace the container's main menu with an in-place composite menu.

## Return value

This method returns S_OK if the container allows the in-place activation.
Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

The in-place object calls **IOleInPlaceSite::OnUIActivate** just before activating its user interface.

### Notes to Implementers

The container should remove any user interface associated with its own activation. If the container is itself an embedded object, it should remove its document-level user interface.

If there is already an object active in place in the same document, the container should call [IOleInPlaceObject::UIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-uideactivate) before calling [OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate).

## See also

[IOleInPlaceObject::UIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-uideactivate)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)