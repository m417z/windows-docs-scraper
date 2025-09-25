# IOleInPlaceSite::OnInPlaceDeactivate

## Description

Notifies the container that the object is no longer active in place.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

**OnInPlaceDeactivate** is called by an in-place object when it is fully deactivated. This function notifies the container that the object has been deactivated, and it gives the container a chance to run code pertinent to the object's deactivation. In particular, **OnInPlaceDeactivate** is called as a result of [IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) being called. Calling **OnInPlaceDeactivate** indicates that the object can no longer support Undo.

### Notes to Implementers

If the container is holding pointers to the [IOleInPlaceObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceobject) and [IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject) interface implementations, it should release them after the **OnInPlaceDeactivate** call.

## See also

[IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)