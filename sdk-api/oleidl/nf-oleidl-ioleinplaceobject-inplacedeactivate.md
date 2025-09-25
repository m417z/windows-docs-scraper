# IOleInPlaceObject::InPlaceDeactivate

## Description

Deactivates an active in-place object and discards the object's undo state.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

### Notes to Callers

This method is called by an active object's immediate container to deactivate the active object and discard its undo state.

### Notes to Implementers

On return from **IOleInPlaceObject::InPlaceDeactivate**, the object discards its undo state. The object application should not shut down immediately after this call. Instead, it should wait for an explicit call to [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) or for the object's reference count to reach zero.

Before deactivating, the object application should give the container a chance to put its user interface back on the frame window by calling [IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate).

If the in-place user interface is still visible during the call to **IOleInPlaceObject::InPlaceDeactivate**, the object application should call its own **IOleInPlaceObject::InPlaceDeactivate** method to hide the user interface. The in-place user interface can be optionally destroyed during calls to **IOleInPlaceObject::InPlaceDeactivate** and **IOleInPlaceObject::InPlaceDeactivate**. But if the user interface has not already been destroyed when the container calls [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close), then it must be destroyed during the call to **IOleObject::Close**.

During the call to [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close), the object should check to see whether it is still active in place. If so, it should call **IOleInPlaceObject::InPlaceDeactivate**.

## See also

[IOleInPlaceObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceobject)

[IOleInPlaceSite::OnInPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplacedeactivate)

[IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate)

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)