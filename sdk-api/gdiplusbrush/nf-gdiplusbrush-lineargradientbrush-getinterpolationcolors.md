# LinearGradientBrush::GetInterpolationColors

## Description

The **LinearGradientBrush::GetInterpolationColors** method gets the colors currently set to be interpolated for this linear gradient brush and their corresponding blend positions.

## Parameters

### `presetColors` [out]

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to an array that receives the colors. A color of a given index in the
*presetColors* array corresponds to the blend position of that same index in the
*blendPositions* array.

### `blendPositions` [out]

Type: **REAL***

Pointer to an array that receives the blend positions. Each number in the array indicates a percentage of the distance between the starting boundary and the ending boundary and is in the range from 0.0 through 1.0, where 0.0 indicates the starting boundary of the gradient and 1.0 indicates the ending boundary. A blend position between 0.0 and 1.0 indicates a line, parallel to the boundary lines, that is a certain fraction of the distance from the starting boundary to the ending boundary. For example, a blend position of 0.7 indicates the line that is 70 percent of the distance from the starting boundary to the ending boundary. The color is constant on lines that are parallel to the boundary lines.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*presetColors*  array. This is the same as the number of elements in the
*blendPositions* array. Before calling the **LinearGradientBrush::GetInterpolationColors** method of a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object, call the [LinearGradientBrush::GetInterpolationColorCount](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getinterpolationcolorcount) method of that same
**LinearGradientBrush** object to determine the current number of colors. The number of blend positions retrieved is the same as the number of colors retrieved.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetInterpolationColorCount](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getinterpolationcolorcount)

[LinearGradientBrush::SetInterpolationColors](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setinterpolationcolors)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)