# D2DSampleInputAtPosition function

Samples input N at an absolute scene position, rather than an input-relative position. Only available for complex inputs.

## Parameters

*N* \[in\]

The input number.

*uv* \[in\]

The uv position.

## Return value

The function returns a **float4**, in the format TEXCOORDN.

## Remarks

The following example shows the function used in a circular wrap.

``` syntax

D2D_PS_ENTRY(CircularWrapPS)
{
    // TODO: perform math to calculate a circular wrap

    // Find the input scene position.
    float2 inputScenePosition = float2( TODO: add math parameters );

    return D2DSampleInputAtPosition(0, inputScenePosition);
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

