# LinearGradientBrush::SetWrapMode

## Description

The **LinearGradientBrush::SetWrapMode** method sets the wrap mode of this linear gradient brush.

## Parameters

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Element of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how areas painted with this linear gradient brush will be tiled. The value of this parameter must be one of the following elements:

* WrapModeTile
* WrapModeTileFlipX
* WrapModeTileFlipY
* WrapModeTileFlipXY

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The boundary lines of a linear gradient brush form a tile. When you paint an area with a linear gradient brush, the tile repeats. A linear gradient brush may have alternate tiles flipped in a certain direction, as specified by the wrap mode. Flipping has the effect of reversing the order of the colors.

The wrap mode defaults to WrapModeTile when a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object is constructed.

#### Examples

The following example creates a linear gradient brush and uses it to fill a rectangle. Next, the code modifies the brush's wrap mode and uses the modified brush to fill another rectangle.

```cpp
VOID Example_SetWrapMode(HDC hdc)
{
   Graphics myGraphics(hdc);

   LinearGradientBrush linGrBrush(
      Rect(0, 0, 100, 50),
      Color(255, 255, 0, 0),  // red
      Color(255, 0, 0, 255),  // blue
      LinearGradientModeHorizontal);

   // Fill a large area using the gradient brush with the default wrap mode.
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 800, 50);

   linGrBrush.SetWrapMode(WrapModeTileFlipX);

   // Fill a large area using the gradient brush with the new wrap mode.
   myGraphics.FillRectangle(&linGrBrush, 0, 75, 800, 50);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getwrapmode)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Tiling a Shape with an Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-tiling-a-shape-with-an-image-use)

[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)