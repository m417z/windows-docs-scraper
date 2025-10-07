# firstbitlow function

Returns the location of the first set bit starting from the lowest order bit and working upward, per component. This intrinsic corresponds to the DXBC instruction [firstbit_lo](https://microsoft.github.io/DirectX-Specs/d3d/archive/D3D11_3_FunctionalSpec.htm#22.11.5%20firstbit).

## Parameters

*value* \[in\]

Type: **[**int**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The input value.

## Return value

Type: **[**int**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The location of the first set bit.

The location is a zero-based count (or index), starting from the least significant bit (LSB). So you can use `1U << firstbitlow(value)` to recreate the corresponding bit found. When no bit is set in the input, the return value is 0xFFFFFFFF (all bits set). Endian-ness isn't relevant here; only bit significance in the integer (not in the memory layout).

## Remarks

The following overloaded versions are also available:

``` syntax
uint2 firstbitlow(uint2 value);
uint3 firstbitlow(uint3 value);
uint4 firstbitlow(uint4 value);
```

### Minimum shader model

This function is supported in the following shader models.

| Shader model | Supported |
|----------------------------------------------------------------------------|-----------|
| [Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5) and higher shader models | yes |

This function is supported in the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| x | x | x | x | x | x |

## See also

* [Intrinsic functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)
* [Shader model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)