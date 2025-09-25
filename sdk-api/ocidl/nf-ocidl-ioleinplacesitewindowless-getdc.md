# IOleInPlaceSiteWindowless::GetDC

## Description

Provides an object with a handle to a device context for a screen or compatible device from its container.

## Parameters

### `pRect` [in]

A pointer to the rectangle that the object wants to redraw, in client coordinates of the containing window. If this parameter is **NULL**, the object's full extent is redrawn.

### `grfFlags` [in]

A combination of values from the [OLEDCFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-oledcflags) enumeration.

### `phDC` [out]

A pointer to a returned device context.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NESTEDPAINT** | The container is already in the middle of a paint session. That is, this method has already been called, and the [IOleInPlaceSiteWindowless::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-releasedc) method has not yet been called. |

## Remarks

A device context obtained by this method should be released by calling [IOleInPlaceSiteWindowless::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-releasedc).

Like other methods in this interface, rectangles are specified in client coordinates of the containing window. The container is expected to intersect this rectangle with the object's site rectangle and clip out everything outside the resulting rectangle. This prevents objects from inadvertently drawing where they are not supposed to.

Containers are also expected to map the device context origin so the object can draw in client coordinates of the containing window, usually the container's window. If the container is merely passing its window device context, this occurs automatically. If it is returning another device context, for example, an offscreen memory device context, then the viewport origin should be set appropriately.

### Notes to Implementers

Depending whether it is returning an on-screen or off-screen device context and depending on how sophisticated it is, container can use one of the following algorithms:

1. On-screen, One Pass Drawing

   1. In the **IOleInPlaceSiteWindowless::GetDC** method, the container should:
      * Get the window device context.
      * If [OLEDC](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-oledcflags)_PAINTBKGND is set, draw the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)_CONTENT aspect of every object behind the object requesting the device context.
      * Return the device context.
   2. In the [ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-releasedc) method, the container should:
      * Draw the DVASPECT_CONTENT of every overlapping object.
      * Release the device context.
2. On-screen, Two Pass Drawing

   1. In the **IOleInPlaceSiteWindowless::GetDC** method, the container should:
      * Get the window device context.
      * Clip out the opaque regions of any overlapping object. These regions do not need to be redrawn since they are already correct on the screen.
      * If OLEDC_PAINTBKGND is not set, return the device context.
      * Otherwise, clip out the opaque parts of the object requesting the device context and draw the opaque parts of every object behind it going front to back.
      * Draw the transparent aspects of every object behind going back to front, setting the clipping region appropriately each time.
      * Finally return the device context.
   2. In the [IOleInPlaceSiteWindowless::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-releasedc) method, the container should:
      * Draw the transparent parts of every overlapping object.
      * Release the device context.
3. Off-screen Drawing

   1. In the **IOleInPlaceSiteWindowless::GetDC** method, the container should:
      * Create a screen compatible memory device context, containing a compatible bitmap of appropriate size.
      * Map the viewport origin of the device context to ensure that the calling object can draw using client area coordinates of the containing window.
      * If OLEDC_PAINTBKGND is set, draw the DVASPECT_CONTENT of every object behind the calling object.
      * Return the device context.
   2. In the [IOleInPlaceSiteWindowless::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-releasedc) method, the container should:
      * Draw the DVASPECT_CONTENT aspect of every overlapping object.
      * Copy the off-screen bitmap to the screen at the location the calling object originally requested in **IOleInPlaceSiteWindowless::GetDC**.
      * Delete and release the memory device context.

When this method returns, the clipping region in the device context should be set so that the object can't paint in any area it is not supposed to. If the object is not opaque, the background should have been painted. If the device context is a screen, any overlapping opaque areas should be clipped out.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)

[IOleInPlaceSiteWindowless::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-releasedc)

[OLEDCFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-oledcflags)