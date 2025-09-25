# IDirect3DTexture9::LockRect

## Description

Locks a rectangle on a texture resource.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the level of the texture resource to lock.

### `pLockedRect` [out]

Type: **[D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect)***

Pointer to a [D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect) structure, describing the locked region.

### `pRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a rectangle to lock. Specified by a pointer to a RECT structure. Specifying **NULL** for this parameter expands the dirty region to cover the entire texture.

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

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Textures created with D3DPOOL_DEFAULT are not lockable. Textures created in video memory are lockable when created with [USAGE_DYNAMIC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage).

For performance reasons, dirty regions are recorded only for level zero of a texture. Dirty regions are automatically recorded when **IDirect3DTexture9::LockRect** is called without [D3DLOCK_NO_DIRTY_UPDATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) or D3DLOCK_READONLY. See [IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture) for more information.

The only lockable format for a depth-stencil texture is [D3DLOCK_D16_LOCKABLE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock).

Video memory textures cannot be locked, but must be modified by calling [IDirect3DDevice9::UpdateSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatesurface) or [IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture). There are exceptions for some proprietary driver pixel formats that Direct3D 9 does not recognize. These can be locked.

This method cannot retrieve data from a texture resource created with [D3DUSAGE_RENDERTARGET](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) because such a texture must be assigned to D3DPOOL_DEFAULT memory and is therefore not lockable. In this case, use instead [IDirect3DDevice9::GetRenderTargetData](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getrendertargetdata) to copy texture data from device memory to system memory.

## See also

[IDirect3DDevice9::GetRenderTargetData](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getrendertargetdata)

[IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture)

[IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)

[IDirect3DTexture9::UnlockRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dtexture9-unlockrect)