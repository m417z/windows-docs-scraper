# ID2D1VertexBuffer::Map

## Description

Maps the provided data into user memory.

## Parameters

### `data` [out]

Type: **const BYTE****

When this method returns, contains the address of a pointer to the available buffer.

### `bufferSize`

Type: **UINT32**

The desired size of the buffer.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |
| D3DERR_DEVICELOST | The device has been lost but cannot be reset at this time. |

## Remarks

If *data* is larger than *bufferSize*, this method fails.

## See also

[ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer)

[ID2D1VertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1vertexbuffer)