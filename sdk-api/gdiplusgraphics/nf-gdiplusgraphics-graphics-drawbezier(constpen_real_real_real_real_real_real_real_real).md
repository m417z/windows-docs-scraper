# DrawBezier(Pen*,REAL,REAL,REAL,REAL,REAL,REAL,REAL,REAL)

## Description

The **Graphics::DrawBezier** method draws a Bézier spline.

## Parameters

### `pen`

Pointer to a pen that is used to draw the Bézier spline.

### `x1`

Real number that specifies the x-coordinate of the starting point of the Bézier spline.

### `y1`

Real number that specifies the y-coordinate of the starting point of the Bézier spline.

### `x2`

Real number that specifies the x-coordinate of the first control point of the Bézier spline.

### `y2`

Real number that specifies the y-coordinate of the first control point of the Bézier spline.

### `x3`

Real number that specifies the x-coordinate of the second control point of the Bézier spline.

### `y3`

Real number that specifies the y-coordinate of the second control point of the Bézier spline.

### `x4`

Real number that specifies the x-coordinate of the ending point of the Bézier spline.

### `y4`

Real number that specifies the y-coordinate of the ending point of the Bézier spline.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

A Bézier spline does not pass through its control points.
The control points act as magnets, pulling the curve in certain directions to influence the way the Bézier spline bends.

#### Examples

The following example draws a Bézier curve.

```cpp
VOID Example_DrawBezier4(HDC hdc)
{
   Graphics graphics(hdc);

   // Set up the pen and curve points.
   Pen greenPen(Color(255, 0, 255, 0));
   REAL startPointx = 100.0f;
   REAL startPointy = 100.0f;
   REAL ctrlPoint1x = 200.0f;
   REAL ctrlPoint1y = 10.0f;
   REAL ctrlPoint2x = 350.0f;
   REAL ctrlPoint2y = 50.0f;
   REAL endPointx = 500.0f;
   REAL endPointy = 100.0f;

   //Draw the curve.
   graphics.DrawBezier(
   &greenPen,
   startPointx,
   startPointy,
   ctrlPoint1x,
   ctrlPoint1y,
   ctrlPoint2x,
   ctrlPoint2y,
   endPointx,
   endPointy);

   //Draw the end points and control points.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   SolidBrush blueBrush(Color(255, 0, 0, 255));
   graphics.FillEllipse(&redBrush, 100 - 5, 100 - 5, 10, 10);
   graphics.FillEllipse(&redBrush, 500 - 5, 100 - 5, 10, 10);
   graphics.FillEllipse(&blueBrush, 200 - 5, 10 - 5, 10, 10);
   graphics.FillEllipse(&blueBrush, 350 - 5, 50 - 5, 10, 10);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[DrawBezier](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbezier(inconstpen_inconstpointf__inconstpointf__inconstpointf__inconstpointf_))

[DrawBeziers Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbeziers(inconstpen_inconstpoint_inint))

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Drawing Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-bezier-splines-use)

[Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-bezier-splines-about)