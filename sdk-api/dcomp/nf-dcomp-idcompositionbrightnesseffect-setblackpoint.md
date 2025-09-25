# IDCompositionBrightnessEffect::SetBlackPoint

## Description

Specifies the lower portion of the brightness transfer curve for the brightness effect.

## Parameters

### `blackPoint` [in, ref]

Type: **const [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f)**

The lower portion of the brightness transfer curve. The black point adjusts the appearance of the darker portions of the image. The vector is for both the x value and the y value, in that order. Each of the values must be between 0 and 1, inclusive.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionBrightnessEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionbrightnesseffect)