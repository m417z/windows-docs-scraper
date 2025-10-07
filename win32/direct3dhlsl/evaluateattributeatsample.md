# EvaluateAttributeAtSample function

Evaluates at the indexed sample location.

## Parameters

*value* \[in\]

Type: **attrib numeric**

The input value.

*sampleindex* \[in\]

Type: **uint**

The sample location.

## Remarks

Interpolation mode can be **linear** or **linear\_no\_perspective** on the variable. Use of **centroid** or **sample** is ignored. Attributes with constant interpolation are also allowed, in which case the sample index is ignored.

### Minimum Shader Model

This function is supported in the following shader models.

| Shader Model | Supported |
|-----------------------------------------------------------------------------|-----------|
| [Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5) and higher shader models | yes |

This function is supported in the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| | | | | x | |

## See also

[Intrinsic Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

