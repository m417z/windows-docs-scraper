# TextureBrush::TextureBrush(IN Image,IN WrapMode)

## Description

Creates a [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object based on an image and a wrap mode. The size of the brush defaults to the size of the image, so the entire image is used by the brush.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that contains the bitmap of the image to use.

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Optional. Element of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how repeated copies of an image are used to tile an area when it is painted with this texture brush. The default value is **WrapModeTile**.

## Remarks

An area that extends beyond the boundaries of the brush is tiled with repeated copies of the brush. A texture brush may have alternate tiles flipped in a certain direction, as specified by the wrap mode. Flipping has the effect of reversing the brush's image. For example, if the wrap mode is specified as **WrapModeTileFlipX**, the brush is flipped about a line that is parallel to the y-axis.

The texture brush is always oriented at (0, 0). If the wrap mode is specified as **WrapModeClamp**, no area outside of the brush is tiled. For example, suppose you create a texture brush, specifying **WrapModeClamp** as the wrap mode:

`TextureBrush(&SomeImage, WrapModeClamp)`

Then, you paint an area with the brush. If the size of the brush has a height of 50 and the painted area is a rectangle with its upper-left corner at (0, 50), you will see no repeated copies of the brush (no tiling).

The default wrap mode for a texture brush is **WrapModeTile**, which specifies no flipping of the tile and no clamping.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[TextureBrush::GetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-getwrapmode)

[TextureBrush::SetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-setwrapmode)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)

[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)