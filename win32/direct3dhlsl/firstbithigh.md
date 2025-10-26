# firstbithigh function

Gets the location of the first set bit starting from the highest order bit and working downward, per component.

## Parameters

*value* \[in\]

Type: **[**int**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The input value.

## Return value

Type: **[**int**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The location of the first set bit.

## Remarks

For a negative signed integer, firstbithigh returns the position of the first bit set to 0.

If no matching bit is found, 0xFFFFFFFF (-1) is returned.

The following overloaded versions are also available:

``` syntax
int2 firstbithigh(int2 value);
int3 firstbithigh(int3 value);
int4 firstbithigh(int4 value);
uint firstbithigh(uint value);
uint2 firstbithigh(uint2 value);
uint3 firstbithigh(uint3 value);
uint4 firstbithigh(uint4 value);
```

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

