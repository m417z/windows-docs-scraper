# Graphics::IsVisible(IN INT,IN INT,IN INT,IN INT)

## Description

The **Graphics::IsVisible** method determines whether the specified rectangle intersects the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The visible clipping region is the intersection of the clipping region of this **Graphics** object and the clipping region of the window.

## Parameters

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the rectangle to test.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the rectangle to test.

### `width` [in]

Type: **INT**

Integer that specifies the width of the rectangle to test.

### `height` [in]

Type: **INT**

Integer that specifies the height of the rectangle to test.

## Return value

Type: **BOOL**

If the specified rectangle intersects the visible clipping region, this method returns **TRUE**; otherwise, it returns **FALSE**.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::IsVisibleClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisibleclipempty)