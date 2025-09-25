# GetVisibleClipBounds(RectF*)

## Description

The **Graphics::GetVisibleClipBounds** method gets a rectangle that encloses the visible clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.
The visible clipping region is the intersection of the clipping region of this **Graphics** object and the clipping region of the window.

## Parameters

### `rect`

Pointer to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that receives the rectangle that encloses the visible clipping region.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example sets the clipping region for the **Graphics** object.
It then gets a rectangle that encloses the visible clipping region and fills that rectangle.

```cpp
VOID Example_GetVisibleClipBounds2(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the clipping region.
   graphics.SetClip(RectF(100.0f, 100.0f, 200.0f, 100.0f));

   // Get a bounding rectangle for the clipping region.
   RectF boundRect;
   graphics.GetVisibleClipBounds(&boundRect);

   // Fill the bounding rectangle.
   graphics.FillRectangle(&SolidBrush(Color(255, 0, 0, 0)), boundRect);
}
```

## See also

[GetClipBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclipbounds(outrect))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::IsVisibleClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisibleclipempty)

[IsVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisible(inconstpointf_))

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)