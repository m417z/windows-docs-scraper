# PathGradientBrush::GetCenterColor

## Description

The **PathGradientBrush::GetCenterColor** method gets the color of the center point of this path gradient brush.

## Parameters

### `color` [out]

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that receives the color of the center point.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default, the center point of a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object is the centroid of the brush's boundary path, but you can set the center point to any location, inside or outside the path, by calling the
[PathGradientBrush::SetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcenterpoint(inconstpoint_)) method of the
**PathGradientBrush** object.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object and uses it to fill an ellipse. Then the code calls the **PathGradientBrush::GetCenterColor** method of the
**PathGradientBrush** object to obtain the center color.

```cpp
VOID Example_GetCenterColor(HDC hdc)
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
   int count = 1;
   pthGrBrush.SetSurroundColors(colors, &count);

   // Fill the ellipse with the path gradient brush.
   graphics.FillEllipse(&pthGrBrush, 0, 0, 200, 100);

   // Obtain information about the path gradient brush.
   Color color;
   pthGrBrush.GetCenterColor(&color);

   // Fill a rectangle with the retrieved color.
   SolidBrush solidBrush(color);
   graphics.FillRectangle(&solidBrush, 0, 120, 200, 30);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getcenterpoint(outpoint))

[PathGradientBrush::SetCenterColor](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcentercolor)

[PathGradientBrush::SetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcenterpoint(inconstpoint_))