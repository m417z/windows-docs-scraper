# D2D1_VERTEX_BUFFER_PROPERTIES structure

## Description

Defines the properties of a vertex buffer that are standard for all vertex shader definitions.

## Members

### `inputCount`

The number of inputs to the vertex shader.

### `usage`

Indicates how frequently the vertex buffer is likely to be updated.

### `data`

The initial contents of the vertex buffer.

### `byteWidth`

The size of the vertex buffer, in bytes.

## Remarks

If **usage** is dynamic, the system might return a system memory buffer and copy these vertices into the rendering vertex buffer for each element.

If the initialization data is not specified, the buffer will be uninitialized.

## See also

[D2D1_VERTEX_USAGE](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_vertex_usage)

[ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer)

[ID2D1EffectContext::LoadVertexShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadvertexshader)