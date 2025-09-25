# MFCreate2DMediaBuffer function

## Description

Creates a system-memory buffer object to hold 2D image data.

## Parameters

### `dwWidth` [in]

Width of the image, in pixels.

### `dwHeight` [in]

Height of the image, in pixels.

### `dwFourCC` [in]

A **FOURCC** code or [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) value that specifies the video format. If you have a video subtype GUID, you can use the first **DWORD** of the subtype.

### `fBottomUp` [in]

If **TRUE,** the buffer's [IMF2DBuffer::ContiguousCopyTo](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-contiguouscopyto) method copies the buffer into a bottom-up format. The bottom-up format is compatible with GDI for uncompressed RGB images. If this parameter is **FALSE**, the **ContiguousCopyTo** method copies the buffer into a top-down format, which is compatible with DirectX.

For more information about top-down versus bottom-up images, see [Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride).

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDMEDIATYPE** | Unrecognized video format. |

## Remarks

The returned buffer object also exposes the [IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2) interface.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)