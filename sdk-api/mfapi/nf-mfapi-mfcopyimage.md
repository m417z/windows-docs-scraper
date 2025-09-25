# MFCopyImage function

## Description

Copies an image or image plane from one buffer to another.

## Parameters

### `pDest` [in]

Pointer to the start of the first row of pixels in the destination buffer.

### `lDestStride` [in]

Stride of the destination buffer, in bytes.

### `pSrc` [in]

Pointer to the start of the first row of pixels in the source image.

### `lSrcStride` [in]

Stride of the source image, in bytes.

### `dwWidthInBytes` [in]

Width of the image, in bytes.

### `dwLines` [in]

Number of rows of pixels to copy.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function copies a single plane of the image. For planar YUV formats, you must call the function once for each plane. In this case, *pDest* and *pSrc* must point to the start of each plane.

This function is optimized if the MMX, SSE, or SSE2 instruction sets are available on the processor. The function performs a non-temporal store (the data is written to memory directly without polluting the cache).

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)