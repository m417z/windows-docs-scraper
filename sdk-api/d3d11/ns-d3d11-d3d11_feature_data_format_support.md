# D3D11_FEATURE_DATA_FORMAT_SUPPORT structure

## Description

Describes which resources are supported by the current graphics driver for a given format.

## Members

### `InFormat`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) to return information on.

### `OutFormatSupport`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of [D3D11_FORMAT_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_format_support) flags indicating which resources are supported.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)