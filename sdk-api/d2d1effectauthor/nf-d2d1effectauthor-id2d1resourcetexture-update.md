# ID2D1ResourceTexture::Update

## Description

Updates the specific resource texture inside the specific range or box using the supplied data.

## Parameters

### `minimumExtents` [in, optional]

Type: **const UINT32***

The "left" extent of the updates if specified; if **NULL**, the entire texture is updated.

### `maximimumExtents` [in, optional]

Type: **const UINT32***

The "right" extent of the updates if specified; if **NULL**, the entire texture is updated.

### `strides` [in]

Type: **const UINT32***

The stride to advance through the input data, according to dimension.

### `dimensions`

Type: **UINT32**

The number of dimensions in the resource texture. This must match the number used to load the texture.

### `data` [in]

Type: **const BYTE***

The data to be placed into the resource texture.

### `dataCount`

Type: **UINT32**

The size of the data buffer to be used to update the resource texture.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

The number of dimensions in the update must match those of the created texture.

## See also

[ID2D1EffectContext::CreateResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createresourcetexture)

[ID2D1ResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1resourcetexture)