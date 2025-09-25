# ID2D1EffectContext::CreateVertexBuffer

## Description

Creates a vertex buffer or finds a standard vertex buffer and optionally initializes it with vertices. The returned buffer can be specified in the render info to specify both a vertex shader and or to pass custom vertices to the standard vertex shader used by [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal).

## Parameters

### `vertexBufferProperties` [in]

Type: **const [D2D1_VERTEX_BUFFER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_vertex_buffer_properties)***

The properties used to describe the vertex buffer and vertex shader.

### `resourceId` [in, optional]

Type: **const GUID***

The unique id that identifies the vertex buffer.

### `customVertexBufferProperties` [in, optional]

Type: **const [D2D1_CUSTOM_VERTEX_BUFFER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_custom_vertex_buffer_properties)***

The properties used to define a custom vertex buffer. If you use a built-in vertex shader, you don't have to specify this property.

### `buffer` [out]

Type: **[ID2D1VertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1vertexbuffer)****

The returned vertex buffer.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)