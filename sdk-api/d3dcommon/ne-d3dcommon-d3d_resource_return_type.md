# D3D_RESOURCE_RETURN_TYPE enumeration

## Description

Indicates return value type.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_RETURN_TYPE_UNORM:1`

### `D3D_RETURN_TYPE_SNORM:2`

### `D3D_RETURN_TYPE_SINT:3`

### `D3D_RETURN_TYPE_UINT:4`

### `D3D_RETURN_TYPE_FLOAT:5`

### `D3D_RETURN_TYPE_MIXED:6`

### `D3D_RETURN_TYPE_DOUBLE:7`

### `D3D_RETURN_TYPE_CONTINUED:8`

### `D3D10_RETURN_TYPE_UNORM`

### `D3D10_RETURN_TYPE_SNORM`

### `D3D10_RETURN_TYPE_SINT`

### `D3D10_RETURN_TYPE_UINT`

### `D3D10_RETURN_TYPE_FLOAT`

### `D3D10_RETURN_TYPE_MIXED`

### `D3D11_RETURN_TYPE_UNORM`

Return type is UNORM.

### `D3D11_RETURN_TYPE_SNORM`

Return type is SNORM.

### `D3D11_RETURN_TYPE_SINT`

Return type is SINT.

### `D3D11_RETURN_TYPE_UINT`

Return type is UINT.

### `D3D11_RETURN_TYPE_FLOAT`

Return type is FLOAT.

### `D3D11_RETURN_TYPE_MIXED`

Return type is unknown.

### `D3D11_RETURN_TYPE_DOUBLE`

Return type is DOUBLE.

### `D3D11_RETURN_TYPE_CONTINUED`

Return type is a multiple-dword type, such as a double or uint64, and the component is continued from the previous component that was declared. The first component represents the lower bits.

## Remarks

The **D3D11_RESOURCE_RETURN_TYPE** enumeration is type defined in the D3D11shader.h header file as a [D3D_RESOURCE_RETURN_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_resource_return_type) enumeration, which is fully defined in the D3DCommon.h header file.

```

typedef D3D_RESOURCE_RETURN_TYPE D3D11_RESOURCE_RETURN_TYPE;
```

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)