## Description

Retrieves the texture-management priority for this texture. This method succeeds only on managed textures.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the texture priority if the call succeeds.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the return value is an error. The method returns DDERR_INVALIDOBJECT if the parameter is invalid or if the texture is not managed by Direct3D.

## Remarks

Priorities are used to determine when managed textures are to be removed from memory. A texture assigned a low priority is removed before a texture with a high priority. If two textures have the same priority, the texture that was used more recently is kept in memory; the other texture is removed.

Applications can set and retrieve priorities only for managed textures (those surfaces that were created with the DDSCAPS2_TEXTUREMANAGE flag). If you call **GetPriority** on a nonmanaged texture, **GetPriority** fails and returns DDERR_INVALIDOBJECT.

**GetPriority** was introduced with the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)