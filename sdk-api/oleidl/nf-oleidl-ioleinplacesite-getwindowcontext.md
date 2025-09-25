# IOleInPlaceSite::GetWindowContext

## Description

Enables an in-place object to retrieve the window interfaces that form the window object hierarchy, and the position in the parent window where the object's in-place activation window should be located.

## Parameters

### `ppFrame` [out]

A pointer to an [IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe) pointer variable that receives the interface pointer to the frame. If an error occurs, the implementation must set *ppFrame* to **NULL**.

### `ppDoc` [out]

A pointer to an [IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow) pointer variable that receives the interface pointer to the document window. If the document window is the same as the frame window, *ppDoc* is set to **NULL**. In this case, the object can only use *ppFrame* or border negotiation. If an error is returned, the implementation must set *ppDoc* to **NULL**.

### `lprcPosRect` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure for the rectangle containing the position of the in-place object in the client coordinates of its parent window. If an error is returned, this parameter must be set to **NULL**.

### `lprcClipRect` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure for the outer rectangle containing the in-place object's position rectangle (*lprcPosRect*). This rectangle is relative to the client area of the object's parent window. If an error is returned, this parameter must be set to **NULL**.

### `lpFrameInfo` [in, out]

A pointer to an [OLEINPLACEFRAMEINFO](https://learn.microsoft.com/windows/win32/api/oleidl/ns-oleidl-oleinplaceframeinfo) structure the container is to fill in with appropriate data. If an error is returned, this parameter must be set to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more of the supplied pointers is invalid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

The [OLEINPLACEFRAMEINFO](https://learn.microsoft.com/windows/win32/api/oleidl/ns-oleidl-oleinplaceframeinfo) structure provides data needed by OLE to dispatch keystroke accelerators to a container frame while an object is active in place.

When an object is activated, it calls **GetWindowContext** from its container. The container returns the handle to its in-place accelerator table through the [OLEINPLACEFRAMEINFO](https://learn.microsoft.com/windows/win32/api/oleidl/ns-oleidl-oleinplaceframeinfo) structure. Before calling **GetWindowContext**, the object must provide the size of the **OLEINPLACEFRAMEINFO** structure by filling in the cb member, pointed to by *lpFrameInfo*.

## See also

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)