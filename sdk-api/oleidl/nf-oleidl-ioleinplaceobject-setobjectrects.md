# IOleInPlaceObject::SetObjectRects

## Description

Specifies how much of the in-place object is to be visible.

## Parameters

### `lprcPosRect` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the position of the in-place object using the client coordinates of its parent window.

### `lprcClipRect` [in]

A pointer to the outer rectangle containing the in-place object's position rectangle (*lprcPosRect*). This rectangle is relative to the client area of the object's parent window.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified pointer is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for the operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

It is possible for *lprcClipRect* to change without *lprcPosRect* changing.

The size of an in-place object's rectangle is always calculated in pixels. This is different from other OLE object's visualizations, which are in **HIMETRIC**.

**Note** While executing **IOleInPlaceObject::SetObjectRects**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **IOleInPlaceObject::SetObjectRects**.

### Notes to Callers

The container should call **IOleInPlaceObject::SetObjectRects** whenever the window position of the in-place object and/or the visible part of the in-place object changes.

### Notes to Implementers

The object must size its in-place window to match the intersection of *lprcPosRect* and *lprcClipRect*. The object must also draw its contents into the object's in-place window so that proper clipping takes place.

The object should compare its width and height with those provided by its container (conveyed through *lprcPosRect*). If the comparison does not result in a match, the container is applying scaling to the object. The object must then decide whether it should continue the in-place editing in the scale/zoom mode or deactivate.

## See also

[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb)

[IOleInPlaceObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceobject)

[IOleInPlaceSite::OnPosRectChange](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onposrectchange)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)