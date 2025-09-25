# D3DX11CreateScan function

## Description

Creates a scan context.

## Parameters

### `pDeviceContext` [in]

Type: **[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)***

The [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) the scan is associated with.

### `MaxElementScanSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum single scan size, in elements (FLOAT, UINT, or INT).

### `MaxScanCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of scans in multiscan.

### `ppScan` [out]

Type: **[ID3DX11Scan](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11scan)****

Pointer to a [ID3DX11Scan Interface](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11scan) pointer that will be set to the created interface object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[D3DCSX 11 Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-functions)