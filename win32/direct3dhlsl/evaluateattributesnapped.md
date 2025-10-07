# EvaluateAttributeSnapped function

Evaluates at the pixel centroid with an offset.

## Parameters

*value* \[in\]

Type: **attrib numeric**

The input value.

*offset* \[in\]

Type: **int2**

A 2D offset from the pixel center using a 16x16 grid.

## Remarks

The range for the *offset* parameter must be defined by the following byte code.

Only the least significant 4 bits of the first two components (U, V) of the pixel offset are used. The conversion from the 4-bit fixed point to float is as follows (MSB...LSB), where the MSB is both a part of the fraction and determines the sign:

- 1000 = -0.5f (-8 / 16)
- 1001 = -0.4375f (-7 / 16)
- 1010 = -0.375f (-6 / 16)
- 1011 = -0.3125f (-5 / 16)
- 1100 = -0.25f (-4 / 16)
- 1101 = -0.1875f (-3 / 16)
- 1110 = -0.125f (-2 / 16)
- 1111 = -0.0625f (-1 / 16)
- 0000 = 0.0f ( 0 / 16)
- 0001 = 0.0625f ( 1 / 16)
- 0010 = 0.125f ( 2 / 16)
- 0011 = 0.1875f ( 3 / 16)
- 0100 = 0.25f ( 4 / 16)
- 0101 = 0.3125f ( 5 / 16)
- 0110 = 0.375f ( 6 / 16)
- 0111 = 0.4375f ( 7 / 16)

> [!Note]
> The left and top edges of a pixel are included in the offset; however, the bottom and right edges are not included. All other bits in the 32-bit integer U and V offset values are ignored.

An implementation can take the offset provided by the shader and obtain a full 32-bit fixed point value (28.4), which spans the valid range, by performing the following calculation:

```
iU = (iU<<28)>>28  // keep lowest 4 bits and sign extend, which yields [-8..7]
```

If an implementation must map the offset to a floating-point offset, it performs the following calculation:

```
fU = ((float)iU)/16
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

