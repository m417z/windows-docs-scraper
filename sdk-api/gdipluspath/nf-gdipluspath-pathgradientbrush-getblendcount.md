# PathGradientBrush::GetBlendCount

## Description

The **PathGradientBrush::GetBlendCount** method gets the number of blend factors currently set for this path gradient brush.

## Return value

Type: **INT**

This method returns the number of blend factors currently set for this path gradient brush.

## Remarks

Before you call the [PathGradientBrush::GetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblend) method of a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object, you must allocate two buffers: one to receive an array of blend factors and one to receive an array of blend positions. To determine the size of the required buffers, call the **PathGradientBrush::GetBlendCount** method of the
**PathGradientBrush** object. The size (in bytes) of each buffer should be the return value of **PathGradientBrush::GetBlendCount** multiplied by
**sizeof**(
**REAL**).

#### Examples

The following example demonstrates several methods of the
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) class, including [PathGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblend), **PathGradientBrush::GetBlendCount**, and [PathGradientBrush::GetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblend). The code creates a
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

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getblend)

[PathGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setblend)