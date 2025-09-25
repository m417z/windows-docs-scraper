# D3DX11CreateSegmentedScan function

## Description

Creates a segmented scan context.

## Parameters

### `pDeviceContext` [in]

Type: **[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)***

Pointer to an [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) interface.

### `MaxElementScanSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum single scan size, in elements (FLOAT, UINT, or INT).

### `ppScan` [out]

Type: **[ID3DX11SegmentedScan](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11segmentedscan)****

Pointer to a [ID3DX11SegmentedScan Interface](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11segmentedscan) pointer that will be set to the created interface object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[D3DCSX 11 Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dcsx11-functions)