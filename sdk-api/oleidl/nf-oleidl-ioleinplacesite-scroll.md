# IOleInPlaceSite::Scroll

## Description

Instructs the container to scroll the view of the object by the specified number of pixels.

## Parameters

### `scrollExtant` [in]

The number of pixels by which to scroll in the X and Y directions.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified pointer is not valid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

As a result of scrolling, the object's visible rectangle can change. If that happens, the container should give the new clipping rectangle to the object by calling [IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects). The intersection of the *lprcClipRect* and *lprcPosRect* rectangles gives the new visible rectangle. See [IOleInPlaceSite::GetWindowContext](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-getwindowcontext) for more information.

### Notes to Callers

Called by an active, in-place object when it is asking the container to scroll.

## See also

[IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)