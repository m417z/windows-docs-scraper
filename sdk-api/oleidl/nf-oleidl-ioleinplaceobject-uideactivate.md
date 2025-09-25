# IOleInPlaceObject::UIDeactivate

## Description

Deactivates and removes the user interface of an active in-place object.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

This method is called by the object's immediate container when, for example, the user has clicked in the client area outside the object.

If the container has called **IOleInPlaceObject::UIDeactivate**, it should later call [IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) to properly clean up resources. The container can assume that stopping or releasing the object cleans up resources if necessary. The object must be prepared to do so if **IOleInPlaceObject::InPlaceDeactivate** has not been called. but either **IOleInPlaceObject::UIDeactivate** or [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) has been called.

### Notes to Implementers

Resources such as menus and windows can be either cleaned up or kept in a hidden state until your object is completely deactivated by calls to either [IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) or [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close). The object application must call [IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate) before doing anything with the composite menus so that the container can first be detached from the frame window. On deactivating the in-place object's user interface, the object is left in a ready state so it can be quickly reactivated. The object stays in this state until the undo state of the document changes. The container should then call **IOleInPlaceObject::InPlaceDeactivate** to tell the object to discard its undo state.

## See also

[IOleInPlaceObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceobject)

[IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate)

[IOleInPlaceObject::ReactivateAndUndo](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-reactivateandundo)

[IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate)

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)