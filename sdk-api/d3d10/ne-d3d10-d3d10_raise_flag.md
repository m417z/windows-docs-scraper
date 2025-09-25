# D3D10_RAISE_FLAG enumeration

## Description

Option(s) for raising an error to a non-continuable exception.

## Constants

### `D3D10_RAISE_FLAG_DRIVER_INTERNAL_ERROR:0x1L`

Raise an internal driver error to a non-continuable exception.

## Remarks

These flags are used by [ID3D10Device::GetExceptionMode](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getexceptionmode) and [ID3D10Device::SetExceptionMode](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-setexceptionmode). Use 0 to indicate no flags; multiple flags can be logically OR'ed together.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)