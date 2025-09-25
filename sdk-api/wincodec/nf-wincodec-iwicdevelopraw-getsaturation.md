# IWICDevelopRaw::GetSaturation

## Description

Gets the saturation value of the raw image.

## Parameters

### `pSaturation` [out]

Type: **double***

A pointer that receives the saturation value of the raw image. The default value is the "as-shot" setting. The value range for saturation is 0.0 through 1.0. A value of 0.0 represents an image with a fully de-saturated image, while a value of 1.0 represents the highest amount of saturation that can be applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.