# IDirect3DVolumeTexture9::GetVolumeLevel

## Description

Retrieves the specified volume texture level.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies a level of the volume texture resource. This method returns a volume for the level specified by this parameter.

### `ppVolumeLevel` [out, retval]

Type: **[IDirect3DVolume9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)****

Address of a pointer to an [IDirect3DVolume9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolume9) interface, representing the returned volume level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Calling this method will increase the internal reference count on the [IDirect3DVolume9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolume9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DVolume9** interface results in a memory leak.

## See also

[IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)