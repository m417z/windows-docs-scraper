# IWICDevelopRaw::SetTint

## Description

Sets the tint value of the raw image.

## Parameters

### `Tint` [in]

Type: **double**

The tint value of the raw image. The default value is the "as-shot" setting if it exists or 0.0. The value range for sharpness is -1.0 through +1.0. The -1.0 lower limit represents a full green bias to the image, while the 1.0 upper limit represents a full magenta bias.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The codec implementer must determine what the outer range values represent and must determine how to map the values to their image processing routines.