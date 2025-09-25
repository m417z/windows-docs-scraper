# Graphics::IsVisible(IN const Point &)

## Description

The **Graphics::IsVisible** method determines whether the specified point is inside the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The visible clipping region is the intersection of the clipping region of this **Graphics** object and the clipping region of the window.

## Parameters

### `point` [in]

Type: **const Point&**

Reference to a point to be tested to see whether it is inside the visible clipping region.

## Return value

Type: **BOOL**

If the specified point is inside the visible clipping region, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::IsVisibleClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisibleclipempty)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)