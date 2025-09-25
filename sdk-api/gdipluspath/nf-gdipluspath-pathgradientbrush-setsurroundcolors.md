# PathGradientBrush::SetSurroundColors

## Description

The **PathGradientBrush::SetSurroundColors** method sets the surround colors of this path gradient brush. The surround colors are colors specified for discrete points on the brush's boundary path.

## Parameters

### `colors` [in]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to an array of [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects that specify the surround colors.

### `count` [in, out]

Type: **INT***

Pointer to an integer that, on input, specifies the number of [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects in the
*colors* array. If the method succeeds, this parameter, on output, receives the number of surround colors set. If the method fails, this parameter does not receive a value.

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
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on an array of three points that defines a triangular path. The code also initializes an array of three [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects. The call to the **PathGradientBrush::SetSurroundColors** method associates each color in the color array with the corresponding (same index) point in the point array. After the surround colors of the path gradient brush have been set, the
[Graphics::FillRectangle](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_)) method uses the path gradient brush to paint a rectangle that includes the triangular path.

One edge of the rendered triangle changes gradually from red to green. The next edge changes gradually from green to black, and the third edge changes gradually from black to red. The code does not set the center color, so the center color has the default value of black. As you move along a straight line from any point on the boundary path (triangle) to the center point, the color changes gradually from that boundary point's color to black.

```cpp
VOID Example_SetSurColor(HDC hdc)
{
   Graphics graphics(hdc);

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

   graphics.FillRectangle(&pthGrBrush, 0, 0, 200, 200);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetSurroundColorCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getsurroundcolorcount)

[PathGradientBrush::GetSurroundColors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getsurroundcolors)