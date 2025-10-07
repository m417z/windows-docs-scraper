# D2DGetInputCoordinate function

Returns the value of the input TEXCOORDN. Available only for complex inputs.

## Parameters

*N* \[in\]

The input number.

## Return value

The function returns a **float4**, in the format TEXCOORDN.

## Remarks

The coordinate returned by this function is in texel space. A shader shouldn't take any dependencies on how this value is calculated. It should use it only to sample the pixel shader's input. For more info, see [Adding a pixel shader to a custom transform](https://learn.microsoft.com/windows/win32/direct2d/custom-effects#adding-a-pixel-shader-to-a-custom-transform).

The following example shows the function used for a displacement map effect.

``` syntax
float2 GetDisplacementOffset(float4 uv0, float4 uv1)
{
    // TODO: return the displacement offset
}

D2D_PS_ENTRY(DisplacementMapBilinear)
{
    const float4 coord0 = D2DGetInputCoordinate(0);
    const float4 coord1 = D2DGetInputCoordinate(1);
    return D2DSampleInput(0, GetDisplacementOffset(coord0, coord1) * coord0.zw + coord0.xy);
}
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------|
| Header<br> | D2d1effecthelpers.hlsli |
| DLL<br> | D2d1.dll |

## See also

[Effect Shader Linking](https://learn.microsoft.com/windows/win32/direct2d/effect-shader-linking)

[HLSL Helpers](https://learn.microsoft.com/windows/win32/direct2d/hlsl-helpers)

