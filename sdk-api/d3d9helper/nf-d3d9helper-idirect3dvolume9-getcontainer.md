# IDirect3DVolume9::GetContainer

## Description

Provides access to the parent volume texture object, if this surface is a child level of a volume texture.

## Parameters

### `riid` [in]

Type: **REFIID**

Reference identifier of the volume being requested.

### `ppContainer` [out, retval]

Type: **void****

Address of a pointer to fill with the container pointer, if the query succeeds.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

If the call succeeds, the reference count of the container is increased by one.

Here's an example getting the parent volume texture of a volume texture.

```

// Assumes pSurface is a valid IDirect3DVolume9 pointer
void *pContainer = NULL;
IDirect3DVolumeTexture9 *pVolumeTexture = NULL;
HRESULT hr = pVolume->GetContainer(IID_IDirect3DVolumeTexture9, &pContainer);
if (SUCCEEDED(hr) && pContainer)
{
    pVolumeTexture = (IDirect3DVolumeTexture9 *)pContainer;

```

## See also

[IDirect3DVolume9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)