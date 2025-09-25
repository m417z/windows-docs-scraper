# Graphics::DrawPie(IN const Pen,IN const Rect &,IN REAL,IN REAL)

## Description

The **Graphics::DrawPie** method draws a pie.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the pie.

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that bounds the ellipse in which to draw the pie.

### `startAngle` [in]

Type: **REAL**

Real number that specifies the angle, in degrees, between the x-axis and the starting point of the arc that defines the pie. A positive value specifies clockwise rotation.

### `sweepAngle` [in]

Type: **REAL**

Real number that specifies the angle, in degrees, between the starting and ending points of the arc that defines the pie. A positive value specifies clockwise rotation.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The following illustration shows the pie that is drawn in the ellipse that is bounded by the rectangle. The illustration also shows the horizontal axis of the ellipse and the direction of the *startAngle* and the *sweepAngle*.

![Illustration showing an ellipse with an outlined pie; the start angle and sweep angle are labeled](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawpie1.png)

#### Examples

The following example draws a pie.

```cpp

VOID Example_DrawPie(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Define the pie.
   Rect ellipseRect(0, 0, 200, 100);
   REAL startAngle = 0.0f;
   REAL sweepAngle = 45.0f;

   // Draw the pie.
   graphics.DrawPie(&blackPen, ellipseRect, startAngle, sweepAngle);
}

```

## See also

[DrawLines Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawlines(inconstpen_inconstpoint_inint))

[FillPie Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpie(inconstbrush_inconstrect__inreal_inreal))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Open and Closed Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-open-and-closed-curves-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)