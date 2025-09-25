# ID2D1ComputeInfo::SetResourceTexture

## Description

Sets the resource texture corresponding to the given shader texture index to the given texture resource. The texture resource must already have been loaded with [ID2D1EffectContext::CreateResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createresourcetexture) method. This call will fail if the specified index overlaps with any input. The input indices always precede the texture LUT indices.

## Parameters

### `textureIndex`

Type: **UINT32**

The index to set the resource texture on.

### `resourceTexture` [in]

Type: **[ID2D1ResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1resourcetexture)***

The resource texture object to set on the shader texture index.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1ComputeInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1computeinfo)