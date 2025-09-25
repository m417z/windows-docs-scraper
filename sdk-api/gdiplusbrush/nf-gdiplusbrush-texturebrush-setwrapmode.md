# TextureBrush::SetWrapMode

## Description

The **TextureBrush::SetWrapMode** method sets the wrap mode of this texture brush.

## Parameters

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Element of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how repeated copies of an image are used to tile an area when it is painted with this texture brush.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An area that extends beyond the boundaries of the brush is tiled with repeated copies of the brush. A texture brush may have alternate tiles flipped in a certain direction, as specified by the wrap mode. Flipping has the effect of reversing the brush's image. For example, if the wrap mode is specified as [WrapModeTileFlipX](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), the brush is flipped about a line that is parallel to the y-axis.

The texture brush is always oriented at (0, 0). If the wrap mode is specified as [WrapModeClamp](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), no area outside of the brush is tiled. For example, suppose you create a texture brush, specifying [WrapModeClamp](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) as the wrap mode:

`TextureBrush(&SomeImage, WrapModeClamp)`

Then you paint an area with the brush. If the size of the brush has a height of 50 and the painted area is a rectangle with its upper-left corner at (0, 50), you will see no repeated copies of the brush (no tiling).

The default wrap mode for a texture brush is [WrapModeTile](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which specifies no flipping of the tile and no clamping.

#### Examples

The following example creates a texture brush, sets the wrap mode of the brush, and uses the brush to fill a rectangle.

```cpp
VOID Example_SetWrapMode(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"HouseAndTree.gif");
   TextureBrush textureBrush(&image);
   textureBrush.SetWrapMode(WrapModeTileFlipX);
   graphics.FillRectangle(&textureBrush, 0, 0, 400, 200);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling a Shape with an Image Texture](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-an-image-texture-use)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[TextureBrush::GetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-getwrapmode)

[Tiling a Shape with an Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-tiling-a-shape-with-an-image-use)

[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)