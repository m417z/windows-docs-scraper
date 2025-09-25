## Description

Retrieves a DXGI interface from an [IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface) instance.

## Parameters

### `device`

Type: **[IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface)\^**

The [IDirect3DSurface](https://learn.microsoft.com/uwp/api/windows.graphics.directx.direct3d11.idirect3dsurface) instance to retrieve the DXGI interface from.

### `dxgi`

Type: **DXGI_TYPE\*\***

On return, contains the retrieved DXGI interface.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also