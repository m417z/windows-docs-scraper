# ID2D1EffectContext::FindVertexBuffer

## Description

This finds the given vertex buffer if it has already been created with [ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer) with the same GUID.

## Parameters

### `resourceId` [in]

Type: **const GUID***

The unique id that identifies the vertex buffer.

### `buffer` [out]

Type: **[ID2D1VertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1vertexbuffer)****

The returned vertex buffer that can be used as a resource in a [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) effect.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_NOTFOUND | The requested vertex buffer was not found. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)