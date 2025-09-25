# IDirect3DResource9::FreePrivateData

## Description

Frees the specified private data associated with this resource.

## Parameters

### `refguid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Reference to the globally unique identifier that identifies the private data to free.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_NOTFOUND.

## Remarks

Direct3D calls this method automatically when a resource is released.

## See also

[IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)