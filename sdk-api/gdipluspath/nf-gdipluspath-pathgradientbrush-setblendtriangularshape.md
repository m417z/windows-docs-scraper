# PathGradientBrush::SetBlendTriangularShape

## Description

The **PathGradientBrush::SetBlendTriangularShape** method sets the blend shape of this path gradient brush.

## Parameters

### `focus` [in]

Type: **REAL**

Real number that specifies where the center color will be at its highest intensity. This number must be in the range 0 through 1.

### `scale` [in, optional]

Type: **REAL**

Optional. Real number that specifies the maximum intensity of center color that gets blended with the boundary color. This number must be in the range 0 through 1. The default value is 1.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default, as you move from the boundary of a path gradient to the center point, the color changes gradually from the boundary color to the center color. You can customize the positioning and blending of the boundary and center colors by calling the **PathGradientBrush::SetBlendTriangularShape** method.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on an ellipse. The code calls the **PathGradientBrush::SetBlendTriangularShape** method of the
**PathGradientBrush** object, passing a focus of 0.2 and a scale of 0.7. Then the code uses the path gradient brush to paint a rectangle that contains the ellipse.

```cpp
VOID Example_SetBlendShape(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path that consists of a single ellipse.
   GraphicsPath path;
   path.AddEllipse(0, 0, 200, 100);

   // Use the path to construct a brush.
   PathGradientBrush pthGrBrush(&path);

   // Set the color at the center of the path to red.
   pthGrBrush.SetCenterColor(Color(255, 255, 0, 0));

   // Set the color along the entire boundary of the path to blue.
   Color colors[] = {Color(255, 0, 0, 255)};
   INT count = 1;
   pthGrBrush.SetSurroundColors(colors, &count);

   pthGrBrush.SetBlendTriangularShape(0.2f, 0.7f);

   // The color is blue on the boundary and at the center.
   // At points that are 20 percent of the way from the boundary to the
   // center, the color is 70 percent red and 30 percent blue.

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

[PathGradientBrush::GetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblend)

[PathGradientBrush::GetBlendCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblendcount)

[PathGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblend)

[PathGradientBrush::SetBlendBellShape](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblendbellshape)