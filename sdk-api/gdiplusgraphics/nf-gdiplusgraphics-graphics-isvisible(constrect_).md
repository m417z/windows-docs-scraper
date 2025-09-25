# Graphics::IsVisible(IN const Rect &)

## Description

The **Graphics::IsVisible** method determines whether the specified rectangle intersects the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The visible clipping region is the intersection of the clipping region of this **Graphics** object and the clipping region of the window.

## Parameters

### `rect` [in]

Type: **const Rect&**

Reference to a rectangle to be tested to determine whether it intersects the visible clipping region.

## Return value

Type: **BOOL**

If the specified rectangle intersects the visible clipping region, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::IsVisibleClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisibleclipempty)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)