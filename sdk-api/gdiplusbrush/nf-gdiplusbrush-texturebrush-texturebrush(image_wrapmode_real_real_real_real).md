# TextureBrush::TextureBrush(IN Image,IN WrapMode,IN REAL,IN REAL,IN REAL,IN REAL)

## Description

Creates a [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object based on an image, a wrap mode, and a defining set of coordinates.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that contains the bitmap of the image to use.

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Element of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how repeated copies of an image are used to tile an area when it is painted with this texture brush.

### `dstX` [in]

Type: **REAL**

Leftmost coordinate of the image portion to be used by this brush.

### `dstY` [in]

Type: **REAL**

Uppermost coordinate of the image portion to be used by this brush.

### `dstWidth` [in]

Type: **REAL**

Width of the brush and width of the image portion to be used by the brush.

### `dstHeight` [in]

Type: **REAL**

Height of the brush and height of the image portion to be used by the brush.

## Remarks

The
*dstX*,
*dstY*,
*dstWidth*, and
*dstHeight* parameters specify a rectangle. The size of the brush is defined by
*dstWidth* and
*dstHeight*. The
*dstX* and
*dstY* parameters have no effect on the brush's size or position — the brush is always oriented at (0, 0). The
*dstX*,
*dstY*,
*dstWidth*, and
*dstHeight* parameters define the portion of the image to be used by the brush.

For example, suppose you have an image that is stored in an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and is 256
×512 (width
×height) pixels. Then you create a [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object based on this image as follows:

`TextureBrush(&someImage, WrapModeTile, 12, 50, 100, 150)`

The brush will have a width of 100 units and a height of 150 units. The brush will use a rectangular portion of the image. This portion begins at the pixel having coordinates (12, 50). The width and height of the portion are 100 and 150, respectively, measured from the starting pixel.

Now suppose you create another [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object based on the same image and specify a different rectangle:

`TextureBrush(&someImage, WrapModeTile, 0, 0, 256, 512)`

The brush will have width and height equal to 256 and 512, respectively. The brush will use the entire image instead of a portion of it because the rectangle specifies a starting pixel at coordinates (0, 0) and dimensions identical to those of the image.