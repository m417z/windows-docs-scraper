# PathGradientBrush::SetWrapMode

## Description

The **PathGradientBrush::SetWrapMode** method sets the wrap mode of this path gradient brush.

## Parameters

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Element of the
[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how areas painted with the path gradient brush will be tiled. The default value is [WrapModeClamp](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The bounding rectangle of a path gradient brush is the smallest rectangle that encloses the brush's boundary path. When you paint the bounding rectangle with the path gradient brush, only the area inside the boundary path gets filled. The area inside the bounding rectangle but outside the boundary path does not get filled.

[WrapModeClamp](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) (the default wrap mode) indicates that no painting occurs outside of the brush's bounding rectangle. All of the other wrap modes indicate that areas outside the brush's bounding rectangle will be tiled. Each tile is a copy (possibly flipped) of the filled path inside its bounding rectangle.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The code calls the **PathGradientBrush::SetWrapMode** method of the
**PathGradientBrush** object to set the brush's wrap mode to [WrapModeTileFlipX](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode). The
[Graphics::FillRectangle](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_)) method uses the path gradient brush to tile a large area.

The output of the code is a grid of tiles. As you move from one tile to the next in a given row, the image (filled boundary path inside the bounding rectangle) is flipped horizontally.

```cpp
VOID Example_SetWrapMode(HDC hdc)
{
   Graphics graphics(hdc);

   Point points[] = {
      Point(0, 0),
      Point(100, 0),
      Point(100, 100)};

   Color colors[] = {
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255),   // blue
      Color(255, 0, 255, 0)};  // green

   INT count = 3;

   PathGradientBrush pthGrBrush(points, 3);
   pthGrBrush.SetSurroundColors(colors, &count);
   pthGrBrush.SetWrapMode(WrapModeTileFlipX);

   graphics.FillRectangle(&pthGrBrush, 0, 0, 800, 800);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-getwrapmode)

[PathGradientBrush::SetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setwrapmode)