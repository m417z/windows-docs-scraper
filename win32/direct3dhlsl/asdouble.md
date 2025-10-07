# asdouble function

Reinterprets a cast value (two 32-bit values) into a double.

## Parameters

*lowbits* \[in\]

Type: **uint**

The low 32-bit pattern of the input value.

*highbits* \[in\]

Type: **uint**

The high 32-bit pattern of the input value.

## Return value

Type: **double**

The input (two 32-bit values) recast as a double.

## Remarks

The following overloaded version is also available:

``` syntax
double2 asdouble(uint2 lowbits, uint2 highbits);
```

If the input value is two 32-bit components, the return type will contain one double. If the input value is four 32-bit components, the return type will contain two doubles. If the input value is a 64-bit type, the returned value will have the same number of components as the input value.

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

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

