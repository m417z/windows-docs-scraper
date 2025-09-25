# PathGradientBrush::SetBlend

## Description

The **PathGradientBrush::SetBlend** method sets the blend factors and the blend positions of this path gradient brush.

## Parameters

### `blendFactors` [in]

Type: **REAL***

Pointer to an array of blend factors. Each number in the array should be in the range 0 through 1.

### `blendPositions` [in]

Type: **REAL***

Pointer to an array of blend positions. Each number in the array should be in the range 0 through 1.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*blendFactors* array. This is the same as the number of elements in the
*blendPositions* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object has a boundary path and a center point. When you fill an area with a path gradient brush, the color changes gradually as you move from the boundary path to the center point. By default, the color is linearly related to the distance, but you can customize the relationship between color and distance by calling the **PathGradientBrush::SetBlend** method.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on an ellipse. The code calls the **PathGradientBrush::SetBlend** method of the
**PathGradientBrush** object to establish a set of blend factors and blend positions for the brush. Then the code uses the path gradient brush to fill the ellipse.

```cpp
VOID Example_SetBlend(HDC hdc)
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

   // Set blend factors and positions for the path gradient brush.
   REAL fac[] = {
      0.0f,
      0.4f,     // 40 percent of the way from aqua to blue
      0.8f,     // 80 percent of the way from aqua to blue
      1.0f};

   REAL pos[] = {
      0.0f,
      0.3f,   // 30 percent of the way from the boundary to the center
      0.7f,   // 70 percent of the way from the boundary to the center
      1.0f};

   pthGrBrush.SetBlend(fac, pos, 4);

   // Fill the ellipse with the path gradient brush.
   graphics.FillEllipse(&pthGrBrush, 0, 0, 200, 100);
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