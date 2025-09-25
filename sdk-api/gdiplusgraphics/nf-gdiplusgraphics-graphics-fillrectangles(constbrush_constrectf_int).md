# FillRectangles(Brush*,RectF*,INT)

## Description

The **Graphics::FillRectangles** method uses a brush to fill the interior of a sequence of rectangles.

## Parameters

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) that is used to fill the interior of each rectangle.

### `rects`

Pointer to an array of rectangles to be filled.

### `count`

Integer that specifies the number of rectangles in the *rects* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example fills a sequence of rectangles.

```cpp
VOID Example_FillRectangles2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Create an array of RectF objects.
   RectF rect1(0.0f, 0.0f, 100.0f, 200.0f);
   RectF rect2(100.5f, 200.5f, 200.5f, 50.5f);
   RectF rect3(300.8f, 0.8f, 50.8f, 150.8f);
   RectF rects[3] = {rect1, rect2, rect3};

   // Fill the rectangles.
   graphics.FillRectangles(&blackBrush, rects, 3);
}
```

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)