# D3DX10FilterTexture function

Generates mipmap chain using a particular texture filter.

## Parameters

*pTexture*

Type: **[**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)\***

The texture object to be filtered. See [**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource).

*SrcLevel*

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The mipmap level whose data is used to generate the rest of the mipmap chain.

*MipFilter*

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flags controlling how each miplevel is filtered (or D3DX10\_DEFAULT for D3DX10\_FILTER\_BOX). See [**D3DX10\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-filter-flag).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

