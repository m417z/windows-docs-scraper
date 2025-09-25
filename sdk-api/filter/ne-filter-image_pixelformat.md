## Description

Specifies the pixel format of an image. This enumeration is used with the [IMAGE_INFO](https://learn.microsoft.com/windows/win32/api/filter/ns-filter-image_info) structure.

## Constants

### `FILTER_PIXELFORMAT_BGRA8`

The image format is 32 bits per pixel. This value corresponds to the Windows Imaging Component (WIC) friendly name **GUID_WICPixelFormat32bppBGRA**.

### `FILTER_PIXELFORMAT_PBGRA8`

The image format is 32 bits per pixel. This value corresponds to the WIC friendly name **GUID_WICPixelFormat32bppPBGRA**.

### `FILTER_PIXELFORMAT_BGR8`

The image format is 24 bits per pixel. This value corresponds to the WIC friendly name **GUID_WICPixelFormat24bppBGR**.

## Remarks

Specifying the bits per pixel (bpp) of an image allows a search indexer to allocate a buffer of the correct size to process the image. For more information on WIC pixel formats, see [Native pixel formats overview](https://learn.microsoft.com/windows/win32/wic/-wic-codec-native-pixel-formats).

## See also

[IMAGE_INFO](https://learn.microsoft.com/windows/win32/api/filter/ns-filter-image_info)

[Native pixel formats overview](https://learn.microsoft.com/windows/win32/wic/-wic-codec-native-pixel-formats)