## Description

Defines a vertex shader and the input element description to define the input layout. The combination is used to allow a custom vertex effect to create a custom vertex shader and pass it a custom layout.

## Members

### `shaderBufferWithInputSignature`

A pointer to the buffer.

### `shaderBufferSize`

The size of the buffer.

### `inputElements`

An array of input assembler stage data types.

### `elementCount`

The number of input elements in the vertex shader.

### `stride`

The vertex stride.

## Remarks

The vertex shader will be loaded by the [CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer) call that accepts the vertex buffer properties.

This structure does not need to be specified if one of the standard vertex shaders is used.

## See also

[D2D1_VERTEX_USAGE](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_vertex_usage)

[ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer)

[ID2D1EffectContext::LoadVertexShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadvertexshader)