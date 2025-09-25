# D3D_TESSELLATOR_PARTITIONING enumeration

## Description

Partitioning options.

## Constants

### `D3D_TESSELLATOR_PARTITIONING_UNDEFINED:0`

### `D3D_TESSELLATOR_PARTITIONING_INTEGER:1`

### `D3D_TESSELLATOR_PARTITIONING_POW2:2`

### `D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD:3`

### `D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN:4`

### `D3D11_TESSELLATOR_PARTITIONING_UNDEFINED`

The partitioning type is undefined.

### `D3D11_TESSELLATOR_PARTITIONING_INTEGER`

Partition with integers only.

### `D3D11_TESSELLATOR_PARTITIONING_POW2`

Partition with a power-of-two number only.

### `D3D11_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD`

Partition with an odd, fractional number.

### `D3D11_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN`

Partition with an even, fractional number.

## Remarks

During tessellation, the partition option helps to determine how the algorithm chooses the next partition value; this enumeration is used by [D3D11_SHADER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_desc).

The **D3D11_TESSELLATOR_PARTITIONING** enumeration is type defined in the D3D11Shader.h header file as a [D3D_TESSELLATOR_PARTITIONING](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_partitioning) enumeration, which is fully defined in the D3DCommon.h header file.

```

typedef D3D_TESSELLATOR_PARTITIONING D3D11_TESSELLATOR_PARTITIONING;
```

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)