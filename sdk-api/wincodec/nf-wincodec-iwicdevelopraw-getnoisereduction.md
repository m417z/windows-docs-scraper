# IWICDevelopRaw::GetNoiseReduction

## Description

Gets the noise reduction value of the raw image.

## Parameters

### `pNoiseReduction` [out]

Type: **double***

A pointer that receives the noise reduction value of the raw image. The default value is the "as-shot" setting if it exists or 0.0. The value range for noise reduction is 0.0 through 1.0. The 0.0 lower limit represents no noise reduction applied to the image, while the 1.0 upper limit represents full highest noise reduction amount that can be applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.