# FillEllipse(Brush*,RectF&)

## Description

The **Graphics::FillEllipse** method uses a brush to fill the interior of an ellipse that is specified by a rectangle.

## Parameters

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to paint the interior of the ellipse.

### `rect`

Reference to a rectangle that specifies the boundaries of the ellipse.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example fills an ellipse defined by a bounding rectangle.

```cpp
VOID Example_FillEllipse2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Create the RectF object that defines the ellipse.
   RectF ellipseRect(0.0f, 0.6f, 200.8f, 100.9f);

   // Fill the ellipse.
   graphics.FillEllipse(&blackBrush, ellipseRect);
}
```

## See also

[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)