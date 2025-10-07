# XMUINT4 structure

Describes an 4D unsigned integer vector.

## Members

**x**

x-component of the vector.

**y**

y-component of the vector.

**z**

z-component of the vector.

**w**

w-component of the vector.

## Remarks

This structure is defined in the ``D3DX\_DXGIFormatConvert.inl`` header in the DirectX SDK (June 2010) for use from C++. The latest version of this header in the [Microsoft.DXSDK.D3DX](https://www.nuget.org/packages/Microsoft.DXSDK.D3DX) NuGet Package no longer defines it, and relies on [DirectX::XMUINT4](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmuint4) in DirectXMath instead.

## Requirements

| Requirement | Value |
|-------------------|--------------------------------------------------------------------------------------------------------|
| Header<br> | D3DX\_DXGIFormatConvert.inl |

## See also

[Structures](https://learn.microsoft.com/windows/win32/direct3dhlsl/format-conversion-structures)

[Unpacking and Packing DXGI\_FORMAT for In-Place Image Editing](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-unpacking-packing-dxgi-format)