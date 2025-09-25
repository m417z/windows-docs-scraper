# PathGradientBrush::SetFocusScales

## Description

The **PathGradientBrush::SetFocusScales** method sets the focus scales of this path gradient brush.

## Parameters

### `xScale` [in]

Type: **REAL**

Real number that specifies the x focus scale.

### `yScale` [in]

Type: **REAL**

Real number that specifies the y focus scale.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default, the center color of a path gradient is at the center point. By calling **PathGradientBrush::SetFocusScales**, you can specify that the center color should appear along a path that surrounds the center point. That path is the boundary path scaled by a factor of
*xScale* in the x direction and by a factor of
*yScale* in the y direction. The area inside the scaled path is filled with the center color.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The code calls the **PathGradientBrush::SetFocusScales** method of the
**PathGradientBrush** object to set the brush's focus scales to (0.2, 0.2). Then the code uses the path gradient brush to paint a rectangle that includes the triangular path.

```cpp
VOID Example_SetFocusScales(HDC hdc)
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
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetFocusScales](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getfocusscales)

[PathGradientBrush::SetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setinterpolationcolors)