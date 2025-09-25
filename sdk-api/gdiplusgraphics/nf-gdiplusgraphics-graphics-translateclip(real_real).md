# TranslateClip(REAL,REAL)

## Description

The **Graphics::TranslateClip** method translates the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `dx`

Real number that specifies the horizontal component of the translation.

### `dy`

Real number that specifies the vertical component of the translation.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example measures the size of a string and then draws a rectangle that represents that size.

```cpp
VOID Example_TranslateClipReal(HDC hdc)
{
   Graphics graphics(hdc);

   // Set the clipping region.
   graphics.SetClip(RectF(0.0f, 0.0f, 100.0f, 50.0f));

   // Translate the clipping region.
   graphics.TranslateClip(40.0f, 30.0f);

   // Fill an ellipse that is clipped by the translated clipping region.
   SolidBrush brush(Color(255, 255, 0, 0));
   graphics.FillEllipse(&brush, 20, 40, 100, 80);

   // Draw the outline of the clipping region (rectangle).
   Pen pen(Color(255, 0, 0, 0), 2.0f);
   graphics.DrawRectangle(&pen, 40, 30, 100, 50);
}
```

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[Graphics::IsClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isclipempty)

[IntersectClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-intersectclip(inconstrect_))

[SetClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstgraphicspath_incombinemode))