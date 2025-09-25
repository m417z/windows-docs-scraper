# IWICBitmapFrameEncode::WritePixels

## Description

Copies scan-line data from a caller-supplied buffer to the [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode) object.

## Parameters

### `lineCount` [in]

Type: **UINT**

The number of lines to encode.

### `cbStride` [in]

Type: **UINT**

The stride of the image pixels.

### `cbBufferSize` [in]

Type: **UINT**

The size of the pixel buffer.

### `pbPixels` [in]

Type: **BYTE***

A pointer to the pixel buffer.

## Return value

Type: **HRESULT**

Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **WINCODEC_ERR_CODECTOOMANYSCANLINES** | The value of *lineCount* is larger than the number of scan lines in the image. |

## Remarks

Successive **WritePixels** calls are assumed to be sequential scan-line access in the output image.