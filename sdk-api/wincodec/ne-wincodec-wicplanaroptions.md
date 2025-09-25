# WICPlanarOptions enumeration

## Description

Specifies additional options to an [IWICPlanarBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicplanarbitmapsourcetransform) implementation.

## Constants

### `WICPlanarOptionsDefault:0`

No options specified.

WIC JPEG Decoder: The default behavior for iDCT scaling is to preserve quality when downscaling by downscaling only the Y plane in some cases, and the image may change to 4:4:4 chroma subsampling.

### `WICPlanarOptionsPreserveSubsampling:0x1`

Asks the source to preserve the size ratio between planes when scaling.

WIC JPEG Decoder: Specifying this option causes the JPEG decoder to scale luma and chroma planes by the same amount, so a 4:2:0 chroma subsampled image outputs 4:2:0 data when downscaling by 2x, 4x, or 8x.

### `WICPLANAROPTIONS_FORCE_DWORD:0x7fffffff`

## See also

[IWICPlanarBitmapSourceTransform::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-copypixels)

[IWICPlanarBitmapSourceTransform::DoesSupportTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-doessupporttransform)