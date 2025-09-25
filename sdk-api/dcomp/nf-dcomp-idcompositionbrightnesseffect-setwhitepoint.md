# IDCompositionBrightnessEffect::SetWhitePoint

## Description

Sets the upper portion of the brightness transfer curve.

## Parameters

### `whitePoint` [in, ref]

Type: **const [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f)**

The upper portion of the brightness transfer curve. The white point adjusts the appearance of the brighter portions of the image.
This vector is for both the x value and the y value, in that order. Each of the values must be between 0 and 1, inclusive.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionBrightnessEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionbrightnesseffect)