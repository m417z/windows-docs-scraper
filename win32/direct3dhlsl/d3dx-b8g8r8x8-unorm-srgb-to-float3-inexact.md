# D3DX\_B8G8R8X8\_UNORM\_SRGB\_to\_FLOAT3\_inexact function

Unpacks DXGI\_FORMAT\_B8G8R8X8\_UNORM\_SRGB shader data to an XMFLOAT3.

## Parameters

*packedInput*

The packed shader data.

## Return value

The unpacked shader data.

## Remarks

This function uses shader instructions that don't have high enough precision to give the exact answer. The alternative function [**D3DX\_B8G8R8X8\_UNORM\_SRGB\_to\_FLOAT3**](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3dx-b8g8r8x8-unorm-srgb-to-float3) uses a lookup table stored in the shader to give an exact SRGB to float conversion.

## Requirements

| Requirement | Value |
|-------------------|--------------------------------------------------------------------------------------------------------|
| Header<br> | D3DX\_DXGIFormatConvert.inl |

## See also

[Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/format-conversion-functions)

[Unpacking and Packing DXGI\_FORMAT for In-Place Image Editing](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-unpacking-packing-dxgi-format)

