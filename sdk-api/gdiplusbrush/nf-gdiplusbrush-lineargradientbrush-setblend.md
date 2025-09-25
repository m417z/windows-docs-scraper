# LinearGradientBrush::SetBlend

## Description

The **LinearGradientBrush::SetBlend** method sets the blend factors and the blend positions of this linear gradient brush to create a custom blend.

## Parameters

### `blendFactors` [in]

Type: **const REAL***

Pointer to an array of real numbers that specify blend factors. Each number in the array specifies a percentage of the ending color and should be in the range from 0.0 through 1.0.

### `blendPositions` [in]

Type: **const REAL***

Pointer to an array of real numbers that specify blend positions. Each number in the array indicates a percentage of the distance between the starting boundary and the ending boundary and is in the range from 0.0 through 1.0, where 0.0 indicates the starting boundary of the gradient and 1.0 indicates the ending boundary. There must be at least two positions specified: the first position, which is always 0.0f, and the last position, which is always 1.0f. Otherwise, the behavior is undefined. A blend position between 0.0 and 1.0 indicates a line, parallel to the boundary lines, that is a certain fraction of the distance from the starting boundary to the ending boundary. For example, a blend position of 0.7 indicates the line that is 70 percent of the distance from the starting boundary to the ending boundary. The color is constant on lines that are parallel to the boundary lines.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*blendFactors* array. This is the same as the number of elements in the
*blendPositions* array. The blend factor at a given array index corresponds to the blend position at that same array index.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object has two boundaries. When you fill an area with a linear gradient brush, the color changes gradually as you move from the starting boundary to the ending boundary. By default, the color is linearly related to the distance, but you can customize the relationship between color and distance by calling the **LinearGradientBrush::SetBlend** method.

#### Examples

The following example creates a linear gradient brush, sets a custom blend, and uses the brush to fill a rectangle.

```cpp
VOID Example_SetBlend(HDC hdc)
{
   Graphics myGraphics(hdc);

   REAL factors[4] = {0.0f, 0.4f, 0.6f, 1.0f};
   REAL positions[4] = {0.0f, 0.2f, 0.8f, 1.0f};
   Rect rect(0, 0, 100, 50);

   LinearGradientBrush linGrBrush(
      rect,
      Color(255, 255, 0, 0),  // red
      Color(255, 0, 0, 255),  // blue
      LinearGradientModeHorizontal);

   linGrBrush.SetBlend(factors, positions, 4);
   myGraphics.FillRectangle(&linGrBrush, rect);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetBlend](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getblend)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)