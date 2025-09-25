# LinearGradientBrush::GetBlend

## Description

The **LinearGradientBrush::GetBlend** method gets the blend factors and their corresponding blend positions from a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object.

## Parameters

### `blendFactors` [out]

Type: **REAL***

Pointer to an array that receives the blend factors. Each number in the array indicates a percentage of the ending color and is in the range from 0.0 through 1.0.

### `blendPositions` [out]

Type: **REAL***

Pointer to an array that receives the blend positions. Each number in the array indicates a percentage of the distance between the starting boundary and the ending boundary and is in the range from 0.0 through 1.0, where 0.0 indicates the starting boundary of the gradient and 1.0 indicates the ending boundary. A blend position between 0.0 and 1.0 indicates a line, parallel to the boundary lines, that is a certain fraction of the distance from the starting boundary to the ending boundary. For example, a blend position of 0.7 indicates the line that is 70 percent of the distance from the starting boundary to the ending boundary. The color is constant on lines that are parallel to the boundary lines.

### `count` [in]

Type: **INT**

Integer that specifies the number of blend factors to retrieve. Before calling the **LinearGradientBrush::GetBlend** method of a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object, call the [LinearGradientBrush::GetBlendCount](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getblendcount) method of that same
**LinearGradientBrush** object to determine the current number of blend factors. The number of blend positions retrieved is the same as the number of blend factors retrieved.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object has two parallel boundaries: a starting boundary and an ending boundary. A color is associated with each of these two boundaries. Each boundary is a straight line that passes through a specified point — the starting boundary passes through the starting point; the ending boundary passes through the ending point — and is perpendicular to the direction of the linear gradient brush. The direction of the linear gradient brush follows the line that is defined by the starting and ending points. This line, the "directional line," may be horizontal, vertical, or diagonal. All points that lie on a line that is parallel to the boundaries are the same color. When you fill an area with a linear gradient brush, the color changes gradually from one line to the next as you move along the directional line from the starting boundary to the ending boundary. By default, the change in color is proportional to the change in distance; that is, a line 30 percent of the distance between the starting boundary and the ending boundary has a color that is 30 percent of the distance between the starting boundary color and the ending boundary color. The color pattern is repeated outside of the starting and ending boundaries.

You can call the [LinearGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setblend) method of a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object to customize the relationship between color and distance. For example, suppose you set the blend positions to {0, 0.5, 1} and you set the blend factors to {0, 0.3, 1}. Then a line 50 percent of the distance between the starting boundary and the ending boundary will have a color that is 30 percent of the distance between the starting boundary color and the ending boundary color.

#### Examples

The following example creates a linear gradient brush, sets its blend, and uses the brush to fill a rectangle. The code then gets the blend. The blend factors and positions can then be inspected or used in some way.

```cpp
VOID Example_GetBlend(HDC hdc)
{
   Graphics myGraphics(hdc);

   // Create a linear gradient brush, and set its blend.
   REAL fac[] = {0.0f, 0.4f, 0.6f, 1.0f};
   REAL pos[] = {0.0f, 0.2f, 0.8f, 1.0f};

   LinearGradientBrush linGrBrush(
      Point(0, 0),
      Point(100, 0),
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255));  // blue

   linGrBrush.SetBlend(fac, pos, 4);

   // Use the linear gradient brush to fill a rectangle.
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 100, 50);

   // Obtain information about the linear gradient brush.
   INT   blendCount;
   REAL* factors = NULL;
   REAL* positions = NULL;

   blendCount = linGrBrush.GetBlendCount();
   factors = new REAL[blendCount];
   positions = new REAL[blendCount];

   linGrBrush.GetBlend(factors, positions, blendCount);

   for(INT j = 0; j < blendCount; ++j)
   {
      // Inspect or use the value in factors[j].
      // Inspect or use the value in positions[j].
   }
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetBlendCount](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getblendcount)

[LinearGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setblend)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)