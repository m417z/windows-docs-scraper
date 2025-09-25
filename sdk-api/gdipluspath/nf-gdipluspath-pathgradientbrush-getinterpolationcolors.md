# PathGradientBrush::GetInterpolationColors

## Description

The **PathGradientBrush::GetInterpolationColors** method gets the preset colors and blend positions currently specified for this path gradient brush.

## Parameters

### `presetColors` [out]

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to an array that receives the preset colors. A color of a given index in the
*presetColors* array corresponds to the blend position of that same index in the
*blendPositions* array.

### `blendPositions` [out]

Type: **REAL***

Pointer to an array that receives the blend positions. Each blend position is a number from 0 through 1, where 0 indicates the boundary of the gradient and 1 indicates the center point. A blend position between 0 and 1 indicates the set of all points that are a certain fraction of the distance from the boundary to the center point. For example, a blend position of 0.7 indicates the set of all points that are 70 percent of the way from the boundary to the center point.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*presetColors* array. This is the same as the number of elements in the
*blendPositions* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A simple path gradient brush has two colors: a boundary color and a center color. When you paint with such a brush, the color changes gradually from the boundary color to the center color as you move from the boundary path to the center point. You can create a more complex gradient by specifying an array of preset colors and an array of blend positions.

Before you call the **PathGradientBrush::GetInterpolationColors** method, you must allocate two buffers: one to hold the array of preset colors and one to hold the array of blend positions. You can call the [PathGradientBrush::GetInterpolationColorCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getinterpolationcolorcount) method of the
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object to determine the required size of those buffers. The size of the color buffer is the return value of **PathGradientBrush::GetInterpolationColorCount** multiplied by
**sizeof**([Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)). The size of the position buffer is the value of **PathGradientBrush::GetInterpolationColorCount** multiplied by
**sizeof**(
**REAL**).

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object from a triangular path. The code sets the preset colors to red, blue, and aqua and sets the blend positions to 0, 0.6, and 1. The code calls the [PathGradientBrush::GetInterpolationColorCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getinterpolationcolorcount) method of the
**PathGradientBrush** object to obtain the number of preset colors currently set for the brush. Next, the code allocates two buffers: one to hold the array of preset colors, and one to hold the array of blend positions. The call to the **PathGradientBrush::GetInterpolationColors** method of the
**PathGradientBrush** object fills the buffers with the preset colors and the blend positions. Finally the code fills a small square with each of the preset colors.

```cpp
VOID Example_GetInterpColors(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path gradient brush from an array of points, and
   // set the interpolation colors for that brush.

   Point points[] = {Point(100, 0), Point(200, 200), Point(0, 200)};
   PathGradientBrush pthGrBrush(points, 3);

   Color col[] = {
      Color(255, 255, 0, 0),     // red
      Color(255, 0, 0, 255),     // blue
      Color(255, 0, 255, 255)};  // aqua

   REAL pos[] = {
      0.0f,    // red at the boundary
      0.6f,    // blue 60 percent of the way from the boundary to the center
      1.0f};   // aqua at the center

   pthGrBrush.SetInterpolationColors(col, pos, 3);

   // Obtain information about the path gradient brush.
   INT colorCount = pthGrBrush.GetInterpolationColorCount();
   Color* colors = new Color[colorCount];
   REAL* positions = new REAL[colorCount];
   pthGrBrush.GetInterpolationColors(colors, positions, colorCount);

   // Fill a small square with each of the interpolation colors.
   SolidBrush solidBrush(Color(255, 255, 255, 255));

   for(INT j = 0; j < colorCount; ++j)
   {
      solidBrush.SetColor(colors[j]);
      graphics.FillRectangle(&solidBrush, 15*j, 0, 10, 10);
   }

   delete [] colors;
   delete [] positions;
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetInterpolationColorCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getinterpolationcolorcount)

[PathGradientBrush::SetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setinterpolationcolors)