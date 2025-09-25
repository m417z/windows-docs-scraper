# PathGradientBrush::SetInterpolationColors

## Description

The **PathGradientBrush::SetInterpolationColors** method sets the preset colors and the blend positions of this path gradient brush.

## Parameters

### `presetColors` [in]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to an array of [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects that specifies the interpolation colors for the gradient. A color of a given index in the
*presetColors* array corresponds to the blend position of that same index in the
*blendPositions* array.

### `blendPositions` [in]

Type: **REAL***

Pointer to an array that specifies the blend positions. Each blend position is a number from 0 through 1, where 0 indicates the boundary of the gradient and 1 indicates the center point. A blend position between 0 and 1 specifies the set of all points that are a certain fraction of the distance from the boundary to the center point. For example, a blend position of 0.7 specifies the set of all points that are 70 percent of the way from the boundary to the center point.

### `count` [in]

Type: **INT**

Integer that specifies the number of [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects in the
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

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The
**PathGradientBrush::SetInterpolationColors** method sets the brush's preset colors to red, blue, and aqua and sets the blend positions to 0, 0, 4, and 1. The
[Graphics::FillRectangle](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_)) method uses the path gradient brush to paint a rectangle that contains the triangular path.

```cpp
VOID Example_SetInterpColors(HDC hdc)
{
   Graphics graphics(hdc);

   Point points[] = {Point(100, 0), Point(200, 200), Point(0, 200)};
   PathGradientBrush pthGrBrush(points, 3);

   Color col[] = {
      Color(255, 255, 0, 0),     // red
      Color(255, 0, 0, 255),     // blue
      Color(255, 0, 255, 255)};  // aqua

   REAL pos[] = {
      0.0f,    // red at the boundary
      0.4f,    // blue 40 percent of the way from the boundary to the center
      1.0f};   // aqua at the center

   pthGrBrush.SetInterpolationColors(col, pos, 3);
   graphics.FillRectangle(&pthGrBrush, 0, 0, 300, 300);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getinterpolationcolors)