# MAGIMAGEHEADER structure

## Description

**Note** The **MAGIMAGEHEADER** structure is deprecated in Windows 7 and later, and should not be used in new applications. There is no alternate functionality.

Describes an image format.

## Members

### `width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of the image.

### `height`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height of the image.

### `format`

Type: **WICPixelFormatGUID**

A WICPixelFormatGUID (declared in wincodec.h) that specifies the pixel format of the image. For a list of available pixel formats, see the [Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats) topic.

### `stride`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The stride, or number of bytes in a row of the image.

### `offset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset of the start of the image data from the beginning of the file.

### `cbSize`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the data.

## See also

[MagImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nc-magnification-magimagescalingcallback)