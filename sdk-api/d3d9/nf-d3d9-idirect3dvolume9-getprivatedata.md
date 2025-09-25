# IDirect3DVolume9::GetPrivateData

## Description

Copies the private data associated with the volume to a provided buffer.

## Parameters

### `refguid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Reference to (C++) or address of (C) the globally unique identifier that identifies the private data to retrieve.

### `pData` [in, out]

Type: **void***

Pointer to a previously allocated buffer to fill with the requested private data if the call succeeds. The application calling this method is responsible for allocating and releasing this buffer. If this parameter is **NULL**, this method will return the buffer size in pSizeOfData.

### `pSizeOfData` [in, out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the size of the buffer at
pData, in bytes. If this value is less than the actual size of the private data, such as 0, the method sets this parameter to the required buffer size, and the method returns D3DERR_MOREDATA.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_MOREDATA, D3DERR_NOTFOUND.

## Remarks

If the data returned is a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or one of its derivative classes, which was previously set by **SetPrivateData** with a `D3DSPD_IUNKNOWN` flag, that interface will have its reference count incremented before the private data is returned.

## See also

[IDirect3DVolume9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)

[IDirect3DVolume9::FreePrivateData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dvolume9-freeprivatedata)

[IDirect3DVolume9::SetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dvolume9-setprivatedata)