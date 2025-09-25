# IDirect3D9Ex::GetAdapterLUID

## Description

This method returns a unique identifier for the adapter that is specific to the adapter hardware. Applications can use this identifier to define robust mappings across various APIs (Direct3D 9, DXGI).

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter from which to retrieve the LUID.

### `pLUID` [in]

Type: **[LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85))***

A unique identifier for the given adapter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex)