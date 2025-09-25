# ID2D1DrawInfo::SetResourceTexture

## Description

Sets the resource texture corresponding to the given shader texture index.

## Parameters

### `textureIndex`

Type: **UINT32**

The index of the texture to be bound to the pixel shader.

### `resourceTexture` [in]

Type: **[ID2D1ResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1resourcetexture)***

The created resource texture.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## See also

[ID2D1DrawInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1drawinfo)