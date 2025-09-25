# IOleInPlaceSite::OnPosRectChange

## Description

Notifies the container that the object extents have changed.

## Parameters

### `lprcPosRect` [in]

A pointer a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the position of the in-place object in the client coordinates of its parent window.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied pointer is invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

### Notes to Callers

The **OnPosRectChange** method is called by the in-place object.

### Notes to Implementers

When the in-place object calls **OnPosRectChange**, the container must call [IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects) to specify the new position of the in-place window and the clipping rectangle. Only then does the object resize its window.

In most cases, the object grows to the right and/or down. There could be cases where the object grows to the left and/or up, as conveyed through *lprcPosRect*. It is also possible to change the object's position without changing its size.

## See also

[IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)