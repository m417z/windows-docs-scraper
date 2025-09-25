# ID2D1DrawInfo::SetVertexProcessing

## Description

Sets a vertex buffer, a corresponding vertex shader, and options to control how the vertices are to be handled by the Direct2D context.

## Parameters

### `vertexBuffer` [in, optional]

Type: **[ID2D1VertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1vertexbuffer)***

The vertex buffer, if this is cleared, the default vertex shader and mapping to the transform rectangles will be used.

### `vertexOptions`

Type: **[D2D1_VERTEX_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_vertex_options)**

Options that influence how the renderer will interact with the vertex shader.

### `blendDescription` [in, optional]

Type: **const [D2D1_BLEND_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_blend_description)***

How the vertices will be blended with the output texture.

### `vertexRange` [in, optional]

Type: **const [D2D1_VERTEX_RANGE](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_vertex_range)***

The set of vertices to use from the buffer.

### `vertexShader`

Type: **GUID***

The GUID of the vertex shader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The vertex shaders associated with the vertex buffer through the vertex shader GUID must have been loaded through the [ID2D1EffectContext::LoadVertexShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadvertexshader) method before this call is made.

If you pass the vertex option [D2D1_VERTEX_OPTIONS_DO_NOT_CLEAR](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_vertex_options), then the method fails unless the blend description is exactly this:

```cpp
D2D1_BLEND_DESCRIPTION blendDesc =
        {
            D2D1_BLEND_ONE,
            D2D1_BLEND_ZERO,
            D2D1_BLEND_OPERATION_ADD,

            D2D1_BLEND_ONE,
            D2D1_BLEND_ZERO,
            D2D1_BLEND_OPERATION_ADD,

            { 1.0f, 1.0f, 1.0f, 1.0f }
        };
```

If this call fails, the corresponding [ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect) instance is placed into an error state and fails to draw.

 If blendDescription is NULL, a foreground-over blend mode is used.

## See also

[ID2D1DrawInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1drawinfo)

[ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer)

[ID2D1EffectContext::LoadVertexShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadvertexshader)