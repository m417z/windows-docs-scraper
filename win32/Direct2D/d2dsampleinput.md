# D2DSampleInput function

Samples input N at position uv. Only available for complex inputs.

## Parameters

*N* \[in\]

The input number.

*uv* \[in\]

The uv position.

## Return value

The function returns a **float4**, in the format TEXCOORDN.

## Remarks

The following example shows the function being used to calculate surface normals.

``` syntax

float3 CalculateSurfaceNormal(TAPARGS)
{
    float3 normal = float3(0, 0, 1.0);

    // unrolled loop
    normal.xy += tap1.zw * D2DSampleInput(0, tap1.xy).a;
    normal.xy += tap2.zw * D2DSampleInput(0, tap2.xy).a;
    normal.xy += tap3.zw * D2DSampleInput(0, tap3.xy).a;
    normal.xy += tap4.zw * D2DSampleInput(0, tap4.xy).a;
    normal.xy += tap5.zw * D2DSampleInput(0, tap5.xy).a;
    normal.xy += tap6.zw * D2DSampleInput(0, tap6.xy).a;

    normal = normalize(normal);

    return normal;
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

