# GetInterface function

## Description

Retrieves the DXGI interface that is wrapped by the IDirect3DDxgiInterfaceAccess object.

## Parameters

### `iid` [in]

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in p.

### `p` [out]

Type: **void\*\***

A pointer to a memory block that receives a pointer to the DXGI interface.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## See also

[Core interfaces](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-interfaces)