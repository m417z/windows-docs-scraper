# IWICPlanarBitmapSourceTransform::DoesSupportTransform

## Description

Use this method to determine if a desired planar output is supported and allow the caller to choose an optimized code path if it is. Otherwise, callers should fall back to [IWICBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsourcetransform) or [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) and retrieve interleaved pixels.

The following transforms can be checked:

* Determine if the flip/rotate option specified via [WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions) is supported.
* Determine if the requested planar pixel format configuration is supported.
* Determine the closest dimensions the implementation can natively scale to given the desired dimensions.

When a transform is supported, this method returns the description of the resulting planes in the *pPlaneDescriptions* parameter.

## Parameters

### `puiWidth` [in, out]

Type: **UINT***

On input, the desired width. On output, the closest supported width to the desired width; this is the same size or larger than the desired width.

### `puiHeight` [in, out]

Type: **UINT***

On input, the desired height. On output, the closest supported height to the desired height; this is the same size or larger than the desired width.

### `dstTransform`

Type: **[WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions)**

The desired rotation or flip operation. Multiple [WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions) can be combined in this flag parameter, see **WICBitmapTransformOptions**.

### `dstPlanarOptions`

Type: **[WICPlanarOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions)**

Used to specify additional configuration options for the transform. See [WICPlanarOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions) for more detail.

WIC JPEG Decoder:

[WICPlanarOptionsPreserveSubsampling](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions) can be specified to retain the subsampling ratios when downscaling. By default, the JPEG decoder attempts to preserve quality by downscaling only the Y plane in some cases, changing the image to 4:4:4 chroma subsampling.

### `pguidDstFormats` [in]

Type: **const WICPixelFormatGUID***

The requested pixel formats of the respective planes.

### `pPlaneDescriptions` [out]

Type: **[WICBitmapPlaneDescription](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicbitmapplanedescription)***

When **pfIsSupported* == TRUE, the array of plane descriptions contains the size and format of each of the planes.

WIC JPEG Decoder: The Cb and Cr planes can be a different size from the values returned by *puiWidth* and *puiHeight* due to chroma subsampling.

### `cPlanes`

Type: **UINT**

The number of component planes requested.

### `pfIsSupported` [out]

Type: **BOOL***

Set to TRUE if the requested transforms are natively supported.

## Return value

Type: **HRESULT**

Check the value of *pfIsSupported* to determine if the transform is supported via [IWICPlanarBitmapSourceTransform::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-copypixels). If this method fails, the output parameters for width, height, and plane descriptions are zero initialized.
Other return values indicate failure.

## See also

[IWICPlanarBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicplanarbitmapsourcetransform)

[IWicPlanarBitmapSourceTransform::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-copypixels)

[WICBitmapPlaneDescription](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicbitmapplanedescription)

[WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions)

[WICPlanarOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions)