# IWICBitmapSourceTransform::GetClosestSize

## Description

Returns the closest dimensions the implementation can natively scale to given the desired dimensions.

## Parameters

### `puiWidth` [in, out]

Type: **UINT***

The desired width. A pointer that receives the closest supported width.

### `puiHeight` [in, out]

Type: **UINT***

The desired height. A pointer that receives the closest supported height.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Windows provided codecs provide the following support for native scaling:

* BMP, ICO, GIF, TIFF: No implementation of [IWICBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapsourcetransform).
* PNG: No scaling support.
* JPEG: Native down-scaling by a factor of 8, 4, or 2.
* JPEG-XR: Native scaling of the original image by powers of 2.