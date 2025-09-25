# IWICBitmap::SetResolution

## Description

Changes the physical resolution of the image.

## Parameters

### `dpiX` [in]

Type: **double**

The horizontal resolution.

### `dpiY` [in]

Type: **double**

The vertical resolution.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method has no effect on the actual pixels or samples stored in the bitmap.
Instead the interpretation of the sampling rate is modified.
This means that a 96 DPI image which is 96 pixels wide is one inch.
If the physical resolution is modified to 48 DPI, then the bitmap is considered to be 2 inches wide but has the same number of pixels.
If the resolution is less than **REAL_EPSILON** (1.192092896e-07F) the error code **WINCODEC_ERR_INVALIDPARAMETER** is returned.