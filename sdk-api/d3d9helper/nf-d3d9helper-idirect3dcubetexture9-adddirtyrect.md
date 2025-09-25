# IDirect3DCubeTexture9::AddDirtyRect

## Description

Adds a dirty region to a cube texture resource.

## Parameters

### `FaceType` [in]

Type: **[D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces)**

Member of the [D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces) enumerated type, identifying the cube map face.

### `pDirtyRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure, specifying the dirty region. Specifying **NULL** expands the dirty region to cover the entire cube texture.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## Remarks

For performance reasons, dirty regions are only recorded for level zero of a texture. For sublevels, it is assumed that the corresponding (scaled) rectangle or box is also dirty. Dirty regions are automatically recorded when [IDirect3DCubeTexture9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-lockrect) is called without [D3DLOCK_NO_DIRTY_UPDATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) or [D3DLOCK_READONLY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock). The destination surface of [IDirect3DDevice9::UpdateSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatesurface) is also marked dirty automatically.

Using [D3DLOCK_NO_DIRTY_UPDATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) and explicitly specifying dirty regions can be used to increase the efficiency of [IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture). Using this method, applications can optimize what subset of a resource is copied by specifying dirty regions on the resource. However, the dirty regions may be expanded to optimize alignment.

## See also

[IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)

[IDirect3DCubeTexture9::GetLevelDesc](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-getleveldesc)

[IDirect3DCubeTexture9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-lockrect)

[IDirect3DCubeTexture9::UnlockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-unlockrect)