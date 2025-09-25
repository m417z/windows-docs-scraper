# IDirect3DResource9::SetPrivateData

## Description

Associates data with the resource that is intended for use by the application, not by Direct3D. Data is passed by value, and multiple sets of data can be associated with a single resource.

## Parameters

### `refguid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Reference to the globally unique identifier that identifies the private data to set.

### `pData` [in]

Type: **const void***

Pointer to a buffer that contains the data to be associated with the resource.

### `SizeOfData` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the buffer at pData, in bytes.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that describes the type of data being passed, or indicates to the application that the data should be invalidated when the resource changes.

| Item | Description |
| --- | --- |
| (none) | If no flags are specified, Direct3D allocates memory to hold the data within the buffer and copies the data into the new buffer. The buffer allocated by Direct3D is automatically freed, as appropriate. |
| D3DSPD_IUNKNOWN | The data at pData is a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. SizeOfData must be set to the size of a pointer to IUnknown, that is, sizeof(IUnknown*). Direct3D automatically callsIUnknown through pData when the private data is destroyed. Private data will be destroyed by a subsequent call to **IDirect3DResource9::SetPrivateData** with the same GUID, a subsequent call to [IDirect3DResource9::FreePrivateData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dresource9-freeprivatedata), or when the [IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9) object is released. For more information, see Remarks. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, E_OUTOFMEMORY.

## Remarks

Direct3D does not manage the memory at pData. If this buffer was dynamically allocated, it is the calling application's responsibility to free the memory.

## See also

[IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)