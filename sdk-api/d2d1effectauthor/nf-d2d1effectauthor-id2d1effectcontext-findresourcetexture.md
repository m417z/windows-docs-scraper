# ID2D1EffectContext::FindResourceTexture

## Description

Finds the given resource texture if it has already been created with [ID2D1EffectContext::CreateResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createresourcetexture) with the same GUID.

## Parameters

### `resourceId` [in]

Type: **const GUID***

The unique id that identifies the resource texture.

### `resourceTexture` [out]

Type: **[ID2D1ResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1resourcetexture)****

The returned texture that can be used as a resource in a Direct2D effect.

## Return value

Type: **HRESULT**

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_NOTFOUND | The requested resource texture was not found. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)