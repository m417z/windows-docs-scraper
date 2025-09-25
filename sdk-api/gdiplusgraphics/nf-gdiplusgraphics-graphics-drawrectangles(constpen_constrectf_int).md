# DrawRectangles(Pen*,RectF*,INT)

## Description

The **Graphics::DrawRectangles** method draws a sequence of rectangles.

## Parameters

### `pen`

Pointer to a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) that is used to draw the rectangles.

### `rects`

Pointer to an array of [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) objects that specify the coordinates of the rectangles to be drawn.

### `count`

Integer that specifies the number of elements in the *rects* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example draws a group of rectangles.

```cpp
VOID Example_DrawRectangles2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Create an array of RectF objects.
   RectF rect1(0.0f, 0.0f, 100.0f, 200.0f);
   RectF rect2(100.0f, 200.0f, 250.0f, 50.0f);
   RectF rect3(300.0f, 0.0f, 50.0f, 100.0f);
   RectF rects[] = {rect1, rect2, rect3};
   RectF* pRects = rects;

   // Draw the rectangles.
   graphics.DrawRectangles(&blackPen, pRects, 3);
}
```

## See also

[DrawRectangles Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawrectangles(inconstpen_inconstrect_inint))

[FillRectangle Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)