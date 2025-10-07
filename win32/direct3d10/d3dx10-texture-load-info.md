# D3DX10\_TEXTURE\_LOAD\_INFO structure

Describes parameters used to load a texture from another texture.

## Members

**pSrcBox**

Type: **[**D3D10\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D10/ns-d3d10-d3d10_box)\***

Source texture box (see [**D3D10\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D10/ns-d3d10-d3d10_box)).

**pDstBox**

Type: **[**D3D10\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D10/ns-d3d10-d3d10_box)\***

Destination texture box (see [**D3D10\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D10/ns-d3d10-d3d10_box)).

**SrcFirstMip**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Source texture mipmap level, see [**D3D10CalcSubresource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nf-d3d10-d3d10calcsubresource) for more detail.

**DstFirstMip**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Destination texture mipmap level, see [**D3D10CalcSubresource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nf-d3d10-d3d10calcsubresource) for more detail.

**NumMips**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mipmap levels in the source texture.

**SrcFirstElement**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

First element of the source texture.

**DstFirstElement**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

First element of the destination texture.

**NumElements**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of elements to load.

**Filter**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Filtering options during resampling (see [**D3DX10\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-filter-flag)).

**MipFilter**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Filtering options when generating mip levels (see [**D3DX10\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-filter-flag)).

## Remarks

This structure is used in a call to [**D3DX10LoadTextureFromTexture**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10loadtexturefromtexture).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

