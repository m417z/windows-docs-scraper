# Graphics::FillPie(IN const Brush,IN const Rect &,IN REAL,IN REAL)

## Description

The **Graphics::FillPie** method uses a brush to fill the interior of a pie.

## Parameters

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to paint the interior of the pie.

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that bounds the ellipse. A curved portion of the ellipse is the arc of the pie.

### `startAngle` [in]

Type: **REAL**

Real number that specifies the angle, in degrees, between the x-axis and the starting point of the pie's arc.

### `sweepAngle` [in]

Type: **REAL**

Real number that specifies the angle, in degrees, between the starting and ending points of the pie's arc.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A pie is a portion of the interior of an ellipse (it is bounded by an elliptical curve and two radial lines). The
*startAngle* and
*sweepAngle* specify the portion of the ellipse to be used.

#### Examples

The following example defines a pie and then fills it.

```cpp
VOID Example_FillPie(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Define the pie shape.
   Rect ellipseRect(0, 0, 200, 100);
   REAL startAngle = 0.0f;
   REAL sweepAngle = 45.0f;

   // Fill the pie.
   graphics.FillPie(&blackBrush, ellipseRect, startAngle, sweepAngle);
}
```

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)