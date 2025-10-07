# ProcessTriTessFactorsMax function

Generates the corrected tessellation factors for a tri patch.

## Parameters

*RawEdgeFactors* \[in\]

Type: **float3**

The edge tessellation factors, passed into the tessellator stage.

*InsideScale* \[in\]

Type: **float**

The scale factor applied to the UV tessellation factors computed by the tessellation stage. The allowable range for InsideScale is 0.0 to 1.0.

*RoundedEdgeTessFactors* \[out\]

Type: **float3**

The rounded edge-tessellation factors calculated by the tessellator stage.

*RoundedInsideTessFactor* \[out\]

Type: **float**

The tessellation factors calculated by the tessellator stage, and rounded.

*UnroundedInsideTessFactor* \[out\]

Type: **float**

The original, unrounded, UV tessellation factors computed by the tessellation stage.

## Return value

This function does not return a value.

## Remarks

Generates the corrected tessellation factors for a tri patch, computing the inside tessellation factor as the maximum of the edge tessellation factors, which is then scaled by InsideScale. The result is then rounded based on the partitioning mode, but the unrounded results are available using the UnroundedInsideTessFactor parameter.

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

