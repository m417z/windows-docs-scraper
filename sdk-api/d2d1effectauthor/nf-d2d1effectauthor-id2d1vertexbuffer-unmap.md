# ID2D1VertexBuffer::Unmap

## Description

Unmaps the vertex buffer.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_WRONG_STATE | The object was not in the correct state to process the method. |

## Remarks

After this method returns, the mapped memory from the vertex buffer is no longer accessible by the effect.

## See also

[ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer)

[ID2D1VertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1vertexbuffer)