# ID3D11Device::CheckFormatSupport

## Description

Get the support of a given format on the installed video device.

## Parameters

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration that describes a format for which to check for support.

### `pFormatSupport` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A bitfield of [D3D11_FORMAT_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_format_support) enumeration values describing how the specified format is supported on the installed device.
The values are ORed together.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns E_INVALIDARG if the *Format* parameter is **NULL**, or returns E_FAIL if the
described format does not exist.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)