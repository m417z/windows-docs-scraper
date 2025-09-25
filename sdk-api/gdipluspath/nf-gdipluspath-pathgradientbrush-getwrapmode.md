# PathGradientBrush::GetWrapMode

## Description

The **PathGradientBrush::GetWrapMode** method gets the wrap mode currently set for this path gradient brush.

## Return value

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

This method returns an element of the
[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that indicates the wrap mode currently set for this path gradient brush.

## Remarks

The bounding rectangle of a path gradient brush is the smallest rectangle that encloses the brush's boundary path. When you paint the bounding rectangle with the path gradient brush, only the area inside the boundary path gets filled. The area inside the bounding rectangle but outside the boundary path does not get filled.

The default wrap mode for a path gradient brush is WrapModeClamp, which indicates that no painting occurs outside of the brush's bounding rectangle. All of the other wrap modes indicate that areas outside the brush's bounding rectangle will be tiled. Each tile is a copy (possibly flipped) of the filled path inside its bounding rectangle.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The code calls the [PathGradientBrush::SetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setwrapmode) method of the
**PathGradientBrush** object to set the wrap mode to [WrapModeTileFlipX](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode). Next, the code calls the **PathGradientBrush::GetWrapMode** method of the
**PathGradientBrush** object to obtain the brush's wrap mode. If the obtained wrap mode is WrapModeTileFlipX, the code calls
[FillRectangle](https://learn.microsoft.com/previous-versions/ms535957(v=vs.85)) to tile a large area with the path gradient brush.

```cpp
VOID Example_GetWrapMode(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path gradient brush based on an array of points,
   // and set its wrap mode.
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

   // Obtain information about the path gradient brush.
   WrapMode wrapMode;
   wrapMode = pthGrBrush.GetWrapMode();

   if(wrapMode == WrapModeTileFlipX)
         graphics.FillRectangle(&pthGrBrush, 0, 0, 800, 800);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::SetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-setwrapmode)

[Tiling a Shape with an Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-tiling-a-shape-with-an-image-use)