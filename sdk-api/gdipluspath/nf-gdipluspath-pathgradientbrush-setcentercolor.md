# PathGradientBrush::SetCenterColor

## Description

The **PathGradientBrush::SetCenterColor** method sets the center color of this path gradient brush. The center color is the color that appears at the brush's center point.

## Parameters

### `color` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the center color.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default the center point is the centroid of the brush's boundary path, but you can set the center point to any location inside or outside the path.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on an ellipse. The code calls the **PathGradientBrush::SetCenterColor** method of the
**PathGradientBrush** object to set the center color to blue. The
[PathGradientBrush::SetSurroundColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setsurroundcolors) method sets the color along the entire boundary to aqua. The
[FillRectangle Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_)) method uses the path gradient brush to paint a rectangle that contains the ellipse.

```cpp
VOID Example_SetCenter(HDC hdc)
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

   graphics.FillRectangle(&pthGrBrush, 0, 0, 300, 300);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetCenterColor](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getcentercolor)

[PathGradientBrush::GetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getcenterpoint(outpoint))

[PathGradientBrush::SetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcenterpoint(inconstpoint_))