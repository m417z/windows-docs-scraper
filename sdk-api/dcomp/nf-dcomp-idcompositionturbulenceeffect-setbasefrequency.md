# IDCompositionTurbulenceEffect::SetBaseFrequency

## Description

Sets the base frequencies in the X and Y direction.

## Parameters

### `frequency` [in, ref]

Type: **const [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f)**

The base frequencies in the X and Y direction. This must be greater than 0. The units are specified in 1/DIPs.
A value of 1 (1/DIPs) for the base frequency results in the Perlin noise completing an entire cycle between two pixels. The ease interpolation for these pixels results in completely random pixels,
since there is no correlation between the pixels.
A value of 0.1(1/DIPs) for the base frequency results in the Perlin noise function repeating every 10 DIPs. This results in correlation between pixels and the typical turbulence effect is visible.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionTurbulenceEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionturbulenceeffect)