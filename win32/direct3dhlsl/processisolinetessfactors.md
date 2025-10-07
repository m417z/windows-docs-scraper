# ProcessIsolineTessFactors function

Generates the rounded tessellation factors for an isoline.

## Parameters

*RawDetailFactor* \[in\]

Type: **float**

The desired detail factor.

*RawDensityFactor* \[in\]

Type: **float**

The desired density factor.

*RoundedDetailFactor* \[out\]

Type: **float**

The rounded detail factor clamped to a range that can be used by the tessellator.

*RoundedDensityFactor* \[out\]

Type: **float**

The rounded density factor clamped to a range that can be used by the tessellator.

## Return value

This function does not return a value.

## Remarks

### Minimum Shader Model

This function is supported in the following shader models.

| Shader Model | Supported |
|-----------------------------------------------------------------------------|-----------|
| [Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5) and higher shader models | yes |

This function is supported in the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| | x | | | | |

## See also

[Intrinsic Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

