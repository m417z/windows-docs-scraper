# PathGradientBrush::GetBlend

## Description

The **PathGradientBrush::GetBlend** method gets the blend factors and the corresponding blend positions currently set for this path gradient brush.

## Parameters

### `blendFactors` [out]

Type: **REAL***

Pointer to an array that receives the blend factors.

### `blendPositions` [out]

Type: **REAL***

Pointer to an array that receives the blend positions.

### `count` [in]

Type: **INT**

Integer that specifies the number of blend factors to retrieve. Before calling the **PathGradientBrush::GetBlend** method of a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object, call the [PathGradientBrush::GetBlendCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblendcount) method of that same
**PathGradientBrush** object to determine the current number of blend factors. The number of blend positions retrieved is the same as the number of blend factors retrieved.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object has a boundary path and a center point. When you fill an area with a path gradient brush, the color changes gradually as you move from the boundary path to the center point. By default, the color is linearly related to the distance, but you can customize the relationship between color and distance by calling the [PathGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblend) method.

#### Examples

The following example demonstrates several methods of the
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) class including [PathGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblend), [PathGradientBrush::GetBlendCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblendcount), and **PathGradientBrush::GetBlend**. The code creates a
**PathGradientBrush** object and calls the **PathGradientBrush::SetBlend** method to establish a set of blend factors and blend positions for the brush. Then the code calls the **PathGradientBrush::GetBlendCount** method to retrieve the number of blend factors. After the number of blend factors is retrieved, the code allocates two buffers: one to receive the array of blend factors and one to receive the array of blend positions. Then the code calls the **PathGradientBrush::GetBlend** method to retrieve the blend factors and the blend positions.

```cpp
VOID Example_GetBlend(HDC hdc)
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

   // Obtain information about the path gradient brush.
   INT blendCount = pthGrBrush.GetBlendCount();
   REAL* factors = new REAL[blendCount];
   REAL* positions = new REAL[blendCount];

   pthGrBrush.GetBlend(factors, positions, blendCount);

   for(INT j = 0; j < blendCount; ++j)
   {
      // Inspect or use the value in factors[j].
      // Inspect or use the value in positions[j].
   }

   delete [] factors;
   delete [] positions;
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetBlendCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblendcount)

[PathGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblend)

[PathGradientBrush::SetCenterColor](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcentercolor)

[PathGradientBrush::SetCenterPoint Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setcenterpoint(inconstpoint_))

[PathGradientBrush::SetSurroundColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setsurroundcolors)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)