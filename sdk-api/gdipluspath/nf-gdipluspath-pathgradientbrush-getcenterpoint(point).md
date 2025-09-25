# PathGradientBrush::GetCenterPoint(OUT Point)

## Description

The **PathGradientBrush::GetCenterPoint** method gets the center point of this path gradient brush.

## Parameters

### `point` [out]

Type: **[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to a
[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) object that receives the center point.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default, the center point of a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object is at the centroid of the brush's boundary path, but you can set the center point to any location, inside or outside the path, by calling the
[SetCenterPoint](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcenterpoint(inconstpoint_)) method of the
**PathGradientBrush** object.

#### Examples

The following example demonstrates several methods of the
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) class including **PathGradientBrush::GetCenterPoint** and [PathGradientBrush::SetCenterColor](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcentercolor). The code creates a
**PathGradientBrush** object and then sets the brush's center color and boundary color. The code calls the **PathGradientBrush::GetCenterPoint** method to determine the center point of the path gradient brush and then draws a line from the origin to that center point.

```cpp
VOID Example_GetCenterPoint(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path that consists of a single ellipse.
   GraphicsPath path;
   path.AddEllipse(0, 0, 200, 100);

   // Use the path to construct a brush.
   PathGradientBrush pthGrBrush(&path);

   // Set the color at the center of the path to blue.
   pthGrBrush.SetCenterColor(Color(255, 0, 0, 255));

   // Set the color along the entire boundary of the path to aqua.
   Color colors[] = {Color(255, 0, 255, 255)};
   INT count = 1;
   pthGrBrush.SetSurroundColors(colors, &count);

   // Fill the ellipse with the path gradient brush.
   graphics.FillEllipse(&pthGrBrush, 0, 0, 200, 100);

   // Obtain information about the path gradient brush.
   Point  centerPoint;
   pthGrBrush.GetCenterPoint(&centerPoint);

   // Draw a line from the origin to the center of the ellipse.
   Pen pen(Color(255, 0, 255, 0));
   graphics.DrawLine(&pen, Point(0, 0), centerPoint);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetCenterColor](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getcentercolor)

[PathGradientBrush::SetCenterColor](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcentercolor)

[PathGradientBrush::SetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcenterpoint(inconstpoint_))