# Graphics::DrawPie(IN const Pen,IN REAL,IN REAL,IN REAL,IN REAL,IN REAL,IN REAL)

## Description

The **Graphics::DrawPie** method draws a pie.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the pie.

### `x` [in]

Type: **REAL**

Real number that specifies the x-coordinate of the upper-left corner of the rectangle that bounds the ellipse in which to draw the pie.

### `y` [in]

Type: **REAL**

Real number that specifies the y-coordinate of the upper-left corner of the rectangle that bounds the ellipse in which to draw the pie.

### `width` [in]

Type: **REAL**

Real number that specifies the width of the rectangle that bounds the ellipse in which to draw the pie.

### `height` [in]

Type: **REAL**

Real number that specifies the height of the rectangle that bounds the ellipse in which to draw the pie.

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

The following illustration shows the pie that is drawn in the ellipse that is bounded by the rectangle. The illustration also shows the horizontal axis of the ellipse and the direction of the
*startAngle* and the *sweepAngle*.

![Illustration showing an ellipse with an outlined pie; the start angle and sweep angle are labeled](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawpie1.png)

#### Examples

The following example draws a pie.

```cpp
VOID Example_DrawPie4(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Define the pie.
   REAL x = 0.0f;
   REAL y = 0.0f;
   REAL width = 200.0f;
   REAL height = 100.0f;
   REAL startAngle = 0.0f;
   REAL sweepAngle = 45.0f;

   // Draw the pie.
   graphics.DrawPie(&blackPen, x, y, width, height, startAngle, sweepAngle);
}

```

## See also

[FillPie Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpie(inconstbrush_inconstrect__inreal_inreal))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Open and Closed Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-open-and-closed-curves-about)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)