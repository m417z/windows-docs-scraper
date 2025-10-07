# asuint function

Reinterprets the bit pattern of a 64-bit value as two unsigned 32-bit integers.

## Parameters

*value* \[in\]

Type: **double**

The input value.

*lowbits* \[out\]

Type: **uint**

The low 32-bit pattern of *value*.

*highbits* \[out\]

Type: **uint**

The high 32-bit pattern of *value*.

## Return value

This function does not return a value.

## Remarks

This function is an alternate version of the [**asuint**](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-asuint) intrinsic that has been available in earlier shader models, and was introduced for Shader Model 5. The original function (recognized in the HLSL compiler by its different signature) remains available to Shader Model 5.

### Minimum Shader Model

This function is supported in the following shader models.

| Shader Model | Supported |
|-----------------------------------------------------------------------------|-----------|
| [Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5) and higher shader models | yes |

This function is supported in the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| x | x | x | x | x | x |

## See also

[Intrinsic Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)

[**asuint (DirectX HLSL)**](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-asuint)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

