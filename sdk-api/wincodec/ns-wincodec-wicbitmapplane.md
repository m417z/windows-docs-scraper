# WICBitmapPlane structure

## Description

Specifies the pixel format, buffer, stride and size of a component plane for a planar pixel format.

## Members

### `Format`

Type: **WICPixelFormatGUID**

Describes the pixel format of the plane.

### `pbBuffer`

Type: **BYTE***

Pointer to the buffer that holds the plane’s pixel components.

### `cbStride`

Type: **UINT**

The stride of the buffer pointed to by *pbData*. Stride indicates the total number of bytes to go from the beginning of one scanline to the beginning of the next scanline.

### `cbBufferSize`

Type: **UINT**

The total size of the buffer pointed to by *pbBuffer*.

## See also

[IWICPlanarBitmapSourceTransform::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-copypixels)

[IWICPlanarBitmapSourceTransform::DoesSupportTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-doessupporttransform)