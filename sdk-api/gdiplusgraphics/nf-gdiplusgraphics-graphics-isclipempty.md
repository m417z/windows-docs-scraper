# Graphics::IsClipEmpty

## Description

The **Graphics::IsClipEmpty** method determines whether the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is empty.

## Return value

Type: **BOOL**

If the clipping region of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is empty, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

If the clipping region of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is empty, there is no area left in which to draw. Consequently, nothing will be drawn when the clipping region is empty.

#### Examples

The following example determines whether the clipping region is empty and, if it isn't, draws a rectangle.

```cpp
VOID Example_IsClipEmpty(HDC hdc)
{
   Graphics graphics(hdc);

   // If the clipping region is not empty, draw a rectangle.
   if (!graphics.IsClipEmpty())
   {
   graphics.DrawRectangle(&Pen(Color(255, 0, 0, 0), 3), 0, 0, 100, 100);
   }
}
```

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[GetClipBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclipbounds(outrect))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[Graphics::IsVisibleClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isvisibleclipempty)

[Graphics::ResetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resetclip)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[SetClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstgraphicspath_incombinemode))