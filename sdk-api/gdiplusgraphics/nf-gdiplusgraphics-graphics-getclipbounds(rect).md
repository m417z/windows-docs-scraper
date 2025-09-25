# Graphics::GetClipBounds(OUT Rect)

## Description

The **Graphics::GetClipBounds** method gets a rectangle that encloses the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `rect` [out]

Type: **Rect***

Pointer to a [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object that receives the rectangle that encloses the clipping region.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The world transformation is applied to the clipping region and then the enclosing rectangle is calculated.

If you do not explicitly set the clipping region of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, its clipping region is infinite. When the clipping region is infinite, **Graphics::GetClipBounds** returns a large rectangle. The
**X** and
**Y** data members of that rectangle are large negative numbers, and the
**Width** and
**Height** data members are large positive numbers.

#### Examples

The following example sets a clipping region, gets the rectangle that encloses the clipping region, and then fills the rectangle.

```cpp
VOID Example_GetClipBounds(HDC hdc)
{
   Graphics graphics(hdc);

   Region   myRegion(Rect(25, 25, 100, 50));
   Rect     rect(40, 60, 100, 50);
   Region   gRegion;
   Rect     enclosingRect;

   SolidBrush  blueBrush(Color(100, 0, 0, 255));
   Pen         greenPen(Color(255, 0, 255, 0), 1.5f);

   // Modify the region by using a rectangle.
   myRegion.Union(rect);

   // Set the clipping region of the graphics object.
   graphics.SetClip(&myRegion);

   // Now, get the clipping region, and fill it.
   graphics.GetClip(&gRegion);
   graphics.FillRegion(&blueBrush, &gRegion);

   // Get a rectangle that encloses the clipping region, and draw the enclosing
   // rectangle.
   graphics.GetClipBounds(&enclosingRect);
   graphics.ResetClip();
   graphics.DrawRectangle(&greenPen, enclosingRect);}
```

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[GetVisibleClipBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getvisibleclipbounds(outrect))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[SetClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstgraphicspath_incombinemode))

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)