# D3D_TESSELLATOR_DOMAIN enumeration

## Description

Domain options for tessellator data.

## Constants

### `D3D_TESSELLATOR_DOMAIN_UNDEFINED:0`

### `D3D_TESSELLATOR_DOMAIN_ISOLINE:1`

### `D3D_TESSELLATOR_DOMAIN_TRI:2`

### `D3D_TESSELLATOR_DOMAIN_QUAD:3`

### `D3D11_TESSELLATOR_DOMAIN_UNDEFINED`

The data type is undefined.

### `D3D11_TESSELLATOR_DOMAIN_ISOLINE`

Isoline data.

### `D3D11_TESSELLATOR_DOMAIN_TRI`

Triangle data.

### `D3D11_TESSELLATOR_DOMAIN_QUAD`

Quad data.

## Remarks

The data domain defines the type of data. This enumeration is used by [D3D11_SHADER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_desc).

The **D3D11_TESSELLATOR_DOMAIN** enumeration is type defined in the D3D11Shader.h header file as a [D3D_TESSELLATOR_DOMAIN](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_domain) enumeration, which is fully defined in the D3DCommon.h header file.

```

typedef D3D_TESSELLATOR_DOMAIN D3D11_TESSELLATOR_DOMAIN;
```

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)