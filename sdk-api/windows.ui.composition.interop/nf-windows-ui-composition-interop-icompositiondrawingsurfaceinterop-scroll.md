# ICompositionDrawingSurfaceInterop::Scroll (windows.ui.composition.interop.h)

## Description

Scrolls a rectangular area of the logical surface.

## Parameters

### `scrollRect` [in, optional]

Type: **const RECT***

The rectangular area of the surface to be scrolled, relative to the upper-left corner of the surface. If this parameter is NULL, the entire surface is scrolled.

### `clipRect` [in, optional]

Type: **const RECT***

The clipRect clips the destination (scrollRect after offset) of the scroll. The only bitmap content that will be scrolled are those that remain inside the clip rectangle after the scroll is completed.

### `offsetX` [in]

Type: **int**

The amount of horizontal scrolling, in pixels. Use positive values to scroll right, and negative values to scroll left.

### `offsetY` [in]

Type: **int**

The amount of vertical scrolling, in pixels. Use positive values to scroll down, and negative values to scroll up.

## Return value

Type: **HRESULT**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[ICompositionDrawingSurfaceInterop](https://learn.microsoft.com/windows/desktop/api/windows.ui.composition.interop/nn-windows-ui-composition-interop-icompositiondrawingsurfaceinterop)