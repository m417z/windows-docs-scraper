# IWICDevelopRaw::SetContrast

## Description

Sets the contrast value of the raw image.

## Parameters

### `Contrast` [in]

Type: **double**

The contrast value of the raw image. The default value is the "as-shot" setting. The value range for contrast is 0.0 through 1.0. The 0.0 lower limit represents no contrast applied to the image, while the 1.0 upper limit represents the highest amount of contrast that can be applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The codec implementer must determine what the upper range value represents and must determine how to map the value to their image processing routines.