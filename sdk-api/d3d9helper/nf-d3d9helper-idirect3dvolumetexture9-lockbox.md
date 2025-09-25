# IDirect3DVolumeTexture9::LockBox

## Description

Locks a box on a volume texture resource.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the level of the volume texture resource to lock.

### `pLockedVolume` [out]

Type: **[D3DLOCKED_BOX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-box)***

Pointer to a [D3DLOCKED_BOX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-box) structure, describing the locked region.

### `pBox` [in]

Type: **const [D3DBOX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dbox)***

Pointer to the volume to lock. This parameter is specified by a pointer to a [D3DBOX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dbox) structure. Specifying **NULL** for this parameter locks the entire volume level.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of zero or more locking flags that describe the type of lock to perform. For this method, the valid flags are:

* D3DLOCK_DISCARD
* D3DLOCK_NO_DIRTY_UPDATE
* D3DLOCK_NOSYSLOCK
* D3DLOCK_READONLY

For a description of the flags, see [D3DLOCK](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

For performance reasons, dirty regions are only recorded for level zero of a texture. Dirty regions are automatically recorded when **LockBox** is called without D3DLOCK_NO_DIRTY_UPDATE or D3DLOCK_READONLY. For more information, see [UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture).

## See also

[IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)

[UnlockBox](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dvolumetexture9-unlockbox)