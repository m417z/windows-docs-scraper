# IDirect3DVolumeTexture9::AddDirtyBox

## Description

Adds a dirty region to a volume texture resource.

## Parameters

### `pDirtyBox` [in]

Type: **const [D3DBOX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dbox)***

Pointer to a [D3DBOX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dbox) structure, specifying the dirty region to add. Specifying **NULL** expands the dirty region to cover the entire volume texture.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

For performance reasons, dirty regions are only recorded for level zero of a texture. For sublevels, it is assumed that the corresponding (scaled) box is also dirty. Dirty regions are automatically recorded when [LockBox](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dvolumetexture9-lockbox) is called without [D3DLOCK_NO_DIRTY_UPDATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) or [D3DLOCK_READONLY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock).

Using [D3DLOCK_NO_DIRTY_UPDATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) and explicitly specifying dirty regions can be used to increase the efficiency of [UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture). Using this method, applications can optimize what subset of a resource is copied by specifying dirty boxes on the resource. However, the dirty regions may be expanded to optimize alignment.

## See also

[IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)