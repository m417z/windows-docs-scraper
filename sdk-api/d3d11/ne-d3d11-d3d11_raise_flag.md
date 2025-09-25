# D3D11_RAISE_FLAG enumeration

## Description

Option(s) for raising an error to a non-continuable exception.

## Constants

### `D3D11_RAISE_FLAG_DRIVER_INTERNAL_ERROR:0x1L`

Raise an internal driver error to a non-continuable exception.

## Remarks

These flags are used by [ID3D11Device::GetExceptionMode](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-getexceptionmode) and [ID3D11Device::SetExceptionMode](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-setexceptionmode). Use 0 to indicate no flags; multiple flags can be logically OR'ed together.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)