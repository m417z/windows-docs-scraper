# ID3DX11Scan::SetScanDirection

## Description

Sets which direction to perform scans in.

## Parameters

### `Direction` [in]

Type: **[D3DX11_SCAN_DIRECTION](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_direction)**

Direction to perform scans in. See [D3DX11_SCAN_DIRECTION](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_direction).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**SetScanDirection** sets the direction [ID3DX11Scan::Scan](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-id3dx11scan-scan) and [ID3DX11Scan::Multiscan](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nf-d3dcsx-id3dx11scan-multiscan) will performed scans in.

## See also

[ID3DX11Scan](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11scan)