# FillPie(Brush*,RectF&,REAL,REAL)

## Description

The **Graphics::FillPie** method uses a brush to fill the interior of a pie.

## Parameters

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to paint the interior of the pie.

### `rect`

Reference to a rectangle that bounds the ellipse.
A curved portion of the ellipse is the arc of the pie.

### `startAngle`

Real number that specifies the angle, in degrees, between the x-axis and the starting point of the pie's arc.

### `sweepAngle`

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

A pie is a portion of the interior of an ellipse (it is bounded by an elliptical curve and two radial lines).
The *startAngle* and *sweepAngle* specify the portion of the ellipse to be used.

#### Examples

The following example defines a pie and then fills it.

```cpp
VOID Example_FillPie2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Define the pie shape.
   RectF ellipseRect(0.5f, 0.8f, 200.9f, 100.6f);
   REAL startAngle = 0.0;
   REAL sweepAngle = 45.8;

   // Fill the pie.
   graphics.FillPie(&blackBrush, ellipseRect, startAngle, sweepAngle);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)