## Description

Sets the maximum level of detail (LOD) for a managed mipmap surface. This method succeeds only on managed textures.

## Parameters

### `unnamedParam1` [in]

The maximum LOD value to be set for the mipmap chain if the call succeeds.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

Applications can call this method only for managed textures (those surfaces that were created with the DDSCAPS2_TEXTUREMANAGE flag). If you call **SetLOD** on a nonmanaged texture, **SetLOD** fails and returns DDERR_INVALIDOBJECT.

**SetLOD** communicates to the Direct3D texture manager the most detailed mipmap in this chain that it should load into local video memory. For example, in a five-level mipmap chain, if you set *dwMaxLOD* to 2, the texture manager should load only mipmap levels 2 through 4 into local video memory at any given time. Likewise, if the most detailed mipmap in the chain has the dimensions 256×256, setting the maximum level to 2 means that the largest mipmap ever present in video memory has dimensions 64×64.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

