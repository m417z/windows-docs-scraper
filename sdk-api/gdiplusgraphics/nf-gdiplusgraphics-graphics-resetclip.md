# Graphics::ResetClip

## Description

The **Graphics::ResetClip** method sets the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to an infinite region.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

If the clipping region of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is infinite, then items drawn by that **Graphics** object will not be clipped.

#### Examples

The following example creates a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and sets its clipping region to a rectangle. The code fills two ellipses that intersect the rectangular clipping region. The first ellipse is clipped, but the second ellipse is not clipped because it is filled after a call to **Graphics::ResetClip**.

```cpp
VOID Example_ResetClip(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the clipping region, and draw its outline.
   graphics.SetClip(Rect(100, 50, 200, 120));
   Pen blackPen(Color(255, 0, 0, 0), 2.0f);
   graphics.DrawRectangle(&blackPen, 100, 50, 200, 120);

   // Fill a clipped ellipse in red.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   graphics.FillEllipse(&redBrush, 80, 40, 100, 70);

   // Reset the clipping region.
   graphics.ResetClip();

   // Fill an unclipped ellipse with blue.
   SolidBrush blueBrush(Color(255, 0, 0, 255));
   graphics.FillEllipse(&blueBrush, 160, 150, 100, 60);
}
```

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[Graphics::IsClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isclipempty)

[IntersectClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-intersectclip(inconstrect_))

[IsEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-isempty)