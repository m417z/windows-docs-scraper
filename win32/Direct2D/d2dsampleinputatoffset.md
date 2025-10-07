# D2DSampleInputAtOffset function

Samples input N at an offset of offset from the input coordinate. Only available for complex inputs.

## Parameters

*N* \[in\]

The input number.

*offset* \[in\]

The uv offset.

## Return value

The function returns a **float4**, in the format TEXCOORDN.

## Remarks

The following example shows the function being used as part of a highlighting and shadows gradient mask.

``` syntax

D2D_PS_ENTRY(HighlightsAndShadowsGradientMask)
{
    MIN_TYPE(float4) blurred = D2DGetInput(0);

    // Compute X and Y gradients
    MIN_TYPE(float) dX1 = D2DSampleInputAtOffset(0, float2(1, 0));
    MIN_TYPE(float) dX2 = D2DSampleInputAtOffset(0, float2(-1, 0));
    MIN_TYPE(float) dY1 = D2DSampleInputAtOffset(0, float2(0, 1));
    MIN_TYPE(float) dY2 = D2DSampleInputAtOffset(0, float2(0, -1));

    // TODO: math to calculate shadow gradients

    // Return the value in the alpha channel.
    blurred.a = // TODO: math to calculate blurred value

    return blurred;
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

