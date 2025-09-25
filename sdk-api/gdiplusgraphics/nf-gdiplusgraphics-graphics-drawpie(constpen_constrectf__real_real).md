# DrawPie(Pen*,RectF&,REAL,REAL)

## Description

The **Graphics::DrawPie** method draws a pie.

## Parameters

### `pen`

Pointer to a pen that is used to draw the pie.

### `rect`

Rectangle that bounds the ellipse in which to draw the pie.

### `startAngle`

Real number that specifies the angle, in degrees, between the x-axis and the starting point of the arc that defines the pie.
A positive value specifies clockwise rotation.

### `sweepAngle`

Real number that specifies the angle, in degrees, between the starting and ending points of the arc that defines the pie.
A positive value specifies clockwise rotation.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example draws a pie.

```cpp
VOID Example_DrawPie2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Define the pie.
   RectF ellipseRect(0, 0, 200, 100);
   REAL startAngle = 0.0f;
   REAL sweepAngle = 45.0f;

   // Draw the pie.
   graphics.DrawPie(&blackPen, ellipseRect, startAngle, sweepAngle);
}
```

## See also

[FillPie Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpie(inconstbrush_inconstrect__inreal_inreal))

[Open and Closed Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-open-and-closed-curves-about)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)