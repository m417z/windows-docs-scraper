# D3D12GetFormatPlaneCount function

Gets the number of planes for the specified DXGI format for the specified virtual adapter (an **ID3D12Device**).

## Parameters

*pDevice* \[in\]

Type: **[**ID3D12Device**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)\***

The virtual adapter (an [**ID3D12Device**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)) for which to get the plane count.

*Format*

Type: **[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) for which to get the plane count.

## Return value

Type: **UINT8**

The plane count for the specified format on the specified virtual adapter.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[**D3D12\_FEATURE\_DATA\_FORMAT\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_format_info)

[**CheckFeatureSupport**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport)

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

