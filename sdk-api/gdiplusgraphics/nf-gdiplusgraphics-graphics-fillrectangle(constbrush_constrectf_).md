# FillRectangle(Brush*,RectF&)

## Description

The **Graphics::FillRectangle** method uses a brush to fill the interior of a rectangle.

## Parameters

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) that is used to paint the interior of the rectangle.

### `rect`

Reference to the rectangle to be filled.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

```cpp
VOID Example_FillRectangle2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Create a RectF object.
   RectF fillRect(1.0f, 2.5f, 100.3f, 100.9f);

   // Fill the rectangle.
   graphics.FillRectangle(&blackBrush, fillRect);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)