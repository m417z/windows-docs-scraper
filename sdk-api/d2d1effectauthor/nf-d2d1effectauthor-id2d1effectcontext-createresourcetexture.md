# ID2D1EffectContext::CreateResourceTexture

## Description

Creates or finds the given resource texture, depending on whether a resource id is specified. It also optionally initializes the texture with the specified data.

## Parameters

### `resourceId` [in, optional]

Type: **const GUID***

An optional pointer to the unique id that identifies the lookup table.

### `resourceTextureProperties` [in]

Type: **const [D2D1_RESOURCE_TEXTURE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_resource_texture_properties)***

The properties used to create the resource texture.

### `data` [in, optional]

Type: **const BYTE***

The optional data to be loaded into the resource texture.

### `strides` [in, optional]

Type: **const UINT32***

An optional pointer to the stride to advance through the resource texture, according to dimension.

### `dataSize`

Type: **UINT32**

The size, in bytes, of the data.

### `resourceTexture` [out]

Type: **[ID2D1ResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1resourcetexture)****

The returned texture that can be used as a resource in a Direct2D effect.

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