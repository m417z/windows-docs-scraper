# D3D10_BIND_FLAG enumeration

## Description

Identifies how to bind a resource to the pipeline.

## Constants

### `D3D10_BIND_VERTEX_BUFFER:0x1L`

Bind a buffer as a [vertex buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

### `D3D10_BIND_INDEX_BUFFER:0x2L`

Bind a buffer as an [index buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

### `D3D10_BIND_CONSTANT_BUFFER:0x4L`

Bind a buffer as a [constant buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to a [shader stage](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)); this flag may NOT be combined with any other bind flag.

### `D3D10_BIND_SHADER_RESOURCE:0x8L`

Bind a buffer or texture to a [shader stage](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)); this flag cannot be used with the [D3D10_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map) flag.

### `D3D10_BIND_STREAM_OUTPUT:0x10L`

Bind an output buffer for the [stream-output stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-stream-stage).

### `D3D10_BIND_RENDER_TARGET:0x20L`

Bind a texture as a render target for the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

### `D3D10_BIND_DEPTH_STENCIL:0x40L`

Bind a texture as a depth-stencil target for the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

## Remarks

In general, binding flags can be combined using a logical OR (except the constant-buffer flag); however, you should use a single flag to allow the device to optimize the resource usage.

This enumeration is used by a:

* [Buffer description](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_buffer_desc) when creating a buffer.
* Texture description when creating a texture (see [D3D10_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture1d_desc) or [D3D10_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture2d_desc) or [D3D10_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture3d_desc)).

A shader-resource buffer is NOT a constant buffer; rather, it is a texture or buffer resource that is bound to a shader, that contains texture or buffer data (it is not limited to a single element type in the buffer). A shader-resource buffer is created with the D3D10_BIND_SHADER_RESOURCE flag and is bound to the pipeline using one of these APIs: [ID3D10Device::GSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetshaderresources), [ID3D10Device::PSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-pssetshaderresources), or [ID3D10Device::VSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vssetshaderresources). Furthermore, a shader-resource buffer cannot use the [D3D10_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map) flag.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)