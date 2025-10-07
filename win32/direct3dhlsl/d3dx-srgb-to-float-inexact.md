# D3DX\_SRGB\_to\_FLOAT\_inexact function

Converts an SRGB value to FLOAT.

## Parameters

*val*

SRGB value to convert.

## Return value

The converted SRGB value.

## Remarks

This function doesn't have a high enough precision to give the exact answer. The alternative function [**D3DX\_SRGB\_to\_FLOAT**](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3dx-srgb-to-float) uses a lookup table to give an exact SRGB to float conversion.

## Requirements

| Requirement | Value |
|-------------------|--------------------------------------------------------------------------------------------------------|
| Header<br> | D3DX\_DXGIFormatConvert.inl |

## See also

[Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/format-conversion-functions)

[Unpacking and Packing DXGI\_FORMAT for In-Place Image Editing](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-unpacking-packing-dxgi-format)

