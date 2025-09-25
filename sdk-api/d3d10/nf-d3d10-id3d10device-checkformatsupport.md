# ID3D10Device::CheckFormatSupport

## Description

Get the support of a given format on the installed video device.

## Parameters

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration that describes a format for which to check for support.

### `pFormatSupport` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A bitfield of [D3D10_FORMAT_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_format_support) enumeration values describing how the specified format is supported on the installed device.
The values are ORed together.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns E_INVALIDARG if the *Format* parameter is **NULL**, or returns E_FAIL if the described
format does not exist.

## Remarks

Most format support is based on the Direct3D feature level. Only a few specific use cases require checking for support.
See [Hardware Support for Direct3D 10 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-0-hardware)
and [Hardware Support for Direct3D 10.1 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-1-hardware) for additional information.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)