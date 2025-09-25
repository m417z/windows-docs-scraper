# IDirect3DCubeTexture9::LockRect

## Description

Locks a rectangle on a cube texture resource.

## Parameters

### `FaceType` [in]

Type: **[D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces)**

Member of the [D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces) enumerated type, identifying a cube map face.

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a level of a mipmapped cube texture.

### `pLockedRect` [out]

Type: **[D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect)***

Pointer to a [D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect) structure, describing the region to lock.

### `pRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a rectangle to lock. Specified by a pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure. Specifying **NULL** for this parameter expands the dirty region to cover the entire cube texture.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of zero or more locking flags that describe the type of lock to perform. For this method, the valid flags are:

* D3DLOCK_DISCARD
* D3DLOCK_NO_DIRTY_UPDATE
* D3DLOCK_NOSYSLOCK
* D3DLOCK_READONLY

You may not specify a subrect when using D3DLOCK_DISCARD. For a description of the flags, see [D3DLOCK](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if one or more of the arguments is invalid.

## Remarks

For performance reasons, dirty regions are only recorded for level zero of a texture. Dirty regions are automatically recorded when **IDirect3DCubeTexture9::LockRect** is called without D3DLOCK_NO_DIRTY_UPDATE or D3DLOCK_READONLY. See [IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture) for more information.

Cube textures created with D3DPOOL_DEFAULT are not lockable. Cube textures created in video memory are lockable when created with [USAGE_DYNAMIC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage).

The only lockable format for a depth-stencil texture is [D3DFMT_D16_LOCKABLE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat).

## See also

[IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)

[IDirect3DCubeTexture9::AddDirtyRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-adddirtyrect)

[IDirect3DCubeTexture9::GetLevelDesc](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-getleveldesc)

[IDirect3DCubeTexture9::UnlockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-unlockrect)