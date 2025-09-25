# ID3DX11Scan::Multiscan

## Description

Performs a multiscan of a sequence.

## Parameters

### `ElementType` [in]

Type: **[D3DX11_SCAN_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_data_type)**

The type of element in the sequence. See [D3DX11_SCAN_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_data_type) for more information.

### `OpCode` [in]

Type: **[D3DX11_SCAN_OPCODE](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_opcode)**

The binary operation to perform. See [D3DX11_SCAN_OPCODE](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_opcode) for more information.

### `ElementScanSize` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of scan in elements.

### `ElementScanPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pitch of the next scan in elements.

### `ScanCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of scans in the multiscan.

### `pSrc` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

Input sequence on the device. Set *pSrc* and *pDst* to the same value for in-place scans.

### `pDst` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

Output sequence on the device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

You must point the parameters *pSrc* and *pDst* to typed buffers (and not to raw or structured buffers). For information about buffer types, see [Types of Resources](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-types). The format of these typed buffers must be [DXGI_FORMAT_R32_FLOAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), **DXGI_FORMAT_R32_UINT**, or **DXGI_FORMAT_R32_INT**. In addition, the format of these typed buffers must match the scan data type that you specify in the *ElementType* parameter. For example, if the scan data type is [D3DX11_SCAN_DATA_TYPE_UINT](https://learn.microsoft.com/windows/desktop/api/d3dcsx/ne-d3dcsx-d3dx11_scan_data_type), the buffer formats must be **DXGI_FORMAT_R32_UINT**.

## See also

[ID3DX11Scan](https://learn.microsoft.com/windows/desktop/api/d3dcsx/nn-d3dcsx-id3dx11scan)