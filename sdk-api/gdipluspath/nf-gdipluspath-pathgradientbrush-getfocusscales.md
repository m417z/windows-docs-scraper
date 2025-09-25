# PathGradientBrush::GetFocusScales

## Description

The **PathGradientBrush::GetFocusScales** method gets the focus scales of this path gradient brush.

## Parameters

### `xScale` [out]

Type: **REAL***

Pointer to a
**REAL** that receives the x focus scale value.

### `yScale` [out]

Type: **REAL***

Pointer to a
**REAL** that receives the y focus scale value.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default, the center color of a path gradient is at the center point. By calling [PathGradientBrush::SetFocusScales](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setfocusscales), you can specify that the center color should appear along a path that surrounds the center point. For example, suppose the boundary path is a triangle and the center point is at the centroid of that triangle. Also assume that the boundary color is red and the center color is blue. If you set the focus scales to (0.2, 0.2), the color is blue along the boundary of a small triangle that surrounds the center point. That small triangle is the main boundary path scaled by a factor of 0.2 in the x direction and 0.2 in the y direction. When you paint with the path gradient brush, the color will change gradually from red to blue as you move from the boundary of the large triangle to the boundary of the small triangle. The area inside the small triangle will be filled with blue.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The code sets the focus scales of the path gradient brush to (0.2, 0.2) and then uses the path gradient brush to fill an area that contains the triangular path. Finally, the code calls the **PathGradientBrush::GetFocusScales** method of the
**PathGradientBrush** object to obtain the values of the x focus scale and the y focus scale.

```cpp
VOID Example_GetFocusScales(HDC hdc)
{
   Graphics graphics(hdc);

   Point points[] = {Point(100, 0), Point(200, 200), Point(0, 200)};

   // No GraphicsPath object is created. The PathGradientBrush
   // object is constructed directly from the array of points.
   PathGradientBrush pthGrBrush(points, 3);

   Color colors[] = {
      Color(255, 255, 0, 0),    // red
      Color(255, 0, 0, 255)};   // blue

   REAL relativePositions[] = {
      0.0f,    // red at the boundary of the outer triangle
      1.0f};   // blue at the boundary of the inner triangle

   pthGrBrush.SetInterpolationColors(colors, relativePositions, 2);

   // The inner triangle is formed by scaling the outer triangle
   // about its centroid. The scaling factor is 0.2 in both
   // the x and y directions.
   pthGrBrush.SetFocusScales(0.2f, 0.2f);

   // Fill a rectangle that is larger than the triangle
   // specified in the Point array. The portion of the
   // rectangle outside the triangle will not be painted.
   graphics.FillRectangle(&pthGrBrush, 0, 0, 200, 200);

   // Obtain information about the path gradient brush.
   REAL xScale = 0.0f;
   REAL yScale = 0.0f;
   pthGrBrush.GetFocusScales(&xScale, &yScale);

   // The value of xScale is now 0.2.
   // The value of yScale is now 0.2.
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::SetFocusScales](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setfocusscales)