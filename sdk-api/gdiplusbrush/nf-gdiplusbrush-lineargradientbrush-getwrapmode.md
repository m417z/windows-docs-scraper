# LinearGradientBrush::GetWrapMode

## Description

The **LinearGradientBrush::GetWrapMode** method gets the wrap mode for this brush. The wrap mode determines how an area is tiled when it is painted with a brush.

## Return value

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

This method returns one of the following elements of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration:

* WrapModeTile
* WrapModeTileFlipX
* WrapModeTileFlipY
* WrapModeTileFlipXY

## Remarks

The boundary lines of a linear gradient brush form a tile. When you paint an area with a linear gradient brush, the tile repeats. A linear gradient brush can have alternate tiles flipped in a certain direction, as specified by the wrap mode. Flipping has the effect of reversing the order of the colors.

The default wrap mode for a linear gradient brush is WrapModeTile, which indicates that no flipping occurs.

#### Examples

The following example creates a linear gradient brush and sets its wrap mode. Next, the code gets the brush's wrap mode and performs tasks based on the brush's current wrap mode.

```cpp
VOID Example_GetWrapMode(HDC hdc)
{
   Graphics myGraphics(hdc);

   // Create a linear gradient brush, and set its wrap mode.
   LinearGradientBrush linGrBrush(
      Point(0,0),
      Point(200, 0),
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255));  // blue

   linGrBrush.SetWrapMode(WrapModeTileFlipX);

   // Obtain information about the linear gradient brush.
   WrapMode wrapMode;
   wrapMode = linGrBrush.GetWrapMode();

   if (wrapMode == WrapModeTileFlipX)
   {
       // Do some task.
   }
   else if (wrapMode == WrapModeTileFlipY)
   {
       // Do a different task.
   }
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::SetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setwrapmode)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Tiling a Shape with an Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-tiling-a-shape-with-an-image-use)

[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)