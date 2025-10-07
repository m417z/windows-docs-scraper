# ddy\_fine function

Computes a high precision partial derivative with respect to the screen-space y-coordinate.

## Parameters

*value* \[in\]

Type: **float**

The input value.

## Return value

Type: **float**

The high precision partial derivative of *value*.

## Remarks

The following overloaded versions are also available:

``` syntax
float2 ddy_fine(float2 value);
float3 ddy_fine(float3 value);
float4 ddy_fine(float4 value);
```

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

