## Description

Values that identify the type of resource to be viewed as a shader resource.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_SRV_DIMENSION_UNKNOWN:0`

The type is unknown.

### `D3D_SRV_DIMENSION_BUFFER:1`

The resource is a buffer.

### `D3D_SRV_DIMENSION_TEXTURE1D:2`

The resource is a 1D texture.

### `D3D_SRV_DIMENSION_TEXTURE1DARRAY:3`

The resource is an array of 1D textures.

### `D3D_SRV_DIMENSION_TEXTURE2D:4`

The resource is a 2D texture.

### `D3D_SRV_DIMENSION_TEXTURE2DARRAY:5`

The resource is an array of 2D textures.

### `D3D_SRV_DIMENSION_TEXTURE2DMS:6`

The resource is a multisampling 2D texture.

### `D3D_SRV_DIMENSION_TEXTURE2DMSARRAY:7`

The resource is an array of multisampling 2D textures.

### `D3D_SRV_DIMENSION_TEXTURE3D:8`

The resource is a 3D texture.

### `D3D_SRV_DIMENSION_TEXTURECUBE:9`

The resource is a cube texture.

### `D3D_SRV_DIMENSION_TEXTURECUBEARRAY:10`

The resource is an array of cube textures.

### `D3D_SRV_DIMENSION_BUFFEREX:11`

The resource is a raw buffer. For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

### `D3D10_SRV_DIMENSION_UNKNOWN`

The type is unknown.

### `D3D10_SRV_DIMENSION_BUFFER`

The resource is a buffer.

### `D3D10_SRV_DIMENSION_TEXTURE1D`

The resource is a 1D texture.

### `D3D10_SRV_DIMENSION_TEXTURE1DARRAY`

The resource is an array of 1D textures.

### `D3D10_SRV_DIMENSION_TEXTURE2D`

The resource is a 2D texture.

### `D3D10_SRV_DIMENSION_TEXTURE2DARRAY`

The resource is an array of 2D textures.

### `D3D10_SRV_DIMENSION_TEXTURE2DMS`

The resource is a multisampling 2D texture.

### `D3D10_SRV_DIMENSION_TEXTURE2DMSARRAY`

The resource is an array of multisampling 2D textures.

### `D3D10_SRV_DIMENSION_TEXTURE3D`

The resource is a 3D texture.

### `D3D10_SRV_DIMENSION_TEXTURECUBE`

The resource is a cube texture.

### `D3D10_1_SRV_DIMENSION_UNKNOWN`

The type is unknown.

### `D3D10_1_SRV_DIMENSION_BUFFER`

The resource is a buffer.

### `D3D10_1_SRV_DIMENSION_TEXTURE1D`

The resource is a 1D texture.

### `D3D10_1_SRV_DIMENSION_TEXTURE1DARRAY`

The resource is an array of 1D textures.

### `D3D10_1_SRV_DIMENSION_TEXTURE2D`

The resource is a 2D texture.

### `D3D10_1_SRV_DIMENSION_TEXTURE2DARRAY`

The resource is an array of 2D textures.

### `D3D10_1_SRV_DIMENSION_TEXTURE2DMS`

The resource is a multisampling 2D texture.

### `D3D10_1_SRV_DIMENSION_TEXTURE2DMSARRAY`

The resource is an array of multisampling 2D textures.

### `D3D10_1_SRV_DIMENSION_TEXTURE3D`

The resource is a 3D texture.

### `D3D10_1_SRV_DIMENSION_TEXTURECUBE`

The resource is a cube texture.

### `D3D10_1_SRV_DIMENSION_TEXTURECUBEARRAY`

The resource is an array of cube textures.

### `D3D11_SRV_DIMENSION_UNKNOWN`

The type is unknown.

### `D3D11_SRV_DIMENSION_BUFFER`

The resource is a buffer.

### `D3D11_SRV_DIMENSION_TEXTURE1D`

The resource is a 1D texture.

### `D3D11_SRV_DIMENSION_TEXTURE1DARRAY`

The resource is an array of 1D textures.

### `D3D11_SRV_DIMENSION_TEXTURE2D`

The resource is a 2D texture.

### `D3D11_SRV_DIMENSION_TEXTURE2DARRAY`

The resource is an array of 2D textures.

### `D3D11_SRV_DIMENSION_TEXTURE2DMS`

The resource is a multisampling 2D texture.

### `D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY`

The resource is an array of multisampling 2D textures.

### `D3D11_SRV_DIMENSION_TEXTURE3D`

The resource is a 3D texture.

### `D3D11_SRV_DIMENSION_TEXTURECUBE`

The resource is a cube texture.

### `D3D11_SRV_DIMENSION_TEXTURECUBEARRAY`

The resource is an array of cube textures.

### `D3D11_SRV_DIMENSION_BUFFEREX`

The resource is a raw buffer. For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

## Remarks

A **D3D_SRV_DIMENSION**-typed value is specified in the **ViewDimension** member of the [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_shader_input_bind_desc) structure or the **Dimension** member of the [D3D11_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_input_bind_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)