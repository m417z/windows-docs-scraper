# IntersectClip(RectF&)

## Description

The **Graphics::IntersectClip** method updates the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to the portion of the specified rectangle that intersects with the current clipping region of this **Graphics** object.

## Parameters

### `rect`

Reference to a rectangle that is used to update the clipping region.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example sets a clipping region and updates the clipping region.
It then draws rectangles to demonstrate the effective clipping region.

```cpp
VOID Example_IntersectClip2(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the clipping region.
   RectF clipRect(0.5f, 0.5f, 200.5f, 200.5f);
   graphics.SetClip(clipRect);

   // Update the clipping region to the portion of the rectangle that
   // intersects with the current clipping region.
   RectF intersectRect(100.5f, 100.5f, 200.5f, 200.5f);
   graphics.IntersectClip(intersectRect);

   // Fill a rectangle to demonstrate the effective clipping region.
   graphics.FillRectangle(&SolidBrush(Color(255, 0, 0, 255)), 0, 0, 500, 500);

   // Reset the clipping region to infinite.
   graphics.ResetClip();

   // Draw clipRect and intersectRect.
   graphics.DrawRectangle(&Pen(Color(255, 0, 0, 0)), clipRect);
   graphics.DrawRectangle(&Pen(Color(255, 255, 0, 0)), intersectRect);
}
```

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[GetClipBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclipbounds(outrect))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[SetClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstgraphicspath_incombinemode))

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)