# IWICDevelopRaw::SetNoiseReduction

## Description

Sets the noise reduction value of the raw image.

## Parameters

### `NoiseReduction` [in]

Type: **double**

The noise reduction value of the raw image. The default value is the "as-shot" setting if it exists or 0.0. The value range for noise reduction is 0.0 through 1.0. The 0.0 lower limit represents no noise reduction applied to the image, while the 1.0 upper limit represents highest noise reduction amount that can be applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The codec implementer must determine what the upper range value represents and must determine how to map the value to their image processing routines.