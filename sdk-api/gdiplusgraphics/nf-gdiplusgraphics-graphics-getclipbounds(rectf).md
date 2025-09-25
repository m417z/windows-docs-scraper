# GetClipBounds(RectF*)

## Description

The **Graphics::GetClipBounds** method gets a rectangle that encloses the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `rect`

Pointer to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that receives the rectangle that encloses the clipping region.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

The world transformation is applied to the clipping region and then the enclosing rectangle is calculated.

If you do not explicitly set the clipping region of a **Graphics** object, its clipping region is infinite.
When the clipping region is infinite, **Graphics::GetClipBounds** returns a large rectangle.
The X and Y data members of that rectangle are large negative numbers, and the *Width* and *Height* data members are large positive numbers.

#### Examples

The following example sets a clipping region, gets the rectangle that encloses the clipping region, and then fills the rectangle.

```cpp
VOID Example_GetClipBounds2(HDC hdc)
{
   Graphics graphics(hdc);

   Region   myRegion(RectF(25.0f, 25.0f, 100.0f, 50.0f));
   RectF    rect(40.0f, 60.0f, 100.0f, 50.0f);
   Region   gRegion;
   RectF    enclosingRect;

   SolidBrush  blueBrush(Color(100, 0, 0, 255));
   Pen         greenPen(Color(255, 0, 255, 0), 1.5f);

   // Modify the region by using a rectangle.
   myRegion.Union(rect);

   // Set the clipping region of the graphics object.
   graphics.SetClip(&myRegion);

   // Now, get the clipping region, and fill it
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

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[SetClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstgraphicspath_incombinemode))

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)