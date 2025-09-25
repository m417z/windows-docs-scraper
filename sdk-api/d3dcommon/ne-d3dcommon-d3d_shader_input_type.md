# D3D_SHADER_INPUT_TYPE enumeration

## Description

Values that identify resource types that can be bound to a shader and that are reflected as part of the resource description for the shader.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_SIT_CBUFFER:0`

The shader resource is a constant buffer.

### `D3D_SIT_TBUFFER`

The shader resource is a texture buffer.

### `D3D_SIT_TEXTURE`

The shader resource is a texture.

### `D3D_SIT_SAMPLER`

The shader resource is a sampler.

### `D3D_SIT_UAV_RWTYPED`

The shader resource is a read-and-write buffer or texture.

### `D3D_SIT_STRUCTURED`

The shader resource is a structured buffer.

For more information about structured buffer, see the **Remarks** section.

### `D3D_SIT_UAV_RWSTRUCTURED`

The shader resource is a read-and-write structured buffer.

### `D3D_SIT_BYTEADDRESS`

The shader resource is a byte-address buffer.

### `D3D_SIT_UAV_RWBYTEADDRESS`

The shader resource is a read-and-write byte-address buffer.

### `D3D_SIT_UAV_APPEND_STRUCTURED`

The shader resource is an append-structured buffer.

### `D3D_SIT_UAV_CONSUME_STRUCTURED`

The shader resource is a consume-structured buffer.

### `D3D_SIT_UAV_RWSTRUCTURED_WITH_COUNTER`

The shader resource is a read-and-write structured buffer that uses the built-in counter to append or consume.

### `D3D10_SIT_CBUFFER`

The shader resource is a constant buffer.

### `D3D10_SIT_TBUFFER`

The shader resource is a texture buffer.

### `D3D10_SIT_TEXTURE`

The shader resource is a texture.

### `D3D10_SIT_SAMPLER`

The shader resource is a sampler.

### `D3D11_SIT_UAV_RWTYPED`

The shader resource is a read-and-write buffer.

### `D3D11_SIT_STRUCTURED`

The shader resource is a structured buffer.

For more information about structured buffer, see the **Remarks** section.

### `D3D11_SIT_UAV_RWSTRUCTURED`

The shader resource is a read-and-write structured buffer.

### `D3D11_SIT_BYTEADDRESS`

The shader resource is a byte-address buffer.

### `D3D11_SIT_UAV_RWBYTEADDRESS`

The shader resource is a read-and-write byte-address buffer.

### `D3D11_SIT_UAV_APPEND_STRUCTURED`

The shader resource is an append-structured buffer.

### `D3D11_SIT_UAV_CONSUME_STRUCTURED`

The shader resource is a consume-structured buffer.

### `D3D11_SIT_UAV_RWSTRUCTURED_WITH_COUNTER`

The shader resource is a read-and-write structured buffer that uses the built-in counter to append or consume.

## Remarks

**D3D_SHADER_INPUT_TYPE**-typed values are specified in the **Type** member of the [D3D11_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_shader_input_bind_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)