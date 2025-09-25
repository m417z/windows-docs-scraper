# PathGradientBrush::GetSurroundColors

## Description

The **PathGradientBrush::GetSurroundColors** method gets the surround colors currently specified for this path gradient brush.

## Parameters

### `colors` [in]

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to an array that receives the surround colors.

### `count` [in, out]

Type: **INT***

Pointer to an integer that, on input, specifies the number of colors requested. If the method succeeds, this parameter, on output, receives the number of colors retrieved. If the method fails, this parameter does not receive a value.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A path gradient brush has a boundary path and a center point. The center point is set to a single color, but you can specify different colors for several points on the boundary. For example, suppose you specify red for the center color, and you specify blue, green, and yellow for distinct points on the boundary. Then as you move along the boundary, the color will change gradually from blue to green to yellow and back to blue. As you move along a straight line from any point on the boundary to the center point, the color will change from that boundary point's color to red.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path that is defined by an array of three points. The code calls the [PathGradientBrush::SetSurroundColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setsurroundcolors) method of the
**PathGradientBrush** object to specify a color for each of the points that define the triangle. The [PathGradientBrush::GetSurroundColorCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getsurroundcolorcount) method determines the current number of surround colors (the colors specified for the brush's boundary path). Next, the code allocates a buffer large enough to receive the array of surround colors and calls **PathGradientBrush::GetSurroundColors** to fill that buffer. Finally the code fills a small square with each of the brush's surround colors.

```cpp
VOID Example_GetSurColors(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path gradient brush and set its surround colors.
   Point pts[] = {
      Point(20, 20),
      Point(100, 20),
      Point(100, 100)};

   Color cols[] = {
      Color(255, 255, 0, 0),  // red
      Color(255, 0, 255, 0),  // green
      Color(255, 0, 0, 0)};   // black

   INT count = 3;
   PathGradientBrush pthGrBrush(pts, 3);
   pthGrBrush.SetSurroundColors(cols, &count);

   // Obtain information about the path gradient brush.
   INT colorCount = pthGrBrush.GetSurroundColorCount();
   Color* colors = new Color[colorCount];
   pthGrBrush.GetSurroundColors(colors, &colorCount);

   // Fill a small square with each of the surround colors.
   SolidBrush solidBrush(Color(255, 255, 255, 255));

   for(INT j = 0; j < colorCount; ++j)
   {
      solidBrush.SetColor(colors[j]);
      graphics.FillRectangle(&solidBrush, 15*j, 0, 10, 10);
   }

   delete [] colors;
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetSurroundColorCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getsurroundcolorcount)

[PathGradientBrush::SetSurroundColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setsurroundcolors)