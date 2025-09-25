# IDirect3DSurface9::LockRect

## Description

Locks a rectangle on a surface.

## Parameters

### `pLockedRect` [out]

Type: **[D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect)***

Pointer to a [D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect) structure that describes the locked region.

### `pRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a rectangle to lock. Specified by a pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure. Specifying **NULL** for this parameter expands the dirty region to cover the entire surface.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of zero or more locking flags that describe the type of lock to perform. For this method, the valid flags are:

* D3DLOCK_DISCARD
* D3DLOCK_DONOTWAIT
* D3DLOCK_NO_DIRTY_UPDATE
* D3DLOCK_NOSYSLOCK
* D3DLOCK_READONLY

You may not specify a subrect when using D3DLOCK_DISCARD. For a description of the flags, see [D3DLOCK](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

If the method fails, the return value can be D3DERR_INVALIDCALL or D3DERR_WASSTILLDRAWING.

## Remarks

If the [D3DLOCK_DONOTWAIT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) flag is specified and the driver cannot lock the surface immediately, **IDirect3DSurface9::LockRect** will return D3DERR_WASSTILLDRAWING so that an application can use the CPU cycles while waiting for the driver to lock the surface.

The only lockable format for a depth-stencil surface is D3DFMT_D16_LOCKABLE. See [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat).

For performance reasons, dirty regions are recorded only for level zero of a texture. Dirty regions are automatically recorded when **IDirect3DSurface9::LockRect** is called without [D3DLOCK_NO_DIRTY_UPDATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) or D3DLOCK_READONLY. See [IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture) for more information.

A multisample back buffer cannot be locked.

This method cannot retrieve data from a surface that is contained by a texture resource created with [D3DUSAGE_RENDERTARGET](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) because such a texture must be assigned to D3DPOOL_DEFAULT memory and is therefore not lockable. In this case, use instead [IDirect3DDevice9::GetRenderTargetData](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getrendertargetdata) to copy texture data from device memory to system memory.

## See also

[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)

[IDirect3DSurface9::UnlockRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-unlockrect)