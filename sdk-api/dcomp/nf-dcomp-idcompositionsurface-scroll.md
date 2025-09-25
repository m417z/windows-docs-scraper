# IDCompositionSurface::Scroll

## Description

Scrolls a rectangular area of a Microsoft DirectComposition logical surface.

## Parameters

### `scrollRect` [in]

The rectangular area of the surface to be scrolled, relative to the upper-left corner of the surface. If this parameter is NULL, the entire surface is scrolled.

### `clipRect` [in, optional]

The *clipRect* clips the destination (*scrollRect* after offset) of the scroll.
The only bitmap content that will be scrolled are those that remain inside the clip rectangle after the scroll is completed.

### `offsetX` [in]

The amount of horizontal scrolling, in pixels. Use positive values to scroll right, and negative values to scroll left.

### `offsetY` [in]

The amount of vertical scrolling, in pixels. Use positive values to scroll down, and negative values to scroll up.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method allows an application to blt/copy a sub-rectangle of a DirectComposition surface object. This avoids re-rendering content that is already available.

The *scrollRect* rectangle must be contained in the boundaries of the surface. If the *scrollRect* rectangle goes outside the bounds of the surface, this method fails.

The bits copied by the scroll operation (source) are defined by the intersection of the *scrollRect* and *clipRect* rectangles.

The bits shown on the screen (destination) are defined by the intersection of the offset source rectangle and *clipRect*.

Scroll operations can only be called before calling [BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) or after calling [EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw). Suspended or resumed surfaces are not candidates for scrolling because they are still being updated.

The application is responsible for ensuring that the scrollable area for an [IDCompositionVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvirtualsurface) is limited to valid pixels. The behavior for invalid pixels in the *scrollRect* is undefined.

Virtual surface sub-rectangular areas that were discarded by a trim or a resize operation can't be scrolled even if the trim or resize is applied in the same batch. [Trim](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-trim) and [Resize](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-resize) are applied immediately.

## See also

[IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)