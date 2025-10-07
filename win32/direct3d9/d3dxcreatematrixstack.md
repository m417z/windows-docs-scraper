# D3DXCreateMatrixStack function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/directxmath-portal) instead along with this header from [GitHub](https://github.com/microsoft/DirectXMath/tree/main/MatrixStack).

Creates an instance of the [**ID3DXMATRIXStack**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmatrixstack) interface.

## Parameters

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Not implemented. Specify zero.

*ppStack* \[out\]

Type: **LPD3DXMATRIXSTACK\***

Address of a pointer filled with an [**ID3DXMATRIXStack**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmatrixstack) interface pointer if the function succeeds.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

