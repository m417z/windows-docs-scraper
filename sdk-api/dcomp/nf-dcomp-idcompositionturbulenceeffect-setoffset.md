# IDCompositionTurbulenceEffect::SetOffset

## Description

Sets the coordinates where the turbulence output is generated.

## Parameters

### `offset` [in, ref]

Type: **const [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f)**

The coordinates where the turbulence output is generated.
The algorithm used to generate the Perlin noise is position dependent, so a different offset results in a different output. This value is not bounded and the units are specified in DIPs

**Note** Note The offset does not have the same effect as a translation because the noise function output is infinite and the function will wrap around the tile.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionTurbulenceEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionturbulenceeffect)