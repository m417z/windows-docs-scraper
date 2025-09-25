# MFGetStrideForBitmapInfoHeader function

## Description

Calculates the minimum surface stride for a video format.

## Parameters

### `format` [in]

FOURCC code or **D3DFORMAT** value that specifies the video format. If you have a video subtype GUID, you can use the first **DWORD** of the subtype.

### `dwWidth` [in]

Width of the image, in pixels.

### `pStride` [out]

Receives the minimum surface stride, in pixels.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function calculates the minimum stride needed to hold the image in memory. Use this function if you are allocating buffers in system memory. Surfaces allocated in video memory might require a larger stride, depending on the graphics card.

If you are working with a DirectX surface buffer, use the [IMF2DBuffer::Lock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-lock2d) method to find the surface stride.

For planar YUV formats, this function returns the stride for the Y plane. Depending on the format, the chroma planes might have a different stride.

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)