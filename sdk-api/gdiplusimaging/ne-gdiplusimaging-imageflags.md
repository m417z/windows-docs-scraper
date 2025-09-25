# ImageFlags enumeration

## Description

The **ImageFlags** enumeration specifies the attributes of the pixel data contained in an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object. The
[Image::GetFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getflags) method returns an element of this enumeration.

## Constants

### `ImageFlagsNone:0`

Specifies no format information.

### `ImageFlagsScalable:0x0001`

Specifies that the image can be scaled.

### `ImageFlagsHasAlpha:0x0002`

Specifies that the pixel data contains alpha values.

### `ImageFlagsHasTranslucent:0x0004`

Specifies that the pixel data has alpha values other than 0 (transparent) and 255 (opaque).

### `ImageFlagsPartiallyScalable:0x0008`

Specifies that the pixel data is partially scalable with some limitations.

### `ImageFlagsColorSpaceRGB:0x0010`

Specifies that the image is stored using an RGB color space.

### `ImageFlagsColorSpaceCMYK:0x0020`

Specifies that the image is stored using a CMYK color space.

### `ImageFlagsColorSpaceGRAY:0x0040`

Specifies that the image is a grayscale image.

### `ImageFlagsColorSpaceYCBCR:0x0080`

Specifies that the image is stored using a YCBCR color space.

### `ImageFlagsColorSpaceYCCK:0x0100`

Specifies that the image is stored using a YCCK color space.

### `ImageFlagsHasRealDPI:0x1000`

Specifies that dots per inch information is stored in the image.

### `ImageFlagsHasRealPixelSize:0x2000`

Specifies that the pixel size is stored in the image.

### `ImageFlagsReadOnly:0x00010000`

Specifies that the pixel data is read-only.

### `ImageFlagsCaching:0x00020000`

Specifies that the pixel data can be cached for faster access.

## See also

[Image::GetFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getflags)