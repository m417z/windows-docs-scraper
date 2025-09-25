# IDCompositionSaturationEffect::SetSaturation(float)

## Description

Sets the saturation of the image.

## Parameters

### `ratio` [in]

Type: **float**

The saturation of the image. You can set the saturation to a value between 0 and 1. If you set it to 1 the output image is fully saturated. If you set it to 0 the output image is monochrome. The saturation value is unitless. The effect calculates a color matrix based on the saturation value (s in the equation here) using the following equation:
![Matrix equation](https://learn.microsoft.com/windows/win32/api/dcomp/images/saturation_formula.png)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionSaturationEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsaturationeffect)