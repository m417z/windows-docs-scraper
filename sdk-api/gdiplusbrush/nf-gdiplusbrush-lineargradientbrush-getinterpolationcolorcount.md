# LinearGradientBrush::GetInterpolationColorCount

## Description

The **LinearGradientBrush::GetInterpolationColorCount** method gets the number of colors currently set to be interpolated for this linear gradient brush.

## Return value

Type: **INT**

This method returns the number of colors to be interpolated for this linear gradient brush. If no colors have been set by using [LinearGradientBrush::SetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setinterpolationcolors), or if invalid positions were passed to **LinearGradientBrush::SetInterpolationColors**, then **LinearGradientBrush::GetInterpolationColorCount** returns 0.

## Remarks

A simple linear gradient brush has two colors: a color at the starting boundary and a color at the ending boundary. When you paint with such a brush, the color changes gradually from the starting color to the ending color as you move from the starting boundary to the ending boundary. You can create a more complex gradient by using the [LinearGradientBrush::SetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setinterpolationcolors) method to specify an array of colors and their corresponding blend positions to be interpolated for this linear gradient brush.

You can obtain the colors and blend positions currently set for a linear gradient brush by calling its [LinearGradientBrush::GetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getinterpolationcolors) method. Before you call the **LinearGradientBrush::GetInterpolationColors** method, you must allocate two buffers: one to hold the array of colors and one to hold the array of blend positions. You can call the **LinearGradientBrush::GetInterpolationColorCount** method to determine the required size of those buffers. The size of the colors buffer is the return value of **LinearGradientBrush::GetInterpolationColorCount** multiplied by
**sizeof**([Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)). The size of the blend positions buffer is the value of **LinearGradientBrush::GetInterpolationColorCount** multiplied by
**sizeof**(
**REAL**).

#### Examples

The following example sets the colors to be interpolated for this linear gradient brush to red, blue, and green and sets the blend positions to 0, 0.3, and 1. The code calls the **LinearGradientBrush::GetInterpolationColorCount** method of a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object to obtain the number of colors currently set to be interpolated for the brush. Next, the code gets the colors and their positions. Then, the code fills a small rectangle with each color.

```cpp
VOID Example_GetInterpColors(HDC hdc)
{
   Graphics myGraphics(hdc);

   // Create a linear gradient brush, and set the colors to be interpolated.
   Color col[] = {
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255),   // blue
      Color(255, 0, 255, 0)};  // green

   REAL pos[] = {
      0.0f,   // red at the left edge
      0.3f,   // blue at 30 percent of the distance from
              // left edge to right edge
      1.0f};  // green at the right edge

   LinearGradientBrush linGrBrush(
      Point(0, 0),
      Point(100, 0),
      Color(255, 0, 0, 0),         // black
      Color(255, 255, 255, 255));  // white

   linGrBrush.SetInterpolationColors(col, pos, 3);

   // Obtain information about the linear gradient brush.
   INT    colorCount = 0;
   Color* colors = NULL;
   REAL*  positions = NULL;

   // How many colors have been specified to be interpolated
   // for this brush?
   colorCount = linGrBrush.GetInterpolationColorCount();

   // Allocate a buffer large enough to hold the set of colors.
   colors = new Color[colorCount];

   // Allocate a buffer to hold the relative positions of the colors.
   positions = REAL[colorCount];

   // Get the colors and their relative positions.
   linGrBrush.GetInterpolationColors(colors, positions, colorCount);

   // Fill a small rectangle with each of the colors.
   SolidBrush* pSolidBrush;
   for(INT j = 0; j < colorCount; j++)
   {
      pSolidBrush = new SolidBrush(colors[j]);
      myGraphics.FillRectangle(pSolidBrush, 15*j, 0, 10, 10);
      delete(pSolidBrush);
   }
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getinterpolationcolors)

[LinearGradientBrush::SetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setinterpolationcolors)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)