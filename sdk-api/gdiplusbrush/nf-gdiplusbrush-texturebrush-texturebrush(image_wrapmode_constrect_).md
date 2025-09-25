# TextureBrush::TextureBrush(IN Image,IN WrapMode,const IN Rect &)

## Description

Creates a [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object based on an image, a wrap mode, and a defining rectangle.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that contains the bitmap of the image to use.

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Element of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how repeated copies of an image are used to tile an area when it is painted with this texture brush.

### `dstRect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that defines the size of this texture brush and the portion of the image to be used by this texture brush. If the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object is created from a metafile, the brush uses the entire image, which is scaled to fit the size of the brush.

## Remarks

The width and height of a texture brush are defined by the width and height of the
*dstRect* rectangle. A texture brush is always oriented at (0, 0). The upper-left point, width, and height of the rectangle specify the starting point, width, and height of the portion of the image to be used by a texture brush.

### How this constructor uses the dstRect rectangle with nonmetafile images

If the dimensions of the
*dstRect* rectangle are smaller than those of the image on which the brush is based, the brush's image is cropped — it is a portion of the image. If the dimensions of the
*dstRect* rectangle are equal to those of the image, the brush's image is identical to the image. The
*dstRect* rectangle must not include areas outside the dimensions of the image. Doing so will either produce unpredictable behavior or generate a run-time error. For example, suppose you have an image that is 256
×256 pixels and you create a [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object based on this image, passing as the
*dstRect* parameter. The brush will use the lower left portion of the image. The lower-left corner of this portion is also the lower-left corner of the image. Now suppose that you create another **TextureBrush** object based on the same image, passing as the
*dstRect* parameter. Note that this rectangle has its uppermost coordinate at 157 instead of 156. This rectangle extends one unit beyond the height of the image and will most likely generate an access violation.

### How this constructor uses the dstRect rectangle with metafile images

If the dimensions of the
*dstRect* rectangle are different from those of the image, the brush's image is scaled smaller or larger as needed to fit the rectangle. For example, suppose you have a metafile image that is 256
×256 pixels and you create a [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object, passing as the
*dstRect* parameter. The brush's image will include all of the metafile image but will be scaled to fit the brush: It will be squished vertically and stretched horizontally. If the dimensions of the rectangle are equal to those of the image, the brush's image is identical to the image.

### How this constructor uses the wrap mode

An area that extends beyond the boundaries of the brush is tiled with repeated copies of the brush. A texture brush may have alternate tiles flipped in a certain direction, as specified by the wrap mode. Flipping has the effect of reversing the brush's image.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[TextureBrush::GetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-getwrapmode)

[TextureBrush::SetWrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-setwrapmode)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)

[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)